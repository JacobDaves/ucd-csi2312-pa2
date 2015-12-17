//
// Created by Jacob on 10/13/2015.
//
// Restarted because my code was getting confusing like you said it
// would be better tyo test as i go so i am.

#include <cmath>
#include "Point.h"

using namespace std;
namespace Clustering {
    // Initializes Point
    Point::Point(int userDim) {
        dim = userDim;
        values =  new double[dim];
    }
    //Not sure i need
    //Point::Point(int dim, double array[]) {
    //
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
    double Point::distanceTo(const Point &other_pt) const {
        if (other_pt.dim == this->dim) {
            double sum = 0;
            for (int i = 0; i < dim; i++) {
                double diff = values[i] - other_pt.values[i];
                sum += diff * diff;

            }
            return (sqrt(sum));

        }
        return 0;
    }
    // Members
    Point &Point::operator*=(double d) {
        for (int i = 0; i < dim; i++)
            values[i] *= d;
        return *this;
    }
    Point &Point::operator/=(double d) {
        for (int i = 0; i < dim; i++)
            values[i] /= d;
        return *this;
    }
    const Point Point::operator*(double d) const {
        return Point(dim) *= d;
    }
    const Point Point::operator/(double d) const {
        return Point(dim) /= d;
    }
    // Friends
    // Adds one points dims to another points dims
    Point &operator+=(Point &lhs, const Point &rhs) {
        if (&lhs == &rhs) {
            return lhs *= 2;
        } else if (lhs.dim != rhs.dim) {
            for (int i = 0; i < lhs.dim; i++)
                lhs.values[i] + rhs.values[i];
        }
        return lhs;
    }
    // now one to subtract just going to use my first one
    // and change it a bit
    Point &operator-=(Point &lhs, const Point &rhs) {
        if (&lhs == &rhs) {
            return lhs *= 0;
        } else if (lhs.dim != rhs.dim) {
            for (int i = 0; i < lhs.dim; i++)
                lhs.values[i] - rhs.values[i];
        }
        return lhs;
    }
    // this one adds two dims together
    const Point operator+(const Point &pt1, const Point &pt2) {
        Point pt3(pt1.dim);
        pt3 += pt1;
        pt3 += pt2;
        return pt3;
    }

    // Subtract now again reusing my old code i know works
    const Point operator-(const Point &pt1, const Point &pt2) {
        Point pt3(pt1.dim);
        pt3 -= pt1;
        pt3 -= pt2;
        return pt3;
    }
    bool operator==(const Point &pt1, const Point &pt2){
        if (pt1.dim != pt2.dim) return false;

        bool isEqual = true;
        for (int i; i < pt1.dim; i++) {
            if(pt1.values[i] != pt2.values[i]){
                isEqual = false;
                break;
            }
        } return isEqual;
    }
    bool operator!=(const Point &pt1, const Point &pt2){
        return !( pt1 == pt2);
    }
    // Overloading isLess operators
    bool operator<(const Point &pt1, const Point &pt2) {
        bool isLess = true;
        for (int i = 0; i < pt1.dim; i++) {
            if (pt1.values[i] >= pt2.values[i]) {
                isLess = false;
                break;
            }
        }
        return isLess;
    }
    bool operator<=(const Point &pt1, const Point &pt2) {
        bool isLessEqual = false;
        for (int i = 0; i < pt1.dim; i++) {
            isLessEqual = (pt1.values[i] <= pt2.values[i]);

        }
        return isLessEqual;
    }
    // Overloading isGreater operator
    bool operator>(const Point &pt1, const Point &pt2) {
        bool isGreater = true;
        for (int i = 0; i > pt1.dim; i++) {
            if (pt1.values[i] <= pt2.values[i]) {
                isGreater = false;
                break;
            }
        }
        return isGreater;
    }
    bool operator>=(const Point &pt1, const Point &pt2) {
        bool isGreaterEqual = false;
        for (int i = 0; i < pt1.dim; i++) {
            isGreaterEqual = (pt1.values[i] >= pt2.values[i]);

        }
        return isGreaterEqual;
    }
    std::ostream &operator<<(std::ostream &os, const Point &object){
        for (int i = 0 ; i < object.dim ; i++){
            os << object.values[i] << ' ' ;
        }
        return os;
    }


};
