#include "graph_base.h"

using namespace cv;

inline Vec3b operator -(const Vec3b &a, const Vec3b &b) {
    Vec3b c = Vec3b(abs(a.val[0] - b.val[0]), abs(a.val[1] - b.val[1]), abs(a.val[2] - b.val[2])) ;
    return c;
}
