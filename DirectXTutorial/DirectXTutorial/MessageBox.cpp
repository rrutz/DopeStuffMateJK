/*

#include <windows.h>    // include the basic windows header file

// the entry point for any Windows program
// WINAPI passes the parameters from right to left
/*
hInstance is just an instance of the window.
hPrevInstance is just an instance of the previous window (if more than one are open). This is obsolete now but is used for backward compatibility.
lpCmdLine is a long pointer to a string that contains the command line calling existence to the application. Usually you will not use them in game programming
nShowCmd indicates how the window is to appear when created.
*/

/*
int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nShowCmd)
{

	/*
	int MessageBox(HWND hWnd,
               LPCTSTR lptext,
               LPCTSTR lpcaption,
               UINT utype);
	HWND is a handle to a window. We have NUll as no has been window created.
	LPCTSTR text to the message box.
	LPCTSTR  is a pointer to a 16-bit string that contains the text of the title bar.
	UINT - This parameter determines what the style of the message box is.
	*/
	// create a "Hello World" message box using MessageBox()

	/*
	MessageBox(NULL,
		L"Hello World!",
		L"Just another Hello World program!",
		MB_ICONEXCLAMATION | MB_OK);

	// return 0 to Windows
	return 0;
}

*/