#include "Cluster.h"


using namespace Clustering;

Cluster Cluster::operator=(const Point &other) {
    double dim = 0;
    if (&other != this) {
        dim = other.dim;
        arr = new double[other.dim];
    }
    return *this;

};