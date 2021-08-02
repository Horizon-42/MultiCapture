#include <iostream>
#include "MultiCamerasCapturer.h"
#include <thread>

int main() {
    string rtsp1 = "rtsp://admin:horizon@1234@192.168.3.127";
    string save1 = "/home/horizon/CLionProjects/MultiCapture/data/cam127/";
    string rtsp2 = "rtsp://admin:qwer1234@192.168.3.129";
    string save2 = "/home/horizon/CLionProjects/MultiCapture/data/cam129/";
    string rtsp3 = "rtsp://admin:horizon@1234@192.168.3.134";
    string save3 = "/home/horizon/CLionProjects/MultiCapture/data/cam134/";
    string rtsp4 = "rtsp://admin:horizon@1234@192.168.3.130";
    string save4 = "/home/horizon/CLionProjects/MultiCapture/data/cam130/";
    int step_frame = 5;
//    std::thread c127(CaptureRtsp, rtsp1, save1, step_frame);
    std::thread c129(CaptureRtsp, rtsp2, save2, step_frame);
    std::thread c134(CaptureRtsp, rtsp3, save3, step_frame);
//    std::thread c130(CaptureRtsp, rtsp4, save4, step_frame);
//    c127.detach();
    c129.detach();
    c134.join();
//    c130.join();
    pthread_exit(NULL);
    return 0;
}
