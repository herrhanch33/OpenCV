
#include "cv.hpp"
#include <iostream>


using namespace std;
using namespace cv;

int main() {
	Mat image, enhanced, abs_enhanced, sharpened, gamma_image;
	image = imread("jeffrey.jpg");

	resize(image, enhanced, Size(1040, 1200), 0, 0, CV_INTER_LANCZOS4);
	
	detailEnhance(enhanced, sharpened, 5, 0.05);

	imshow("fixed", enhanced);

	imshow("sharpened", sharpened);

	imwrite("jeff.jpg", sharpened);

	waitKey(0);

	return 0;
}
