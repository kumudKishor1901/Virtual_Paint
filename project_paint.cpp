#include<iostream>
#include<opencv2/highgui.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/imgproc.hpp>
using namespace std;
using namespace cv;

vector<vector<int>> mycolors = { {104,133,62,128,255,255} };
vector<Scalar> colors = { {255,0,0} };
Mat img;
vector<vector<int>> newPoints;// {{x,y,index of colors}}

//int hmin, smin, vmin, hmax, smax, vmax;

Point getContours(Mat mask) {
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	findContours(mask, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	vector<vector<Point>> cornerPoint(contours.size());
	vector<Rect> boundRect(contours.size());
	Point myPoints(0, 0);
	for (int i = 0; i < contours.size(); i++) {
		int area = contourArea(contours[i]);
		cout << area << endl;
		
		if (area > 500) {
			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], cornerPoint[i], 0.02 * peri, true);
			boundRect[i] = boundingRect(cornerPoint[i]);
			drawContours(img, cornerPoint, i, Scalar(250, 0, 250), 2);
		
				myPoints.x = boundRect[i].x + boundRect[i].width / 2;
				myPoints.y = boundRect[i].y;
			
			
		}
	}
	return myPoints;
}

void drawOnCanvas(vector<vector<int>> newPoints) {
	for (int i = 0; i < newPoints.size(); i++) {
		circle(img, Point(newPoints[i][0], newPoints[i][1]), 10, colors[newPoints[i][2]], FILLED);
	}
}
vector<vector<int>> findColor(Mat img) {
	Mat imgHsv;
	
	cvtColor(img, imgHsv, COLOR_BGR2HSV);
	for (int i = 0; i < mycolors.size(); i++) {
		Scalar lower(mycolors[i][0], mycolors[i][1], mycolors[i][2]);
		Scalar upper(mycolors[i][3], mycolors[i][4], mycolors[i][5]);
		Mat mask;
		inRange(imgHsv, lower, upper, mask);
		imshow(to_string(i), mask);
		Point myPoints = getContours(mask);
		if (myPoints.x != 0 && myPoints.y != 0) {
			newPoints.push_back({ myPoints.x,myPoints.y,i });
		}


	}
	return newPoints;
	
	
}

/* */

int main() {
	
	VideoCapture cap(1);
	

	while (true) {
		cap.read(img);
		vector<vector<int>> newPoints = findColor(img);
		drawOnCanvas(newPoints);
		imshow("img",img);
		waitKey(1);
	}

	return 0;
}
