#include <Windows.h>
#include <tchar.h>
#include "resource.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam) {
	switch (iMsg)
	{
	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case ID_FILE_HELLO:
			MessageBox(hWnd, TEXT("HELLO"), TEXT("HELLO"), MB_OK);
			break;
		case ID_FILE_EXIT:
			PostQuitMessage(0);
			break;
		}
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	
	return DefWindowProc(hWnd, iMsg, wParam, lParam);
}

INT APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE, 
	_In_ LPSTR pszLine, _In_ INT nShow) {
	WNDCLASS wc;
	HWND hWnd;
	MSG msg;

	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDC_ICON);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = reinterpret_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	wc.lpszClassName = TEXT("MY APP");

	RegisterClass(&wc);

	hWnd = CreateWindow(TEXT("MY APP"), TEXT("SAMPLE APPLICATION"), 
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 
		CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
	
	ShowWindow(hWnd, SW_SHOW);

	while (GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}