#include <Rcpp.h>

using std::vector;
using std::string;
using std::cout;
using std::cerr;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::copy;
using std::back_inserter;
using std::swap;
using std::max_element;
using std::min_element;
using Rcpp::NumericVector;
using Rcpp::IntegerVector;
using Rcpp::as;
using Rcpp::wrap;

#define LEVEL_MAX 16
#define TAB "    "

struct node {
  int id;
  int size;
  struct node *next;
};
