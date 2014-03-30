CC=g++
CFLAGS=-g -Wall -std=c++0x
OPT=-O2
LIB=-lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_nonfree -lopencv_legacy
SRC=main.cpp
OBJ=image_base.o test_image.o segmentation.o

debug: $(OBJ) $(SRC)
	$(CC) $(CFLAGS) $^ -o $@ $(LIB) 

release: $(OBJ) $(SRC)
	$(CC) $(CFLAGS) $(OPT) $^ -o $@ $(LIB) 

image_base.o: image_base.cpp
	$(CC) $(CFLAGS) -c $^

test_image.o: test_image.cpp
	$(CC) $(CFLAGS) -c $^

segmentation.o: segmentation.cpp
	$(CC) $(CFLAGS) -c $^

clean:
	-rm release debug $(OBJ)
