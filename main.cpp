#include "common.h"
#include "test_image.h"
#include "segmentation.h"

int main(int argc, const char ** argv) {

    if(argc < 3) {
        puts("please tell me the file name and file type of original image!");
        exit(1);
    }
    if(argc == 4 && strcmp("test", argv[3]) == 0) {
        TestImage test_obj(argv);
        test_obj.getExt();
        test_obj.drawTestImage(300, 400);
    }

    Segmentation test_seg(argv);
    test_seg.buildGraph();
    test_seg.generalSegmentation();
    test_seg.drawSegmentation();
    test_seg.drawSuperPixel();

    return 0;
}
