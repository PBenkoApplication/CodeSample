#ifndef IRENDEROBJECT_H
#define IRENDEROBJECT_H
#include "../../../Core/SceneGraph/Placement.h"
#include "../../../Geometry/IGeo3D.h"
#include "../../Textures/ITexture.h"
#include "../Buffer/BufferHandler.h"
#include "../../Shaders/PresetShaderType.h"
#include "../../Material/Material.h"
#include <memory>
#include "../../Textures/TextureFactory/DirectXTextureFactory.h"
#include "../../../Physics/BoundingVolumes/AABB.h"
//#include "../../../Physics/BoundingVolumes/BoundingSphere.h"

namespace BAME
{
	class ITextureFactory;

	class RenderObject
	{
	public:


		RenderObject(IGeo3D* geo, Placement* place, ITextureFactory* textureFactory);
		RenderObject(IGeo3D* geo, ITextureFactory* textureFactory, std::string const& filePath, bool isSRGB);
		void SetTextures(Material const* material);
		RenderObject(BoneMesh* geo, Placement* place, ITextureFactory* textureFactory);
		~RenderObject();
		//void CalculateVertexBoneList(std::vector<Vertex> const& vertexList, MeshBoneData const& meshBoneData, std::vector<VertexBone>& vertexBoneList) const;

		Matrix4x4f const& GetWorldMatrix() const;
		std::vector<unsigned int> const& GetIndexList() const;
		std::vector<Vertex> const& GetVertexList() const;
		//std::vector<VertexBone> const& GetVertexBoneList() const;
		PresetShaderType GetShaderType() const;
		void Update() const;

		template <class T>
		T* GetVertexBuffer() const
		{
			return BufferHandler::Get().GetVertexBuffer<T>(mVertexBufferListKey);
		}

		template <class T>
		T* GetIndexBuffer() const
		{
			return BufferHandler::Get().GetIndexBuffer<T>(mIndexBufferListKey);
		}

		bool IsVisible() const;

		const Material* GetMaterial() const;

		Placement* GetPlacement() const
		{
			return mPlace;
		}

		IGeo3D* GetGeo() const
		{
			return mGeo;
		}

		ITexture* GetDiffuseTexture() const;
		ITexture* GetBumpMap() const;
		ITexture* GetSpecularMap() const;
		ITexture* GetEnvironmentMap() const;
		ITexture* GetDisplacementMap() const;

		void SetDiffuseTexture(Texture const& texture, bool isSRGB);
		void SetBumpMap(Texture const& texture, bool isSRGB);
		void SetSpecularMap(Texture const& texture, bool isSRGB);
		void SetEnvironmentMap(const Texture& texture, bool isSRGB);
		void SetDisplacementMap(const Texture& texture, bool isSRGB);
		//void SetSkyboxTexture(Texture& texture);
		/*void SetSkyboxTexture(std::string const& front, std::string const& back,
			std::string const& left, std::string const& right,
			std::string const& top, std::string const& bottom);*/

		ITexture* GetSkyboxTexture() const;

		void SetWorldMatrixForRender(Matrix4x4f const& matrix) { mWorldMatrixForRender = matrix; }
		Matrix4x4f const& GetWorldMatrixForRender() const;

		AABB const& GetBoundingBox() const{ return mBoundingSphere; }
		void SetBoundingBox(AABB const& boundingSphere) { mBoundingSphere = boundingSphere; }
	protected:
		IGeo3D* mGeo;
		Placement* mPlace;
		AABB mBoundingSphere;

		ITextureFactory* mTextureFactory;
		/*	std::unique_ptr<ITexture> mDiffuseTexture;
			std::unique_ptr<ITexture> mBumpTexture;
			std::unique_ptr<ITexture> mSpecularTexture;
			std::unique_ptr<ITexture> mEnvironmentTexture;
			std::unique_ptr<ITexture> mDisplacementTexture;
			std::unique_ptr<ITexture> mSkyboxTexture;
	*/
		ManagedTexturePtr mDiffuseTexture;
		ManagedTexturePtr mBumpTexture;
		ManagedTexturePtr mSpecularTexture;
		ManagedTexturePtr mEnvironmentTexture;
		ManagedTexturePtr mDisplacementTexture;
		ManagedTexturePtr mSkyboxTexture;


		int mVertexBufferListKey;
		int mIndexBufferListKey;

		Matrix4x4f mWorldMatrixForRender;
	};
}
#endif
