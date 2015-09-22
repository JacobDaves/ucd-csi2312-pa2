//
// Created by Jacob on 9/7/2015.
//
// A 3-dimensional point class!
// Coordinates are double-precision floating point.
#include <ostream>
#include <iostream> 

#ifndef __point_h
#define __point_h

namespace Clustering {

    class Point {

    private:
        int dim;
        double *arr;


    public:
        // Constructors
        Point();                      // default constructor
        Point(int);    // n diminsion constructor
        //point(int, double);
        Point(double *gArray);  //copy constructor
        Point &operator=(const Point &); //overloaded operator=
        // Destructor
        ~Point();

        // Mutator methods
        void setArr(int, double);

        void setDim(int nDim);

        // Accessor methods
        double getArr(int);

        int getDim();

        // Member functions
        double distanceTo(Point &);

        Point &operator*=(Point &);

        Point &operator/=(Point &);

        Point operator*(double);

        Point operator/(double);

       // double &operator[](int index) { return arr[index - 1]; }

        // Friend memeber functions
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
#endif // __point_h