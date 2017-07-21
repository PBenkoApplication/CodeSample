#ifndef OPENGL_WINDOW_H
#define OPENGL_WINDOW_H
#include "../IWindow.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>


namespace BAME
{
	class OpenGLWindow final : public IWindow
	{
	public:


		void CreateTheWindow(const int windowWidth, const int windowHeight, const char title[20]) override;
		void CreateTheWindowDefault() override;
		void SetTitle(std::string const& title) override;
		void Close() override;
		void Dispose() override;
		bool IsCloseRequested() override;
		void HandleEvents() override;

		GLFWwindow* GetWindowContext() const;

		OpenGLWindow();
		~OpenGLWindow();

	private:
		static void Error_Callback(int error, const char* description);
		static void Close_Callback(GLFWwindow* window);

		GLFWwindow* mWindow;
	};
}
#endif
