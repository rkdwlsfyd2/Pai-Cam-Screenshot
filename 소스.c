#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <stdio.h>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	int CAM_ID = -1;
	Mat frame1;
	VideoCapture cap(CAM_ID); // ī�޶� ����
	if (!cap.isOpened()) { // ī�޶� ���ȴ��� Ȯ��
		printf("Can't open the CAM(%d)\n", CAM_ID);
		return -1;
	}
	while (1) {
		//ī�޶󿡼� �̹��� ������
		cap >> frame1;
		//���� �̹����� �����쿡 ǥ��
		imshow("CAM_Window", frame1);
		//10ms ���� Ű �Է� ���
		if (waitKey(10) >= 0) break;
	}
	//������ ����
	destroyWindow("CAM_Window");
	return 0;

}