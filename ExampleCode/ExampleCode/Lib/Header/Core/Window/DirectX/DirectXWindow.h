#ifndef DIRECTX_WINDOW_H
#define DIRECTX_WINDOW_H
#include <windows.h>
#include "../IWindow.h"
#include <Mouse.h>
#include <Keyboard.h>


namespace BAME
{
	class DirectXWindow final : public IWindow
	{
	public:
		DirectXWindow();
		~DirectXWindow();
		void CreateTheWindow(const int windowWidth, const int windowHeight, const char title[20]) override;
		void CreateTheWindowDefault() override;
		void SetTitle(std::string const& title) override;
		void Close() override;
		void Dispose() override;
		bool IsCloseRequested() override;
		void HandleEvents() override;

		HWND GetHWND() const;

		HINSTANCE GetHINSTANCE() const;

		void ShowCursor(bool value);

		std::shared_ptr<DirectX::Mouse> const& GetMouse() const
		{
			return mouse;
		}

		std::shared_ptr<DirectX::Keyboard> const& GetKeyboard() const
		{
			return keyboard;
		}

		UINT GetClientWidth() const;;
		UINT GetClientHeight() const;;
	private:
		static LRESULT CALLBACK WindowProcStatic(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

		LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);


		HWND mHwnd;
		HINSTANCE mhInstance;
		std::shared_ptr<DirectX::Mouse> mouse;
		std::shared_ptr<DirectX::Keyboard> keyboard;

		UINT mClientWidth;
		UINT mClientHeight;
	};
}
#endif DIRECTX_WINDOW_H
