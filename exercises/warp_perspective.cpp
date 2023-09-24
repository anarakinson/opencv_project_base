#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
#include <string>



int main() {

    std::string path{"assets/j4.jpg"};

    // load image as matrix
    cv::Mat img = cv::imread(path);
    cv::Mat matrix, img_warped;

    float w = 200;
    float h = 255;

    cv::Point2f src[4] = { {112, 139}, {251, 141}, {157, 214}, {302, 214} };
    cv::Point2f dst[4] = { {0, 0}, {w, 0}, {0, h}, {w, h} };

    matrix = cv::getPerspectiveTransform(src, dst);
    cv::warpPerspective(img, img_warped, matrix, cv::Point(w, h));

    for (int i = 0; i < 4; ++i) {
        cv::circle(img, src[i], 5, cv::Scalar(0, 0, 255), cv::FILLED);
    }

    // display
    cv::imshow("Img", img);
    cv::imshow("Img warped", img_warped);
    cv::waitKey(0);

}