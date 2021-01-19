#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include "TrackBar.h"

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	////视频播放
	//namedWindow("[Video]", WINDOW_NORMAL);
	//VideoCapture cap;
	//cap.open("E:\\课程资料\\毕设\\小毕设\\视频\\ORB.mp4");
	//Mat frame;	//save frame of video
	//for (;;) {
	//	cap >> frame;
	//	if (frame.empty()) break;
	//	imshow("[Video]", frame);
	//	if (waitKey(100) >= 0) break;	//如果等待期间有键盘输入，将退出循环
	//}
	Mat img1;
	namedWindow("img1", WINDOW_NORMAL);
	//namedWindow("降采样", WINDOW_NORMAL);
	img1 = imread("E:\\VS_project\\OpenCV\\TestMat\\1.png");
	imshow("img1", img1);

	VideoCapture g_cap;
	namedWindow("Video", WINDOW_NORMAL);
	g_cap.open("E:\\课程资料\\毕设\\小毕设\\视频\\ORB.mp4");
	int frames = static_cast<int> (g_cap.get(CAP_PROP_FRAME_COUNT));
	int tmpw = static_cast<int> (g_cap.get(CAP_PROP_FRAME_WIDTH));
	int tmph = static_cast<int> (g_cap.get(CAP_PROP_FRAME_HEIGHT));
	cout << "Videos has " << frames << endl;
	cout << "frames of dimensions(" << tmpw << " , " << tmph << " ) " << endl;

	int g_slider_position = 0;
	int g_run = 1, g_dontset = 0;//start out in step mode
	Mat frame;
	TrackBar bar{ g_slider_position , g_run , g_dontset , g_cap, frame };
	createTrackbar("Position", "Video", &(bar.g_slider_position),
		frames, onTrackbarSlide, &bar);
	while (1) {
		if (bar.g_run != 0)
		{
			bar.g_cap >> bar.frame;
			if (bar.frame.empty()) break;
			int current_pos = static_cast<int> (bar.g_cap.get(CAP_PROP_POS_FRAMES));
			bar.g_dontset = 1;
			setTrackbarPos("Position", "Video", current_pos);
			imshow("Video", bar.frame);

			bar.g_run -= 1;
		}

		char c = static_cast<char> (waitKey(10));
		if (c == 's')	//single step
		{
			bar.g_run = 1;
			imshow("Video", bar.frame);
			cout << "Single step, run = " << bar.g_run << endl;
		}
		if (c == 'r')	//run step
		{
			bar.g_run = -1;//when g_run is a negative number, it's in run mode.
			imshow("Video", bar.frame);
			cout << "Run mode, run = " << bar.g_run << endl;
		}
		if (c == 27)
			break;
	}
	//Mat src = imread("1.png");
	//Gaussian_Blur(src);
	return 0;
}