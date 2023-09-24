#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
#include <string>



int main() {

    // create blank matrix (w, h, type, color)
    cv::Mat img{512, 512, CV_8UC3, cv::Scalar(123, 123, 123)}; // CV_8UC3 - 8 bit, unsigned, 3 channels, BGR

    // draw circle
    cv::circle(img, cv::Point(256, 256), 155, cv::Scalar(0, 20, 255), cv::FILLED); // center, radius, color, thickness (int or type)
    // draw rectangle
    cv::rectangle(img, cv::Point(130, 226), cv::Point(382, 286), cv::Scalar(255, 255, 255), cv::FILLED); // (x, y), (w, h), color, thickness
    // draw line
    cv::line(img, cv::Point(140, 280), cv::Point(372, 280), cv::Scalar(25, 25, 25), 2); // start, end, color, thickness

    // add text
    std::string text{"Welcome out!"};
    cv::putText(img, text, cv::Point(137, 262), cv::FONT_HERSHEY_DUPLEX, 1.1, cv::Scalar(255, 50, 0), 2); // text, (x, y), font, size, color, thickness


    // display
    cv::imshow("Img", img);
    cv::waitKey(0);

}