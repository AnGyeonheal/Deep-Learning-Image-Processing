#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>
#include "OpenCV_Setting.h"

using namespace cv;

/// Global variables

Mat src, src_gray;
Mat dst, detected_edges;

int edgeThresh = 1;
int lowThreshold;
int const max_lowThreshold = 100;
int ratio = 3;
int kernel_size = 3;
const char* window_name = "Edge Map";

/**
 * @function CannyThreshold
 * @brief Trackbar callback - Canny thresholds input with a ratio 1:3
 */
void CannyThreshold(int, void*)
{
	/// Reduce noise with a kernel 3x3   
	/// src_gray --> detected_edges
	detected_edges = filter(src_gray, GAUSSIAN, 3);

    for(int i=0; i<2; i++){
        medianBlur(src_gray, src_gray, 3);
    }
    medianBlur(src_gray, detected_edges, 3);



	/// Canny detector
	///  detected_edges-->detected_edges:  lowThreshold, lowThreshold*ratio, kernel_size
	//
    Canny(detected_edges, detected_edges, lowThreshold, max_lowThreshold, kernel_size);



    /// Using Canny's output as a mask, we display our dst_undistorted
	dst = Scalar::all(0);

	src.copyTo(dst, detected_edges);
	imshow(window_name, dst);
}


/** @function main */
int main(int argc, char** argv)
{
	/// Load an image
	
	const char* filename = "C:\\Users\\heal\\source\\repos\\DLIP_GH\\Image\\TrafficSign1.png";
	

	/// Read the image
	src = imread(filename, 1);

	if (!src.data)
	{
		return -1;
	}

	/// Create a matrix of the same type and size as src (for dst)
	dst.create(src.size(), src.type());

	/// Convert the image to grayscale
	cvtColor(src, src_gray, COLOR_BGR2GRAY);

	/// Create a window
	namedWindow(window_name, WINDOW_AUTOSIZE);

	/// Create a Trackbar for user to enter threshold
	createTrackbar("Min Threshold:", window_name, &lowThreshold, max_lowThreshold, CannyThreshold);

	/// Show the image
	CannyThreshold(0, 0);

	/// Wait until user exit program by pressing a key
	waitKey(0);

	return 0;
}
