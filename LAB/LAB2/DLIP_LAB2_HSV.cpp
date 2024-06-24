#include <iostream>
#include <opencv2/opencv.hpp>
#include "cameraParam.h"


using namespace std;
using namespace cv;

// Global variables for Threshold
int threshold_value = 0;
int threshold_type = 0;
int morphology_type = 0;
int const max_value = 255;
int const max_type = 4;
int const max_BINARY_value = 255;
#define UP 0
#define FRONT 1

// Global variables for Morphology
int element_shape = MORPH_RECT;      // MORPH_RECT, MORPH_ELIPSE, MORPH_CROSS
int n = 3;
Mat element = getStructuringElement(element_shape, Size(n, n));
int actual_width = 100;
int actual_height = 0;

int hmin;
int hmax;
int smin;
int smax;
int vmin;
int vmax;

// red
int hmin_b = 0;
int hmax_b = 179;
int smin_b = 157;
int smax_b = 255;
int vmin_b = 105;
int vmax_b = 255;

int pointX[4];
int pointY[4];

int blue_X[4];
int blue_Y[4];

int pointX_blue[4];
int pointY_blue[4];
int pointX_red[4];
int pointY_red[4];

Mat src, src_gray, dst, src_copy, hsv, dst_inrange, dst_blured, dst_blue, blue_warp, red_warp;
vector<vector<Point> > contours;
vector<vector<Point> > contours_blue;

// Function headers
void resetImage();
void CallBackFunc(int event, int x, int y, int flags, void* userdata);
void updateWarpedImage();
void calculate(Mat warped, int pov);
void find4points();
vector<Point2f> sortVerticesClockwise(vector<Point2f> vertices);

vector<Point2f> clickedPoints;
vector<Point2f> point_blue;
vector<Point2f> point_red;

int selectedPointIndex = -1;  // Index of the point being dragged

int main() {
    // import Image, xml
    cameraParam param("C:\\Users\\heal\\source\\repos\\DLIP_GH\\LAB\\LAB2\\lab2.xml");
    src = imread("C:\\Users\\heal\\source\\repos\\DLIP_GH\\LAB\\LAB2\\LAB2_Image\\1.jpg");

    if (src.empty()) {
        cout << "Could not open or find the image!" << endl;
        return -1;
    }

    // Undistort
    src = param.undistort(src);  // Undistort the image

    src.copyTo(src_copy);

    int k = 9;
    blur(src, dst_blured, Size(k,k));
    // Find object's HSV
    cvtColor(dst_blured, hsv, COLOR_BGR2HSV, 0);
    // find4points
    find4points();
    updateWarpedImage();
    imshow("src", src);

    waitKey(0);
}

void updateWarpedImage() {

    int width = 440;
    int height_r = 290;
    int height_b = 260;

    // blue
    vector<Point2f> dstCorners_blue = { Point2f(point_blue[0].x, 0),
                                   Point2f(point_blue[0].x + width, 0),
                                   Point2f(point_blue[0].x + width, height_b),
                                   Point2f(point_blue[0].x, height_b)};

    // Compute the perspective transformation matrix
    Mat transformMatrix_blue = getPerspectiveTransform(point_blue, dstCorners_blue);   // 원근 변환 행렬을 계산(c: 이미지의 관심 영역 모서리4개 좌표, d: 출력 이미지에서 해당 모서리 좌표)
    warpPerspective(dst_blured, blue_warp, transformMatrix_blue, src.size());      // 원근 변환된 이미지 생성

    // red
    vector<Point2f> dstCorners_red = { Point2f(point_red[0].x, point_red[0].y),
                                        Point2f(point_red[0].x + width, point_red[0].y),
                                        Point2f(point_red[0].x + width,point_red[0].y + height_r),
                                        Point2f(point_red[0].x,point_red[0].y + height_r)};

    // Compute the perspective transformation matrix
    Mat transformMatrix = getPerspectiveTransform(point_red, dstCorners_red);   // 원근 변환 행렬을 계산(c: 이미지의 관심 영역 모서리4개 좌표, d: 출력 이미지에서 해당 모서리 좌표)
    warpPerspective(dst_blured, red_warp, transformMatrix, src.size());      // 원근 변환된 이미지 생성

    imshow("blue_warp", blue_warp);
    imshow("red_warp", red_warp);


    calculate(blue_warp, FRONT);
    calculate(red_warp, UP);
}

