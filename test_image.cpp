#include "test_image.h"

using namespace cv;

TestImage::TestImage(): ImageBase() {
}

TestImage::TestImage(const char ** argv): ImageBase(argv) {
}

TestImage::~TestImage() {
}

void TestImage::drawTestImage(const int &h, const int &w) {
    // draw circles sharing same center
    input_image = Mat(w, h, CV_8UC3);
    if(input_image.data == NULL) {
        puts("Create image matrix failed!");
        exit(1);
    }

    printf("created image height: %d, width: %d\n", input_image.rows, input_image.cols);
    printf("created image height: %d, width: %d\n", height(), width());
    int x = w / 2, y = h / 2;

    for(int i = 0; i < input_image.rows; i++) {
        for(int j = 0; j < input_image.cols; j++) {
            
            if(SQUARE(i - x) + SQUARE(j - y) < SQUARE(w / 20)) {
                input_image.at<Vec3b>(i, j) = Vec3b(255, 0, 0);
            }
            else if(SQUARE(i - x) + SQUARE(j - y) < SQUARE(w / 10)) {
                input_image.at<Vec3b>(i, j) = Vec3b(255, 255, 0);
            }
            else if(SQUARE(i - x) + SQUARE(j - y) < SQUARE(w / 5)) {
                input_image.at<Vec3b>(i, j) = Vec3b(255, 255, 255);
            }
            else if(SQUARE(i - x) + SQUARE(j - y) < SQUARE(w / 3)) {
                input_image.at<Vec3b>(i, j) = Vec3b(0, 255, 255);
            }
            else {
                input_image.at<Vec3b>(i, j) = Vec3b(0, 0, 255);
            }
        }
    }

    saveImage(input_image, input_dir, input_file, file_ext);
}

