//
// Created by Jacob on 9/21/2015.
// Restarted because my code was getting confusing like you said it
// would be better tyo test as i go so i am.

#include "Point.h"

using namespace std;
namespace Clustering {
    // Initializes Point
    Point::Point(int userDim) {
        dim = userDim;
        values =  new double[dim];
    }
    //Not sure i need
    //Point::Point(int, double *) {
   // }
    // Copy constructor
    Point::Point(const Point &pt) {
        values = new double[pt.dim];
        dim = pt.dim;
        for (int i = 0; i < dim; i++){
            values[i] = pt.values[i];
        }
    }
    // Overload the assignment operator
    Point &Point::operator=(const Point &pt){
        if (&pt != this) {
            dim = pt.dim;
            values = new double[pt.dim];
            for (int i = 0; i < dim; i++){
                values[i] = pt.values[i];
            }
        }
        return *this;
    }
    // Destructor
    Point::~Point() {
        delete[] values;
    }
    // Accessors & mutators
    int Point::getDims() const {
        return dim;
    }
    double Point::getValue(int userIndex) const {
        return values[userIndex];
    }
    void Point::setDims(int nDim) {
        dim = nDim;
    }
    void Point::setValue(int index, double userValue) {
        values[index] = userValue;
    }
    // Functions
    double Point::distanceTo(Point &other) {
        if (other.dim == this->dim) {
            double sum = 0;
            for (int i = 0; i < dim; i++) {
                double diff = arr[i] - other.arr[i];
                sum += diff * diff;

            }
            return sqrt(sum);

        }
        return 0;
    }



};