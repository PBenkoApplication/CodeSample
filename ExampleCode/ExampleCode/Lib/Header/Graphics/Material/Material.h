#ifndef MATERIAL_H
#define MATERIAL_H
#include "../Textures/Texture.h"
#include "ColorRGB.h"
#include "../Shaders/PresetShaderType.h"
#include "../../Mathematics/Vector2f.h"
#include "ShadowProperties.h"

namespace BAME
{
	class Material : public ShadowProperties
	{
	public:
		Material();
		~Material();

		ColorRGB const& GetDiffuse() const;
		ColorRGB const& GetAmbient() const;
		ColorRGB const& GetSpecular() const;
		ColorRGB const& GetEmissive() const;


		Texture const& GetDiffuseTexture() const;
		Texture const& GetSpecularMap() const;
		Texture const& GetBumpMap() const;
		Texture const& GetGlowMap() const;
		Texture const& GetDisplacementMap() const;
		Texture const& GetEnvironmentMap() const;
		PresetShaderType GetShaderType() const;

		float GetGlossiness() const;
		float GetAlpha() const;
		bool IsDiffuseTextureUsed() const;
		bool IsBumpMapUsed() const;
		bool IsSpecularMapUsed() const;
		bool IsEnvironmentMapUsed() const;
		bool IsDisplacementMapUsed() const;
		bool IsParallaxOcclusionUsed() const;

		void SetDiffuse(ColorRGB const& diffuse);
		void SetEmissive(ColorRGB const& emissive);
		void SetAmbient(ColorRGB const& ambient);
		void SetSpecular(ColorRGB const& specular);

		void SetDiffuse(const float r, const float g, const float b);
		void SetEmissive(const float r, const float g, const float b);
		void SetAmbient(const float r, const float g, const float b);
		void SetSpecular(const float r, const float g, const float b);
		void SetGlossiness(const float glossiness);
		void SetAlpha(float alpha);

		void SetDiffuseMap(std::string const& filepath, bool issRGB=false);
		void SetDiffuseMap(Texture const& texture);
		void SetSpecularMap(std::string const& filepath, bool issRGB = false);
		void SetSpecularMap(Texture const& texture);
		void SetBumpMap(std::string const& filepath, bool issRGB = false);
		void SetBumpMap(Texture const& texture);
		void SetGlowMap(std::string const& filepath, bool issRGB = false);
		void SetGlowMap(Texture const& texture);
		void SetDisplacementMap(std::string const& filepath, bool issRGB = false);
		void SetDisplacementMap(Texture const& texture);
		void SetEnvironmentMap(std::string const& filepath, bool issRGB = false);
		void SetEnvironmentMap(Texture const& texture);
		void SetShaderType(const PresetShaderType shaderType);

		void SetTextureOffset(Vector2f const& offset);
		void SetParallaxOcclusion(bool enabled);

		Vector2f const& GetTextureOffset() const;

		bool IsDiffsRGB() const;
		bool IsSpecssRGB() const;
		bool IsBumpssRGB() const;
		bool IsGlowsRGB() const;
		bool IsDispsRGB() const;
		bool IsEnvsRGB() const;

	private:

		bool mIsDiffsRGB;
		bool mIsSpecsRGB;
		bool mIsBumpsRGB;
		bool mIsGlowsRGB;
		bool mIsDispsRGB;
		bool mIsEnvsRGB;

		ColorRGB mEmissive;
		ColorRGB mAmbient;
		ColorRGB mDiffuse;
		ColorRGB mSpecular;

		Texture mDiffuseMap;
		Texture mSpecularMap;
		Texture mBumpMap;
		Texture mGlowMap;
		Texture mDisplacementMap;
		Texture mEnvironmentMap;

		PresetShaderType mShaderType;
		Vector2f mTextureOffset;

		float mGlossiness;
		float mAlpha;
		bool mIsTransparent;
		bool mUseTexture;
		bool mUseBumpMap;
		bool mUseSpecularMap;
		bool mUseEnvironmentMap;
		bool mUseDisplacementMap;
		bool mUseParallaxOcclusion;
	};
}

#endif
