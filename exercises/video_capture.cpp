#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
#include <string>



int main() {

    // open mp4 video
    // std::string path{"assets/opossum.mp4"};
    // cv::VideoCapture cap{path};
    
    // catch wideo from web camera 
    cv::VideoCapture cap{0};
    
    cv::Mat img;

    while(true) {

        cap.read(img);
        cv::imshow("Img", img);
        int k = cv::waitKey(1);
        
        if (k == 'q') {
            break;
        }

    }

    cap.release();
    cv::destroyAllWindows ();

}