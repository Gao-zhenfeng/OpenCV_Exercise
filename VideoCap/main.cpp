#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using std::endl;
using std::cout;

int main(int argc, char** argv)
{
	namedWindow("Example", WINDOW_AUTOSIZE);
	namedWindow("Log_Polar", WINDOW_AUTOSIZE);

	VideoCapture capture;
	if (argc == 1)
		capture.open(0);
	else
		capture.open(argv[1]);

	if (!capture.isOpened())
	{
		std::cerr << "Couldn't open capture." << endl;
		return -1;
	}

	double fps = capture.get(CAP_PROP_FPS);//帧率

	Size size(	//图像长宽
		(int)capture.get(CAP_PROP_FRAME_WIDTH),
		(int)capture.get(CAP_PROP_FRAME_WIDTH)
	);
	VideoWriter writer;
	writer.open("VideoTest.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'), fps, size);

	Mat logpolar_frame, bgr_frame;

	while (true)
	{
		capture >> bgr_frame;
		if (bgr_frame.empty()) break;

		imshow("Example", bgr_frame);
		logPolar(
			bgr_frame, //input image
			logpolar_frame, //output log-polar frame
			Point2f((float)bgr_frame.cols / 2, (float)bgr_frame.rows / 2), //对数极坐标中心
			40,	//Magnitude (scale paremeter)
			WARP_FILL_OUTLIERS
		);
		imshow("Log_Polar", logpolar_frame);
		writer << logpolar_frame;
		char c = waitKey(10);
		if (c == 27) break;
	}
	capture.release();
	return 0;
}