// copyright: see the header of "main.cc"
#include "header.h"
#include "utility.h"
#include "io.h"

void initialize(vector<struct node>& tree, vector<int>& index) {
  for (unsigned int i = 0; i < index.size(); i++) {
    index[i] = i;
    tree[i].id = -1;
    tree[i].size = 1;
    tree[i].next = NULL;
  }
}

void discretize(vector<double>& X_raw, vector<int>& X, const int level) {
  double dm = 1 << level;
  for (unsigned int i = 0; i < X.size(); i++) {
    X[i] = floor(X_raw[i] * dm);
  }
}

void bucketsort(vector<int>& x, vector<int>& index) {
  vector<vector<int> > buckets;
  buckets.resize(1 << LEVEL_MAX);

  for (vector<int>::iterator itr = index.begin(), end = index.end(); itr != end; ++itr) {
    buckets[ x[*itr] ].push_back(*itr);
  }

  int counter = 0;
  for (vector<vector<int> >::iterator itr = buckets.begin(), end = buckets.end(); itr != end; ++itr) {
    for (vector<int>::iterator itr2 = (*itr).begin(), end2 = (*itr).end(); itr2 != end2; ++itr2) {
      index[counter] = *itr2;
      counter++;
    }
  }
}

void slice(vector<int>& X, vector<int>& x, const int n, const int dim) {
  int raise = n * dim;
  for (int i = 0; i < n; i++) {
    x[i] = X[i + raise];
  }
}

void addNode(vector<struct node>& tree, int idx1, int idx2) {
  struct node *p, *p1, *p2, *p1_prev, *p2_prev;
  if (idx1 > idx2) swap(idx1, idx2);

  p1 = &tree[idx1];
  while (p1->next != NULL) p1 = p1->next;
  p2 = &tree[idx2];
  while (p2->next != NULL) p2 = p2->next;

  // merge two clusters
  if (p1 != p2) {
    p = p1; // target
    p1 = &tree[idx1];
    while (p1->next != NULL) {
      p1_prev = p1;
      p1 = p1->next;
      p1_prev->next = p;
    }

    p2 = &tree[idx2];
    while (p2->next != NULL) {
      p2_prev = p2;
      p2 = p2->next;
      p2_prev->next = p;
    }
    p2->next = p;
    p->size += p2->size;
  }
}

int labeling(vector<struct node>& tree, const int noise) {
  int id = 1;
  struct node *p;

  for (unsigned int i = 0; i < tree.size(); i++) {
    p = &tree[i];
    while (p->next != NULL) p = p->next;
    if (p->size <= noise) tree[i].id = 0;
    else {
      if (p->id == -1) p->id = id++;
      tree[i].id = p->id;
    }
  }
  return id - 1;
}

void check(vector<int>& X, vector<int>& index, vector<struct node>& tree,
	   const int n, const int d, const int reach) {
  int diff;
  for (int i = 0; i < (n - 1); i++) {
    diff = 0;
    for (int j = 0; j < d; j++) {
      diff += abs( X[index[i] + j * n] - X[index[i + 1] + j * n] );
      if (diff > reach) break;
    }
    if (diff <= reach)
      addNode(tree, index[i], index[i + 1]);
  }
}

int makeHierarchy(vector<double>& X_raw, vector<int>& X, vector<int>& index, vector<int>& x, vector<struct node>& tree,
		  const int level, vector<int>& param) {
  const int n = param[0];
  const int d = param[1];
  const int reach = param[3];
  const int noise = param[4];

  initialize(tree, index);
  discretize(X_raw, X, level);

  for (int dim = d - 1; dim >= 0; dim--) {
    // slice
    slice(X, x, n, dim);
    // sort x at dimension "dim"
    bucketsort(x, index);
  }

  for (int dim = d - 1; dim >= 0; dim--) {
    // slice
    slice(X, x, n, dim);
    // sort x at dimension "dim"
    bucketsort(x, index);
    // check
    check(X, index, tree, n, d, reach);
  }

  return labeling(tree, noise);
}

void BOOL(vector<double>& X_raw, vector<int>& label, vector<int>& param) {
  const int n = param[0];
  const int cl_min = param[2];

  vector<int> X(X_raw.size());
  vector<int> index(n);
  vector<int> x(n);
  vector<struct node> tree(n);

  normalize(X_raw); // normalize the given dataset "X_raw"

  for (int level = 1; level < LEVEL_MAX; level++) {
    cout << TAB << "Level " << level << " ... ";
    int cl = makeHierarchy(X_raw, X, index, x, tree, level, param); // perform clustering for each level
    cout << "end" << endl;
    cout << TAB << "Number of clusters: " << cl << endl;
    if (cl >= cl_min) break;
    else if (cl == 0) {
      cout << "Noise parameter is too large." << endl;
      break;
    }
  }

  for (int i = 0; i < n; i++) {
    label[i] = tree[i].id;
  }
}
