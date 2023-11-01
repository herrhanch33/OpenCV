/*
#include <cv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	Mat image, canny;
	image = imread("lena.png", 0);

	//performs canny edge detection
	//image: input Mat, canny: output Mat
	//190: Thresh_low of double thresholding
	//200: Thresh_hugh of double thresholding
	//3: aperture size of the Sobel operation
	Canny(image, canny, 190, 200, 3);

	imshow("Input image", image);
	imshow("canny", canny);

	waitKey(0);
}
*/