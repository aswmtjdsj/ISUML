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

        bool loadInput(const char *, const char *, const char *);
        bool saveImage(const cv::Mat &, const char *, const char *, const char *);

        int width() const;
        int height() const;

    protected:

    char * input_dir,
         * output_dir,
         * input_file,
         * file_ext;
    
    cv::Mat input_image;
};

#endif
