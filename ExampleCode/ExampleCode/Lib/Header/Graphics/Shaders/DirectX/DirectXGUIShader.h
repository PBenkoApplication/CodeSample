#ifndef DIRECTXGUISHADER_H
#define DIRECTXGUISHADER_H
#include <DirectXMath.h>
#include "DirectXShader.h"
using namespace DirectX;

namespace BAME
{
	class DirectXGUIShader final : public DirectXShader
	{
	public:

		DirectXGUIShader(Microsoft::WRL::ComPtr<ID3D11Device> const& device, Microsoft::WRL::ComPtr<ID3D11DeviceContext> const& deviceContext);

		~DirectXGUIShader()
		{
		};

		void Update(RenderObject const& renderObj, Matrix4x4f const& viewMatrix, Matrix4x4f const& projectionMatrix, Vector3f const& camPos, ShaderData const& renderData) override;

		void SetActive() override;

	private:

		void CreateInputLayout() override;

		void CreateVertexShader() override;
		void CreatePixelShader() override;
		void CreateGeometryShader() override;

		void CreateConstantBuffers() override;

		void createTextureSampler();

		Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> mShaderResourceView;
		Microsoft::WRL::ComPtr<ID3D11SamplerState> mSamplerState;

		//Microsoft::WRL::ComPtr<ID3D11Resource> mResource;

		// Shader resources
		enum ConstantBufferTypes
		{
			CB_Appliation,
			CB_Frame,
			CB_Object,
			//CB_Material,
			NumConstantBuffers
		};

		Microsoft::WRL::ComPtr<ID3D11Buffer> mD3dConstantBuffers[NumConstantBuffers];

		struct cbPerApplication
		{
		};

		struct cbPerFrame
		{
			XMMATRIX mViewMatrix;
			XMMATRIX mProjectionMatrix;
			XMMATRIX mMVPMatrix;
		};

		struct cbPerObject
		{
			XMMATRIX mWorldMatrix;
		};

	private:
		//Matrix4x4f mOrthoProjMatrix;
		cbPerFrame perFrame;
		cbPerObject perObject;
	};
}
#endif
