#ifndef DIRECTXINPUTAPI_H
#define DIRECTXINPUTAPI_H
#include "IInputAPI.h"
#include "../Window/DirectX/DirectXWindow.h"

namespace BAME
{
	class DirectXInputAPI :public IInputAPI
	{
	public:
		DirectXInputAPI();
		~DirectXInputAPI();
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
		DirectXWindow* mWindow;

		std::shared_ptr<DirectX::Mouse::ButtonStateTracker> mMouseTracker;
		std::unique_ptr<DirectX::Keyboard::KeyboardStateTracker> mKeyboardTracker;

		bool mLastKeys[int(Key::LAST)];

		Vector2f mMousePos;
	};
}
#endif
