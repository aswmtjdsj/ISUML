ISUML
=====

This project is about Image Segmentation via Machine Learning. A course project for CSE 512.

class structure:

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

class SuperPixel {
    public:
    SuperPixel();
    SuperPixel(const cv::Vec3b &, const Node &);

    std::string info() const;

    cv::Vec3b color;
    Node classifier_pixel;
};

class Segmentation: public ImageBase {
    public:
        Segmentation();
        Segmentation(const char **);
        ~Segmentation();

        std::vector <std::vector<SuperPixel> > region;
        std::vector <Edge> graph;

        void buildGraph();
        void printGraph(const int &) const;
        void printNode(const int &, const int &) const;
        bool inImage(const int &, const int &) const;

        void generalSegmentation();
        void drawSegmentation();
        SuperPixel & getRegion(const Node &); 
};

class TestImage: public ImageBase {
    public:
        TestImage();
        TestImage(const char **);
        ~TestImage();

        void drawTestImage(const int &, const int &);
};
