//
// Created by Jacob on 10/13/2015.
//

#ifndef PA2_IP_DAVES_FINAL_REMAKE_2015_CLUSTER_H
#define PA2_IP_DAVES_FINAL_REMAKE_2015_CLUSTER_H

#include "Point.h"

namespace Clustering {

    typedef Point *PointPtr;
    typedef struct LNode *LNodePtr;

//    struct LNode;
//    typedef LNode *LNodePtr;

    struct LNode {
        PointPtr p;
        LNodePtr next;
    };

    class Cluster {
        int size;
        LNodePtr points;

    public:
        Cluster() : size(0), points(nullptr) {};

        // The big three: cpy ctor, overloaded operator=, dtor // TODO
        Cluster(const Cluster &);
        Cluster &operator=(const Cluster &);
        ~Cluster();

        // Set functions: They allow calling c1.add(c2.remove(p)); // TODO
        void add(const PointPtr &);
        const PointPtr &remove(const PointPtr &);

        // Overloaded operators // TODO ****Done

        // IO // TODO
        friend std::ostream &operator<<(std::ostream &, const Cluster &);
        friend std::istream &operator>>(std::istream &, Cluster &);

        // Set-preserving operators (do not duplicate points in the space)
        // - Friends // TODO?
        friend bool operator==(const Cluster &lhs, const Cluster &rhs);

        // - Members //TODO
        Cluster &operator+=(const Cluster &rhs); // union
        Cluster &operator-=(const Cluster &rhs); // (asymmetric) difference

        Cluster &operator+=(const Point &rhs); // add point
        Cluster &operator-=(const Point &rhs); // remove point

        // Set-destructive operators (duplicate points in the space)
        // - Friends // TODO
        friend const Cluster operator+(const Cluster &lhs, const Cluster &rhs);
        friend const Cluster operator-(const Cluster &lhs, const Cluster &rhs);

        friend const Cluster operator+(const Cluster &lhs, const PointPtr &rhs);
        friend const Cluster operator-(const Cluster &lhs, const PointPtr &rhs);

    };

}
#endif //PA2_IP_DAVES_FINAL_REMAKE_2015_CLUSTER_H
