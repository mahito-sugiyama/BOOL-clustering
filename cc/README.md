BOOL: Fast special clustering via discretization
================================================

A fast spatial clustering algorithm for multivariate data.

Usage
-----

Given a multivariate dataset, this C++ program performs clustering and produces cluster labels of each data point.
To use it, type:

	$ make
	$ ./bool -c <number_of_clusters> -i <input_file> -o <output_file>

* `<number_of_clusters` specifies the minimum number of clusters to be produced.
* A dataset is read from `<input_file>`, which should be a comma-separated text file without row and column names.
	Rows and columns correspond to respective data points and dimensions (default value: "input").
* Resulting class labels are written to `<output_file>` (default value: "output").
* The noise parameter is set by the option `-n` (default value: 50).
* The distance parameter is set by the option `-r` (default value: 1).
* Please use the `-h` option to get more detailed usage information.


Example
-------

	$ make
	$ ./bool -s 6
		Read data from:   "input"
		Write results to: "output"
		Parameters:
			Number of data points: 8000
			Number of dimensions:  2
			Number of clusters:    6
			Noise parameter:       50
			Distance parameter:    1
		Start BOOL:
			Level 1 ... end
			Number of clusters: 1
			Level 2 ... end
			Number of clusters: 1
			Level 3 ... end
			Number of clusters: 1
			Level 4 ... end
			Number of clusters: 1
			Level 5 ... end
			Number of clusters: 1
			Level 6 ... end
			bNumber of clusters: 2
			Level 7 ... end
			Number of clusters: 6
		Total running time:
			0.015821 sec.
		Running time for clustering (without file intput & output):
			0.008175 sec.

Contact
-------

* Author: Mahito Sugiyama
* Affiliation: ISIR, Osaka University, Japan
* Mail: mahito@ar.sanken.osaka-u.ac.jp
