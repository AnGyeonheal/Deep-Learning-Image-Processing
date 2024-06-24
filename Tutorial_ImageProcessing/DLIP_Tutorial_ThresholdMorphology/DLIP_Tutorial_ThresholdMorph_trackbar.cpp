/*------------------------------------------------------/
* Image Proccessing with Deep Learning
* OpenCV : Threshold using Trackbar Demo
* Created: 2021-Spring
------------------------------------------------------*/

#include <iostream>
#include <opencv2/opencv.hpp>
#include <fstream>

using namespace std;
using namespace cv;

// Global variables for Threshold
int normal = 0;
int threshold_value = 0;
int threshold_type = 0;
int morphology_type = 0;
int morphology_type2 = 0;

int filter_type = 0;

int const max_normalize = 1;
int const max_value = 255;
int const max_th = 8;
int const max_mo = 4;
int const max_BINARY_value = 255;
int const max_filter = 2;

// Global variables for Morphology

Mat origin, src, src_gray, dst, dst_morph, dst_morph2;
Mat dst_filtered, temp;
Mat dst_normalized;

// Trackbar strings

String window_name = "Threshold & Morphology Demo";
String Normalize = "Normalize:";
String trackbar_type = "Thresh Type:";
String trackbar_value = "Thresh Value:";
String trackbar_morph = "Morph Type :";
String trackbar_morph2 = "Morph Type2 :";
String Filter_type = "Filter Type :";


// Function headers
void Threshold_Demo(int, void*);
void Morphology_Demo(int, void*);
void Morphology_Demo2(int, void*);

void Filter_Demo(int, void*);
void plotHist(Mat src, string plotname, int width, int height);
void contour(Mat& src, Mat dst);
Mat resizing(Mat src, int x_size, int y_size);
void Normalize_Demo(int, void*);



int main()
{
    // Load an image
    src = imread("C:\\Users\\hilla\\source\\repos\\DLIP_GH\\Image\\lab\\blur1_lab.png", IMREAD_COLOR);

    // Make a copy of the original image to work with
    origin = src.clone(); // 여기에서 원본 이미지의 복사본을 만듭니다.

    // Convert the image to Gray
    cvtColor(src, src_gray, COLOR_BGR2GRAY);


    // Create a window to display the results
    namedWindow(window_name, WINDOW_NORMAL);

    // Create trackbar to choose type of threshold
    createTrackbar(trackbar_type, window_name, &threshold_type, max_th, Threshold_Demo);
    createTrackbar(trackbar_value, window_name, &threshold_value, max_value, Threshold_Demo);
    createTrackbar(trackbar_morph, window_name, &morphology_type, max_mo, Morphology_Demo);
    createTrackbar(trackbar_morph2, window_name, &morphology_type2, max_mo, Morphology_Demo2);
    createTrackbar(Filter_type, window_name, &filter_type, max_filter, Filter_Demo);


    // Call the function to initialize
    Threshold_Demo(0, 0);
    Morphology_Demo(0, 0);
    Morphology_Demo2(0, 0);
    Filter_Demo(0, 0);


    // Wait until user finishes program
    while (true) {
        // Refresh src image from the original before processing
        src = origin.clone(); // 여기에서 원본 이미지로부터 src 이미지를 갱신합니다.

        int c = waitKey(20);
        if (c == 27) // ESC 키를 누르면 종료
            break;
    }
}
void Normalize_Demo(int, void*){

    switch(normal){
        case 0: src_gray.copyTo(dst_normalized); break;
        case 1: normalize(src_gray, dst_normalized, 0, 255, cv::NORM_MINMAX, CV_8UC1); break;

    }
    contour(src, dst_normalized);
    plotHist(dst_normalized,"Histogram", 500, 500);
    imshow("Contours on Original", resizing(src, 750, 750));
    imshow("", resizing(dst_normalized, 750, 750));
}


void Threshold_Demo(int, void*)	// default form of callback function for trackbar
{
    /*
    * 0: Binary
    * 1: Threshold Truncated
    * 2: Threshold to Zero
    * 3: Threshold to Zero Inverted
    * 8: Threshold OTSU
    */

    threshold(src_gray, dst, threshold_value, max_BINARY_value, threshold_type);
    // imshow(window_name, dst);
    contour(src, dst);
    plotHist(dst,"Histogram", 500, 500);
    imshow("Contours on Original", resizing(src, 750, 750));
    imshow("", resizing(dst, 750, 750));
}

