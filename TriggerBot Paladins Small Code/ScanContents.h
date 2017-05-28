#pragma once
#include<iostream>
#include<Windows.h>
#include<string>
using namespace std;

class ScanContents {
public:
	int _centerX;
	int _centerY;
	HDC _hdc;

	ScanContents(int centerX, int centerY, HDC hdc);
	void scanReticle();
	void manageMouse(COLORREF pixel, int x, int y);
	bool checkColour(COLORREF pixel);
};