//
// Created by Jacob on 9/21/2015.
//
#ifndef CLUSTERING_POINT_H
#define CLUSTERING_POINT_H

#include <iostream>

namespace Clustering {

    class Point {
        int dim;        // number of dimensions of the point
        double *values; // values of the point's dimensions

    public:
        Point(int); //TODO ***Done
        //Not sure i need it
        // Point(int, double *);

        // Big three: cpy ctor, overloaded operator=, dtor//TODO ***Done
        Point(const Point &);
        Point &operator=(const Point &);
        ~Point();

        // Accessors & mutators// TODO ***Done
        void setValue(int, double);
        double getValue(int) const;
        int getDims() const;
        //had to add this to yours
        void setDims(int nDim);
        // Functions
        double distanceTo(const Point &) const;

        // Overloaded operators

        // Members//TODO ***Doing
        Point &operator*=(double);
        Point &operator/=(double);
        const Point operator*(double) const; // prevent (p1*2) = p2;
        const Point operator/(double) const;

        double &operator[](int index) { return values[index - 1]; } // TODO out-of-bds?

        // Friends//TODO
        friend Point &operator+=(Point &, const Point &);
        friend Point &operator-=(Point &, const Point &);
        friend const Point operator+(const Point &, const Point &);
        friend const Point operator-(const Point &, const Point &);

        friend bool operator==(const Point &, const Point &);
        friend bool operator!=(const Point &, const Point &);

        friend bool operator<(const Point &, const Point &);
        friend bool operator>(const Point &, const Point &);
        friend bool operator<=(const Point &, const Point &);
        friend bool operator>=(const Point &, const Point &);

        friend std::ostream &operator<<(std::ostream &, const Point &);
        friend std::istream &operator>>(std::istream &, Point &);
    };

}
#endif //CLUSTERING_POINT_H