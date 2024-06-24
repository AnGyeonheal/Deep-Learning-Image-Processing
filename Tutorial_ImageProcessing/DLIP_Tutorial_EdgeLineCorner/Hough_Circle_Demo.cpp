#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	Mat src, gray;
	
	String filename = "C:\\Users\\hilla\\source\\repos\\DLIP_GH\\Image\\coins.png";
	
	/* Read the image */
	src = imread(filename, 1);
	
	if (!src.data)
	{
		printf(" Error opening image\n");
		return -1;
	}
		
	cvtColor(src, gray, COLOR_BGR2GRAY);

	/* smooth it, otherwise a lot of false circles may be detected */
/*	GaussianBlur(gray, gray, Size(9, 9), 2, 2);
    GaussianBlur(gray, gray, Size(9, 9), 2, 2);*/
    for(int i=0; i<3; i++){
        medianBlur(gray, gray, 3);
    }

    imshow("gray", gray);

	vector<Vec3f> circles;
	HoughCircles(gray, circles, HOUGH_GRADIENT, 2, gray.rows / 32, 225, 75);
    // param1 : 임계값을 높일 때:
    //임계값을 높이면 에지 검출기가 더 강한 에지만을 에지로 인식합니다. 즉, 더 높은 대비 또는 더 명확한 경계를 가진 객체의 에지만 감지됩니다.
    //결과적으로, 원의 경계가 뚜렷하고 대비가 강한 원들만 검출됩니다. 미세하거나 희미한 원은 누락될 수 있습니다.
    //잘못된 원 검출이 감소할 수 있으나, 이로 인해 일부 실제 원들도 검출되지 않을 위험이 있습니다.
    //임계값을 낮출 때:
    //낮은 임계값은 약한 에지도 포함하게 되므로, 이미지의 미세한 패턴이나 약한 대비를 가진 원도 에지로 간주됩니다.
    //이는 더 많은 원이 검출될 수 있지만, 동시에 잘못된 원 검출의 수도 증가할 수 있습니다. 예를 들어, 질감이나 잡음 또한 원으로 잘못 인식될 수 있습니다.

    // param2 : 중심 임계값으로, 원 중심을 검출하기 위한 임계값입니다.
    // 이 값이 낮을수록 더 많은 원이 검출되지만 잘못된 검출의 가능성도 증가합니다. 반대로, 값이 높을수록 더 적은 원이 검출되지만 더 정확한 원들이 검출됩니다.
	for (size_t i = 0; i < circles.size(); i++)
	{
		Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
		int radius = cvRound(circles[i][2]);

		/* draw the circle center */
		circle(src, center, 3, Scalar(0, 255, 0), -1, 8, 0);

		/* draw the circle outline */
		circle(src, center, radius, Scalar(0, 0, 255), 3, 8, 0);
	}

	namedWindow("circles", 1);
	imshow("circles", src);
	
	/* Wait and Exit */
	waitKey();
	return 0;
}
