#ifndef DIRECTXLIGHTNINGPASSSHADER_H
#define DIRECTXLIGHTNINGPASSSHADER_H
#include <DirectXMath.h>
#include "DirectXShader.h"
#include "../../Lighting/DirectLight.h"
using namespace DirectX;


namespace BAME
{
	class DirectXLightningPassShader : public DirectXShader
	{
	public:
		DirectXLightningPassShader(Microsoft::WRL::ComPtr<ID3D11Device> const& device, Microsoft::WRL::ComPtr<ID3D11DeviceContext> const& deviceContext);
		~DirectXLightningPassShader();

		void Update(RenderObject const& renderObj, Matrix4x4f const& viewMatrix, Matrix4x4f const& projectionMatrix, Vector3f const& camPos, ShaderData const& renderData) override;
		void SetActive() override;

	private:

		void CreateInputLayout() override;

		void CreateVertexShader() override;
		void CreatePixelShader() override;
		void CreateGeometryShader() override;

		void CreateConstantBuffers() override;

		void createTextureSampler();

		//Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> mShaderResourceView;
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
			PCB_Light,
			PCB_NumConstantBuffers
		};

		//Microsoft::WRL::ComPtr<ID3D11Buffer> mD3dConstantBuffers[NumConstantBuffers];
		Microsoft::WRL::ComPtr<ID3D11Buffer> mD3dPixelConstantBuffers[PCB_NumConstantBuffers];

		//Textures
		//0: Diffuse, 1:Specular, 2: Bump, 3: Environment
		//Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> mD3dPixelShaderResourceViewList[3];
		//Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> mPixelShaderEnvironmentMapResView;


		struct cbPerApplication
		{
		};

		struct alignas(16) cbPerFrame
		{
		};

		struct alignas(16) cbPerObject
		{
		};

		enum LightType
		{
			DLight = 0,
			PLight = 1,
			SLight = 2
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

			int LightNumber;
			//----------------------------------- (16 byte boundary)
			Light Lights[200];
			//std::vector<Light> Lights;
		};

		/*void UpdateConstantBuffer(ID3D11Buffer* buffer, void const* data, size_t dataSize);*/
	};
}
#endif
