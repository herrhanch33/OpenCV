/*

//HW8 21701062 Chang Hee Han background subtraciton program
#include <iostream>
#include "cv.hpp"

using namespace std;
using namespace cv;

int main() {

	Mat background, avg, image, gray, result, foregroundMask, foregroundImg, opening, element, backgroundImg, dilation;
	Ptr<BackgroundSubtractor> bg_model = createBackgroundSubtractorMOG2();
	VideoCapture capture("background.mp4");

	element = getStructuringElement(MORPH_ELLIPSE, Size(7, 7));

	vector <vector<Point>> contours;
	vector <Vec4i> hierarchy;

	int cnt = 10;
	int i = 0;

	capture >> background;
	cvtColor(background, background, CV_BGR2GRAY);

	while (true) {

		if (i < 9) {
			capture.read(image);

			cvtColor(image, image, CV_BGR2GRAY);

			//if (!capture.read(image))break;

			add(image / cnt, background * (cnt - 1) / cnt, background);
			cnt++;
			i++;

			waitKey(33);

			if (i == 9) {
				imwrite("background.jpg", background);
				imshow("background", background);
			}
		}

		if (capture.grab() == 0) break;
		capture.retrieve(image);

		//capture >> image;
		image.copyTo(gray);
		cvtColor(image, gray, CV_BGR2GRAY);

		//resize(image, gray, Size(640, 480));
		//if (foregroundMask.empty())
		//foregroundMask.create(image.size(), image.type());

		//bg_model->apply(image, foregroundMask);

		absdiff(background, gray, foregroundMask);
		threshold(foregroundMask, foregroundMask, 20, 255, CV_THRESH_BINARY);
		//GaussianBlur(foregroundMask, foregroundMask, Size(7, 7), 3.5, 3.5);
		//foregroundImg = Scalar::all(0);
		//image.copyTo(foregroundImg, foregroundMask);
		//bg_model->getBackgroundImage(backgroundImg);

		foregroundMask.copyTo(foregroundImg);
		gray.copyTo(foregroundImg, foregroundMask);
		morphologyEx(foregroundImg, foregroundImg, MORPH_CLOSE, element);
		findContours(foregroundImg, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);

		vector<Rect> boundRect(contours.size());
		int contourSize = 0;

		for (int i = 0; i < contours.size(); i++) {
			if (contourArea(contours[i]) > 400) {
				boundRect[i] = boundingRect(Mat(contours[i]));
				contourSize++;
			}
		}
			for (int i = 0; i < contours.size(); i++){
		
					rectangle(image, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 0, 255), 2, 8, 0);
					putText(image, format("Object count: %d", contourSize), Point(50, 80), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255), 4);
				//imshow("countours", image);
			}

		imshow("background image", background);
		imshow("Result(x,y) video", foregroundMask);
		imshow("Result(x,y) video2", foregroundImg); //wasn't sure which of the two was needed for 2nd window.
		imshow("Result video (with rectangles and text)", image);


		waitKey(33);

	}
}
*/