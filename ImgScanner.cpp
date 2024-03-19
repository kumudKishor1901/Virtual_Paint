# DONT USE THIS CODE 
#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

Mat img, imgGray, imgCanny, imgDilate, imgWarp;
vector<vector<Point>> contours;
vector<Vec4i> hierarchy;

Mat getWarpPerspective(Mat img, vector<vector<Point>> cornerPoints, vector<Rect> boundRect);
Mat getDocumentScanned(Mat imgDilate);

int main() {
    string path = "Resources/paper.jpg";
    img = imread(path);
    resize(img, img, Size(), 0.4, 0.4);
    cvtColor(img, imgGray, COLOR_BGR2GRAY);
    Canny(imgGray, imgCanny, 30, 80);
    Mat kernel = getStructuringElement(MORPH_RECT, Size(2, 2));
    dilate(imgCanny, imgDilate, kernel);
    Mat scannedImg = getDocumentScanned(imgDilate);

    imshow("img", img);
    imshow("imgCanny", imgCanny);
    imshow("imgDilate", imgDilate);
    imshow("scannedImg", scannedImg);
    waitKey(0);
}

Mat getWarpPerspective(Mat img, vector<Point> biggest) {
  

  
}

Mat getDocumentScanned(Mat imgDilate) {
    findContours(imgDilate, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
   
    vector<vector<Point>> cornerPoints(contours.size());
    vector<Point> biggest;
    int maxArea = 0;
    for (int i = 0; i < contours.size(); i++) {
     
        int area = contourArea(contours[i]);

        if (area > 1000) {
            float perimeter = arcLength(contours[i], true);
            approxPolyDP(contours[i], cornerPoints[i], 0.02 * perimeter, true);

            if (area > maxArea) {
                maxArea = area;
                biggest = { {cornerPoints[i][0]},{cornerPoints[i][1]},{cornerPoints[i][2]},{cornerPoints[i][3]}};
            }
            
        }

       
    }

    Mat scannedImg = getWarpPerspective(img, biggest);
    return scannedImg;
}
