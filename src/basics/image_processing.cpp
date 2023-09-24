#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
#include <string>



int main() {

    std::string path{"assets/j4.jpg"};

    // load image as matrix
    cv::Mat img = cv::imread(path);
    cv::Mat img_gray, img_canny, img_dilate, img_erode;

    // create gray copy
    cv::cvtColor(img, img_gray, cv::COLOR_BGR2GRAY);

    // add blur to image, kernel size 7x7
    cv::GaussianBlur(img, img, cv::Size(5, 5), 5, 0);

    // edge detector
    cv::Canny(img, img_canny, 50, 150);

    // dilation and erodion
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
    cv::dilate(img_canny, img_dilate, kernel);
    cv::erode(img_dilate, img_erode, kernel);

    // display
    cv::imshow("Img", img);
    cv::imshow("ImgGray", img_gray);
    cv::imshow("Edges", img_canny);
    cv::imshow("Dilation", img_dilate);
    cv::imshow("Erodion", img_erode);
    cv::waitKey(0);

}