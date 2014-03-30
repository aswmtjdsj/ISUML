#ifndef TEST_IMAGE_H
#define TEST_IMAGE_H

#include "image_base.h"

class TestImage: public ImageBase {
    public:
        TestImage();
        TestImage(const char **);
        ~TestImage();

        void drawTestImage(const int &, const int &);
};

#endif
