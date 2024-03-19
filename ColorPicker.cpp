#include<iostream>
#include<opencv2/highgui.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int hmin = 0, smin = 0, vmin = 0;
int hmax = 179, smax = 255, vmax = 255;
int main() {
	Mat img,mask,imgHsv;
	VideoCapture cap(1);
	namedWindow("Trackbars", (512, 512));
	createTrackbar("Hue min", "Trackbars", &hmin, 179);
	createTrackbar("Hue max", "Trackbars", &hmax, 179);
	createTrackbar("Sat min", "Trackbars", &smin, 255);
	createTrackbar("Sat max", "Trackbars", &smax, 255);
	createTrackbar("Val min", "Trackbars", &vmin, 255);
	createTrackbar("Val max", "Trackbars", &vmax, 255);
	//88,83,22,168,233,255
	
	while (true) {
		cap.read(img);
		cvtColor(img, imgHsv, COLOR_BGR2HSV);
		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);
		inRange(imgHsv, lower, upper, mask);
		cout << hmin << "," << smin << "," << vmin << "," << hmax << "," << smax << "," << vmax << endl;

		imshow("mask", mask);
		imshow("img", img);
		waitKey(10);
	}
}