#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	Mat img1, img2;
	namedWindow("img1", WINDOW_NORMAL);
	namedWindow("img2[降采样]", WINDOW_NORMAL);

	img1 = imread("E:\\VS_project\\OpenCV\\TestMat\\1.png");
	if (img1.empty())
	{
		cout << "can't open image " << endl;
		return -1;
	}
	imshow("img1", img1);
	pyrDown(img1, img2);//对img1进行降采样得到img2
	imshow("img2[降采样]", img2);
	waitKey(0);
	//system("pause");
	return 0;
}