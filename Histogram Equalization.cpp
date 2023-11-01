/*
#include "cv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	Mat image;
	Mat hist_equalized_image;

	image = imread("lena.png", 0);
	if (!image.data) exit(1); //Check image

	equalizeHist(image, hist_equalized_image);

	imshow("Input Image", image);
	imshow("Hist Equalized Image", hist_equalized_image);

	waitKey(0);
	return 0;
}
*/