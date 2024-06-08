#include <iostream>
#include <Windows.h>


using namespace std;


int main()
{
	int newVal = 456;
	int readVal = 0;

	HWND hwnd = FindWindowA(NULL, "Test");

	if (hwnd == NULL)
	{

		MessageBoxA(0, "Cannot find window!", "Cannot find window!", MB_ICONERROR);
		Sleep(3000);
		exit(-1);

	}
	else
	{
		DWORD pId;
		GetWindowThreadProcessId(hwnd, &pId);
		HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pId);


		if (pId == NULL)
		{
			MessageBoxA(0, "Cannot find process!", "Cannot find process!", MB_ICONERROR);
			Sleep(3000);
			exit(-1);


		}
		else
		{
			ReadProcessMemory(hProcess, (PBYTE*)0x6fff0c, &readVal, sizeof(readVal), 0);
			cout << "The standard value of i:" << readVal << endl;

			WriteProcessMemory(hProcess, (PBYTE*)0x6fff0c, &newVal, sizeof(newVal), 0);

			cout << "The new value of i:" << newVal << endl;

			Sleep(6000);
		}

	}



}