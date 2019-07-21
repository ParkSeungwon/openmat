#include<iostream>
#include"mat.h"
using namespace std;
using namespace cv;

int main()
{
	my::Mat<float, 3, 3> m{2.3f,3,4,2,3,3,2,2,2};
	my::Mat<float, 3, 3> n{1.3f,3,4,2,3,3,2,2,2};
	my::Mat m2;
	cout << m  << endl;;
	m.cv::Mat::operator=(imread("1.JPG"));
	imshow("test", m);
	waitKey();
	cout << m.cols << ' ' << m.rows << endl;
	cout << +m.at<Vec3b>(3,2)[2] << endl;
	cout << n.at<int>(0,0) << endl;

	Mat_<int> mat(9,9);
	cerr << mat.at<int>(0,3);
}

