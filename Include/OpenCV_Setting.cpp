/*
    CLASS: DLIP
    DATE: 2024-03-22
    BY: Gyeonheal An
    ID: 21900416
*/

#include "OpenCV_Setting.h"

Mat resizing(Mat src, int x_size, int y_size){
    Mat sized;
    resize(src ,sized, Size(x_size, y_size));
    return sized;
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



Mat filter(Mat src_gray, int filter_type, int ksize){
    Mat dst_filtered, dst;

    int kernel_size = 3;
    int scale = 1;
    int delta = 0;
    int ddepth = CV_16S;

    switch(filter_type){
        case NONE: src_gray.copyTo(dst_filtered); break;
        case GAUSSIAN: GaussianBlur(src_gray, dst_filtered, cv::Size(ksize,ksize), 0, 0); break;
        case MEDIAN: medianBlur(src_gray, dst_filtered, ksize); break;
        case LAPLACIAN:
            cv::Laplacian(src_gray, dst, ddepth, ksize, scale, delta, cv::BORDER_DEFAULT);
            src_gray.convertTo(src_gray, CV_16S);
            dst_filtered = src_gray - dst;
            dst_filtered.convertTo(dst_filtered, CV_8U);
            break;
    }
    return dst_filtered;
}

Mat Threshold_Morphology(Mat src, Mat dst, int threshold_value, int threshold_type, int morphology_type){
    Mat dst_morph;
    int element_shape = MORPH_RECT;		// MORPH_RECT, MORPH_ELIPSE, MORPH_CROSS
    int n = 3;
    Mat element = getStructuringElement(element_shape, Size(n, n));

    /*
    * 0: Binary
    * 1: Threshold Truncated
    * 2: Threshold to Zero
    * 3: Threshold to Zero Inverted
    * 8: Threshold OTSU
    */
    threshold(src, dst, threshold_value, 255, threshold_type);

    switch (morphology_type) {
        case NONE: dst.copyTo(dst_morph);	break;
        case ERODE: erode(dst, dst_morph, element); break;
        case DILATE: dilate(dst, dst_morph, element); break;
        case OPEN: morphologyEx(dst, dst_morph, MORPH_OPEN, element); break;
        case CLOSE: morphologyEx(dst, dst_morph, MORPH_CLOSE, element); break;
    }
    return dst_morph;
}

