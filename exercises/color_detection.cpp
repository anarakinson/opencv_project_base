#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
#include <string>



int main() {

    std::string path{"assets/j4.jpg"};

    // load image as matrix
    cv::Mat img = cv::imread(path);
    cv::Mat img_hsv, mask;
    
    cv::cvtColor(img, img_hsv, cv::COLOR_BGR2HSV);

    // create UI
    int hmin{}, smin{}, vmin{};
    int hmax{255}, smax{255}, vmax{255};
    // add UI window
    cv::namedWindow("Track bars", cv::WINDOW_NORMAL);
    // resize window
    cv::resizeWindow("Track bars", 460, 80);
    // add bars
    cv::createTrackbar("Hue min", "Track bars", &hmin, 179);
    cv::createTrackbar("Hue max", "Track bars", &hmax, 179);
    cv::createTrackbar("Sat min", "Track bars", &smin, 255);
    cv::createTrackbar("Sat max", "Track bars", &smax, 255);
    cv::createTrackbar("Val min", "Track bars", &vmin, 255);
    cv::createTrackbar("Val max", "Track bars", &vmax, 255);

    while (true) {
    
        // set color search parameters
        cv::Scalar lower(hmin, smin, vmin);
        cv::Scalar upper(hmax, smax, vmax);
        cv::inRange(img_hsv, lower, upper, mask);

        // display
        cv::imshow("Img", img);
        cv::imshow("Img HSV", img_hsv);
        cv::imshow("Img mask", mask);
        int k = cv::waitKey(1);

        if (k == 'q') {
            break;
        }

    }

    cv::destroyAllWindows ();

}