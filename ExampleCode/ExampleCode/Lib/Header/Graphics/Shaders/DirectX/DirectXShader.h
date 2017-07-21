#ifndef DIRECTXSHADER_H
#define DIRECTXSHADER_H
#include "../IShader.h"
#include <wrl/client.h>
#include <d3d11.h>

namespace BAME
{
	class DirectXShader : public IShader
	{
	public:
		DirectXShader(Microsoft::WRL::ComPtr<ID3D11Device> const& device, Microsoft::WRL::ComPtr<ID3D11DeviceContext> const& deviceContext);
		virtual ~DirectXShader();

		Microsoft::WRL::ComPtr<ID3D11VertexShader> const& GetVertexShader() const;
		Microsoft::WRL::ComPtr<ID3D11PixelShader> const& GetPixelShader() const;
		Microsoft::WRL::ComPtr<ID3D11GeometryShader> const& GetGeometryShader() const;


		/*virtual void Update(RenderObject const& renderObj, Matrix4x4f const& viewMatrix, Matrix4x4f const& projectionMatrix) = 0;*/

		void Init() override;
	protected:
		virtual void CreateVertexShader() = 0;
		virtual void CreatePixelShader() = 0;
		virtual void CreateGeometryShader() = 0;

		virtual void CreateInputLayout() = 0;
		virtual void CreateConstantBuffers() = 0;

		//void AddShaderRessourceView(Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> const& shaderResourceView);

	public:
		void Deactivate() override;
	protected:
		Microsoft::WRL::ComPtr<ID3D11VertexShader> mD3dVertexShader = nullptr;
		Microsoft::WRL::ComPtr<ID3D11PixelShader> mD3dPixelShader = nullptr;
		Microsoft::WRL::ComPtr<ID3D11GeometryShader> mD3dGeometryShader = nullptr;
		Microsoft::WRL::ComPtr<ID3D11InputLayout> mD3dInputLayout = nullptr;

		Microsoft::WRL::ComPtr<ID3D11Device> const& mDevice;
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> const& mDeviceContext;


		//std::vector<Microsoft::WRL::ComPtr<ID3D11ShaderResourceView>>mD3dPixelShaderResourceViewList;
	};
}
#endif
