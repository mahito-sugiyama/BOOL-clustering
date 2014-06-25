// copyright: see the header of "main.cc"
void normalize(vector<double>& X_raw) {
  double x_max = *max_element(X_raw.begin(), X_raw.end());
  double x_min = *min_element(X_raw.begin(), X_raw.end());
  double denom = x_max - x_min + 0.0000001;

  for (unsigned int i = 0; i < X_raw.size(); i++) {
      X_raw[i] = (X_raw[i] - x_min) / denom;
  }
}

void transpose(vector<double>& X_raw, const int n, const int d) {
  vector<double> X_tmp;

  copy(X_raw.begin(), X_raw.end(), back_inserter(X_tmp));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < d; j++) {
      X_raw[i + j * n] = X_tmp[j + i * d];
    }
  }
}

// currently not used
void normalizeEach(vector<double>& X_raw, const int n, const int d) {
  for (int dim = 0; dim < d; dim++) {
    int start = n * dim;
    int end = n * (dim + 1);
    double x_max = *max_element(X_raw.begin() + start, X_raw.begin() + end);
    double x_min = *min_element(X_raw.begin() + start, X_raw.begin() + end);
    double denom = x_max - x_min + 0.0000001;
    for (int i = 0; i < n; i++) {
      X_raw[i + start] = (X_raw[i + start] - x_min) / denom;
    }
  }
}
