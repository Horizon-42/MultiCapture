//
// Created by 刘东旭 on 2021/7/15.
//

#include "MultiCamerasCapturer.h"

bool CaptureRtsp(string rtsp, string save_dir, int wait_time) {
    VideoCapture vc;
    if (rtsp == "")
        vc = VideoCapture(0);
    else {
        vc = VideoCapture(rtsp);
    }
    if (!vc.isOpened()) {
        cout << "camera stream cannot be open.\n";
        return false;
    }

    Mat frame;
    time_t time_stamp;
    while (vc.read(frame)) {
        time_stamp = time(NULL);
        string file_name = to_string(time_stamp) + ".png";
        imwrite(save_dir + file_name, frame);
        imshow(save_dir, frame);
        char c = (char) waitKey(wait_time);
        if (c == 27 || c == 'q' || c == 'Q')
            break;
    }
}