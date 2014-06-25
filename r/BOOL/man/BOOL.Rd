\name{BOOL}
\alias{BOOL}
\title{
  Fast spatial clustering via discretization
}
\description{
  This algorithm performs fast spatial clustering for a multivariate dataset, which can detect arbitrarily shaped clusters and is noise tolerant.
}
\usage{
BOOL(X, cl, reach = 1, noise = 50)
}
\arguments{
  \item{X}{
    a data matrix, where rows and columns correspond to data points and
    dimensions, respectively.
  }
  \item{cl}{
    number of clusters.
  }
  \item{reach}{
    distance parameter, which controls the connectivity between data points.
  }
  \item{noise}{
    noise parameter, if the number of data points in a cluster is
    smaller than this parameter, the cluster is assumed to be a set of noises.
  }
}
\details{
  \code{BOOL} is an efficient clustering method using discretization.
  It repeatedly discretize data points and marge them if the Manhattan
  distance between them is smaller than the distance parameter \code{reach}.
  The number of clusters monotonically increases if discretization
  becomes fine, and it stops if the number of clusters is larger then
  the input \code{cl}.
  Moreover, clusters whose size is smaller than \code{noise} are
  detected as noise.
  The efficient clustering is achieved by sorting them in advance.
}
\value{
  a vector of cluster labels of given data points
}
\references{
  Sugiyama, M., Yamamoto, A.: A Fast and Flexible Clustering Algorithm Using Binary Discretization,
  IEEE ICDM 2011.
}
\author{
  Mahito Sugiyama
}
\note{
  A data matrix \code{X} is normalized internally.
}
\examples{
X <- rbind(matrix(rnorm(2000, 0, 1), ncol=2), matrix(rnorm(2000, 5, 1),
ncol=2))
  ## Generate a dataset with 2000 objects and 2 dimensions, where there are two clusters
cl <- BOOL(X, 2)
  ## Perform clustering and store cluster labels in 'cl'
plot(X, col = cl)
  ## Plot clusters
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{ clustering }
\keyword{ discretization }
\keyword{ sort }
