#include <iostream>
#include "Point.h"
#include "Cluster.h"

using namespace std;
using namespace Clustering;
//
//	Code i got from going to class not sure how it all works yet
//	but pretty much copied from what i saw of yours
  

int main() {
    Point p;

    cout << computeArea(x, y, z);

    p.setArr(i, 20* (dims / 2-i));

    cout << p << endl;

    Point p1(p);

    cout << p1 << endl;

    p1 = dims / 3;

    cout <<p-p1 << endl;

    Point p2(p-p1);

    cout << p2 << endl;

    p2/= dims * 1.5;

    Point p3(p1-p2);

    cout << p3 << endl;

    p3 *= dims * 1;

    return 0;

}


// computeArea...
 Takes a 3 point reference and then finds the area
double computeArea(Point &, Point &, Point &) {
   // double side1 = x.distanceTo(y);
   // double side2 = y.distanceTo(z);
   // double side3 = x.distanceTo(y);
        float prim = x+y+z
        float sum = prim/2
        double tArea = sqrt(s(s-x)(s-y)(s-z))    //(sqrt((side1+side2+side3)*(side1+side2-side3)*(side2+side3-side1)*(side1+side3-side2))/4);//Heron's theory
    return tArea;
}