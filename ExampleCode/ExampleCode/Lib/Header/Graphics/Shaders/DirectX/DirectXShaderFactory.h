#ifndef DIRECTXSHADERFACTORY_H
#define DIRECTXSHADERFACTORY_H

#include "../IShaderFactory.h"
#include <d3d11.h>
#include <wrl/client.h>

namespace BAME
{
	class DirectXShaderFactory final : public IShaderFactory
	{
	public:
		DirectXShaderFactory(Microsoft::WRL::ComPtr<ID3D11Device> const& device, Microsoft::WRL::ComPtr<ID3D11DeviceContext> const& deviceContext);
		~DirectXShaderFactory();

		std::unique_ptr<IShader> CreateBasicShader() override;
		std::unique_ptr<IShader> CreateGUIShader() override;
		std::unique_ptr<IShader> CreateLightningShader() override;
		std::unique_ptr<IShader> CreateSkydomeShader() override;
		std::unique_ptr<IShader> CreateTexturePhongShader() override;
		std::unique_ptr<IShader> CreateTextureShader() override;
		std::unique_ptr<IShader> CreateParticleShader() override;
		std::unique_ptr<IShader> CreateGeometryPassShader() override;
		std::unique_ptr<IShader> CreateLightningPassShader() override;
		std::unique_ptr<IShader> CreateSkyboxShader() override;
		std::unique_ptr<IShader> CreateShadowMapShader() override;
		std::unique_ptr<IShader> CreateLightningSkinning() override;
		std::unique_ptr<IShader> CreateDemoSceneShader() override;
		//void SetActiveShader(const IShader::ShaderType shadertype) override;
		////void Init(Microsoft::WRL::ComPtr<ID3D11Device> const& device, Microsoft::WRL::ComPtr<ID3D11DeviceContext> const& deviceContext);
		//void UpdateView(Matrix4x4f const& viewMatrix, Matrix4x4f const& projectionMatrix, Vector3f const& camPos);
		//void BindObjectToShader(RenderObject const& renderObj);
	private:
		Microsoft::WRL::ComPtr<ID3D11Device> const& mDevice;
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> const& mDeviceContext;
		//Microsoft::WRL::ComPtr<ID3D11Device> m3DDevice;
		//Microsoft::WRL::ComPtr<ID3D11DeviceContext> mDeviceContext;
		///*DirectXBasicShader mBasicShader;
		//DirectXTextureShader mTextureShader;
		//DirectXGUIShader mGUIShader;
		//DirectXTexturePhongShader mTexturePhongShader;
		//DirectXPhongShader mPhongShader;
		//DirectXLightningShader mLightningShader;
		//DirectXSkydomeShader mSkydomeShader;*/
		//IShader::ShaderType mActiveShader;


		/*Matrix4x4f mViewMatrix;
		Matrix4x4f mProjMatrix;
		Vector3f mCamPos;*/
	};
}

#endif
