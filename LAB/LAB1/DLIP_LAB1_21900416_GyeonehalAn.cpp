#include <opencv2/opencv.hpp>
#include <iostream>
#include "OpenCV_Setting.h"

void contour(Mat& src, Mat dst);

cv::Mat origin, src, src_gray, dst, dst_filtered, dst_morph, dst_morph2, dst_normalized;
int element_shape = MORPH_RECT;
int n = 3;
Mat element = getStructuringElement(element_shape, Size(n, n));

vector<vector<Point>> contours;
vector<vector<Point>> contours_save;
vector<vector<Point>> contours_nuthole;
vector<int> nutIndex;
vector<Vec4i> hierarchy;

Scalar color_M5_B = Scalar(255, 0, 0);
Scalar color_M6_B = Scalar(0, 255, 0);
Scalar color_M5_HN = Scalar(0, 0, 255);
Scalar color_M5_RN = Scalar(255, 255, 0);
Scalar color_M6_N= Scalar(0, 255, 255);

int M5_B = 0;
int M6_B = 0;
int M5_HN = 0;
int M5_RN = 0;
int M6_N = 0;

int main(){
    // |************************* Read, Resize, Convert to GrayScale Sourc Image *************************|
    src = cv::imread("C:\\Users\\hilla\\source\\repos\\DLIP_GH\\Image\\Lab_GrayScale_TestImage.jpg", 1);
    cvtColor(src, src_gray, COLOR_BGR2GRAY);

    // |************************* Tresholding and Morpholgy *************************|
    threshold(src_gray, dst, 111, 255, 4);
    morphologyEx(dst, dst_morph, MORPH_CLOSE, element);

    // |************************* Filter *************************|
    dst_filtered = filter(dst_morph, MEDIAN, 3);
    imshow("dst_filtered", resizing(src_gray, 850, 850));

    // |************************* Ploting Histogram *************************|
    plotHist(src_gray,"", 850, 850);

    // |************************* Draw Contours on the original image *************************|
    Mat white = cv::Mat(src.size(), src.type(), cv::Scalar(255, 255, 255));

    contour(src, dst_filtered);
    imshow("Contours", resizing(src, 850, 850));

    std::cout << "M5 Bolt: " << M5_B << std::endl;
    std::cout << "M6 Bolt: " << M6_B << std::endl;
    std::cout << "M5 Hex Nut: " << M5_HN << std::endl;
    std::cout << "M5 Rect Nut: " << M5_RN << std::endl;
    std::cout << "M6 HEX Nut: " << M6_N << std::endl;

    waitKey(0);
}

void contour(Mat& src, Mat dst){
    /// Find contours
    findContours(dst, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);

    for(int i = 0; i < contours.size(); i++)
    {
        if(contourArea(contours[i]) < 330 || contourArea(contours[i]) > 30000 ){
            continue;   // useless contours
        }
        else if(contourArea(contours[i]) < 1500){
            contours_nuthole.push_back(contours[i]);    // saving nut hole
        }
        else{
            contours_save.push_back(contours[i]);   // saving others
        }
    }

    for(int i=0; i<contours_nuthole.size(); i++){
        Rect nutholeRect = boundingRect(contours_nuthole[i]);
        for(int j=0; j<contours_save.size(); j++){
            Rect boundRect = boundingRect(contours_save[j]);
            if(boundRect.x < nutholeRect.x && nutholeRect.x < boundRect.x+boundRect.width && boundRect.y < nutholeRect.y && nutholeRect.y < boundRect.y + boundRect.height){    // Finding the hole location
                nutIndex.push_back(j);      // Save the Index of nuts
                if(contourArea(contours_nuthole[i]) > 1000){    // Finding the M6 Hex nut
                    rectangle(src, boundRect.tl(), boundRect.br(), color_M6_N, 2);
                    rectangle(src, nutholeRect.tl(), nutholeRect.br(), color_M6_N, 2);
                    M6_N++;
                }
                else{
                    if(contourArea(contours_save[j]) > 8000){       // Finding the M5 Rectangle nuts that are stuck together
                        rectangle(src, nutholeRect.tl(), nutholeRect.br(), color_M5_RN, 2);
                        rectangle(src, boundRect.tl(), boundRect.br(), color_M5_RN, 2);
                        M5_RN++;
                    }
                    else if(6500 < contourArea(contours_save[j]) && contourArea(contours_save[j]) < 8000){      // Finding the M5 Hex nuts that are stuck together
                        rectangle(src, nutholeRect.tl(), nutholeRect.br(), color_M5_HN, 2);
                        rectangle(src, boundRect.tl(), boundRect.br(), color_M5_HN, 2);
                        M5_HN++;
                    }
                    else if(contourArea(contours_save[j]) < 4000){  // Finding the M5 Rectangle nuts
                        rectangle(src, nutholeRect.tl(), nutholeRect.br(), color_M5_HN, 2);
                        rectangle(src, boundRect.tl(), boundRect.br(), color_M5_HN, 2);
                        M5_HN++;
                    }
                    else if(contourArea(contours_save[j]) > 4000){  // Finding the M5 Hex nuts
                        rectangle(src, nutholeRect.tl(), nutholeRect.br(), color_M5_RN, 2);
                        rectangle(src, boundRect.tl(), boundRect.br(), color_M5_RN, 2);
                        M5_RN++;
                    }
                }
            }
        }
    }
    for(int k=0; k<contours_save.size(); k++){
        if (find(nutIndex.begin(), nutIndex.end(), k) == nutIndex.end()) {      // Finding the Bolts
            Rect boundRect = boundingRect(contours_save[k]);
            if(contourArea(contours_save[k]) < 9000){
                rectangle(src, boundRect.tl(), boundRect.br(), color_M5_B, 2);  // Finding the M5 bolts
                M5_B++;
            }
            else {
                rectangle(src, boundRect.tl(), boundRect.br(), color_M6_B, 2);  // Finding the M6 bolts
                M6_B++;
            }
        }
    }
}