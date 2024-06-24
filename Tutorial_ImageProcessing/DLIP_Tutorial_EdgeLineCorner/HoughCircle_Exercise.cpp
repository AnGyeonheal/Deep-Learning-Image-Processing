//
// Created by An Gyeonheal on 2024-04-16.
//
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

Mat src, gray;
void HoughCircle(int, void*);

int main(int argc, char** argv)
{
    String filename = "C:\\Users\\heal\\source\\repos\\DLIP_GH\\Image\\eyepupil.png";

    /* Read the image */
    src = imread(filename, 1);

    if (!src.data)
    {
        printf(" Error opening image\n");
        return -1;
    }

    cvtColor(src, gray, COLOR_BGR2GRAY);

    /* smooth it, otherwise a lot of false circles may be detected */
    GaussianBlur(gray, gray, Size(5, 5), 4, 4);

    imshow("gray", gray);

    HoughCircle(0, 0);

    /* Wait and Exit */
    waitKey();
    return 0;
}

void HoughCircle(int, void*){
    vector<Vec3f> circles;
    HoughCircles(gray, circles, HOUGH_GRADIENT, 1, gray.rows / 50, 100, 40);

    for (size_t i = 0; i < circles.size(); i++)
    {
        Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
        int radius = cvRound(circles[i][2]);

        /* draw the circle outline */
        circle(src, center, radius, Scalar(0, 0, 255), 3, 8, 0);
    }

    namedWindow("HoughCircle", 1);
    imshow("HoughCircle", src);

}

/*image: 입력 이미지입니다. 이 함수는 주로 그레이스케일 또는 하나의 채널을 가진 이미지를 입력으로 받습니다.

circles: 검출된 원의 중심 좌표와 반지름을 저장할 벡터입니다.

method: 원을 검출하기 위한 메소드입니다. 현재 OpenCV에서는 HOUGH_GRADIENT만 지원합니다.

dp: 입력 이미지 해상도에 대한 역비율입니다. 예를 들어, dp=1은 원의 검출을 위해 입력 이미지와 동일한 해상도를 사용하고, dp=2는 입력 이미지의 해상도의 반만큼 사용합니다.

minDist: 검출된 원들 사이의 최소 거리입니다. 이 값이 작을수록 검출되는 원의 수가 많아질 수 있습니다.

param1: Canny 엣지 검출기에 전달되는 임계값 상위 임계값입니다.

param2: 허프 변환에 사용되는 임계값입니다. 이 값이 작을수록 검출되는 원의 수가 많아지며, 큰 값은 검출되는 원의 정확도를 높입니다.

minRadius: 검출할 원의 최소 반지름입니다.

maxRadius: 검출할 원의 최대 반지름입니다.*/
