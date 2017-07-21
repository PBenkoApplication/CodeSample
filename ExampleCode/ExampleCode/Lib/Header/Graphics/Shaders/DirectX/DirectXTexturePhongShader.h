#ifndef DIRECTXTEXTUREPHONGSHADER_H
#define DIRECTXTEXTUREPHONGSHADER_H
#include <DirectXMath.h>
#include "DirectXShader.h"
using namespace DirectX;

namespace BAME
{
	class DirectXTexturePhongShader final : public DirectXShader
	{
	public:

		DirectXTexturePhongShader(Microsoft::WRL::ComPtr<ID3D11Device> const& device, Microsoft::WRL::ComPtr<ID3D11DeviceContext> const& deviceContext): DirectXShader(device, deviceContext)
		{
		};

		~DirectXTexturePhongShader()
		{
		};

		void Update(RenderObject const& renderObj, Matrix4x4f const& viewMatrix, Matrix4x4f const& projectionMatrix, Vector3f const& camPos, ShaderData const& renderData) override;
		//void Update(RenderObject const& renderObj, Matrix4x4f const& viewMatrix, Matrix4x4f const& projectionMatrix, Vector3f const& camPos);


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

		// Shader resources
		enum ConstantBufferTypes
		{
			CB_Appliation,
			CB_Frame,
			CB_Object,
			CB_Light,
			//CB_Material,
			NumConstantBuffers
		};

		enum PixelConstantBufferTypes
		{
			PCB_Light,
			PCB_NumConstantBuffers
		};

		Microsoft::WRL::ComPtr<ID3D11Buffer> mD3dConstantBuffers[NumConstantBuffers];
		Microsoft::WRL::ComPtr<ID3D11Buffer> mD3dPixelConstantBuffers[PCB_NumConstantBuffers];


		struct cbPerApplication
		{
		};

		struct cbPerFrame
		{
			XMMATRIX mViewMatrix;
			XMMATRIX mProjectionMatrix;
			XMMATRIX mMVP;
		};

		struct cbPerObject
		{
			XMMATRIX mWorldMatrix;
			XMMATRIX mInverseTransposeWorldMatrix;
		};

		struct cbDirectionalPhongLight
		{
			XMFLOAT3 lightColor;
			float lightIntensity;
			XMFLOAT3 lightDirection;
			float filler;
		};
	};
}
#endif
