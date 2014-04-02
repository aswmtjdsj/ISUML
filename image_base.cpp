#include "image_base.h"

using namespace cv;

ImageBase::ImageBase() {
    input_dir = NULL;
    output_dir = NULL;
    input_file = NULL;
    file_ext = NULL;
}

ImageBase::ImageBase(const char ** argv) {
    input_dir = new char[MAX_FILE_NAME];
    output_dir = new char[MAX_FILE_NAME];
    input_file = new char[MAX_FILE_NAME];
    file_ext = new char[MAX_FILE_NAME];

    sprintf(input_file, "%s", argv[1]);
    setExt(argv[2]);
    sprintf(input_dir, "./input"); 
    mkdir(input_dir, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    printf("Input directory %s created!\n", input_dir);

    sprintf(output_dir, "./output");
    mkdir(output_dir, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    printf("Output directory %s created!\n", output_dir);
    sprintf(output_dir, "./output/%s", input_file); 
    mkdir(output_dir, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    printf("Output sub-directory %s created!\n", output_dir);
}

int ImageBase::width() const {
    return input_image.rows;
}

int ImageBase::height() const {
    return input_image.cols;
}

void ImageBase::setExt(const char * ext) {
    sprintf(file_ext, "%s", ext);
}

char * ImageBase::getExt() {
    char * ext = new char[MAX_FILE_NAME];
    snprintf(ext, strlen(file_ext) + 1, "%s", file_ext);
    printf("file extension: %s\n", ext);
    return ext;
}

bool ImageBase::loadInput(const char *dir, const char * file, const char * ext) {
    char * file_name = new char[MAX_FILE_NAME];
    sprintf(file_name, "%s/%s.%s", dir, file, ext);
    input_image = imread(file_name);

    delete [] file_name;
    return input_image.data != NULL;
}

bool ImageBase::saveImage(const cv::Mat &img, const char *dir, const char * file, const char * ext) {
    char * file_name = new char[MAX_FILE_NAME];
    sprintf(file_name, "%s/%s.%s", dir, file, ext);
    printf("Saving image %s...", file_name);
    bool result = imwrite(file_name, img);

    delete [] file_name;
    return result;
}

ImageBase::~ImageBase() {
    printf("Delete char pointers!\n");
    if(input_dir != NULL) {
        delete [] input_dir;
    }

    if(output_dir != NULL) {
        delete [] output_dir;
    }

    if(input_file != NULL) {
        delete [] input_file;
    }

    if(file_ext != NULL) {
        delete [] file_ext;
    }
}
