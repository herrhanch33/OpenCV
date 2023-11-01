/*
//HW7 21701062 Chang Hee Han

#include <iostream>
#include "cv.hpp"

using namespace std;
using namespace cv;

int main() {
	Mat finger, adaptive, adaptive_1;
	Mat fingerdst, adaptivedst, adaptive_1dst;

	finger = imread("finger_print.png", 0);
	adaptive = imread("adaptive.png", 0);
	adaptive_1 = imread("adaptive_1.jpg", 0);

	//cvtColor(finger, finger, CV_BGR2GRAY); ////
	//adaptiveThreshold(finger, fingerdst, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 85, 15); // 
	//double threshold(finger, fingerdst, 100, 255, THRESH_BINARY);
	threshold(finger, fingerdst, 160, 255, THRESH_BINARY);
	adaptiveThreshold(adaptive, adaptivedst, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 7, 10);
	//threshold(adaptive_1, adaptive_1dst, 80, 255, THRESH_BINARY | THRESH_OTSU);
	adaptiveThreshold(adaptive_1, adaptive_1dst, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 21, 9);

	//cout << adaptive_1.size << endl;

	imshow("finger image", fingerdst);
	imshow("adaptive image", adaptivedst); 
	imshow("adaptive 1 image", adaptive_1dst);
	//imshow("adaptive 1 original image", adaptive_1);

	waitKey(0);

	return 0;
}
*/