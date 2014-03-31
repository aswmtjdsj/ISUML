#ifndef SEGMENTATION_H
#define SEGMENTATION_H

#include "image_base.h"
#include "graph_base.h"

#ifndef BASE_THRESHOLD
#define BASE_THRESHOLD 5
#endif

class SuperPixel {
    public:
    SuperPixel();
    SuperPixel(const cv::Vec3b &, const Node &);

    std::string info() const;

    cv::Vec3b color;
    Node classifier_pixel;
};

class Segmentation: public ImageBase {
    public:
        Segmentation();
        Segmentation(const char **);
        ~Segmentation();

        std::vector <std::vector<SuperPixel> > region;
        std::vector <Edge> graph;

        void buildGraph();
        void printGraph(const int &) const;
        void printNode(const int &, const int &) const;
        bool inImage(const int &, const int &) const;

        void generalSegmentation();
        void drawSegmentation();
        SuperPixel getRegion(const Node &);
};

#endif
