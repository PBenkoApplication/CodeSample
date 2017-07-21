#ifndef DirectXDemoSceneShader_H
#define DirectXDemoSceneShader_H
#include <DirectXMath.h>
#include "DirectXShader.h"
using namespace DirectX;
namespace BAME
{
	class DirectXDemoSceneShader :public DirectXShader
	{
	public:
		DirectXDemoSceneShader(Microsoft::WRL::ComPtr<ID3D11Device> const& device, Microsoft::WRL::ComPtr<ID3D11DeviceContext> const& deviceContext);
		~DirectXDemoSceneShader();

		void Update(RenderObject const& renderObj, Matrix4x4f const& viewMatrix, Matrix4x4f const& projectionMatrix, Vector3f const& camPos, ShaderData const& renderData) override;
		void SetActive() override;

		void SetResolution(int width, int height);

		void SetGlobalTime(float globalTime);

	private:

		void CreateInputLayout() override;

		void CreateVertexShader() override;
		void CreatePixelShader() override;
		void CreateGeometryShader() override;

		void CreateConstantBuffers() override;

		void createTextureSampler();

		//Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> mShaderResourceView;
		Microsoft::WRL::ComPtr<ID3D11SamplerState> mSamplerState;

		enum PixelConstantBufferTypes
		{
			PCB_Properties,
			PCB_NumConstantBuffers
		};

		Microsoft::WRL::ComPtr<ID3D11Buffer> mD3dPixelConstantBuffers[PCB_NumConstantBuffers];


		struct alignas(16) PixelProperty
		{
			float GlobalTime;
			XMINT2 Resolution;
			int padding;
		};

		struct cbPerApplication
		{
		};

		struct alignas(16) cbPerFrame
		{
		};

		struct alignas(16) cbPerObject
		{
		};

		XMINT2 mResolution;
		float mGlobalTime;
	};
}
#endif
