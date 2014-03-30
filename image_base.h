#ifndef IMAGE_BASE_H
#define IMAGE_BASE_H

#include "common.h"

class ImageBase {

    public:

        ImageBase();
        ImageBase(const char **);
        ~ImageBase();

        void setExt(const char *);
        char * getExt();

        void loadInput(const char *);
        bool saveImage(const cv::Mat &, const char *, const char *);

    protected:

    char * input_dir,
         * output_dir,
         * input_file,
         * file_ext;
    
    cv::Mat input_image;
};

#endif
