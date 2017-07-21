#ifndef OPENGLINPUTAPI_H
#define OPENGLINPUTAPI_H
#include "IInputAPI.h"
#include "../Window/OpenGL/OpenGLWindow.h"

namespace BAME
{
	class OpenGLInputAPI : public IInputAPI
	{
	public:
		OpenGLInputAPI();
		~OpenGLInputAPI();
		void Init(IWindow* window) override;
		void Update() override;
		bool GetKey(Key const& key) override;
		bool GetKeyDown(Key const& key) override;
		bool GetKeyUp(Key const& key) override;
		bool GetMouse(MouseButton const& mouseButton) override;
		bool GetMouseDown(MouseButton const& mouseButton) override;
		bool GetMouseUp(MouseButton const& mouseButton) override;

		void SetMousePosition(Vector2f const& mousepos) override;
		void ShowCursor(bool enabled) override;
		Vector2f const& GetMousePosition() override;

		void SetMousePos(Vector2f const& mousepos) override;

		static void SetMousePosStatic(Vector2f const& mousepos);

		bool GetKey(int key);
		bool GetMouse(int mouseButton);


	private:
		bool mLastKeys[GLFW_KEY_LAST + 1];
		bool mLastMouse[GLFW_MOUSE_BUTTON_LAST + 1];


		static Vector2f mMousePos;
		OpenGLWindow* mWindow;
	};
}

#endif
