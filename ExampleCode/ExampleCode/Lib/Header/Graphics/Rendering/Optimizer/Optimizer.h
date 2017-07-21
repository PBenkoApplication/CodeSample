#ifndef OPTIMIZER_H
#define OPTIMIZER_H
#include <../../../Mathematics/Vector3f.h>
#include <memory>
#include "../../../Core/SceneGraph/Camera.h"
#include "../../../Physics/BoundingVolumes/AABB.h"

namespace BAME
{

	class Optimizer
	{
	public:
		/*static void setCamInternals(float angle, float ratio, float nearD, float farD);
		static void setCamDef(Vector3f const& p, Vector3f const& l, Vector3f const& u);

		 static bool checkPointInFrustum(Vector3f const& point);
		 static bool checkSphereInFrustum(Vector3f& p, float radius);*/
		static bool checkBoxInFrustum(Matrix4x4f const& model, AABB const& aabb);
		static bool checkSphereInFrustum(Matrix4x4f const& model, float radius);

		static Optimizer* GetInstance();

		static void SetCamera(Camera* camera);
	private:
		static Camera* mCam;
		//static Vector3f mCamPos;
		//static Vector3f X, Y, Z; //the camera referential
		//static float mNearD, mFarD, width, height, mRatio, mTang;
		//static float sphereFactorX;
		//static float sphereFactorY;
		static std::unique_ptr<Optimizer> mInstance;
		Optimizer();
		
		//~Optimizer();
	};
}
#endif