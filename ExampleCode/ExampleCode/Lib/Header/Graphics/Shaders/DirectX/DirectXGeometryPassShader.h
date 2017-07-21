#ifndef DIRECTXGEOMETRYPASSSHADER_H
#define DIRECTXGEOMETRYPASSSHADER_H
#include <DirectXMath.h>
#include "DirectXShader.h"
#include "../../Lighting/DirectLight.h"
using namespace DirectX;


namespace BAME
{
	class DirectXGeometryPassShader : public DirectXShader
	{
	public:
		DirectXGeometryPassShader(Microsoft::WRL::ComPtr<ID3D11Device> const& device, Microsoft::WRL::ComPtr<ID3D11DeviceContext> const& deviceContext);
		~DirectXGeometryPassShader();

		void Update(RenderObject const& renderObj, Matrix4x4f const& viewMatrix, Matrix4x4f const& projectionMatrix, Vector3f const& camPos, ShaderData const& renderData) override;
		//void Update(RenderObject const& renderObj, Matrix4x4f const& viewMatrix, Matrix4x4f const& projectionMatrix, Vector3f const& camPos, std::vector<DirectLight*> const& directLightList, std::vector<PointLight*> const& pointLightList, std::vector<SpotLight*> const& spotLightList);
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
		Microsoft::WRL::ComPtr<ID3D11SamplerState> mSamplerCubeMapState;

		// Shader resources
		enum ConstantBufferTypes
		{
			CB_Appliation,
			CB_Frame,
			CB_Object,
			//CB_Material,
			NumConstantBuffers
		};

		enum PixelConstantBufferTypes
		{
			PCB_Material,
			PCB_NumConstantBuffers
		};

		Microsoft::WRL::ComPtr<ID3D11Buffer> mD3dConstantBuffers[NumConstantBuffers];
		Microsoft::WRL::ComPtr<ID3D11Buffer> mD3dPixelConstantBuffers[PCB_NumConstantBuffers];

		//Textures
		//0: Diffuse, 1:Specular, 2: Bump, 3: Environment
		Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> mD3dPixelShaderResourceViewList[5];
		Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> mPixelShaderEnvironmentMapResView;


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


		struct alignas(16) _Material
		{
			_Material()
				: Emissive(0.0f, 0.0f, 0.0f, 1.0f)
				  , Ambient(0.1f, 0.1f, 0.1f, 1.0f)
				  , Diffuse(1.0f, 1.0f, 1.0f, 1.0f)
				  , Specular(1.0f, 1.0f, 1.0f, 1.0f)
				  , SpecularPower(128.0f)
				  , UseTexture(0),
				  UseBumpMap(0),
				  UseSpecularMap(0),
				  UseEnvironmentMap(0),
				  Alpha(1),
				  UseParallaxMapping(0)

			{
			}

			DirectX::XMFLOAT4 Emissive;
			//----------------------------------- (16 byte boundary)
			DirectX::XMFLOAT4 Ambient;
			//----------------------------------- (16 byte boundary)
			DirectX::XMFLOAT4 Diffuse;
			//----------------------------------- (16 byte boundary)
			DirectX::XMFLOAT4 Specular;

			//----------------------------------- (16 byte boundary)
			float SpecularPower;
			// Add some padding complete the 16 byte boundary.
			int UseTexture;
			int UseBumpMap; // 4 bytes
			int UseSpecularMap;
			int UseEnvironmentMap;
			float Alpha;
			DirectX::XMFLOAT2 TextureOffset;
			int UseParallaxMapping;
			float Padding[3];
			// Add some padding to complete the 16 byte boundary.

			//----------------------------------- (16 byte boundary)
		}; // Total:                                80 bytes (5 * 16)

		struct alignas(16) MaterialProperties
		{
			_Material Material;
		};
	};
}
#endif
