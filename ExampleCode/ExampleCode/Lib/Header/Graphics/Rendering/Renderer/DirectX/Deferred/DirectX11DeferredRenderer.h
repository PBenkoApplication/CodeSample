#ifndef DIRECTX11DEFERREDRENDERER_H
#define DIRECTX11DEFERREDRENDERER_H
#include "../../IRenderer.h"
#include "../DirectXHelper.h"
#include "../../../Core/Window/DirectX/DirectXWindow.h"
#include "../../../../Shaders/DirectX/DirectXShaderFactory.h"
#include "../../../Geometry/LineMesh/Grid.h"
#include "d3d11.h"
#include "../../../../../Geometry/TriangleMesh/VerticalPlane.h"
using namespace DirectX;

namespace BAME
{
	class DirectX11DeferredRenderer : public IRenderer
	{
	public:

		explicit DirectX11DeferredRenderer(IWindow* window, SceneManager* sceneManager, ShaderHandler* shaderHandler);
		~DirectX11DeferredRenderer();

		bool Init() override;
		bool CreateDeviceDeviceContextSwapChain(const bool vSync, HRESULT& hr);
		void Shutdown() override;

		void BeforeRenderScene() override;
		void AfterRenderScene() override;
		void RenderScene() override;
		void RenderBoundingBoxes();
		void RenderSkybox();
		void Clear(const float clearColor[4], const float clearDepth, const unsigned char clearStencil);

		DXGI_RATIONAL QueryRefreshRate(const unsigned screenWidth, const unsigned screenHeight, const bool vsync) const;
		void DrawRenderObjectIndexed(const RenderObject const* renderObj);
		bool CreateBackbuffer();
		bool CreateDepthStencilBuffer();
		bool CreateRasterizer();
		bool InitDirectX(const HINSTANCE hInstance, const bool vSync);
		void Present(const bool vSync) const;
		void SetDebugView(bool value) override;

		Microsoft::WRL::ComPtr<ID3D11Device> const& GetDevice() const;

		Microsoft::WRL::ComPtr<ID3D11DeviceContext> const& GetDeviceContext() const;
	private:

		void RenderGUI();
		void RenderGeoPoint();
		void RenderGeometries();
		void RenderDebugObjects();

		void RenderGeoLine();
		void RenderGeoTriangle();

		bool InitGBuffer();

		Microsoft::WRL::ComPtr<IDXGISwapChain> mSwapChain;
		Microsoft::WRL::ComPtr<ID3D11Device> mDevice;

		Microsoft::WRL::ComPtr<ID3D11DeviceContext> mDeviceContext;

		//Debug
		Microsoft::WRL::ComPtr<ID3D11Debug> pDebug;

		// render target view for the back buffer of the swap chain.

		//Der G-Buffer hält die Texturen für den Geometrypass
		//0: Position, 1: Alpedo(Diffuse), 2: Specular/Glossiness, 3: Normal  
		Microsoft::WRL::ComPtr<ID3D11Texture2D> mGBuffer[4];

		//0: Position, 1: Alpedo(Diffuse) 2: Specular/Glossiness, 3: Normal  
		Microsoft::WRL::ComPtr<ID3D11RenderTargetView> mGBufferRenderTargetView[4];

		Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> mGBufferShaderResourceView[5];

		Microsoft::WRL::ComPtr<ID3D11RenderTargetView> mBackbufferRenderTargetView;

		// Depth/stencil view for use as a depth buffer.
		Microsoft::WRL::ComPtr<ID3D11DepthStencilView> mD3dDepthStencilView;

		// A texture to associate to the depth stencil view.
		Microsoft::WRL::ComPtr<ID3D11Texture2D> mD3dDepthStencilBuffer;

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
		std::unique_ptr<Placement> mScreenQuadPlace;
		std::unique_ptr<VerticalPlane> mScreenQuad;
		std::unique_ptr<RenderObject> mScreenQuadRenderObj;
	};
}
#endif
