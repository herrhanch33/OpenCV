/*
//Homework 4 21701062 Chang Hee Han Histogram program
#include "cv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

Mat drawHistogram(Mat src) {

	//Matrix arrays for drawing histogram
	Mat hist, histImage;

	//Establish the number of bins and histogram background
	int i, hist_w, hist_h, bin_w, histSize;
	float range[] = { 0, 256 };
	const float* histRange = { range };

	hist_w = 512;
	hist_h = 512;
	histSize = 16;
	bin_w = cvRound((double)hist_w / histSize);

	//Bin value of 8 for computing values of components
	int histSize1 = 8;
	Mat value;

	//draw the histogram
	histImage = Mat(hist_h, hist_w, CV_8UC3, Scalar(255, 255, 255));

	// compute the histogram
	// &src: input image, 1: #of src image, 0: #of channels numerated from 0 ~ channels()-1, Mat(): optional mask
	// hist: output histogram, 1: histogram dimension, &histSize: array of histogram size, &histRange: array of histogram's boundaries
	calcHist(&src, 1, 0, Mat(), hist, 1, &histSize, &histRange);

	// Fit the histogram to [0, histImage.rows]
	// hist: input Mat, hist: output Mat, 0: lower range boundary of range normalization, histImage.rows: upper range boundary
	// NORM_MINMAX: normalization type, -1: when negative, the output array has the same type as src, Mat(): optional mask

	//Compute the value of each component of a normalized histogram of the input image; write all values on the input image and display results
	calcHist(&src, 1, 0, Mat(), value, 1, &histSize1, &histRange);

	//Total pixel value
	float pixels = src.total();

	//Vector to copy computed Mat value
	vector<double> vec;
	value.copyTo(vec);

	//Variable to calculate value of each component
	float actval = 0;

	//Count variable j
	int j = 1;
	
	//For loop using converted vector value to calculate and display value of each component of normalized histogram
	for (float i : vec) {
		
		float actval = i / pixels;
		//cout << actval << endl;

		putText(src, "Bin" + to_string(j) + " : " + to_string(actval), Point(0, (j) * 30), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 0), 2, 4);
		j++;
	}

	//Normalize and draw histogram
	normalize(hist, hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

	//cout << hist << endl;

	for (i = 0; i < histSize; i++)
	{
		rectangle(histImage, Point(bin_w * i, hist_h), Point(bin_w * i + hist_w / histSize, hist_h - cvRound(hist.at<float>(i))), Scalar(0, 0, 0), -1);

	}
	return histImage;
}

int main() {
	//Original, equalized, and histogram images
	Mat image, hist_equalized_image, hist_graph, hist_equalized_graph, value_graph;

	//Read original image as grayscale image
	image = imread("moon.png", 0);
	if (!image.data) { exit(1); } //Check if input image file is there

	equalizeHist(image, hist_equalized_image); //Histogram Equalized Image

	//Draw histogram for original and equalized image
	hist_graph = drawHistogram(image);
	hist_equalized_graph = drawHistogram(hist_equalized_image);

	//Display images
	imshow("before", image);
	imshow("after", hist_equalized_image);
	imshow("h1", hist_graph);
	imshow("h2", hist_equalized_graph);
	
	waitKey(0);
	return 0;
}
*/