void calculate(Mat warped, int pov){
    // Find object's HSV
    string window_name;
    if(pov == UP){
        hmin = 98;
        hmax = 138;
        smin = 33;
        smax = 110;
        vmin = 171;
        vmax = 255;

        hmin = 95;
        hmax = 138;
        smin = 20;
        smax = 110;
        vmin = 216;
        vmax = 255;
        window_name = "UP";
    }
    else if(pov == FRONT){
        hmin = 80;
        hmax = 179;
        smin = 18;
        smax = 151;
        vmin = 13;
        vmax = 140;
        window_name = "FRONT";
    }
    cvtColor(warped, hsv, COLOR_BGR2HSV, 0);
    inRange(hsv, Scalar(MIN(hmin, hmax), MIN(smin, smax), MIN(vmin, vmax)),
            Scalar(MAX(hmin, hmax), MAX(smin, smax), MAX(vmin, vmax)), dst_inrange);

    // Morphology
    int element_shape = MORPH_RECT;		// MORPH_RECT, MORPH_ELIPSE, MORPH_CROSS
    int n = 15;
    Mat element = getStructuringElement(element_shape, Size(n, n));
    erode(dst_inrange, dst_inrange, element);
    dilate(dst_inrange, dst_inrange, element);

    // Contour
    findContours(dst_inrange, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);        // object

    // find max contour
    double maxArea = 0;
    int maxArea_idx = 0;

    for (int i = 0; i < contours.size(); i++)
        if (contourArea(contours[i]) > maxArea) {
            maxArea = contourArea(contours[i]);
            maxArea_idx = i;
        }

    Rect boxPoint = boundingRect(contours[maxArea_idx]);
    actual_height = actual_width * boxPoint.height / boxPoint.width;
    printf("actual height = %d\n", actual_height);
    rectangle(warped, boxPoint, Scalar(0, 255, 0), 3);

    // Show the warped image
    imshow("Inrange" + window_name, dst_inrange);
    // imshow("dst_blured", dst_blured);
    imshow(window_name, warped);
}

void find4points(){
    // Find background HSV
    inRange(hsv, Scalar(MIN(hmin_b, hmax_b), MIN(smin_b, smax_b), MIN(vmin_b, vmax_b)),
            Scalar(MAX(hmin_b, hmax_b), MAX(smin_b, smax_b), MAX(vmin_b, vmax_b)), dst_blue);

    // Morphology
    int element_shape = MORPH_RECT;		// MORPH_RECT, MORPH_ELIPSE, MORPH_CROSS
    int n = 15;
    Mat element = getStructuringElement(element_shape, Size(n, n));
    erode(dst_blue, dst_blue, element);
    dilate(dst_blue, dst_blue, element);

    imshow("dst_inragne",dst_blue);
    findContours(dst_blue, contours_blue, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);        // blue background

    for(int i=0; i<contours_blue.size(); i++){
        // 근사화하여 꼭짓점 찾기
        vector<Point> contour = contours_blue[i];
        vector<Point2f> approx;

        approxPolyDP(contour, approx, arcLength(contour, true) * 0.02, true);

        // 사각형의 꼭짓점이 맞는지 확인
        if (approx.size() == 4 && i == 1) {
            for (int j = 0; j < 4; j++) {
                point_blue.push_back(Point2f(static_cast<float>(approx[j].x), static_cast<float>(approx[j].y)));
            }
        }
        else if (approx.size() == 4 && i == 0) {
            for (int j = 0; j < 4; j++) {
                point_red.push_back(Point2f(static_cast<float>(approx[j].x), static_cast<float>(approx[j].y)));
            }
        }
        else {
            cout << "The largest contour does not have 4 vertices." << endl;
        }
    }
    point_blue = sortVerticesClockwise(point_blue);
    point_red = sortVerticesClockwise(point_red);
    for(int i=0; i<4; i++){
        cout << "Point blue(" << point_blue[i].x << ", " << point_blue[i].y << ")" << endl;
        circle(src, point_blue[i], 5, Scalar(255, 0 + i*50, 0 + i*50), -1);

    }
    for(int i=0; i<4; i++){
        cout << "Point red(" << point_red[i].x << ", " << point_red[i].y << ")" << endl;
        circle(src, point_red[i], 5, Scalar(0 + i*50, 0 + i*50, 255), -1);
    }
}

vector<Point2f> sortVerticesClockwise(vector<Point2f> vertices) {
    vector<Point2f> point_(4); // 4개의 꼭짓점을 저장할 공간 확보
    float minDistance = numeric_limits<float>::max();
    int minIndex = -1;

    // 좌측 상단 꼭짓점 찾기
    for(int i = 0; i < vertices.size(); i++) {
        float dist = pow(vertices[i].x, 2) + pow(vertices[i].y, 2);
        if (dist < minDistance) {
            minDistance = dist;
            minIndex = i;
        }
    }
    point_[0] = vertices[minIndex]; // 최소 거리 꼭짓점을 point_[0]에 저장
    // 아크탄젠트 값과 원래 인덱스를 저장
    vector<pair<double, int>> indexMap;
    for (int i = 0; i < vertices.size(); i++) {
        if (i != minIndex) {
            double angle = atan2(vertices[i].y - point_[0].y, vertices[i].x - point_[0].x);
            indexMap.push_back({angle, i});
        }
    }
    // 각도에 따라 오름차순 정렬
    sort(indexMap.begin(), indexMap.end(), [](const pair<double, int>& a, const pair<double, int>& b) {
        return a.first < b.first;
    });
    // 정렬된 순서대로 point_ 배열에 꼭짓점 저장
    for (int i = 0; i < indexMap.size(); i++) {
        point_[i + 1] = vertices[indexMap[i].second];
    }
    // 완성된 꼭짓점 목록 반환
    return point_;
}