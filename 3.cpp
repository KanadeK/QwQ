#include <QCoreApplication>
#include "iostream"
#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main()
{
    string path = "C:\\QT\\img\\board.jpg";//路径
    Mat img = imread(path);//将图片加载
    imshow("Image", img);//创建窗口
    Mat imgGray,imgBlur,imgCanny,imgDil,imgErode;
    //将照片转换为灰度
    cvtColor(img, imgGray, COLOR_BGR2GRAY);
    //高斯模糊
    GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);
    //Canny边缘检测器  一般在使用Canny边缘检测器之前会做一些模糊处理
    Canny(imgBlur, imgCanny, 25, 75);
    //创建一个可以使用膨胀的内核
    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
    //图像膨胀
    dilate(imgCanny, imgDil, kernel);
    //图像侵蚀
    erode(imgDil, imgErode, kernel);
    //结果呈现
    imshow("Image", img);
    imshow("Image Gray", imgGray);
    imshow("Image Blur", imgBlur);
    imshow("Image Canny", imgCanny);
    imshow("Image Dilation", imgDil);
    imshow("Image Erode", imgErode);
    {
            cout << "could not load the images" << endl;
            return -1;
        }
        namedWindow("input_images", CV_WINDOW_AUTOSIZE);
        namedWindow("output_images", CV_WINDOW_AUTOSIZE);
        cvtColor(src, gray_src, CV_BGR2GRAY);
        Canny(gray_src,gray_src,150,200);
        cvtColor(gray_src, line_detect, CV_GRAY2BGR);
        vector<Vec4f> plines;
        HoughLinesP(gray_src, plines, 1, CV_PI / 180.0, 10, 0, 10);
        Scalar color = Scalar(0, 255, 0);
        for (size_t i = 0; i < plines.size(); i++)
        {
            Vec4f hline = plines[i];
            line(line_detect, Point(hline[0], hline[1]), Point(hline[2], hline[3]), color, 3, LINE_AA);
        }
        imshow("input_images", src);
        imshow("output_images", line_detect);
        waitKey(0);
        destroyAllWindows();

    waitKey(0);
    return 0;
}
