#include <Windows.h>
#include <gl\GL.h>
#pragma comment (lib, "opengl32.lib")

int main() {
	//Getting a handle to the console window
	HWND console = GetConsoleWindow();

	//This little section is for removing the scroll bar, but it's not the best
	ShowScrollBar(console, SB_BOTH, false);

	CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
	COORD newSize;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bufferInfo);

	//NOTE: These values may need to be adjusted
	newSize.X = bufferInfo.dwSize.X;
	newSize.Y = 20; //bufferInfo.dwSize.Y;

	//You could check if this works, I don't really care
	int status = SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), newSize);

	//Making a pixel format discriptor for an opengl context
	PIXELFORMATDESCRIPTOR pfd = {
		sizeof(PIXELFORMATDESCRIPTOR),
		1,
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
		PFD_TYPE_RGBA,
		32,
		0, 0, 0, 0, 0, 0,
		0,
		0,
		0,
		0, 0, 0, 0,
		24,
		8,
		PFD_MAIN_PLANE,
		0,
		0, 0, 0
	};

	//Creating a device context
	HDC deviceContext = GetDC(console);

	//Making a pixel format with the pixel format discriptor
	int autoPixelFormat = ChoosePixelFormat(deviceContext, &pfd);
	SetPixelFormat(deviceContext, autoPixelFormat, &pfd);

	//And finally, creating the opengl context
	HGLRC oglContext = wglCreateContext(deviceContext);
	wglMakeCurrent(deviceContext, oglContext);

	/* OpenGL 1.1 function
	 * You can load in functions but since you can't really
	 * get proper input from the console (because it's not owned by this program)
	 * I decided to not mank anything impressive, just a proof of concept.
	 */
	while (true) {
		glClear(GL_COLOR_BUFFER_BIT);

		glColor3f(0.f, 0.f, 0.f);
		glBegin(GL_QUADS);
		glVertex2i(-1, 1);
		glVertex2i(1, 1);
		glVertex2i(1, -1);
		glVertex2i(-1, -1);
		glEnd();

		glColor3f(0.7f, 1.f, 0.9f);
		glBegin(GL_TRIANGLES);
		glVertex2i(0, 1);
		glVertex2i(1, -1);
		glVertex2i(-1, -1);
		glEnd();

		//This part just makes sure the console ONLY updates when a new rendered frame is ready
		//It _should_ prevent flickering of the carrot
		LockWindowUpdate(NULL);
		SwapBuffers(deviceContext);
		LockWindowUpdate(console);
	}

	//Deleting the context in the end
	wglDeleteContext(oglContext);

	return 0;
}