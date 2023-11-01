/*
#include "cv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	Mat image, gamma_image;
	image = imread("barcode.jpeg", 0);

	//Gamma Image
	MatIterator_<uchar> it, end;
	unsigned char pix[256];

	float gamma = 2.5; // Increase Gamma 

	for (int i = 0; i < 256; i++) {
		pix[i] = saturate_cast<uchar>(pow((float)(i / 255.0), gamma) * 255.0f);
	}

	gamma_image = image.clone();

	for (it = gamma_image.begin<uchar>(), end = gamma_image.end<uchar>(); it != end; it++) {
		*it = pix[(*it)];
	}

	imshow("gamma image", gamma_image);

	waitKey(0);

}
*/