/*
#include <iostream>
#include <sstream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/video.hpp>
using namespace cv;
using namespace std;

int main()
{
    Ptr<BackgroundSubtractor> pBackSub;
    //create Background Subtractor objects
    pBackSub = createBackgroundSubtractorKNN();

    VideoCapture capture("faces.mp4");
    Mat frame, fgMask;
    while (true) {
        capture >> frame;
        resize(frame, frame, Size(640, 480));
        if (frame.empty())
            break;
        //update the background model
        pBackSub->apply(frame, fgMask);
        //get the frame number and write it on the current frame
        rectangle(frame, cv::Point(10, 2), cv::Point(100, 20),
            cv::Scalar(255, 255, 255), -1);
        stringstream ss;
        ss << capture.get(CAP_PROP_POS_FRAMES);
        string frameNumberString = ss.str();
        putText(frame, frameNumberString.c_str(), cv::Point(15, 15),
            FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 0));
        //show the current frame and the fg masks
        imshow("Frame", frame);
        imshow("FG Mask", fgMask);
        //get the input from the keyboard
        int keyboard = waitKey(30);
        if (keyboard == 'q' || keyboard == 27)
            break;

        Mat image, foregroundMask, backgroundImg, foregroundImg, element, grayImage, anotherImage;

        vector <vector<Point>> contours;
        vector <Vec4i> hierarchy;

        findContours(fgMask, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);

        int contourSize = 0;
        for (int i = 0; i < contours.size(); i++) {
            if (contourArea(contours[i]) > 4000 && contourArea(contours[i]) < 25600) {
                contourSize++;
                //cout << contourSize;
            }
        }putText(foregroundImg, format("There are: %d people.", contourSize), Point(50, 80), FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 255, 255), 4);
    }
    return 0;
}*/