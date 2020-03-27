#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;


int main()
{
	VideoCapture cap;
	cap.open(0);

	while (1)
	{
		Mat frame;
		Mat medianblur_frame;
		bool rSucess = cap.read(frame);
		medianBlur(frame, medianblur_frame, 3);
		imshow("frame", frame);
		imshow("medianblur_frame", medianblur_frame);
		waitKey(0);
	}
}