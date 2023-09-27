#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
#include <string>



// convert to gray, blur, canny and dilate for highlight edges
cv::Mat get_edges(cv::Mat &src) {
    
    cv::Mat edges;
    cv::cvtColor(src, edges, cv::COLOR_BGR2GRAY);
    cv::GaussianBlur(edges, edges, cv::Size(3, 3), 3, 0);
    cv::Canny(edges, edges, 25, 75);

    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
    cv::dilate(edges, edges, kernel);

    return edges;

}

void get_contours(cv::Mat &img, cv::Mat &edges) {

    std::string object_type;
    std::vector<std::vector<cv::Point>> contours{};
    std::vector<cv::Vec4i> hierarchy{};

    // find contours
    cv::findContours(edges, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
    
    // vector that will primitivize contours and contain only sharp peaks
    std::vector<std::vector<cv::Point>> con_poly(contours.size());
    // vector contains bounding boxes
    std::vector<cv::Rect> bboxes(contours.size());

    for (int i = 0; i < contours.size(); ++i) {
        int area = cv::contourArea(contours[i]);

        if (area > 700) {

            // primitivize contours and get only sharp peaks
            double peri = cv::arcLength(contours[i], true);
            cv::approxPolyDP(contours[i], con_poly[i], 0.02*peri, true);

            // draw contour by peaks
            // cv::drawContours(img, con_poly, i, cv::Scalar(255, 0, 255), 2);

            // get bbox
            bboxes[i] = cv::boundingRect(con_poly[i]);
            
            // count peaks and choose shape name
            int obj_cor = static_cast<int>(con_poly[i].size());
            if (obj_cor == 3) { object_type = "triangle"; }
            else if (obj_cor == 4) { 
                float ratio = float(bboxes[i].width) / float(bboxes[i].height);
                if (ratio > 0.95 && ratio < 1.05) { object_type = "square"; }
                else { object_type = "rectangle"; } 
            }
            else if (obj_cor == 5) { object_type = "pentagone"; }
            else if (obj_cor == 6) { object_type = "hexagone"; }
            else if (obj_cor > 6) { 
                float ratio = float(bboxes[i].width) / float(bboxes[i].height);
                if (ratio > 0.95 && ratio < 1.05) { object_type = "circle"; }
                else { object_type = "other"; } 
            }

            // draw bbox and object type name
            if (object_type != "other") {
                cv::rectangle(img, bboxes[i].tl(), bboxes[i].br(), cv::Scalar(0, 255, 0), 2);
                cv::putText(img, object_type, {bboxes[i].x, bboxes[i].y - 5}, cv::FONT_HERSHEY_DUPLEX, 0.75, cv::Scalar(0, 255, 0), 2);
            }
            
        }
    }

}


int main() {

    std::string path{"assets/simple-shapes.jpg"};

    // load image as matrix
    cv::Mat img = cv::imread(path);
    
    if (img.empty()) {
        std::cout << "Could not read the image: " << path << std::endl;
        return 1;
    }

    // preprocess
    cv::Mat edges = get_edges(img);

    // find and draw contours
    get_contours(img, edges);

    // display
    cv::imshow("Img", img);
    cv::imshow("Img dilated", edges);
    cv::waitKey(0);

}
