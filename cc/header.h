// copyright: see the header of "main.cc"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cmath>
#include <unistd.h>

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

#define LEVEL_MAX 16
#define TAB "    "

struct node {
  int id;
  int size;
  struct node *next;
};
