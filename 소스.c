#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <stdio.h>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	int CAM_ID = -1;
	Mat frame1;
	VideoCapture cap(CAM_ID); // 카메라 생성
	if (!cap.isOpened()) { // 카메라 열렸는지 확인
		printf("Can't open the CAM(%d)\n", CAM_ID);
		return -1;
	}
	while (1) {
		//카메라에서 이미지 얻어오기
		cap >> frame1;
		//얻어온 이미지를 윈도우에 표시
		imshow("CAM_Window", frame1);
		//10ms 동안 키 입력 대기
		if (waitKey(10) >= 0) break;
	}
	//윈도우 종료
	destroyWindow("CAM_Window");
	return 0;

}