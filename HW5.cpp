/*
//21701062 Chang Hee Han HW5 Program
#include "cv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

//Negative Transformation
Mat negImger(Mat src) {
	Mat negImged, mergImg;
	Mat bgr[3];
	negImged = src.clone();
	split(negImged, bgr);

	for (int k = 0; k < 3; k++)
	for (int i = 0; i < src.rows; i++)
		for (int j = 0; j < src.cols; j++)
			bgr[k].at<uchar>(i, j) = 255 - bgr[k].at<uchar>(i, j);

	merge(bgr, 3, mergImg);

	return mergImg;
}

//Gamma Image
Mat gammaImger(Mat src) {

	Mat gammaImged, mergImg;
	Mat bgr[3];

	float gamma = 2.5;

	MatIterator_<uchar> it, end;
	unsigned char pix[3][256];

	for (int k = 0; k < 3; k++) {
	for (int i = 0; i < 256; ++i) {
		pix[k][i] = saturate_cast<uchar>(pow((float)(i / 255.0), gamma) * 255.0f);
	}
}
	gammaImged = src.clone();
	split(gammaImged, bgr);

	for (int k = 0; k < 3; k++) {
		for (it = bgr[k].begin<uchar>(), end = bgr[k].end<uchar>(); it != end; ++it) {
			*it = pix[k][(*it)];
		}
	}
	merge(bgr, 3, mergImg);
	
	return mergImg;
}

Mat histImger(Mat src) {
	Mat histImged, mergImg;
	Mat bgr[3];
	histImged = src.clone();
	//vector<Mat> channels;
	//cvtColor(src, histImged, CV_BGR2HSV);
	split(histImged, bgr);
	for (int k = 0; k < 3; k++) {
		equalizeHist(bgr[k], bgr[k]);
	}
	//equalizeHist(channels[0], channels[0]);
	merge(bgr, 3, mergImg);
	//cvtColor(histImged, histImged, CV_BGR2HSV);

	return mergImg;
}

Mat colorSpliter(Mat src) {

	Mat HSV;
	vector<Mat> mo(3);
	//mo(0) = Hue, mo(1) = Saturation, mo(2) = Intensity/Value

	int rows = src.rows;
	int cols = src.cols;
	uchar* h;
	uchar* s;
	uchar* v;

	cvtColor(src, HSV, CV_BGR2HSV);
	split(HSV, mo);

	for (int j = 0; j < rows; j++) {
		h = mo[0].ptr<uchar>(j);
		s = mo[1].ptr<uchar>(j);
		for (int i = 0; i < cols; i++) {
			if (h[i] > 9 && h[i] < 23) s[i] = s[i];
			else s[i] = 0;
		}
		
	}
	merge(mo, HSV);
	cvtColor(HSV, HSV, CV_HSV2BGR);

	return HSV;

}

Mat colorConverter(Mat src) {
	Mat changecolor;
	vector<Mat>cc(3); //CC+ Color Change / Color Conversion

	int rows = src.rows;
	int cols = src.cols;
	uchar* h;
	uchar* s;
	uchar* v;

	cvtColor(src, changecolor, CV_BGR2HSV);
	split(changecolor, cc);

	for (int j = 0; j < rows; j++) {
		h = cc[0].ptr<uchar>(j);
		s = cc[1].ptr<uchar>(j);
		for (int i = 0; i < cols; i++) {
			if (h[i] +50 > 179) h[i] = h[i]+50 - 179;
			else h[i] += 50;
		}
		
	}
	merge(cc, changecolor);
	cvtColor(changecolor, changecolor, CV_HSV2BGR);

	return changecolor;
}

Mat blurer(Mat src) {
	Mat blurimg;

	blur(src, blurimg, Size(9, 9));

	return blurimg;

}

Mat whitebalancer(Mat src) {
	Mat balancedimg;
	balancedimg = src.clone();
	Mat bgr_channels[3];
	split(src, bgr_channels);
	
	double avg;
	int sum, temp, i, j, c;

	for (c = 0; c < src.channels(); c++) {
		sum = 0;
		avg = 0.0f;
		for (i = 0; i < src.rows; i++) {
			for (j = 0; j < src.cols; j++) {
				sum += bgr_channels[c].at<uchar>(i, j);
			}
		}
		avg = sum / (src.rows * src.cols);
		for (i = 0; i < src.rows; i++) {
			for (j = 0; j < src.cols; j++) {
				temp = (128 / avg) * bgr_channels[c].at<uchar>(i, j);
				if (temp > 255) bgr_channels[c].at<uchar>(i, j) = 255;
				else bgr_channels[c].at<uchar>(i, j) = temp;
			}
		}
	}
	merge(bgr_channels, 3, balancedimg);

	return balancedimg;

}

int main() {
	Mat image, negimg, gammaimg, colorimg, balanceimg;

	image = imread("lena.png");

	if (!image.data) exit(1);

	imshow("lena", image);

	colorimg = imread("colorful.jpg");
	if (!colorimg.data)exit(1);

	imshow("colorful", colorimg);

	balanceimg = imread("balancing.jpg");

	if (!balanceimg.data) exit(1);

	imshow("balancing", balanceimg);

	while (1) {
		int key = waitKey(30000);
		
		if (key == 110 || key == 'n' || key == 'N')
		{
			cout << "Pressed n = Negative Transformation" << endl;
			imshow("lena", negImger(image));
		}
		else if (key == 103 || key == 'g' || key == 'G') {
			cout << "Pressed g = Gamma Correction" << endl;
			imshow("lena", gammaImger(image));
			
		}
		else if (key == 104 || key == 'h' || key == 'H') {

			cout << "Pressed h = Histogram Equalization" << endl;
			imshow("lena", histImger(image));
		}
		
		else if (key == 114 || key == 'r' || key == 'R') {

			cout << "Pressed r = Reset to Original Image" << endl;
			imshow("lena", image);
			imshow("colorful", colorimg);
			imshow("balancing", balanceimg);
		}
		else if (key == 115 || key == 's' || key == 'S') {
			cout << "Pressed s = Color Slicing" << endl;
			imshow("colorful", colorSpliter(colorimg));
		}
		else if (key == 99 || key == 'c' || key == 'C') {
			cout << "Pressed c = Color Conversion" << endl;
			imshow("colorful", colorConverter(colorimg));
		}
		else if (key == 97 || key == 'a' || key == 'A') {
			cout << "Pressed a = Average Filter Blurring" << endl;
			imshow("balancing", blurer(balanceimg));
		}
		else if (key == 119 || key == 'w' || key == 'W') {
			cout << "Pressed w = White Balancing" << endl;
			imshow("balancing", whitebalancer(balanceimg));
		}

		else if (key == 27) {
			cout << "Pressed ESC = Quit the Progarm" << endl;
			break;
		}
		else if (key == -1){

		cout << "No Key Was Pressed!" << endl;
			destroyAllWindows();
			break;

		}
 	}
}
*/
