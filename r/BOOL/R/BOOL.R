BOOL <-
function(X, cl, reach = 1, noise = 50) {
  .Call("BOOLcc", as.vector(X), c(nrow(X), ncol(X), cl, reach, noise))
}
