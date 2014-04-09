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
    SuperPixel(const cv::Vec3b &, const Node &, const int _size = 1);

    std::string info() const;

    cv::Vec3b color;
    Node classifier_pixel;
    int size;
};

class Segmentation: public ImageBase {

    public:

        Segmentation();
        Segmentation(const char **);
        ~Segmentation();

        std::vector <std::vector<SuperPixel> > region;
        std::vector <Edge> graph;
        std::map <Node, std::set<ImagePixel> > super_pixel_set;

        void buildGraph();
        void printGraph(const int &) const;
        void printNode(const int &, const int &) const;
        bool inImage(const int &, const int &) const;

        void generalSegmentation();
        void drawSegmentation();
        void drawSuperPixel();

        SuperPixel & getRegion(const Node &); // make the super pixel available for modification
};

#endif
