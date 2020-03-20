#include <iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	cv::Mat srcMat = cv::imread("D:\\Files\\coins.png");//读取图片
	cv::Mat eroMat;
	cv::Mat dilMat;
	cv::Mat opeMat;
	cv::Mat cloMat;
	cv::Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));//定义结构元素
	cv::Mat binMat;
	threshold(srcMat, binMat, 100, 255, THRESH_BINARY);//二值化
	morphologyEx(binMat, eroMat, MORPH_ERODE, kernel);//腐蚀运算
	morphologyEx(binMat, dilMat, MORPH_DILATE, kernel);//膨胀运算
	morphologyEx(binMat, opeMat, MORPH_OPEN, kernel);//开运算
	morphologyEx(binMat, cloMat, MORPH_CLOSE, kernel);//闭运算
	cv::imshow("srcMat", srcMat);//显示腐蚀运算图像
	cv::imshow("eroMat", eroMat);//显示膨胀运算图像
	cv::imshow("dilMat", dilMat);//显示开运算图像
	cv::imshow("opeMat", opeMat);//显示闭运算图像
	cv::imshow("cloMat", cloMat);
	waitKey(0);
}