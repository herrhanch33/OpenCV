/*
#include "cv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	Mat image = imread("saltnpepper.png", 0);
	imshow("SaltAndPepper", image);
	Mat mf1, mf2;
	// Blurs an image using the median filter
	// image: src, mf1: dst, 3: aperture size(must be odd and greater than 1)
	medianBlur(image, mf1, 3);
	imshow("MedianFiltered1", mf1);

	medianBlur(image, mf2, 9);
	imshow("MedianFiltered2", mf2);

	waitKey(0);
	return 0;
}
*/