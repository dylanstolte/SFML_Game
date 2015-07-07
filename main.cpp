#include <Windows.h>

#include "Engine.h"

//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
int main()
{
	Engine* engine = new Engine();

	try
	{
		engine->Go();
	}
	catch(char* e)
	{
		MessageBoxA(NULL, e, "Exception Occured", MB_OK | MB_ICONERROR);
	}
	return 1;
}

