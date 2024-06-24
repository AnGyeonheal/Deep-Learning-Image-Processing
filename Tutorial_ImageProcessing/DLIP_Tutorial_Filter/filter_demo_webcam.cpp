/*------------------------------------------------------/
* Image Proccessing with Deep Learning
* OpenCV : Filter Demo - Video
* Created: 2021-Spring
------------------------------------------------------*/

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    /*  open the video camera no.0  */
    VideoCapture cap(1);

    if (!cap.isOpened())	// if not success, exit the programm
    {
        cout << "Cannot open the video cam\n";
        return -1;
    }

    namedWindow("MyVideo", WINDOW_AUTOSIZE);

    int key = 0;
    int kernel_size = 11;
    int filter_type = 0;
    while (1)
    {
        Mat src, dst;

        /*  read a new frame from video  */
        bool bSuccess = cap.read(src);

        if (!bSuccess)	// if not success, break loop
        {
            cout << "Cannot find a frame from  video stream\n";
            break;
        }


        key = waitKey(30);
        if (key == 27) // wait for 'ESC' press for 30ms. If 'ESC' is pressed, break loop
        {
            cout << "ESC key is pressed by user\n";
            break;
        }
        else if (key == 'b' || key == 'B')
        {
            filter_type = 1;	// blur
        }

        /* Keyboard input for other filters*/
        else if (key == 'g' || key == 'G'){
            filter_type = 2;    // Gaussian
        }

        else if (key == 'm' || key == 'M'){
            filter_type = 3;    // Medium
        }
        else if (key == 'l' || key == 'L'){
            filter_type = 4;    // Laplacian
        }

        else if (key == 'u' || key == 'U'){
            kernel_size += 2;    // Kernel_size up
            if (kernel_size >= 21) kernel_size = 21;
        }

        else if (key == 'd' || key == 'D'){
            kernel_size -= 2;    // Kernel_size down
            if (kernel_size <= 1) kernel_size = 1;
        }

        if (filter_type == 1)
            blur(src, dst, cv::Size(kernel_size, kernel_size), cv::Point(-1, -1));

        else if (filter_type == 2)
            GaussianBlur(src, dst, cv::Size(kernel_size, kernel_size), 0, 0);

        else if (filter_type == 3)
            medianBlur(src, dst, kernel_size);

        else if (filter_type == 4)
            Laplacian(src, dst, -1, kernel_size, 1, 0);

        else
            src.copyTo(dst);

        imshow("MyVideo", dst);
    }
    return 0;
}