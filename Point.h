//
// Created by Jacob on 10/13/2015.
//


#ifndef PA2_IP_DAVES_FINAL_REMAKE_2015_POINT_H
#define PA2_IP_DAVES_FINAL_REMAKE_2015_POINT_H

#include <iostream>

namespace Clustering {

    class Point {
    private:
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
        // Functions // TODO ***Done
        double distanceTo(const Point &) const;

        // Overloaded operators

        // Members//TODO ***Done
        Point &operator*=(double);
        Point &operator/=(double);
        const Point operator*(double) const; // prevent (p1*2) = p2;
        const Point operator/(double) const;

        double &operator[](int index) { return values[index - 1]; } // TODO out-of-bds? ???

        // Friends//TODO ***doing
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
        // When would i use this?
        friend std::istream &operator>>(std::istream &, Point &);
    };

}

#endif //PA2_IP_DAVES_FINAL_REMAKE_2015_POINT_H
