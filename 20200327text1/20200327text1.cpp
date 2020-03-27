#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;


int main()
{
	VideoCapture cap;
	cap.open(0);
	if (!cap.isOpened())
	{
		std::cout << "不能打开视频文件" << std::endl;
		return-1;
	}
	double fps = cap.get(CAP_PROP_FPS);
	std::cout << "fps" << fps << std::endl;
	while (1)
	{
		Mat frame;
		Mat medianblur_frame;
		Mat blur_frame;
		Mat Gaussianblur_frame;
		Mat dx;
		Mat dy;
		Mat abs_dx;
		Mat abs_dy;
		cap.read(frame);
		medianBlur(frame, medianblur_frame, 3);
		blur(frame, blur_frame,Size (3,3));
		GaussianBlur(frame, Gaussianblur_frame,Size(3,3),1,0);
		Sobel(frame, dx, CV_16SC1, 1, 0, 3);
		convertScaleAbs(dx, abs_dx);
		Sobel(frame, dy, CV_16SC1, 0, 1, 3);
		convertScaleAbs(dy, abs_dy);
		imshow("frame", frame);
		imshow("medianblur_frame", medianblur_frame);
		imshow("blur_frame", blur_frame);
		imshow("Gaussianblur_frame", Gaussianblur_frame);
		imshow("dx", abs_dx);
		imshow("dy", abs_dy);
		waitKey(0);
	}
}