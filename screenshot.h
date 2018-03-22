#pragma once
#include <Windows.h>
#include <stdio.h>
#include <assert.h>

namespace screenshot {
	PBITMAPINFO CreateBitmapInfoStruct(HBITMAP hBmp);
	void CreateBMPFile(char* pszFile, HBITMAP hBMP);
	int screenshot(char* filename);
}