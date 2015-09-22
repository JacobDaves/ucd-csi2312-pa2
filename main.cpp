#include <iostream>
#include <cmath>
#include "Point.h"
#include "Cluster.h"

using namespace std;
using namespace Clustering;
//
//	Code i got from going to class not sure how it all works yet
//	but pretty much copied from what i saw of yours
double computeArea(Point &p1, Point &p2, Point &p3);

int main() {
    Point p();

    cout << computeArea;

    p.setValues(i, 20* (dim / 2-i));

    cout << p << endl;

    Point p1(p);

    cout << p1 << endl;

    p1 = dim / 3;

    cout <<p-p1 << endl;

    Point p2(p-p1);

    cout << p2 << endl;

    p2/= dim * 1.5;

    Point p3(p1-p2);

    cout << p3 << endl;

    p3 *= dim * 1;

    return 0;

}


// computeArea...
// Finds the area of the object
double computeArea(Point &p1, Point &p2, Point &p3) {
     double side1 = p1.distanceTo(p2);
     double side2 = p2.distanceTo(p3);
     double side3 = p3.distanceTo(p1);
    double sum = ((side1 + side2 + side3)/2);
    double tArea = (sqrt(sum - side1));  //Heron's theory
    return tArea;
}