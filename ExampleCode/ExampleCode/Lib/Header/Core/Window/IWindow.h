#ifndef IWINDOW_H
#define IWINDOW_H
#include <string>


namespace BAME
{
	class IWindow
	{
	public:

		IWindow();

		virtual ~IWindow();

		virtual void CreateTheWindowDefault() = 0;
		virtual void CreateTheWindow(const int windowWidth, const int windowHeight, const char title[20]) = 0;
		virtual void SetTitle(const std::string& title) = 0;
		virtual void Close() = 0;
		virtual void Dispose() = 0;
		virtual bool IsCloseRequested() = 0;
		virtual void HandleEvents() = 0;

		int GetHeight() const;

		int GetWidth() const;

		std::string const& GetTitle() const;;

	protected:
		const int defaultWindowWidth = 1280;
		const int defaultWindowHeight = 720;
		const std::string defaultWindowTitle = "BAM Engine";

		int mWidth;
		int mHeight;
		std::string mTitle;
		bool mIsCloseRequested = false;
	};
}
#endif
