/*
    BOOL: Fast spatial clustering via discretization
    Copyright (C) 2014 Mahito Sugiyama

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

    Contact: Mahito Sugiyama <mahito.sugiyama@tuebingen.mpg.de>

    Please refer the following article in your published research:
    Sugiyama, M., Yamamoto, A.: A Fast and Flexible Clustering Algorithm Using Binary Discretization,
    Proceedings of the 2011 IEEE International Conference on Data Mining (ICDM 2011), 1212-1217, 2011.
*/
#include "header.h"
#include "utility.h"
#include "io.h"
#include "bool.h"

int main(int argc, char **argv) {
  clock_t t1 = clock();

  if (argc <= 1) {
    cout << "ERROR: Arguments are not enough." << endl
	 << "       Please use the '-h' option for the usage information." << endl;
    exit(0);
  }

  vector<int> param(5, 0);
  param[3] = 1;  // default value for the distance parameter
  param[4] = 50; // default value for the noise parameter

  int opt;
  string input = "input";
  string output = "output";
  while ((opt = getopt(argc, argv, "vhc:i:o:r:n:")) != -1) {
    switch (opt) {
    case 'v':
      cout << "BOOL version 1.0" << endl;
      exit(0);
    case 'h':
      cout << "Usage: ./bool -c <number of clusters> -i <input_file> -o <output_file> [options]" << endl
	   << "Synopsis: clustering via discretization (BOOL)" << endl
	   << "Options:" << endl
	   << TAB << "-i: input file name        (default value: input)" << endl
	   << TAB << "-o: output file name       (default value: output)" << endl
	   << TAB << "-r: reachability distance  (default value: 1)" << endl
	   << TAB << "-n: reachability parameter (default value: 50)" << endl
	   << "Example: ./bool -c 6 -i input.csv -o output.txt" << endl;
      exit(0);
    case 'c':
      param[2] = atoi(optarg);
      break;
    case 'i':
      input = optarg;
      break;
    case 'o':
      output = optarg;
      break;
    case 'r':
      param[3] = atoi(optarg);
      break;
    case 'n':
      param[4] = atoi(optarg);
      break;
    default:
      cerr << "ERROR: an unknown option is set" << endl;
      exit(1);
    }
  }

  if (param[2] == 0) {
    cout << "Please specify the number of clusters by '-c'." << endl;
    exit(0);
  }

  vector<double> X_raw;
  cout << "Read data from:   \"" << input  << "\"" << endl
       << "Write results to: \"" << output << "\"" << endl;
  readFile(input, X_raw, param); // read an input file <input> and store to "X_raw"
  transpose(X_raw, param[0], param[1]); // transpose "X_raw" for the subsequent process

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

  writeFile(output, label); // write labels to <output>

  cout << "Total running time: " << endl
       << TAB << (double)(t3 - t1) / CLOCKS_PER_SEC << " sec." << endl
       << "Running time for clustering (without file intput & output): " << endl
       << TAB << (double)(t3 - t2) / CLOCKS_PER_SEC << " sec." << endl;
}
