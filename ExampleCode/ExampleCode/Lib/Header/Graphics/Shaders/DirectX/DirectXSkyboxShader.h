#ifndef DIRECTXSKYBOXSHADER_H
#define DIRECTXSKYBOXSHADER_H
#include "DirectXShader.h"
#include <DirectXMath.h>
using namespace DirectX;


namespace BAME
{
	class DirectXSkyboxShader : public DirectXShader
	{
	public:
		DirectXSkyboxShader(Microsoft::WRL::ComPtr<ID3D11Device> const& device, Microsoft::WRL::ComPtr<ID3D11DeviceContext> const& deviceContext);
		~DirectXSkyboxShader();

		//void Update(RenderObject const& renderObj, Matrix4x4f const& viewMatrix, Matrix4x4f const& projectionMatrix, Vector3f const& eyePos);

		void Update(RenderObject const& renderObj, Matrix4x4f const& viewMatrix, Matrix4x4f const& projectionMatrix, Vector3f const& camPos, ShaderData const& renderData) override;
		void SetActive() override;

	private:

		void CreateInputLayout() override;

		void CreateVertexShader() override;
		void CreatePixelShader() override;
		void CreateGeometryShader() override;

		void CreateConstantBuffers() override;

		void createTextureSampler();

	private:
		Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> mShaderResourceView;
		Microsoft::WRL::ComPtr<ID3D11SamplerState> mSamplerState;

		// Shader resources
		enum ConstantBufferTypes
		{
			CB_Frame,
			NumConstantBuffers
		};

		Microsoft::WRL::ComPtr<ID3D11Buffer> mD3dConstantBuffers[NumConstantBuffers];


		struct alignas(16) cbPerFrame
		{
			XMMATRIX mViewMatrix;
			XMMATRIX mProjectionMatrix;
			XMMATRIX mMVPMatrix;
		};


		Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> mD3dPixelShaderResourceViewList[1];
	};
}
#endif
