#ifndef IINPUTAPI_H
#define IINPUTAPI_H
#include "../../Mathematics/Vector2f.h"
#include "../../Input/Key.h"
#include "../Window/IWindow.h"

namespace BAME
{
	class IInputAPI
	{
	public:
		IInputAPI();
		virtual ~IInputAPI();

		virtual void Init(IWindow* window) = 0;

		virtual void Update() = 0;

		virtual bool GetKey(Key const& key) = 0;

		virtual bool GetKeyDown(Key const& key) = 0;

		virtual bool GetKeyUp(Key const& key) = 0;

		virtual void SetMousePos(Vector2f const& mousepos) =0;

		virtual bool GetMouse(MouseButton const& mouseButton) = 0;

		virtual bool GetMouseDown(MouseButton const& mouseButton) = 0;

		virtual bool GetMouseUp(MouseButton const& mouseButton) = 0;

		virtual void SetMousePosition(Vector2f const& mousepos) = 0;
		virtual void ShowCursor(bool enabled) = 0;

		virtual Vector2f const& GetMousePosition() = 0;
	};
}
#endif
