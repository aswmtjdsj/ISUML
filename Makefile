CC=g++
DEBUG_FLAGS= -DDEBUG_LEVEL=LEVEL_DEBUG
RELEASE_FLAGS= -DDEBUG_LEVEL=LEVEL_RELEASE
CFLAGS=-g -Wall -std=c++0x $(DEBUG_FLAGS) -DBASE_THRESHOLD=10
#need modifications
OPT=-O2
LIB=-lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_nonfree -lopencv_legacy
SRC=main.cpp
OBJ=graph_base.o image_base.o test_image.o segmentation.o

debug: $(OBJ) $(SRC)
	$(CC) $(CFLAGS) $^ -o $@ $(LIB) 

release: $(OBJ) $(SRC)
	$(CC) $(CFLAGS) $(OPT) $^ -o $@ $(LIB) 

graph_base.o: graph_base.cpp
	$(CC) $(CFLAGS) -c $^

image_base.o: image_base.cpp
	$(CC) $(CFLAGS) -c $^

test_image.o: test_image.cpp
	$(CC) $(CFLAGS) -c $^

segmentation.o: segmentation.cpp
	$(CC) $(CFLAGS) -c $^

clean:
	-rm $(OBJ) release debug debug_info release_info
