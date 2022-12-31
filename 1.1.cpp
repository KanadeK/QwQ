#include <opencv2/opencv.hpp>
#include <iostream>
#include <QDebug>
#include <vector>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;




int main() {

    string path = "C:\\Users\\12070\\Pictures\\Screenshots\\RM.jpg";
    Mat img = imread(path);
    Mat imgGray,imgBlur,imgCanny,imgDil,imgErode;
    //将照片转换为灰度
    cvtColor(img, imgGray, COLOR_BGR2GRAY);
    //高斯模糊
    GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);
    //Canny边缘检测器  一般在使用Canny边缘检测器之前会做一些模糊处理
    Canny(imgBlur, imgCanny, 25, 75);
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


    void cv::GaussianBlur
            (
                InputArray 	src,
                OutputArray dst,
                Size 	ksize,
                double 	sigmaX,
                double 	sigmaY = 0,
                int 	borderType = BORDER_DEFAULT
            )
        //载入
        Mat src = imread("C:\\Users\\12070\\Pictures\\Screenshots\\1.jpg");
        //显示
        imshow("src",src);

        //高斯滤波3
        Mat dst3;
        Size ksize3(3,3);
        GaussianBlur(src,dst3,ksize3,0,0);
        imshow("dst3",dst3);

        //高斯滤波5
        Mat dst5;
        Size ksize5(5,5);
        GaussianBlur(src,dst5,ksize5,0,0);
        imshow("dst5",dst5);

        //高斯滤波7
        Mat dst7;
        Size ksize7(7,7);
        GaussianBlur(src,dst7,ksize7,0,0);
        imshow("dst7",dst7);

//二值化
        QImage Binaryzation(const QImage &img)
        {
            QImage imgCopy;

            if (img.format() != QImage::Format_RGB888) {
                imgCopy = QImage(img).convertToFormat(QImage::Format_RGB888);
            } else {
                imgCopy = QImage(img);
            }
            uint8_t *rgb = imgCopy.bits();
            int newGray = 0;
            int gray = 0;
            int size = img.width() * img.height();
            for (int i = 0; i < size ; i++) {
                gray = (rgb[i * 3] + rgb[i * 3 + 1] + rgb[i * 3 + 2]) / 3;
                if (gray > 128)
                    newGray = 255;
                else
                    newGray = 0;
                rgb[i * 3] = newGray;
                rgb[i * 3 + 1] = newGray;
                rgb[i * 3 + 2] = newGray;
            }
            return imgCopy;
        }


        waitKey(0);

}
