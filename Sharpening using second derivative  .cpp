/*
#include "cv.hpp"
#include <iostream>


using namespace cv;
using namespace std;

int main() {
	Mat image, laplacian, abs_laplacian, sharpening;
	image = imread("Moon.png", 0);

	GaussianBlur(image, image, Size(3, 3), 0, 0, BORDER_DEFAULT);
	// calculates the Laplacian of an image
	// image: src, laplacian: dst, CV_16S: desire depth of dst,
	// 1: aperture size used to compute second-derivative (optional)
	// 1: optional scale factor for the computed Laplacian values
	// 0: optional delta value that is added to the result
	Laplacian(image, laplacian, CV_16S, 1, 1, 0);
	//Laplacian(image, laplacian, CV_16S, 5, 5, 5);
	convertScaleAbs(laplacian, abs_laplacian);
	sharpening = abs_laplacian + image;

	imshow("Input image", image);
	imshow("Laplacian", laplacian);
	imshow("abs_Laplacian", abs_laplacian);
	imshow("Sharpening", sharpening);

	waitKey(0);
}*/