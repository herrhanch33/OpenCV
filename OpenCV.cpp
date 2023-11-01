#include "cv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main() {

	Mat img = imread("lena.png");
	Mat negative_img = im

	if (img.empty()) {
		cerr << "image reading is failed!" << endl;
		exit(-1);
	}

	imshow("lena", img);
	waitKey(0);
}