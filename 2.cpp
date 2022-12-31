#include <QCoreApplication>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <QDebug>
#include <vector>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;


const int g_nManAlphaValue = 100; //Alpha值的最大值
int g_nAlphaValueSlider;//滑动条对应的变量
double g_dAlphaValue;
double g_dBetaValue;

Mat g_srcImage1;
Mat g_srcImage2;
Mat g_dstImage;




void on_Trackbar(int, void*) {
    //求出当前alpha值相对于最大值的比例
    g_dAlphaValue = (double)g_nAlphaValueSlider / g_nManAlphaValue;
    //则beta值为1减去alpha的值
    g_dBetaValue = (1.0 - g_dAlphaValue);

    //根据alpha和beta值进行线性混合
    addWeighted(g_srcImage1, g_dAlphaValue, g_srcImage2, g_dBetaValue, 0.0, g_dstImage);

    //显示效果图
    imshow("tiaojie", g_dstImage);
}

int main(int argc, char** argv)
{
    //加载图像
    g_srcImage2 = imread("RM.jpg");
    if (!g_srcImage1.data){
        return -1;
    }
    if (!g_srcImage2.data) {
        return -1;
    }
    //设置滑动条初始值为70
    g_nAlphaValueSlider = 100;

    //创建窗体
    namedWindow("hsv调节", WINDOW_NORMAL);

    //在创建的窗体中创建一个滑动条控件
    char TrackbarName[50] = "透明值 100";
    //sprintf(TrackbarName, "透明值 %d", g_nManAlphaValue);

    createTrackbar("h-max","h-min","s-max","s-min","v-max","v-min");
    waitKey(0);

    return 0;

}
