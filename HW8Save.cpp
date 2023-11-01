/*
#include <iostream>
#include "cv.hpp"

using namespace std;
using namespace cv;

void getAverage() {

	Mat frame, background, avg, gray, image;
	VideoCapture capture("background.mp4");

	int cnt = 10;
	int i = 0;

	capture >> frame;
	cvtColor(frame, gray, CV_BGR2GRAY);

	while (true) {

		capture.read(image);

		cvtColor(image, image, CV_BGR2GRAY);

		//if (!capture.read(image))break;

		add(image / cnt, gray * (cnt - 1) / cnt, gray);

		//imshow("gray", gray);
		//imshow("original", frame);
		if (i == 9) {
			imwrite("background.jpg", gray);
		}
		cnt++;
		i++;

		waitKey(33);
	}

}

void generateBinary() {
	Mat background, image, gray, result, foregroundMask, foregroundImg;

	VideoCapture capture("background.mp4");

	capture >> background;
	cvtColor(background, background, CV_BGR2GRAY);

	while (true) {
		if (capture.grab() == 0) break;
		capture.retrieve(image);
		cvtColor(image, gray, CV_BGR2GRAY);

		absdiff(background, gray, foregroundMask);
		threshold(foregroundMask, foregroundMask, 20, 255, CV_THRESH_BINARY);
		foregroundMask.copyTo(foregroundImg);
		gray.copyTo(foregroundImg, foregroundMask);

		//imshow("foregroundImg", foregroundImg);
		imshow("foregroundMask", foregroundMask);
		//imshow("background", background);

		waitKey(33);
	}
}
void drawBoundRect() {
	Mat gray = imread("background.jpg", 0);
	Mat result;
	threshold(gray, result, 180, 255, THRESH_BINARY_INV);
	vector <vector<Point>> contours;
	vector <Vec4i> hierarchy;
	findContours(result, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);

	putText(result, format("contour count: %d", contours.size()), Point(50, 80), FONT_HERSHEY_SIMPLEX, 1, Scalar(128), 4);

	vector<Rect> boundRect(contours.size());
	for (int i = 0; i < contours.size(); i++) {
		boundRect[i] = boundingRect(Mat(contours[i]));

		for (int i = 0; i < contours.size(); i++)
			rectangle(result, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 0, 255), 2, 8, 0);
		imshow("countours", result);
		waitKey(0);
	}
}
int main() {
	Mat backgroundImg;

	getAverage();
	backgroundImg = imread("background.jpg");
	imshow("background", backgroundImg);
	//generateBinary();
	drawBoundRect();

}
*/