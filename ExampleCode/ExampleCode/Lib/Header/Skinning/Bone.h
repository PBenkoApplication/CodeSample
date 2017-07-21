#ifndef BONE_H
#define BONE_H
#include "../Mathematics/Matrix4x4f.h"
#include <map>

namespace BAME
{
	class Bone
	{
	public:
		Bone();
		Bone(std::string const& name, Matrix4x4f const& offesetMatrix);
		Matrix4x4f const& GetOffsetMatrix() const;
		Matrix4x4f const& GetFinalTransformMatrix() const;
		void SetFinalTransform(Matrix4x4f const& matrix);
		
	private:
		std::string mName;
		Matrix4x4f mOffsetMatrix;
		Matrix4x4f mFinalTransformation;
	};
}

#endif