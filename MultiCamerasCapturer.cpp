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

    // 判断文件夹是否存在
    filesystem::path save(save_dir);
    if (!filesystem::exists(save)) {
        filesystem::create_directories(save);
    }

    Mat frame;
    timespec tn;
    int cnt = 1;
    while (vc.read(frame)) {
        clock_gettime(CLOCK_REALTIME, &tn);
        imshow(save_dir, frame);
        cnt += 1;
        if (cnt % wait_time == 0) {
            string file_name = to_string(tn.tv_sec * 1000000000 + tn.tv_nsec) + ".png";
            imwrite(save_dir + file_name, frame);
            cnt = 1;
        }
        char c = (char) waitKey(1);
        if (c == 27 || c == 'q' || c == 'Q') {
            waitKey(10);
            break;
        }
    }
}