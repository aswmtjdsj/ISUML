#include "graph_base.h"

using namespace cv;
using namespace std;

Vec3b operator -(const Vec3b &a, const Vec3b &b) {
    return Vec3b(abs(a.val[0] - b.val[0]), abs(a.val[1] - b.val[1]), abs(a.val[2] - b.val[2])) ;
}

Vec3b operator +(const Vec3b &a, const Vec3b &b) {
    return Vec3b(a.val[0] + b.val[0], a.val[1] + b.val[1], a.val[2] + b.val[2]) ;
}

Vec3b operator *(const Vec3b &a, const double &s) {
    return Vec3b(a.val[0] * s, a.val[1] * s, a.val[2] * s) ;
}

Vec3b color_combine(const Vec3b &a, const double &u, const Vec3b &b, const double &v) {
    return Vec3b(a.val[0] * u + b.val[0] * v, a.val[1] * u + b.val[1] * v, a.val[2] * u + b.val[2] * v) ;
}

int norm2(const cv::Vec3b &color) {
    int temp = 0;
    for(int i = 0; i < 3; i++) {
        temp += square(color.val[i]);
    }
    return temp;
}

Edge::Edge() {
}

Edge::Edge(const Node &_from, const Node &_to, const int &w): from(_from), to(_to), weight(w) {
}

bool operator <(const Edge a, const Edge b) {
    return a.weight < b.weight;
}

void Edge::print() const {
    printf("Edge %s -> %s: %d\n", nodeToStr(from).c_str(), nodeToStr(to).c_str(), weight);
}

string nodeToStr(const Node &node) {
    return "(" + to_string(node.second) + ", " + to_string(node.first) + ")";
}
