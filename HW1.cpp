/*#include "cv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	Mat frame;
	VideoCapture cap("background.mp4");

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

		int total_frames = cap.get(CAP_PROP_FRAME_COUNT);
		int current_frames = cap.get(CAP_PROP_POS_FRAMES);
		double time = cap.get(CAP_PROP_POS_MSEC);

		if (time == 3000) {
			break;
		}

		char c = (char)waitKey(1);
		if (c == 27) {
			break;
		}

		cout << "frames: " << current_frames << "/" << total_frames << endl;

		waitKey(24);
	}
}
}
*/