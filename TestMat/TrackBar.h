#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;
class TrackBar
{
public:
	int g_slider_position{ 0 };
	int g_run{ 1 };
	int g_dontset{ 0 };
	VideoCapture g_cap;
	Mat frame;
	TrackBar(int g_slider_position, int g_run, int g_dontset,
		VideoCapture& g_cap, Mat& frame);
};

void onTrackbarSlide(int pos, void* bar);
void Gaussian_Blur(const Mat& image);
