/*
//HW9 21701062 Chang Hee Han
#include <iostream>
#include "cv.hpp"

using namespace std;
using namespace cv;

//1280 * 720 contourArea face direction haarscascade 

// b = 98, f = 102, g = 103;

int main() {

	Mat image, foregroundMask, backgroundImg, foregroundImg, element, grayImage, anotherImage;

	VideoCapture cap("Faces.mp4");

	Ptr<BackgroundSubtractor> bg_model = createBackgroundSubtractorMOG2();

	vector <vector<Point>> contours;
	vector <Vec4i> hierarchy;
	vector<Rect> faces;
	CascadeClassifier face_classifier;

	element = getStructuringElement(MORPH_ELLIPSE, Size(1.5, 1.5));

	bool part1 = true, part2 = true, part3 = true;
	int trigger = 0, trigger2 = 0, trigger3 = 0;

	face_classifier.load("haarcascade_frontalface_alt.xml");

	while (true) {

		cap >> image;

		resize(image, image, Size(640, 480));

		if (!cap.read(image)) { break; }

		int key = waitKey(33);

		if (key == 98 || key == 'b') {
			++trigger;
			if (trigger % 2 == 1) {
				part1 = false;
			}
			if (trigger % 2 == 0) {
				part1 = true;
			}
		}
		if (key == 102 || key == 'f') {
			++trigger2;
			if (trigger2 % 2 == 1) {
				part2 = false;
			}
			if (trigger2 % 2 == 0) {
				part2 = true;
			}
		}
		if (key == 103 || key == 'g') {
			++trigger3;
			if (trigger3 % 2 == 1) {
				part3 = false;
			}
			if (trigger3 % 2 == 0) {
				part3 = true;
			}
		}
		if (key == 27 || key == 'esc') {
			break;
		}

		if (part1 == true && part2 == true && part3 == true) {
			imshow("Output", image);
		}
		if (part1 == false) {
			resize(image, image, Size(640, 480));
			if (foregroundMask.empty())
				foregroundMask.create(image.size(), image.type());

			bg_model->apply(image, foregroundMask);
			GaussianBlur(foregroundMask, foregroundMask, Size(7, 7), 3.5, 3.5);
			threshold(foregroundMask, foregroundMask, 5, 255, THRESH_BINARY);
			foregroundImg = Scalar::all(0);
			image.copyTo(foregroundImg, foregroundMask);

			morphologyEx(foregroundImg, foregroundImg, MORPH_CLOSE, element);
			findContours(foregroundMask, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);

			int contourSize = 0;
			for (int i = 0; i < contours.size(); i++) {
				if (contourArea(contours[i]) > 4000 && contourArea(contours[i]) < 25600) {
					contourSize++;
					//cout << contourSize;
				}
			}
			putText(foregroundImg, format("There are: %d people.", contourSize), Point(50, 80), FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 255, 255), 4);
			imshow("Output", foregroundImg);
		}

		if (part2 == false) {
			
			image.copyTo(anotherImage);

			resize(anotherImage, anotherImage, Size(640, 480));

			int i;
			cvtColor(anotherImage, grayImage, COLOR_BGR2GRAY);

			face_classifier.detectMultiScale(
				grayImage, faces, 1.2, 3, 0, Size(20, 20)
			);

			Rect farRect;
			Rect nearRect(0, 0, 600, 600);

			for (i = 0; i < faces.size(); i++) {
				if (faces[i].area() > farRect.area()) { farRect = faces[i]; }
				if (faces[i].area() < nearRect.area()) { nearRect = faces[i]; }
			}

			for(i = 0; i < faces.size(); i++){

				Point tr(faces[i].x + faces[i].width, faces[i].y);
				Point lb(faces[i].x, faces[i].y+faces[i].height);
				rectangle(anotherImage, tr, lb, Scalar(0, 255, 255), 3, 4, 0);
				Point farlb(farRect.x, farRect.y + farRect.height);

				Point fartr(farRect.x+farRect.width, farRect.y);
				rectangle(anotherImage, fartr, farlb, Scalar(0, 255, 0), 3, 4, 0);
				Point nearlb(nearRect.x, nearRect.y + nearRect.height);

				Point neartr(nearRect.x+nearRect.width, nearRect.y);
				rectangle(anotherImage, neartr, nearlb, Scalar(255, 0, 0), 3, 4, 0);
			}
			imshow("Output", anotherImage);
		}

		if (part3 == false) {
			Mat lastImage, bgModel, fgModel, foreground, final1, final2, final3, grayLastimg;
			
			image.copyTo(lastImage);
			resize(lastImage, lastImage, Size(640, 480));

			cvtColor(lastImage, grayLastimg, COLOR_BGR2GRAY);
			face_classifier.detectMultiScale(grayLastimg, faces, 1.1, 3, 0, Size(10, 10));

			for (int i = 0; i < faces.size(); i++) {
				Point lbot(faces[i].x, faces[i].y + faces[i].height);
				Point rtop(faces[i].x + faces[i].width, faces[i].y);
				if (i == 0) { Rect facecut1(lbot, rtop); 
				grabCut(lastImage, final1, facecut1, bgModel, fgModel, 1, GC_INIT_WITH_RECT);
				compare(final1, GC_PR_FGD, final1, CMP_EQ);
				}
				if (i == 1) { Rect facecut2(lbot, rtop); 
				grabCut(lastImage, final2, facecut2, bgModel, fgModel, 1, GC_INIT_WITH_RECT);
				compare(final2, GC_PR_FGD, final2, CMP_EQ);
				}
				if (i == 2) { Rect facecut3(lbot, rtop); 
				grabCut(lastImage, final3, facecut3, bgModel, fgModel, 1, GC_INIT_WITH_RECT);}
				compare(final3, GC_PR_FGD, final3, CMP_EQ);
			}

			//Point lbot1(faces[0].x, faces[0].y + faces[0].height);
			//Point rtop1(faces[0].x + faces[0].width, faces[0].y);
			//Rect facecut1(lbot1, rtop1);

			//Point lbot2(faces[1].x, faces[1].y + faces[1].height);
			//Point rtop2(faces[1].x + faces[1].width, faces[1].y);
			//Rect facecut2(lbot2, rtop2);

			//Point lbot3(faces[2].x, faces[2].y + faces[2].height);
			//Point rtop3(faces[2].x + faces[2].width, faces[2].y);
			//Rect facecut3(lbot3, rtop3);

			//foreground = Mat(lastImage.size(), CV_8UC3, Scalar(255, 255, 255));
			Mat back = imread("nightsky.jpg");
			resize(back, back, Size(640, 480));
			lastImage.copyTo(back, final1);
			lastImage.copyTo(back, final2);
			lastImage.copyTo(back, final3);

			//imshow("original", image);
			imshow("Output", back);
			//imshow("Foreground", foreground);
			

		}
		waitKey(33);


		}
	}
	*/
	
