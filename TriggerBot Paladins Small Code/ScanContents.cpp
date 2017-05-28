#include"ScanContents.h"

ScanContents::ScanContents(int centerX = 0, int centerY = 0, HDC hdc = nullptr) {
	_centerX = centerX;
	_centerY = centerY;
	_hdc = hdc;
}

void ScanContents::scanReticle() {
	while (true)
	{
		manageMouse(GetPixel(_hdc, _centerX, _centerY), _centerX, _centerY);
		Sleep(10);
		if (GetAsyncKeyState(VK_DELETE))
		{
			system("cls");
			cout << "You are about to close this.." << endl;
			system("pause");
			exit(0);
		}
	}
}

void ScanContents::manageMouse(COLORREF pixel, int x, int y) {
	if (checkColour(pixel)) {
		mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
		mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);
	}
}

bool ScanContents::checkColour(COLORREF pixel) {
	int r = GetRValue(pixel);
	int g = GetGValue(pixel);
	int b = GetBValue(pixel);
	//cout << r << ":R " << b << ":B " << g << ":G " << endl;
	bool red = (r < 255 && r>245);
	bool blue = (110 < b&&b < 120) || (55 < b&&b < 65);
	bool green = (110 < g&&g < 120) || (170 < g&&g < 175);
	if (red && blue && green)
		return true;
	else
		return false;
}