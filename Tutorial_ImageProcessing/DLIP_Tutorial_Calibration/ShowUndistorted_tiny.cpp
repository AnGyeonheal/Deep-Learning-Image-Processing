#include <iostream>
#include <opencv.hpp>
#include "cameraParam.h"

using namespace cv;

int main()
{
	cameraParam param("C:\\Users\\heal\\source\\repos\\DLIP_GH\\Tutorial\\DLIP_Tutorial_Calibration\\calibTest.xml");
	Mat src = imread("C:\\Users\\heal\\source\\repos\\DLIP_GH\\Tutorial\\DLIP_Tutorial_Calibration\\calibTest.jpg");
	Mat dst = param.undistort(src);


    resize(src, src, Size(500, 500));
    resize(dst, dst, Size(500, 500));

	imshow("src", src);
	imshow("dst", dst);
	 
	waitKey(0);
    return(0);
}
