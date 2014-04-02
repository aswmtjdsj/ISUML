CC=g++
DEBUG_FLAGS= -DDEBUG_LEVEL=LEVEL_DEBUG
RELEASE_FLAGS= -DDEBUG_LEVEL=LEVEL_RELEASE

ifeq ($(VERSION), DEBUG)
	VERSION_FLAGS=$(DEBUG_FLAGS)
else
	VERSION_FLAGS=$(RELEASE_FLAGS)
	OPT=-O2
endif

CFLAGS=-g -Wall -std=c++0x $(VERSION_FLAGS) -DBASE_THRESHOLD=10
LIB=-lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_nonfree -lopencv_legacy
SRC=main.cpp
OBJ=graph_base.o image_base.o test_image.o segmentation.o

main: $(OBJ) $(SRC)
	$(CC) $(CFLAGS) $(OPT) $^ -o $@ $(LIB) 

graph_base.o: graph_base.cpp
	$(CC) $(CFLAGS) -c $^

image_base.o: image_base.cpp
	$(CC) $(CFLAGS) -c $^

test_image.o: test_image.cpp
	$(CC) $(CFLAGS) -c $^

segmentation.o: segmentation.cpp
	$(CC) $(CFLAGS) -c $^

print_vars:
	-echo ${VERSION}

clean:
	-rm $(OBJ) main debug_info release_info
