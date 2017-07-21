#ifndef DIRECTXSKYDOMESHADER_H
#define DIRECTXSKYDOMESHADER_H
#include "DirectXShader.h"
#include <DirectXMath.h>
using namespace DirectX;


namespace BAME
{
	class DirectXSkydomeShader : public DirectXShader
	{
	public:
		DirectXSkydomeShader(Microsoft::WRL::ComPtr<ID3D11Device> const& device, Microsoft::WRL::ComPtr<ID3D11DeviceContext> const& deviceContext);
		~DirectXSkydomeShader();

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
			CB_Appliation,
			CB_Frame,
			CB_Object,
			NumConstantBuffers
		};

		Microsoft::WRL::ComPtr<ID3D11Buffer> mD3dConstantBuffers[NumConstantBuffers];

		struct cbPerApplication
		{
		};

		struct alignas(16) cbPerFrame
		{
			XMMATRIX mViewMatrix;
			XMMATRIX mProjectionMatrix;
			XMMATRIX mMVPMatrix;
			XMFLOAT4 mEyePosition;
		};

		struct alignas(16) cbPerObject
		{
			XMMATRIX mWorldMatrix;
			XMMATRIX mInverseTransposeWorldMatrix;
		};
	};
}
#endif
