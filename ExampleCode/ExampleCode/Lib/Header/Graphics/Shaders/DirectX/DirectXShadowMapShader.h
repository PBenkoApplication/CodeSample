#ifndef DIRECTXSHADOWMAPSHADER_H
#define DIRECTXSHADOWMAPSHADER_H
#include <DirectXMath.h>
#include "DirectXShader.h"
using namespace DirectX;

namespace BAME
{
	class DirectXShadowMapShader :public DirectXShader
	{
	public:
		DirectXShadowMapShader(Microsoft::WRL::ComPtr<ID3D11Device> const& device, Microsoft::WRL::ComPtr<ID3D11DeviceContext> const& deviceContext);
		~DirectXShadowMapShader();
		void SetActive() override;
		void Update(RenderObject const& renderObj, Matrix4x4f const& viewMatrix, Matrix4x4f const& projectionMatrix, Vector3f const& camPos, ShaderData const& renderData) override;
	protected:
		void CreateVertexShader() override;
		void CreatePixelShader() override;
		void CreateGeometryShader() override;
		void CreateInputLayout() override;
		void CreateConstantBuffers() override;

	private:
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

		struct alignas(16) cbPerFrame
		{
			XMMATRIX mMVPMatrix;
			XMFLOAT3 lightPos;
			float padding;
		};

		struct alignas(16) cbPerObject
		{
		};
	};
}
#endif
