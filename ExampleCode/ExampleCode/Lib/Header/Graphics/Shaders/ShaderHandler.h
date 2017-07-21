#ifndef ISHADERHANDLER_H
#define ISHADERHANDLER_H
#include "IShader.h"
#include "../Lighting/DirectLight.h"
#include "../Lighting/PointLight.h"
#include "../Lighting/SpotLight.h"
#include <vector>
#include "../../Mathematics/Matrix4x4f.h"
#include "../Rendering/Renderer/RenderObject.h"
#include "PresetShaderType.h"
#include "IShaderFactory.h"
#include "IParticleShader.h"

//Curiously Returning Template
//http://stackoverflow.com/questions/6703199/inheriting-template-methods
//https://en.wikipedia.org/wiki/Curiously_recurring_template_pattern
//Ermöglicht das die Template methode getShader() vererbt werden kann (Polymorphismus)

namespace BAME
{
	class ShaderHandler
	{
	public:
		ShaderHandler();;

		virtual ~ShaderHandler();;


		void UpdateLights(std::vector<DirectLight*> const& directLightList, std::vector<PointLight*> const& pointLightList, std::vector<SpotLight*> const& spotLightList);

		void SetActiveShader(const PresetShaderType shadertype);
		void UpdateView(Matrix4x4f const& viewMatrix, Matrix4x4f const& projectionMatrix, Vector3f const& camPos);
		void BindObjectToShader(RenderObject const& renderObj);
		void BindObjectToShader();
		void UnbindShader();
		void SetShaderData(ShaderData const& shaderData);
		void Init(IShaderFactory* shaderFactory);

		IShader* GetParticleShader() { return mShaderList.at(PresetShaderType::ParticleShader).get(); }// dynamic_cast<IParticleShader*>(mShaderList.at(PresetShaderType::ParticleShader).get()); }

		IShader* GetShader(PresetShaderType shaderType) { return mShaderList.at(shaderType).get(); }

	protected:
		std::vector<DirectLight*> mDirectLightList;
		std::vector<PointLight*> mPointLightList;
		std::vector<SpotLight*> mSpotLightList;
		Matrix4x4f mViewMatrix;
		Matrix4x4f mProjMatrix;
		Vector3f mCamPos;
		ShaderData mRenderData;
	private:
		std::map<PresetShaderType, std::unique_ptr<IShader>> mShaderList;
		PresetShaderType mActiveShaderType;
	};
}
#endif
