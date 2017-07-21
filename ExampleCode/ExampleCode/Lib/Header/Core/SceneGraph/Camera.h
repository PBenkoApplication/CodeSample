#ifndef CAMERA_H
#define CAMERA_H
#include "../../Mathematics/Vector3f.h"
#include "../../Mathematics/Matrix4x4f.h"
#include "../../Graphics/Rendering/Renderer/RendererType.h"
#include "../../Core/InputAPI/InputManager.h"

namespace BAME
{
	class Camera
	{
	public:
		Camera();
		~Camera();
		void Init(InputManager* inputManager, const int windowWidth, const int windowHeight, const float fov, const Vector3f& startPosition, const Vector3f& viewDirection, const Vector3f& upDirection, const float nearClippingPlane, const float farClippingPlane);
	private:
		enum ProjectionType
		{
			ORTHOGRAPHIC,
			PERSPECTIVE
		};

		Vector3f mPosition;
		Vector3f mViewDirection;
		Vector3f mUpDirection;
		Vector3f mForwardDirection;
		Vector3f mRightDirection;
		Matrix4x4f mViewMatrix;
		Matrix4x4f mProjectionMatrix;
		ProjectionType mProjectionType;
		float mAspectRatio;
		float mFOV;
		float mNearClippingPlane;
		float mFarClippingPlane;
		float mAngleX;
		float mWindowWidth;
		float mWindowHeight;

		float mTranslationSensitivity;
		float mRotationSensitivity;
		bool mCursorIsShown;


		Vector3f mGlobalYAxis;

		RendererType mRendererType;
		InputManager* mInputManager;

		float mShakeDuration = 0;
		bool mIsShaking = false;
		void CalculateViewMatrix();
		void CalculateViewMatrix(Vector3f const& position);
		void CalculateProjMatrix();
		void CalculateMovement(float deltaTime = 1);


	public:
		void Update(float deltaTime = 1);

		float GetAspectRatio() const
		{
			return mAspectRatio;
		}

		void SetAspectRatio(const float value)
		{
			mAspectRatio = value;
		}

		float GetFOV() const
		{
			return mFOV;
		}

		void SetFOV(const float value)
		{
			mFOV = value;
		}

		float GetNearClippingPlane() const
		{
			return mNearClippingPlane;
		}

		void SetNearClippingPlane(const float value)
		{
			mNearClippingPlane = value;
		}

		float GetFarClippingPlane() const
		{
			return mFarClippingPlane;
		}

		void SetFarClippingPlane(const float value)
		{
			mFarClippingPlane = value;
		}

		void SetOrthographic()
		{
			mProjectionType = ORTHOGRAPHIC;
		}

		void SetPerspective()
		{
			mProjectionType = PERSPECTIVE;
		}

		Vector3f const& GetPosition() const
		{
			return mPosition;
		}

		void SetPosition(Vector3f const& value)
		{
			mPosition = value;
		}

		Vector3f const& GetViewDirection() const
		{
			return mViewDirection;
		}

		void SetViewDirection(Vector3f const& value)
		{
			mViewDirection = value;
		}

		Vector3f const& GetUpDirection() const
		{
			return mUpDirection;
		}

		void SetUpDirection(Vector3f const& value)
		{
			mUpDirection = value;
		}

		Matrix4x4f const& GetViewMatrix() const
		{
			return mViewMatrix;
		}

		void SetViewMatrix(Matrix4x4f const& value)
		{
			mViewMatrix = value;
		}

		Matrix4x4f const& GetProjectionMatrix() const
		{
			return mProjectionMatrix;
		}

		void SetProjectionMatrix(Matrix4x4f const& value)
		{
			mProjectionMatrix = value;
		}

		void Move(const float globalX, const float globalY, const float globalZ);
		void Move(Vector3f const& direction, float amount);
		Vector3f GetShakePosition() const;
		void Shake(float time);
		void RotateX(const float angle);
		void RotateY(const float angle);
		Vector3f const& GetForward() const;
		Vector3f GetLeft() const;
		Vector3f GetRight() const;

		void SetTranslationSensitivity(float sensitivity)
		{
			mTranslationSensitivity = sensitivity * 10;
		}

		void SetRotationSensitivity(float sensitivity)
		{
			mRotationSensitivity = sensitivity * 100;
		}

		void SetRendererType(RendererType rendererType)
		{
			mRendererType = rendererType;
		}
	};
}
#endif
