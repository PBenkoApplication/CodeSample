#ifndef DIRECTXLIGHTNINGSHADER_H
#define DIRECTXLIGHTNINGSHADER_H
#include <DirectXMath.h>
#include "DirectXShader.h"
#include "../../Lighting/DirectLight.h"
using namespace DirectX;


namespace BAME
{
	class DirectXLightningShader : public DirectXShader
	{
	public:
		DirectXLightningShader(Microsoft::WRL::ComPtr<ID3D11Device> const& device, Microsoft::WRL::ComPtr<ID3D11DeviceContext> const& deviceContext);
		~DirectXLightningShader();

		void Update(RenderObject const& renderObj, Matrix4x4f const& viewMatrix, Matrix4x4f const& projectionMatrix, Vector3f const& camPos, ShaderData const& renderData) override;
		void SetActive() override;

		void SetShadowMap(Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> const& shadowMap);



	private:

		void CreateInputLayout() override;

		void CreateVertexShader() override;
		void CreatePixelShader() override;
		void CreateGeometryShader() override;

		void CreateConstantBuffers() override;

		void createTextureSampler();

	public:
		void Deactivate() override;
	private:
		Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> mShaderResourceView;
		Microsoft::WRL::ComPtr<ID3D11SamplerState> mSamplerState;
		Microsoft::WRL::ComPtr<ID3D11SamplerState> mSamplerStateNoAni;

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
			PCB_Light,
			PCB_NumConstantBuffers
		};

		Microsoft::WRL::ComPtr<ID3D11Buffer> mD3dConstantBuffers[NumConstantBuffers];
		Microsoft::WRL::ComPtr<ID3D11Buffer> mD3dPixelConstantBuffers[PCB_NumConstantBuffers];

		//Textures
		//0: Diffuse, 1:Specular, 2: Bump, 3: Environment
		Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> mD3dPixelShaderResourceViewList[6];
		Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> mPixelShaderEnvironmentMapResView;


		struct cbPerApplication
		{
		};

		struct alignas(16) cbPerFrame
		{
			XMMATRIX mViewMatrix;
			XMMATRIX mProjectionMatrix;
			XMMATRIX mMVPMatrix;
			XMMATRIX mLightWorldViewProj;
			XMFLOAT4 mLightPos;
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
				  UseParallaxMapping(0),
				  UsePCFShadow(0),
				  PCFKernelFactor(4)

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
			int UsePCFShadow;
			int PCFKernelFactor;
			float Padding;
			// Add some padding to complete the 16 byte boundary.

			//----------------------------------- (16 byte boundary)
		}; // Total:                                80 bytes (5 * 16)

		struct alignas(16) MaterialProperties
		{
			_Material Material;
		};

		enum LightType
		{
			DLight=0,
			PLight=1,
			SLight=2
		};

		struct alignas(16) Light
		{
			DirectX::XMFLOAT4 Position; // 16 bytes
			//----------------------------------- (16 byte boundary)
			DirectX::XMFLOAT4 Direction; // 16 bytes
			//----------------------------------- (16 byte boundary)
			DirectX::XMFLOAT4 Color; // 16 bytes
			//----------------------------------- (16 byte boundary)

			int LightType; // 4 bytes
			int Enabled = 0; // 4 bytes
			float minDistance;
			float maxDistance;
			float intensity;
			float minSpotAngle;
			float maxSpotAngle;
			float spotTightness;
		};

		struct alignas(16) LightProperties
		{
			DirectX::XMFLOAT4 EyePosition; // 16 bytes
			//----------------------------------- (16 byte boundary)
			DirectX::XMFLOAT4 GlobalAmbient; // 16 bytes
			//----------------------------------- (16 byte boundary)
			Light Lights[200];
		};
	};
}
#endif
