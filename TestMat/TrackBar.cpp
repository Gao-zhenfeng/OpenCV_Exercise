#include "TrackBar.h"

TrackBar::TrackBar(int g_slider_position, int g_run, int g_dontset, VideoCapture& g_cap, Mat& frame)
	: g_slider_position(g_slider_position), g_run(g_run),
	g_dontset(g_dontset), g_cap(g_cap), frame(frame)
{
}

void onTrackbarSlide(int pos, void* bar)
{
	TrackBar tBar = *(TrackBar*)(bar);
	tBar.g_cap.set(CAP_PROP_POS_FRAMES, pos);
	if (!tBar.g_dontset)
	{
		tBar.g_run = 1;		//单步模式
		//g_run应在新的跳转触发后置零
		tBar.g_dontset = 0;
	}
}