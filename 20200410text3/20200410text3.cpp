#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() {


	Mat src = imread("E:\\Git\\metal-part-distorted-03.png", 1);
	Mat dst;
	Mat canny;
	Canny(src, canny, 60, 180, 3);
	cvtColor(canny, dst, COLOR_GRAY2BGR);
	vector<Vec4i>lines;

	HoughLinesP(canny, lines,1, CV_PI / 180, 20, 5, 5);

	vector<Vec4i>::iterator it = lines.begin();
	for (int it = 0; it < lines.size(); it++) {
		Point pt1, pt2;
		pt1.x = lines[it][0];
		pt1.y = lines[it][1];
		pt2.x = lines[it][2];
		pt2.y = lines[it][3];
		line(src, pt1, pt2, Scalar(0, 0, 255), 1, CV_AA);
	}

	imshow("src", src);
	imshow("canny", canny);

	waitKey(0);

}