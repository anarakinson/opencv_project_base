#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>

#include <iostream>
#include <string>



int main() {

    // catch wideo from web camera 
    cv::VideoCapture cap{0}; 
    cv::Mat img;
    
    // create classifier
    cv::CascadeClassifier face_detector;
    face_detector.load("OpenCV_cascades/haarcascades/haarcascade_frontalface_default.xml");
    if (face_detector.empty()) {
        std::cout << "XML file not loaded" << std::endl;
        return 1;
    }
    
    // vector to store detected objects
    std::vector<cv::Rect> detected{};

    while (cap.isOpened()) {

        cap.read(img);
        cv::flip(img, img, 1); // 0 - y axis, 1 - x axis, -1 - both axis

        // detect
        face_detector.detectMultiScale(img, detected, 1.1, 10);  // scale factor, min neighbors

        // draw bboxes 
        for (int i = 0; i < detected.size(); ++i) {
            cv::rectangle(img, detected[i].tl(), detected[i].br(), cv::Scalar(0, 255, 0), 2);
        }

        // display
        cv::imshow("Img", img);

        int k = cv::waitKey(1);
        if (k == 'q') {
            break;
        }
        std::cout << detected.size() << std::endl;

    }

    cap.release();
    cv::destroyAllWindows ();

}