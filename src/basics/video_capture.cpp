#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
#include <string>
#include <map>



int main(int argc, char **argv) {

    // open mp4 video
    // std::string path{"assets/opossum.mp4"};
    // cv::VideoCapture cap{path};
    // int waitkey = 5
    
    // parse args
    int cam_id = -1;
    int rotation = 0;
    std::map<int, cv::RotateFlags> rotation_map{
        {90, cv::ROTATE_90_CLOCKWISE},
        {180, cv::ROTATE_180},
        {270, cv::ROTATE_90_COUNTERCLOCKWISE},
    };
    std::map<std::string, int> flip_map{
        {"y", 0},
        {"x", 1},
        {"xy", -1},
    };

    std::string flip = "";

    std::cout << "USAGE: \n" 
              << "app <camera id> <rotation: ( 0 | 90 | 180 | 270 )> <flip: ( x | y | xy )>"
              << std::endl;
    if (argc > 1) {
        cam_id = std::atoi(argv[1]);
    } if (argc > 2) {
        rotation = std::atoi(argv[2]);
    } if (argc > 3) {
        flip = std::string(argv[3]);
    }

    // check arguments
    if (rotation != 0 && rotation != 90 && rotation != 180 && rotation != 270) {
        std::cerr << "ERROR: wrong rotation argument\n";
        return 1;
    }
    if (flip != "" && flip != "x" && flip != "y" && flip != "xy") {
        std::cerr << "ERROR: wrong flip argument\n";
        return 1;
    }
    std::cout << "Using camera: " << cam_id 
              << "\nRotation: " << rotation 
              << "\nFlip: " << flip << std::endl;

    // catch wideo from web camera 
    cv::VideoCapture cap{cam_id};
    int waitkey = 1;
    
    cv::Mat img;

    while (cap.isOpened()) {

        cap.read(img);
        if (rotation != 0) {
            cv::rotate(img, img, rotation_map[rotation]); 
        }
        if (flip != "") {
            cv::flip(img, img, flip_map[flip]); // 0 - y axis, 1 - x axis, -1 - both axis
        }

        cv::imshow("Img", img);

        int k = cv::waitKey(waitkey);
        if (k == 'q') {
            break;
        }

    }

    cap.release();
    cv::destroyAllWindows ();

}