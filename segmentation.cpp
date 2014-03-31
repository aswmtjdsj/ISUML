#include "segmentation.h"

using namespace cv;

Segmentation::Segmentation(): ImageBase() {
}

Segmentation::Segmentation(const char ** argv): ImageBase(argv) {
    loadInput(input_dir, input_file, file_ext);
    printf("loaded image height: %d, width: %d\n", height(), width());
    /*if(saveImage(input_image, output_dir, input_file, file_ext)) {
        printf("image %s.%s saved in dir %s!\n", input_file, file_ext, output_dir);
    }
    else {
        printf("image %s.%s save failed!\n", input_file, file_ext);
    }*/
}

void Segmentation::buildGraph() {
    for(int i = 0; i < height(); i++) {
        for(int j = 0; j < width(); j++) {
            Vec3b from_pixel = input_image.at<Vec3b>(j, i);
            for(int k = 0; k < 8; k++) {
                int ah = i + dh[k], aw = j + dw[k];
                Vec3b to_pixel = input_image.at<Vec3b>(aw, ah);
            }
        }
    }
}

Segmentation::~Segmentation() {
}
