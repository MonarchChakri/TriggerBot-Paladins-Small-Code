#include "ScanContents.h"

int main(int argc, char* argv[]) {

	do
	{
		system("cls");
		cout << "Paladins Triggerbot." << endl;
		cout << "Put Reticle type to 'Drop' and reticle colour to 'Yellow' for best performance.." << endl;
		cout << "Press '1' on numpad to search for game" << endl;
		Sleep(1000);
	} while (!GetAsyncKeyState(VK_NUMPAD1));

	string gameName = "Chaos (32-bit, DX9)";
	HWND gameWND = FindWindow(0, gameName.c_str());
	RECT reticle;

	while (!gameWND)
	{
		system("cls");
		cout << "Waiting for game." << endl;
		gameWND = FindWindow(0, gameName.c_str());
		Sleep(1000);
	}

	do
	{
		system("cls");
		cout << "Found game." << endl;
		cout << "Press '1' on numpad to start triggerbot" << endl;
		Sleep(1000);
	} while (!GetAsyncKeyState(VK_NUMPAD1));

	system("cls");
	cout << "Triggerbot started. Hover over enemies to auto shoot.." << endl;
	cout << "Press Delete to close" << endl;

	GetWindowRect(gameWND, &reticle);
	HDC hdcMain = GetDC(HWND_DESKTOP);
	int startX = reticle.right - ((reticle.right - reticle.left) / 2);
	int startY = reticle.bottom - ((reticle.bottom - reticle.top) / 2);

	ScanContents scan(startX - 1, startY + 11, hdcMain);
	scan.scanReticle();

	system("cls");
	cout << "You are about to close this.." << endl;
	system("pause");
	return 0;
}