void Morphology_Demo(int, void*)  // default form of callback function for trackbar
{
    int element_shape = MORPH_RECT;		// MORPH_RECT, MORPH_ELIPSE, MORPH_CROSS
    int n = 3;
    Mat element = getStructuringElement(element_shape, Size(n, n));
    /*
    * 0: None
    * 1: Erode
    * 2: Dilate
    * 3: Close
    * 4: Open
    */

    switch (morphology_type) {
        case 0: dst.copyTo(dst_morph);	break;
        case 1: erode(dst, dst_morph, element); break;
        case 2: dilate(dst, dst_morph, element); break;
        case 3: morphologyEx(dst, dst_morph, MORPH_OPEN, element); break;
        case 4: morphologyEx(dst, dst_morph, MORPH_CLOSE, element); break;
    }
    // imshow(window_name, dst_morph);
    contour(src, dst_morph);
    plotHist(dst_morph,"Histogram", 500, 500);
    imshow("Contours on Original", resizing(src, 750, 750));
    imshow("", resizing(dst_morph, 750, 750));
}
void Morphology_Demo2(int, void*)  // default form of callback function for trackbar
{
    int element_shape = MORPH_RECT;		// MORPH_RECT, MORPH_ELIPSE, MORPH_CROSS
    int n = 3;
    Mat element = getStructuringElement(element_shape, Size(n, n));
    /*
    * 0: None
    * 1: Erode
    * 2: Dilate
    * 3: Close
    * 4: Open
    */

    switch (morphology_type2) {
        case 0: dst_morph.copyTo(dst_morph2);	break;
        case 1: erode(dst_morph, dst_morph2, element); break;
        case 2: dilate(dst_morph, dst_morph2, element); break;
        case 3: morphologyEx(dst_morph, dst_morph2, MORPH_OPEN, element); break;
        case 4: morphologyEx(dst_morph, dst_morph2, MORPH_CLOSE, element); break;
    }
    // imshow(window_name, dst_morph);
    contour(src, dst_morph2);
    plotHist(dst_morph2,"Histogram", 500, 500);
    imshow("Contours on Original", resizing(src, 750, 750));
    imshow("", resizing(dst_morph2, 750, 750));
}

void Filter_Demo(int, void*){

    int kernel_size = 9;
    int scale = 1;
    int delta = 0;
    int ddepth = CV_16S;
    int ksize = 9;

    switch(filter_type){
        case 0: dst_morph2.copyTo(dst_filtered); break;
        case 1: GaussianBlur(dst_morph2, dst_filtered, cv::Size(ksize,ksize), 0, 0); break;
        case 2: medianBlur(dst_morph2, dst_filtered, ksize); break;
        case 3:
            cv::Laplacian(dst_morph2, temp, ddepth, kernel_size, scale, delta, cv::BORDER_DEFAULT);
            dst_morph2.convertTo(dst_morph2, CV_16S);
            dst_filtered = dst_morph2 - dst;
            dst_filtered.convertTo(dst_filtered, CV_8U);
            break;
    }
    // imshow(window_name, dst_filtered);
    contour(src, dst_filtered);
    plotHist(dst_filtered,"Histogram", 500, 500);
    imshow("Contours on Original", resizing(src, 750, 750));
    imshow("", resizing(dst_filtered, 750, 750));
}

void plotHist(Mat src, string plotname, int width, int height) {
    /// Compute the histograms
    Mat hist;
    /// Establish the number of bins (for uchar Mat type)
    int histSize = 256;
    /// Set the ranges (for uchar Mat type)
    float range[] = { 0, 256 };

    const float* histRange = { range };
    calcHist(&src, 1, 0, Mat(), hist, 1, &histSize, &histRange);

    double min_val, max_val;
    cv::minMaxLoc(hist, &min_val, &max_val);
    Mat hist_normed = hist * height / max_val;
    float bin_w = (float)width / histSize;
    Mat histImage(height, width, CV_8UC1, Scalar(255));
    for (int i = 0; i < histSize - 1; i++) {
        line(histImage,
             Point((int)(bin_w * i), height - cvRound(hist_normed.at<float>(i, 0))),
             Point((int)(bin_w * (i + 1)), height - cvRound(hist_normed.at<float>(i + 1, 0))),
             Scalar(0), 2, 8, 0);
    }

    imshow(plotname, histImage);
}
void contour(Mat& src, Mat dst){
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;

    /// Find contours
    findContours(dst, contours, hierarchy, RETR_CCOMP, CHAIN_APPROX_SIMPLE);

    /// Convert the source image to color if it is not already
    for(int i = 0; i < contours.size(); i++)
    {
        if(contourArea(contours[i]) < 250){
            continue;
        }
        else{
            Scalar color = Scalar(rand() & 255, rand() & 255, rand() & 255); // Random color
            Rect boundRect = boundingRect(contours[i]);
            rectangle(src, boundRect.tl(), boundRect.br(), color, 2);
        }
    }
    namedWindow("Contours on Original", WINDOW_AUTOSIZE);

}
Mat resizing(Mat src, int x_size, int y_size){
    Mat sized;
    resize(src ,sized, Size(x_size, y_size));
    return sized;
}