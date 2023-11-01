/*
#include "cv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat gray_image, negative_image, log_image, gamma_image; //mat is array of pixels. color and properties.

	gray_image = imread("barcode.jpg", 0); //Original Image

	//Negative Image
	negative_image = 255 - gray_image.clone(); 

	//Log Image
	double c = 1.5f; //f gives more decimal places

	gray_image.clone().convertTo(log_image, CV_32F);

	log_image = abs(log_image) + 1; // or abs(log_image+1);

	log(log_image, log_image);

	normalize(log_image, log_image, 0, 255, NORM_MINMAX);

	convertScaleAbs(log_image, log_image, c); //convert to unsigned 8-bit

	//Gamma Image
	MatIterator_<uchar> it, end;
	unsigned char pix[256];

	float gamma = 0.5;
	
	for (int i = 0; i < 256; i++) {
		pix[i] = saturate_cast<uchar>(pow((float)(i / 255.0), gamma) * 255.0f);
	}

	gamma_image = gray_image.clone();

	for (it = gamma_image.begin<uchar>(), end = gamma_image.end<uchar>(); it != end; it++) {
		*it = pix[(*it)];
	}

	imshow("gray image", gray_image);
	imshow("negative image", negative_image);
	imshow("log image", log_image);
	imshow("gamma image", gamma_image);

	waitKey(0);

	destroyAllWindows();

	return 0;
}


/*
	gamma_image = gray_image.clone();

	

	gamma_image.convertTo(gamma_image, CV_32F);

	normalize(gamma_image, gamma_image, 0, 1.0, NORM_MINMAX); // do it at the beginning and turn it back to 255. Convert it to float and normalize it to 1 and do the calculation. Normalize back to 255 and use unsigned character.

	pow(gamma_image, gamma, gamma_image);

	normalize(gamma_image, gamma_image, 0, 255, NORM_MINMAX);

	convertScaleAbs(gamma_image, gamma_image, 1);
	*/
