#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>

#include <iostream>
#include <string>



int main() {

    std::string path{"assets/neo.jpg"};

    // load image as matrix
    cv::Mat img = cv::imread(path); 

    if (img.empty()) {
        std::cout << "Could not read the image: " << path << std::endl;
        return 1;
    }

    // create classifier
    cv::CascadeClassifier face_detector;
    face_detector.load("OpenCV_cascades/haarcascades/haarcascade_frontalface_default.xml");
    if (face_detector.empty()) {
        std::cout << "XML file not loaded" << std::endl;
        return 1;
    }
    
    // vector to store detected objects
    std::vector<cv::Rect> detected{};
    // detect
    face_detector.detectMultiScale(img, detected, 1.1, 10);  // scale factor, min neighbors

    // draw bboxes 
    for (int i = 0; i < detected.size(); ++i) {
        cv::rectangle(img, detected[i].tl(), detected[i].br(), cv::Scalar(0, 255, 0), 2);
    }

    // display
    cv::imshow("Img", img);
    cv::waitKey(0);

}