//#ifndef NULLRENDERER_H
//#define NULLRENDERER_H
//#include "IRenderer.h"
//#include "DirectX/DirectXHelper.h"
//#include "../../../Core/Window/DirectX/DirectXWindow.h"
//#include <memory>
//#include "../../Shaders/DirectX/DirectXShaderFactory.h"
//#include "../../../Geometry/Grid.h"
//#include "d3d11.h"
//using namespace DirectX;
//
//namespace BAME
//{
//	class NullRenderer : public IRenderer
//	{
//	public:
//
//		explicit NullRenderer(std::shared_ptr<Window> const& window, SceneManager* sceneManager, ShaderHandler* shaderHandler);
//		~NullRenderer();
//		bool Init() override;
//		void Shutdown() override;
//		void RenderScene() override;
//		void BeforeRenderScene() override;
//		void AfterRenderScene() override;
//		void SetDebugView(bool value) override;
//
//
//		void Clear(const float clearColor[4], const float clearDepth, const unsigned char clearStencil);
//		DXGI_RATIONAL QueryRefreshRate(const unsigned screenWidth, const unsigned screenHeight, const bool vsync) const;
//		bool InitDirectX(const HINSTANCE hInstance, const bool vSync);
//		void Present(const bool vSync) const;
//
//
//		Microsoft::WRL::ComPtr<ID3D11Device> const& GetDevice() const
//		{
//			return mD3dDevice;
//		}
//
//	private:
//
//		// Direct3D device and swap chain.
//		Microsoft::WRL::ComPtr<ID3D11Device> mD3dDevice;
//		Microsoft::WRL::ComPtr<ID3D11DeviceContext> mD3dDeviceContext;
//		Microsoft::WRL::ComPtr<IDXGISwapChain> mD3dSwapChain;
//		//Debug
//		Microsoft::WRL::ComPtr<ID3D11Debug> pDebug;
//
//		// render target view for the back buffer of the swap chain.
//		Microsoft::WRL::ComPtr<ID3D11RenderTargetView> mD3dRenderTargetView;
//
//		// Depth/stencil view for use as a depth buffer.
//		Microsoft::WRL::ComPtr<ID3D11DepthStencilView> mD3dDepthStencilView;
//
//		// A texture to associate to the depth stencil view.
//		Microsoft::WRL::ComPtr<ID3D11Texture2D> mD3dDepthStencilBuffer;
//
//		// Define the functionality of the depth/stencil stages.
//		Microsoft::WRL::ComPtr<ID3D11DepthStencilState> mD3dDepthStencilState;
//		// Define the functionality of the rasterizer stage.
//		Microsoft::WRL::ComPtr<ID3D11RasterizerState> mD3dRasterizerState;
//		Microsoft::WRL::ComPtr<ID3D11RasterizerState> mD3DRasterizerStarteWireFrame;
//
//		Microsoft::WRL::ComPtr<ID3D11BlendState> mBlendState;
//
//		D3D11_VIEWPORT mViewport;
//		D3D11_VIEWPORT mViewport2;
//
//		std::shared_ptr<DirectXWindow> mWindow;
//
//		Placement* mGridPlace;
//		Grid* mGrid;
//		RenderObject* mGridRenderObj;
//	};
//}
//#endif
//
