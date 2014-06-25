#include "header.h"
#include "utility.h"
#include "bool.h"

RcppExport SEXP BOOLcc(SEXP _X, SEXP _param) {
  vector<double> X_raw = Rcpp::as<vector<double> >(_X);
  vector<int> param = Rcpp::as<vector<int> >(_param);

  clock_t t1 = clock();

  cout << "Parameters:" << endl
       << TAB << "Number of data points: " << param[0] << endl
       << TAB << "Number of dimensions:  " << param[1] << endl
       << TAB << "Number of clusters:    " << param[2] << endl
       << TAB << "Noise parameter:       " << param[4] << endl
       << TAB << "Distance parameter:    " << param[3] << endl;

  vector<int> label(param[0]); // store cluster labels of each data point

  clock_t t2 = clock();

  cout << "Start BOOL:" << endl;
  BOOL(X_raw, label, param); // perform BOOL clustering

  clock_t t3 = clock();

  cout << "Total running time: " << endl
       << TAB << (double)(t3 - t1) / CLOCKS_PER_SEC << " sec." << endl
       << "Running time for clustering (without file intput & output): " << endl
       << TAB << (double)(t3 - t2) / CLOCKS_PER_SEC << " sec." << endl;

  return wrap(label);
}
