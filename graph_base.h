#ifndef GRAPH_BASE_H 
#define GRAPH_BASE_H

#include "common.h"

typedef std::pair<int, int> node;

typedef std::pair<node, int> edge;

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

inline cv::Vec3b operator -(const cv::Vec3b &, const cv::Vec3b &);

#endif
