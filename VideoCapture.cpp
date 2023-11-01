#include "cv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	Mat frame;
	VideoCapture cap;
	// check if file exists. if none program ends
	if (cap.open("background.mp4") == 0) {
		cout << "no such file!" << endl;
		waitKey(0);
	}
	while (1) {
		cap >> frame;
		if (frame.empty()) {
			cout << "end of video" << endl;
			break;
		}
		imshow("video", frame);
		waitKey(300);
	}
	}
