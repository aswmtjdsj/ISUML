#ifndef SEGMENTATION_H
#define SEGMENTATION_H

#include "image_base.h"
#include "graph_base.h"

class Segmentation: public ImageBase {
    public:
        Segmentation();
        Segmentation(const char **);
        ~Segmentation();

        std::vector < std::vector<edge> > graph;
        void buildGraph();
};

#endif
