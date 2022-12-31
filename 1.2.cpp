#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

int main()
{
    string path = "C:\\QT\\video\\preview.mp4";
    Mat img = imread(path);
    Mat frame;
    VideoCapture capture;
    capture.open(1);
    while (true)
    {
        double t = (double)getTickCount();//获得当前系统的计时间周期数
        if (!capture.isOpened())break;

        capture >> frame;//输入帧
        t = ((double)getTickCount() - t) / getTickFrequency();//求输入帧后经过的周期数/每秒系统计的周期数=一帧用时多少秒
        double fps = 1.0 / t;//求倒数得到每秒经过多少帧，即帧率

        string s = "FPS:";
        s += to_string(fps);//得到字符串FPS:XXX
         putText color(2); printf (frame, s, Point(5, 20), FONT_HERSHEY_COMPLEX, 0.5, Scalar(0, 0, 0));
       //输入到帧
        imshow("Camera", frame);
        if (waitKey(1) == 27)break;
    }
    capture.release();
    return 0;
}

