#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
#include <string>



int main() {

    std::string path{"assets/j4.jpg"};

    // load image as matrix
    cv::Mat img = cv::imread(path);
    cv::Mat img_resized, img_scaled, img_cropped;

    // resized copy
    cv::resize(img, img_resized, cv::Size(600, 600)); 
    cv::resize(img, img_scaled, cv::Size(), 0.75, 0.75); 

    // crop image (x, y, w, h)
    cv::Rect roi(50, 50, 250, 250);
    img_cropped = img(roi);

    // display
    std::string Image_name{"Img"};
    std::string Image_resized_name{"Img resized"};
    std::string Image_scaled_name{"Img scaled"};
    // add sizes to title ("Title - XxY")
    Image_name         += " - " + std::to_string(img.size().width)         + "x" + std::to_string(img.size().height);
    Image_resized_name += " - " + std::to_string(img_resized.size().width) + "x" + std::to_string(img_resized.size().height);
    Image_scaled_name  += " - " + std::to_string(img_scaled.size().width)  + "x" + std::to_string(img_scaled.size().height);

    cv::imshow(Image_name, img);
    cv::imshow(Image_resized_name, img_resized);
    cv::imshow(Image_scaled_name, img_scaled);
    cv::imshow("Image cropped", img_cropped);
    cv::waitKey(0);

}