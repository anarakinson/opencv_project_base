#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
#include <string>



int main() {

    // open mp4 video
    // std::string path{"assets/opossum.mp4"};
    // cv::VideoCapture cap{path};
    // int waitkey = 5
    
    // catch wideo from web camera 
    cv::VideoCapture cap{0};
    int waitkey = 1;
    
    cv::Mat img;

    while (cap.isOpened()) {

        cap.read(img);
        cv::flip(img, img, 1); // 0 - y axis, 1 - x axis, -1 - both axis
        cv::imshow("Img", img);

        int k = cv::waitKey(waitkey);
        if (k == 'q') {
            break;
        }

    }

    cap.release();
    cv::destroyAllWindows ();

}