#ifndef GRAPH_BASE_H 
#define GRAPH_BASE_H

#include "common.h"

#define square(x) ((x) * (x))

typedef std::pair<int, int> Node;

class Edge {
    public:
        Edge();
        Edge(const Node &, const Node &, const int &);

        friend bool operator <(const Edge, const Edge);
        void print() const;

        Node from, to;
        int weight;
};

// left, left-top, top, right-top
// right, right-bottom, bottom, left-bottom

const int dh[] = {
    0, -1, -1, -1,
    0, 1, 1, 1, 1
};

const int dw[] = { 
    -1, -1, 0, 1,
    1, 1, 0, -1
};

cv::Vec3b operator -(const cv::Vec3b &, const cv::Vec3b &);

int norm2(const cv::Vec3b &);


std::string nodeToStr(const Node &);


#endif
