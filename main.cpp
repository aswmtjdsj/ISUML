#include "common.h"
#include "test_image.h"

int main(int argc, const char ** argv) {

    if(argc < 3) {
        puts("please tell me the file name and file type of original image!");
        exit(1);
    }

    TestImage test_obj(argv);
    test_obj.getExt();
    test_obj.drawTestImage(300, 400);

    return 0;
}
