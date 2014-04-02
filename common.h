#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <ctime>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <sys/stat.h>

#define SQUARE(x) ((x) * (x))

#define MAX_FILE_NAME 100

#define LEVEL_RELEASE 0
#define LEVEL_DEBUG 3

#ifndef DEBUG_LEVEL
#define DEBUG_LEVEL LEVEL_DEBUG
#endif

#endif
