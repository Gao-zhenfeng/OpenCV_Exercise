#include <opencv2/opencv.hpp>

using namespace cv;
using std::cout;
using std::endl;

int main(int argc, char** argv)
{
	Mat img_rgb, img_gry, img_cny, img_pyr;
	namedWindow("Example Gray", WINDOW_NORMAL);
	namedWindow("Example Canny", WINDOW_NORMAL);

	img_rgb = imread("E:\\VS_project\\OpenCV\\TestMat\\1.png");
	cvtColor(img_rgb, img_gry, COLOR_BGR2GRAY);
	imshow("Example Gray", img_gry);

	Canny(img_gry, img_cny, 10, 100, 3, true);
	pyrDown(img_gry, img_pyr);
	imshow("Example Canny", img_cny);
	//读写pixel
	int x = 16, y = 32;
	Vec3b intensity = img_rgb.at<Vec3b>(y, x);//Vec3b  Vec<uchar, 3>

	uchar blue = intensity[0];
	uchar green = intensity[1];
	uchar red = intensity[2];
	//At (x,y) = (16, 32): (blue, green, red) = (164,164,164)
	cout << "At (x,y) = (" << x << ", " << y <<
		"): (blue, green, red) = (" <<
		(unsigned int)blue << "," <<
		(unsigned int)green << "," <<
		(unsigned int)red << ")" << endl;
	//Gray pixel there is: 164
	cout << "Gray pixel there is: " <<
		(unsigned int)img_gry.at<uchar>(y, x) << endl;
	x /= 4; y /= 4;
	//Pyramid pixel there is: 164
	cout << "Pyramid pixel there is: " <<
		(unsigned int)img_pyr.at<uchar>(y, x) << endl;//get pixel
	img_cny.at<uchar>(x, y) = 128;//set pixel
	waitKey(0);
	return 0;
}