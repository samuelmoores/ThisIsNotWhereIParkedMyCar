#include "Window.h"

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	try
	{
		Window wnd(800, 300, "Donkey Fart Box");

		MSG msg;
		BOOL gResult;

		while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		if (gResult == -1)
		{
			return -1;
		}

		return msg.wParam;
	}
	catch (const AquaException& e)
	{
		std::wstring what_wide;
		std::wstring type_wide;
		int i = 0;

		while (e.what()[i] != '\0')
		{
			what_wide.push_back(static_cast<wchar_t>(e.what()[i++]));
		}

		i = 0;

		while (e.GetType()[i] != '\0')
		{
			type_wide.push_back(static_cast<wchar_t>(e.GetType()[i++]));
		}

		MessageBox(nullptr, what_wide.c_str(), type_wide.c_str(), MB_OK | MB_ICONEXCLAMATION);
	}
	catch (const std::exception& e)
	{
		std::wstring what_wide = L"";
		int i = 0;

		while (e.what()[i] != '\0')
		{
			what_wide.push_back(static_cast<wchar_t>(e.what()[i++]));
		}

		MessageBox(nullptr, what_wide.c_str(), L"Standard Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	catch (...)
	{
		MessageBox(nullptr, L"No details available", L"Unkown Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	return -1;
}