#ifndef RENDERERTYPE_H
#define RENDERERTYPE_H
#include <string>

namespace BAME
{
	enum class RendererType
	{
		DirectX11_Forward,
		DirectX11_Deferred,
		DirectX11_DemoScene,
		OpenGL4_0_Forward,
		NO_RENDERER
	};

	inline std::string GetRendererAsString(RendererType rendererType)
	{
		switch (rendererType)
		{
		case RendererType::DirectX11_Forward:
			return "DirectX 11.1 Forward";
		case RendererType::DirectX11_Deferred:
			return "DirectX 11.1 Deferred";
		case RendererType::OpenGL4_0_Forward:
			return "OpenGL 4.0 Forward";
		case RendererType::NO_RENDERER:
			return "NullRenderer";
		default: break;
		}
		return "Undefined Renderer";
	}
}
#endif
