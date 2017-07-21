#ifndef DIRECTX11RENDERER_H
#define DIRECTX11RENDERER_H
#include "../IRenderer.h"
#include "DirectXHelper.h"
#include "../../../Core/Window/DirectX/DirectXWindow.h"
#include "../../../Shaders/DirectX/DirectXShaderFactory.h"
#include "../../../Geometry/LineMesh/Grid.h"
#include "d3d11.h"
#include "../../../../ParticleSystem/ParticleSystem.h"
using namespace DirectX;

namespace BAME
{
	class DirectX11Renderer : public IRenderer
	{
	public:

		explicit DirectX11Renderer(IWindow* window, SceneManager* sceneManager, ShaderHandler* shaderHandler);
		~DirectX11Renderer();

		bool Init() override;
		
		void Shutdown() override;

		void BeforeRenderScene() override;
		void AfterRenderScene() override;
		void RenderScene() override;

		
		DXGI_RATIONAL QueryRefreshRate(const unsigned screenWidth, const unsigned screenHeight, const bool vsync) const;
		void DrawRenderObjectIndexed(const RenderObject const* renderObj);
		bool InitDirectX(const HINSTANCE hInstance, const bool vSync);
		void Present(const bool vSync) const;
		void SetDebugView(bool value) override;


		bool InitShadowMapping(unsigned shadomMapSize);

		Microsoft::WRL::ComPtr<ID3D11Device> const& GetDevice() const;

		Microsoft::WRL::ComPtr<ID3D11DeviceContext> const& GetDeviceContext() const;
	private:

		void RenderGeoLine(std::vector<RenderObject*> const& renderObjectList);
		void RenderGeoPoint(std::vector<RenderObject*> const& renderObjectList);
		void RenderGeoTriangle(std::vector<RenderObject*> const& renderObjectList);
		void RenderShadowMap(std::vector<RenderObject*> const& renderObjectList);
		void RenderParticleSystems(std::vector<IParticleSystem*> const& particleSystemList);
		void RenderGUI(std::vector<RenderObject*> const& renderObjectList);
		void RenderBoundingBoxes(std::vector<RenderObject*> const& renderObjectList);
		void RenderSkybox(RenderObject* renderObj);
		void RenderDebugObjects();
		void RenderGeoBone(const std::vector<RenderObject*>& renderObjList);

		void Clear(const float clearColor[4], const float clearDepth, const unsigned char clearStencil);


		Microsoft::WRL::ComPtr<IDXGISwapChain> mSwapChain;
		Microsoft::WRL::ComPtr<ID3D11Device> mDevice;

		Microsoft::WRL::ComPtr<ID3D11DeviceContext> mDeviceContext;

		//Debug
		Microsoft::WRL::ComPtr<ID3D11Debug> pDebug;

		// render target view for the back buffer of the swap chain.
		Microsoft::WRL::ComPtr<ID3D11RenderTargetView> mD3dRenderTargetView;

		// Depth/stencil view for use as a depth buffer.
		Microsoft::WRL::ComPtr<ID3D11DepthStencilView> mD3dDepthStencilView;

		// A texture to associate to the depth stencil view.
		Microsoft::WRL::ComPtr<ID3D11Texture2D> mD3dDepthStencilBuffer;

		Microsoft::WRL::ComPtr<ID3D11Texture2D> mD3dDepthShadowMapBuffer;
		Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> mShadowMapResView;
		Microsoft::WRL::ComPtr<ID3D11DepthStencilView> mD3dShadowMapDepthView;
	/*	Microsoft::WRL::ComPtr<ID3D11RenderTargetView> mShadowRenderTargetView;
		Microsoft::WRL::ComPtr<ID3D11Texture2D> mShadowBackBuffer;*/

		Microsoft::WRL::ComPtr<ID3D11DepthStencilState> mD3dDepthStencilStateShadow;

		// Define the functionality of the depth/stencil stages.
		Microsoft::WRL::ComPtr<ID3D11DepthStencilState> mD3dDepthStencilState;
		// Define the functionality of the rasterizer stage.
		Microsoft::WRL::ComPtr<ID3D11RasterizerState> mD3dRasterizerState;
		Microsoft::WRL::ComPtr<ID3D11RasterizerState> mD3DRasterizerStarteWireFrame;

		Microsoft::WRL::ComPtr<ID3D11BlendState> mBlendState;

		D3D11_VIEWPORT mViewport;
		D3D11_VIEWPORT mViewport2;

		DirectXWindow* mWindow;

		Placement* mGridPlace;
		Grid* mGrid;
		RenderObject* mGridRenderObj;
	};
}
#endif
