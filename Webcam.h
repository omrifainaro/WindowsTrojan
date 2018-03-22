#pragma once
#include <Windows.h>
#include <algorithm>
#include <memory>
#include "escapi.h"
#include "Utils.h"

class Webcam {
public:
	Webcam(int width, int height);
	void shootCam(LPCTSTR filename);
private:
	struct SimpleCapParams capture;
};