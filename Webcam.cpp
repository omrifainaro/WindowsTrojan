#include "Webcam.h"

void intPxlArrToBytePxlArr(int* arr, int size, BYTE* arr2) {
	int c = 0;
	for (int i = 0; i < size; i++)
	{
		arr2[  c  ] = (BYTE)(arr[i] & 0xff);
		arr2[c + 1] = (BYTE)(arr[i] >> 8 & 0xff);
		arr2[c + 2] = (BYTE)(arr[i] >> 16 & 0xff);
		c += 3;
	}
}

Webcam::Webcam(int width, int height)
{
	int devices = setupESCAPI();

	if (devices == 0)
	{
		printf("ESCAPI initialization failure or no devices found.\n");
		return;
	}

	this->capture.mWidth = width;
	this->capture.mHeight = height;
	this->capture.mTargetBuf = new int[width * height];

	if (initCapture(0, &capture) == 0)
	{
		printf("Capture failed - device may already be in use.\n");
		return;
	}
}

void Webcam::shootCam(LPCTSTR filename)
{
	doCapture(0);

	while (isCaptureDone(0) == 0)
	{

	}

	BYTE* arr2 = new BYTE[this->capture.mWidth * this->capture.mHeight * 3];
	intPxlArrToBytePxlArr(capture.mTargetBuf, this->capture.mWidth * this->capture.mHeight, arr2);
	deinitCapture(0);

	SaveBitmapToFile(arr2, capture.mWidth, capture.mHeight, 24, 0, filename);
}
