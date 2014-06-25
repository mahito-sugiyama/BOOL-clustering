\name{BOOL-package}
\alias{BOOL-package}
\docType{package}
\title{
  Fast spatial clustering via discretization
}
\description{
  This package is an implementation of the BOOL algorithm, which
  can efficiently detect arbitrarily shaped clusters and is noise tolerant.
}
\details{
\tabular{ll}{
  Package: \tab BOOL\cr
  Type: \tab Package\cr
  Version: \tab 1.0\cr
  Date: \tab 2014-06-25\cr
  License: \tab GPL (>= 2)\cr
}
This package contains a function \code{BOOL} that performs clustering.
}
\author{
  Mahito Sugiyama

  Maintainer: Mahito Sugiyama \code{<mahito@ar.sanken.osaka-u.ac.jp>}
}
\references{
  Sugiyama, M., Yamamoto, A.: A Fast and Flexible Clustering Algorithm Using Binary Discretization,
  IEEE ICDM 2011.
}
\keyword{ clustering }
\keyword{ discretization }
\keyword{ sort }
\examples{
X <- rbind(matrix(rnorm(2000, 0, 1), ncol=2), matrix(rnorm(2000, 5, 1),
ncol=2))
  ## Generate a dataset with 2000 objects and 2 dimensions, where there are two clusters
cl <- BOOL(X, 2)
  ## Perform clustering and store cluster labels in 'cl'
plot(X, col = cl)
  ## Plot clusters
}
