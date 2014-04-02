#include "segmentation.h"

using namespace cv;
using namespace std;

SuperPixel::SuperPixel() {
}

SuperPixel::SuperPixel(const cv::Vec3b &pixel_color, const Node &pixel):color(pixel_color), classifier_pixel(pixel) {
}

string SuperPixel::info() const {
    string information = "SuperPixel " + nodeToStr(classifier_pixel) + ": [" + to_string(color.val[0]) + ", " + to_string(color.val[1]) + ", " + to_string(color.val[2]) + "].";
    return information;
}

Segmentation::Segmentation(): ImageBase() {
}

Segmentation::Segmentation(const char ** argv): ImageBase(argv) {
    cout << "Loading Input Image..." << endl;
    loadInput(input_dir, input_file, file_ext);
    printf("loaded image height: %d, width: %d\n", height(), width());
}

void Segmentation::buildGraph() {
    cout << "Building Graph..." << endl;
    region.resize(height());
    graph.resize(0);
    for(int i = 0; i < height(); i++) {
        region[i].resize(width());
        for(int j = 0; j < width(); j++) {
            Vec3b from_pixel = input_image.at<Vec3b>(j, i);
            region[i][j] = SuperPixel(from_pixel, Node(i, j));

            for(int k = 0; k < 8; k++) {
                int ah = i + dh[k], aw = j + dw[k];
                if(inImage(ah, aw)) {
                    Vec3b to_pixel = input_image.at<Vec3b>(aw, ah);
                    graph.push_back(Edge(Node(i, j), Node(ah, aw), norm2(from_pixel - to_pixel)));
                }
            }
        }
    }

    cout << "Graph size: " << graph.size() << " edges." << endl;
    cout << "Sorting graph edges..." << endl;
    sort(graph.begin(), graph.end());
    printGraph(DEBUG_LEVEL);
}

void Segmentation::printGraph(const int &flag) const{
    if(flag > 0) {
        cout << "Printing graph..." << endl;
        if((flag & 1) == 1) {
            cout << "Printing nodes..." << endl;
            for(int i = 0; i < height(); i++) {
                for(int j = 0; j < width(); j++) {
                    printNode(i, j);
                }
            }
        }
        if((flag & 2) == 2) {
            cout << "Printing edges..." << endl;
            for(auto ptr = graph.begin(); ptr != graph.end(); ptr++) {
                ptr->print();
            }
        }
    }
}

void Segmentation::printNode(const int &h, const int &w) const {
    printf("%s\n", region[h][w].info().c_str());
}

bool Segmentation::inImage(const int &h, const int &w) const {
    return 0 <= h && h < height() && 0 <= w && w < width();
}

void Segmentation::generalSegmentation() {
    cout << "Segmenting..." << endl;
    for(auto ptr = graph.begin(); ptr != graph.end(); ptr++) {
        Node a = ptr->from, b = ptr->to;
        SuperPixel ra = getRegion(a), rb = getRegion(b);
        if(ra.classifier_pixel == rb.classifier_pixel) {
            continue;
        }
        int w = ptr->weight;
        if(w < square(BASE_THRESHOLD)) { // need modification, updating while in process 

#if DEBUG_LEVEL == LEVEL_DEBUG
            cout << w << endl;
            printNode(ra.classifier_pixel.first, ra.classifier_pixel.second);
            printNode(rb.classifier_pixel.first, rb.classifier_pixel.second);
#endif

            // no size info here
            getRegion(a).color = color_combine(ra.color, 0.5, rb.color, 0.5);
            getRegion(b) = getRegion(a);

#if DEBUG_LEVEL == LEVEL_DEBUG
            printNode(ra.classifier_pixel.first, ra.classifier_pixel.second);
            printNode(rb.classifier_pixel.first, rb.classifier_pixel.second);
#endif
        }
        else {
            break;
        }
    }
}

void Segmentation::drawSegmentation() {
    Mat segmented_image = Mat(width(), height(), CV_8UC3);
    for(int i = 0; i < height(); i++) {
        for(int j = 0; j < width(); j++) {
            segmented_image.at<Vec3b>(j, i) = region[i][j].color;
        }
    }
    char * segmented_file = new char[100];
    sprintf(segmented_file, "%s_segmented", input_file);
    if(saveImage(segmented_image, output_dir, segmented_file, file_ext)) {
        cout << "Segmented image saved!" << endl;
    }
    else {
        cout << "Segmented image saving failed!" << endl;
    }
}

SuperPixel & Segmentation::getRegion(const Node &node) {
    int h = node.first, w = node.second;
    if(region[h][w].classifier_pixel != node) {
        region[h][w] = getRegion(region[h][w].classifier_pixel);
    }
    return region[h][w];
}

Segmentation::~Segmentation() {
}
