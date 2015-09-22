//
// Created by Jacob on 9/7/2015.
//
#include <cmath> // needed for sqrt() and pow()
#include "Point.h" // needed to use Point class
#include <iostream>
#include <ostream>

        using namespace std;
// Default constructor
// Initializes the point to (dim)
        Point::Point() {
            dim = 0;
            arr = new double[dim];

        }

// Constructor
// Initializes the point to ( userDim )
        Point::Point(int userDim) {
            dim = userDim;
            arr = new double[dim];
        }
// The copy constructor
        Point::Point(double *gArray){
            arr = gArray;
        }
// Overloaded assignment operator 
        Point &Point::operator=(const Point &other){
            double dim = 0;
            if (&other != this) {
                dim = other.dim;
                arr = new double[other.dim];
            }
            return *this;
        }
// Destructor
// No dynamic allocation, so nothing to do; if omitted, generated automatically
        Point::~Point() {
            delete[] arr;
        }

// Mutator methods
// Change the arr of private member variables

        void Point::setDim(int nDim) {

            dim = nDim;
        }

        void Point::setArr(int userIndex, double userValues){

            arr[userIndex] = userValues;
        }
// Accessors
// Return the current arr of private member variables

        int Point::getDim() {
            return dim;
        }

        double Point::getArr(int userIndex) {
            return arr[userIndex];
        }
//member functions
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
        Point &Point::operator*=(double d) {
            for (int i = 0; i < dim; i++)
                arr[i] *= d;
            return *this;
        }
        Point &Point::operator/=(double d) {
            for (int i = 0; i < dim; i++)
                arr[i] /= d;
            return *this;
        }
        const Point Point::operator*(double d) const {
            return Point(dim) *= d;
        }
        const Point Point::operator/(double d) const {
            return Point(dim) /= d;
        }

// Friend members - overloaded operators
        Point &operator+=(Point &lhs, const Point &rhs) {
            if (&lfs == &rhs) {
                return lhs *= 2;
            } else if (lhs.dim != rhs.dim) {
                for (int i = 0; i < lhs.dim; i++)
                    lhs.arr[i] + rhs.arr[i];
            }
            return lhs;
        }
        Point &operator-=(Point &lhs, const Point &rhs) {
            if (&lfs == &rhs) {
                return lhs *= 0;
            } else if (lhs.dim != rhs.dim) {
                for (int i = 0; i < lhs.dim; i++)
                    lhs.arr[i] - rhs.arr[i];
            }
            return lhs;
        }
        const Point Point::operator-(double d) const {
            return Point(dim) -= d;
        }
        const Point Point::operator+(double d) const {
            return Point(dim) += d;
        };
	//overload == operator

    bool Clustering::operator==(const Point &point, const Point &otherp)
	{
		if (point.getDim() == otherp.getDim())
		{
			//for loop that checks if any elements are different an returns flase if they are
			for (int i = 0; i < point.getDim(); i++)
			{
				if (point.arr[i] != otherp.arr[i])
					return false;
			}
			return true;
		}
		else
			return false;
	}
    // overloaded !=
    bool Clustering::operator!=(const Point &point, const Point &otherp)
	{
		return !(point == otherp);
	}
    
    // Overloaded < 
    bool Point::operator<(const Point &point, const Point &otherp)
    {
        
        return (point != point1 && !(point > otherp));
    }
        
    // overloaded >    
        bool Clustering::operator>(const Point &point, const Point &otherp)
    {
        
        return (point != point1 && !(point < otherp));
    }

    // Overloaded <=
        bool Clustering::operator<=(const Point &point, const Point &otherp)
    {
        
        return (point < otherp || point == otherp);
    }

    // overlaod >= I just used the formentioned functions im not sure if they work yet
    bool Clustering::operator>=(const Point &point, const Point &otherp)
    {
        
        return (point > otherp || point == otherp);
    }
     std::ostream &operator<<(std::ostream &os, const Point &point)
    {
        cout << "(";
       
        for (int i = 0; i < point.getDim() - 1; i++) {
            os << point.getArr(i) << ",";
        }
        
        cout << point.getArr(point.getDim() - 1) << ")\n";

        return os;
    }

// Calculates the distance between the point and the one passed

// computeArea...
// Takes a 3 point reference and then finds the area
//double computeArea(Point &, Point &, Point &) {
//    double side1 = A.distanceTo(B);
//    double side2 = B.distanceTo(C);
//    double side3 = A.distanceTo(C);
//        double TriArea = (sqrt((side1+side2+side3)*(side1+side2-side3)*(side2+side3-side1)*(side1+side3-side2))/4);//Heron's theory
//    return TriArea;
//}