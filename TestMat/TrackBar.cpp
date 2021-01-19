#include "TrackBar.h"

TrackBar::TrackBar(int g_slider_position, int g_run, int g_dontset, VideoCapture& g_cap, Mat& frame)
	: g_slider_position(g_slider_position), g_run(g_run),
	g_dontset(g_dontset), g_cap(g_cap), frame(frame)
{
}

void onTrackbarSlide(int pos, void* bar)
{
	TrackBar tBar = *(TrackBar*)(bar);
	tBar.g_cap >> tBar.frame;
	imshow("Video", tBar.frame);
	tBar.g_cap.set(CAP_PROP_POS_FRAMES, pos);//使进度条移动到我们希望的位置
	if (!tBar.g_dontset)
	{
		tBar.g_run = 1;		//单步模式
		//g_run应在新的跳转触发后置零
		tBar.g_dontset = 0;
	}
}

void Gaussian_Blur(const Mat& image)
{
	namedWindow("Example2_5-in", WINDOW_NORMAL);
	namedWindow("Example2_5-out", WINDOW_NORMAL);
	imshow("Example2_5-in", image);
	//Creat an image to hold the smooth output
	Mat out;
	GaussianBlur(image, out, Size(5, 5), 3, 3);
	GaussianBlur(out, out, Size(5, 5), 3, 3);
	imshow("Example2_5-out", out);
	waitKey(0);
}