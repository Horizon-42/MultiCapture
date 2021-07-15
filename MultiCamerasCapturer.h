//
// Created by 刘东旭 on 2021/7/15.
//

#ifndef MULTICAMERASCAPTURE_MULTICAMERASCAPTURER_H
#define MULTICAMERASCAPTURE_MULTICAMERASCAPTURER_H

#include <opencv2/opencv.hpp>
#include <string>
#include <ctime>

using namespace std;
using namespace cv;

bool CaptureRtsp(string rtsp, string save_dir, int wait_time);


#endif //MULTICAMERASCAPTURE_MULTICAMERASCAPTURER_H
