//
// Created by An Gyeonheal on 2024-03-22.
//
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

#ifndef DLIP_GH_OPENCV_SETTING_H
#define DLIP_GH_OPENCV_SETTING_H

#endif //DLIP_GH_OPENCV_SETTING_H

#define NONE 0
#define GAUSSIAN 1
#define MEDIAN 2
#define LAPLACIAN 3

#define BINARY 0
#define TRUNCATED 1
#define ZERO 2
#define ZEROINVERTED 3
#define OTSU 8

#define NONE 0
#define ERODE 1
#define DILATE 2
#define OPEN 3
#define CLOSE 4

Mat resizing(Mat src, int x_size, int y_size);
void plotHist(Mat src, string plotname, int width, int height);
void contour(Mat& src, Mat dst);
Mat filter(Mat src_gray, int filter_type, int ksize);
Mat Threshold_Morphology(Mat src, Mat dst, int threshold_value, int threshold_type, int morphology_type);