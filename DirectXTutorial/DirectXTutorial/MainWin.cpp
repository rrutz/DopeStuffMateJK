#pragma once

/*

	There is no single function we can call to create a window.

	Just like the previous lesson, we will be using the function WinMain() to start out our program. 
	We will also use another function called WinProc(). 
	This function will handle any event messages Windows sends to us while the program is running.

	The below code is essentially just 3 steps:
		1. RegisterClassEx();
		2. CreateWindowEx();
		3. ShowWindow();

	wc - This is a struct that contains the information for the window class.

	ZeroMemory(&wc, sizeof(WNDCLASSEX)) - 
		ZeroMemory is a function that initializes an entire block of memory to NULL. 
		The address provided in the first parameter sets where the block is to start. 
		The second parameter indicates how long the block is.

	2. CreateWindowEx();
	HWND CreateWindowEx(DWORD dwExStyle,
		LPCTSTR lpClassName,
		LPCTSTR lpWindowName,
		DWORD dwStyle,
		int x,
		int y,
		int nWidth,
		int nHeight,
		HWND hWndParent,
		HMENU hMenu,
		HINSTANCE hInstance,
		LPVOID lpParam);

	3.
	HWND hWnd - This is simply the handle to the window we just created, so we place in here the value Windows gave back to us.


	BOOL GetMessage(LPMSG lpMsg,
		HWND hWnd,
		UINT wMsgFilterMin,
		UINT wMsgFilterMax);

		lpMsg is a pointer to a message struct.
		hWnd  is the handle to the window the message should come from. In this parameter, NULL means get the next message for any of our windows.

*/

#include <windows.h>
#include <windowsx.h>

LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);


LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	// sort through and find what code to run for the message given
	switch (message)
	{
		// this message is read when the window is closed
	case WM_DESTROY:
	{
		// close the application entirely
		PostQuitMessage(0);
		return 0;
	} break;
	}

	// Handle any messages the switch statement didn't
	return DefWindowProc(hWnd, message, wParam, lParam);
}



// the entry point for any Windows program
int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// The handle for the window
	HWND hWnd;

// 1. Registering the Window Class (makes the window class) - begin 
	// This structure hold information for the window class
	WNDCLASSEX wc;

	// Clear out the window class for use
	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	// Fill in the struct with the needed information
	wc.cbSize = sizeof(WNDCLASSEX);				// Set size of this structure 
	wc.style = CS_HREDRAW | CS_VREDRAW;			// In this member, we store the style of the window.
	wc.lpfnWndProc = WindowProc;				// This value tells the window class what function to use when it gets a message from Windows.
	wc.hInstance = hInstance;					// handle to a copy of our application.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);	// This member stores the default mouse image for the window class.
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;	// This member contains the 'brush' that will be used to color the background of our window. 
	wc.lpszClassName = L"WindowClass1";			// This is the name of the window class we are building.

	// Register the window class
	RegisterClassEx(&wc);						// This function finally registers the window class.

// 1. Registering the Window Class - end

	// Create the window and use the result as the handle
	hWnd = CreateWindowEx(NULL,
		L"WindowClass1",    // name of the window class
		L"Our First Windowed Program",   // title of the window
		WS_OVERLAPPEDWINDOW,    // window style
		300,    // x-position of the window
		100,    // y-position of the window
		1000,    // width of the window
		800,    // height of the window
		NULL,    // we have no parent window, NULL
		NULL,    // we aren't using menus, NULL
		hInstance,    // application handle
		NULL);    // used with multiple windows, NULL

    // Display the window on the screen
	ShowWindow(hWnd, nCmdShow);


	// Enter the main loop:

	// This struct holds Windows event messages
	MSG msg;  // MSG is a struct which contains all the data regarding a single event message.
	
	/*
	// Wait for the next message in the queue, store the result in 'msg'
	while (GetMessage(&msg, NULL, 0, 0))
	{
		// Translate keystroke messages into the right format
		TranslateMessage(&msg);

		// Send the message to the WindowProc function
		DispatchMessage(&msg);
	}
	*/


	// Enter the infinite message loop
	while (TRUE)
	{
		// Check to see if any messages are waiting in the queue
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			// translate keystroke messages into the right format
			TranslateMessage(&msg);

			// send the message to the WindowProc function
			DispatchMessage(&msg);

			// check to see if it's time to quit
			if (msg.message == WM_QUIT)
				break;
		}
		else
		{
			// Run game code here
			// ...
			// ...
		}
	}


	// Return this part of the WM_QUIT message to Windows
	return msg.wParam;
}

