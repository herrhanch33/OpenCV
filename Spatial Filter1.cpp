/*
#include "cv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	Mat image, AvgImg, GaussianImg;
	image = imread("lena.png");

	//Average Filtering
	//Blurs an image using the normalized box filter
	// image: input image, AvgImg: output image, Size(5, 5): blurring kernel size blur(image, AvgImg, Size(5, 5));
	//cout << image.cols << endl;
	//cout << image.rows << endl;
	Rect rect(0, 0, (image.size().width / 2), (image.size().height)); // or can use image.rows and image.cols
	Rect rect2((image.size().width /2), 0, (image.size().width / 2), (image.size().height));
	Mat rect_roi = image(rect);
	Mat otherhalf = image(rect2);
	blur(image(rect), AvgImg, Size(7, 7)); // 
	hconcat(AvgImg, otherhalf, AvgImg);

	//Blurs an image using a Gaussian filter
	// image: input image, GaussianImg: output image, Size(5, 5): Gaussian kernel size
	// 1.5: Gaussian kernel standard deviation in X direction
	//GaussianBlur(image, GaussianImg, Size(5, 5), 1.5);

	imshow("Input image", image);
	imshow("Average image", AvgImg);
	//imshow("Gaussian blurred image", GaussianImg);

	//Sharpening
	Mat moonimg, laplacian, sharpening, abs_laplacian;
	moonimg = imread("moon.png");

	//cout << moonimg.size().width << moonimg.size().height << endl;
	Rect rect3((moonimg.size().width/2), 0, (moonimg.size().width / 2), moonimg.size().height);
	//Rect rect3(moonimg.rows / 2, 0, moonimg.rows / 2, moonimg.cols);
	Rect rect4(0, 0, (moonimg.size().width / 2), (moonimg.size().height));
	Mat rect_roi2 = moonimg(rect3);
	Mat otherhalf2 = moonimg(rect4);
	//GaussianBlur(moonimg, moonimg, Size(3, 3), 0, 0, BORDER_DEFAULT);
	// calculates the Laplacian of an image
	// image: src, laplacian: dst, CV_16S: desire depth of dst,
	// 1: aperture size used to compute second-derivative (optional)
	// 1: optional scale factor for the computed Laplacian values
	// 0: optional delta value that is added to the result
	Laplacian(moonimg(rect3), laplacian, CV_16S, 1, 1, 0);
	convertScaleAbs(laplacian, abs_laplacian);
	sharpening = abs_laplacian + moonimg(rect3);
	hconcat(otherhalf2, sharpening, sharpening);
	imshow("Moon Image", moonimg);
	imshow("Moon_Filtered", sharpening);

	//Median Filtering
	Mat saltnpepper;
	saltnpepper = imread("saltnpepper.png");
	imshow("SaltAndPepper", saltnpepper);
	Mat mf1, mf2; //Median filter 1 & 2
	// Blurs an image using the median filter
	// image: src, mf1: dst, 3: aperture size(must be odd and greater than 1)
	medianBlur(saltnpepper, mf1, 9);
	imshow("MedianFiltered1", mf1);

	//medianBlur(saltnpepper, mf2, 9);
	//imshow("MedianFiltered2", mf2);
	

	waitKey(0);
	return 0;
}
*/