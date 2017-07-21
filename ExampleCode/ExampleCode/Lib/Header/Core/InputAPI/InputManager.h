#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H
#include "IInputAPI.h"

namespace BAME
{
	class InputManager
	{
	public:
		InputManager();
		~InputManager();

		void Init(IInputAPI* input, IWindow* window);

		void Update() const;
		bool GetKey(Key const& key) const;
		bool GetKeyDown(Key const& key) const;
		bool GetKeyUp(Key const& key) const;
		bool GetMouse(MouseButton const& mouseButton) const;
		bool GetMouseDown(MouseButton const& mouseButton) const;
		bool GetMouseUp(MouseButton const& mouseButton) const;
		void SetMousePos(Vector2f const& mousepos) const;
		void SetMousePosition(Vector2f const& mousepos) const;
		void ShowCursor(bool enabled) const;
		Vector2f const& GetMousePosition() const;
		Vector2f const& GetMousePositionRelative() const;
		void SetMouseSensitivity(float sensitivity);

		float GetMouseSensitivity();

	private:
		IInputAPI* mInputAPI;
		float mMouseSensitivity;
		IWindow* mWindow;
	};
}
#endif
