BOOL: Fast special clustering via discretization
================================================

A fast spatial clustering algorithm for multivariate data.

Summary
-------

This is a fast spatial clustering algorithm for multivariate (real-valued) data, which can detect arbitrarily shaped clusters and is noise tolerant.
This algorithm has the following advantages:

* **Fast**; the time complexity is linear in the number of data points; it is faster than *K*-means,
* **Frexible**; it can find arbitrarily shaped clusters (for example, *K*-means finds only convex clusters), and
* **Easy to use**; it is robust to parameter setting. The number of clusters is needed, but you do not need to be careful for the other two parameters in most cases.

Please see the following paper for the detailed information about this method and refer it in your published research:

* Sugiyama, M., Yamamoto, A.: **A Fast and Flexible Clustering Algorithm Using Binary Discretization**,
    *Proceedings of the 2011 IEEE International Conference on Data Mining* (ICDM 2011), 1212-1217, 2011.

Both an R package and C++ implementation are available.

Contact
-------

* Author: Mahito Sugiyama
* Affiliation: ISIR, Osaka University, Japan
* Mail: mahito@ar.sanken.osaka-u.ac.jp
