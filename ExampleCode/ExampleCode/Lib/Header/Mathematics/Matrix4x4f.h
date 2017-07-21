#ifndef MATRIX4X4F_H
#define MATRIX4X4F_H
#include "Vector3f.h"
#include "Vector4f.h"

namespace BAME
{
	class Matrix4x4f
	{
	public:
		/*Matrix4x4f(const Matrix4x4f& other)
		{
			mMatrix[0][0] = other.mMatrix[0][0];
			mMatrix[0][1] = other.mMatrix[0][1];
			mMatrix[0][2] = other.mMatrix[0][2];
			mMatrix[0][3] = other.mMatrix[0][3];

			mMatrix[1][0] = other.mMatrix[1][0];
			mMatrix[1][1] = other.mMatrix[1][1];
			mMatrix[1][2] = other.mMatrix[1][2];
			mMatrix[1][3] = other.mMatrix[1][3];

			mMatrix[2][0] = other.mMatrix[2][0];
			mMatrix[2][1] = other.mMatrix[2][1];
			mMatrix[2][2] = other.mMatrix[2][2];
			mMatrix[2][3] = other.mMatrix[2][3];

			mMatrix[3][0] = other.mMatrix[3][0];
			mMatrix[3][1] = other.mMatrix[3][1];
			mMatrix[3][2] = other.mMatrix[3][2];
			mMatrix[3][3] = other.mMatrix[3][3];
		}

		Matrix4x4f(Matrix4x4f&& other) noexcept
		{
						mMatrix[0][0] = other.mMatrix[0][0];
						mMatrix[0][1] =other.mMatrix[0][1];
						mMatrix[0][2] = other.mMatrix[0][2];
						mMatrix[0][3] = other.mMatrix[0][3];
			
						mMatrix[1][0] = other.mMatrix[1][0];
						mMatrix[1][1] = other.mMatrix[1][1];
						mMatrix[1][2] = other.mMatrix[1][2];
						mMatrix[1][3] = other.mMatrix[1][3];
			
						mMatrix[2][0] = other.mMatrix[2][0];
						mMatrix[2][1] = other.mMatrix[2][1];
						mMatrix[2][2] = other.mMatrix[2][2];
						mMatrix[2][3] = other.mMatrix[2][3];
			
						mMatrix[3][0] = other.mMatrix[3][0];
						mMatrix[3][1] = other.mMatrix[3][1];
						mMatrix[3][2] = other.mMatrix[3][2];
						mMatrix[3][3] = other.mMatrix[3][3];
		}

		Matrix4x4f& operator=(const Matrix4x4f& other)
		{
			if (this == &other)
				return *this;

			mMatrix[0][0] = other.mMatrix[0][0];
			mMatrix[0][1] = other.mMatrix[0][1];
			mMatrix[0][2] = other.mMatrix[0][2];
			mMatrix[0][3] = other.mMatrix[0][3];

			mMatrix[1][0] = other.mMatrix[1][0];
			mMatrix[1][1] = other.mMatrix[1][1];
			mMatrix[1][2] = other.mMatrix[1][2];
			mMatrix[1][3] = other.mMatrix[1][3];

			mMatrix[2][0] = other.mMatrix[2][0];
			mMatrix[2][1] = other.mMatrix[2][1];
			mMatrix[2][2] = other.mMatrix[2][2];
			mMatrix[2][3] = other.mMatrix[2][3];

			mMatrix[3][0] = other.mMatrix[3][0];
			mMatrix[3][1] = other.mMatrix[3][1];
			mMatrix[3][2] = other.mMatrix[3][2];
			mMatrix[3][3] = other.mMatrix[3][3];

			return *this;
		}

		Matrix4x4f& operator=(Matrix4x4f&& other) noexcept
		{
			if (this == &other)
				return *this;

			mMatrix[0][0] = other.mMatrix[0][0];
			mMatrix[0][1] = other.mMatrix[0][1];
			mMatrix[0][2] = other.mMatrix[0][2];
			mMatrix[0][3] = other.mMatrix[0][3];

			mMatrix[1][0] = other.mMatrix[1][0];
			mMatrix[1][1] = other.mMatrix[1][1];
			mMatrix[1][2] = other.mMatrix[1][2];
			mMatrix[1][3] = other.mMatrix[1][3];

			mMatrix[2][0] = other.mMatrix[2][0];
			mMatrix[2][1] = other.mMatrix[2][1];
			mMatrix[2][2] = other.mMatrix[2][2];
			mMatrix[2][3] = other.mMatrix[2][3];

			mMatrix[3][0] = other.mMatrix[3][0];
			mMatrix[3][1] = other.mMatrix[3][1];
			mMatrix[3][2] = other.mMatrix[3][2];
			mMatrix[3][3] = other.mMatrix[3][3];

			return *this;
		}*/


		Matrix4x4f();
		~Matrix4x4f();
//Matrix4x4f(const Matrix4x4f&& other) noexcept
//		{
//
//			mMatrix[0][0] = other.mMatrix[0][0];
//			mMatrix[0][1] =other.mMatrix[0][1];
//			mMatrix[0][2] = other.mMatrix[0][2];
//			mMatrix[0][3] = other.mMatrix[0][3];
//
//			mMatrix[1][0] = other.mMatrix[1][0];
//			mMatrix[1][1] = other.mMatrix[1][1];
//			mMatrix[1][2] = other.mMatrix[1][2];
//			mMatrix[1][3] = other.mMatrix[1][3];
//
//			mMatrix[2][0] = other.mMatrix[2][0];
//			mMatrix[2][1] = other.mMatrix[2][1];
//			mMatrix[2][2] = other.mMatrix[2][2];
//			mMatrix[2][3] = other.mMatrix[2][3];
//
//			mMatrix[3][0] = other.mMatrix[3][0];
//			mMatrix[3][1] = other.mMatrix[3][1];
//			mMatrix[3][2] = other.mMatrix[3][2];
//			mMatrix[3][3] = other.mMatrix[3][3];
//		}

		
		void SetMatrix(const float f[4][4]);
		void SetMatrixAsRowMajor(const float m00, const float m01, const float m02, const float m03,
		                         const float m10, const float m11, const float m12, const float m13,
		                         const float m20, const float m21, const float m22, const float m23,
		                         const float m30, const float m31, const float m32, const float m33);
		float GetValue(const int row, const int col) const;
		//const float* GetValues() const;
		float* GetMatrix();
		void Set(const int row, const int col, const float value);
		float Get(const int row, const int col) const;
		static Matrix4x4f GetOrthogonalProjMatrix(float right, float left, float top, float bottom, float nearPlane, float farPlane);
		static Matrix4x4f GetLookAtRH(Vector3f eye, Vector3f target, Vector3f up);
		void SetIdentity();
		Matrix4x4f Add(Matrix4x4f const& matrix);
		void SetMatrixAsColumnMajor(const float* const values[16]);
		void SetMatrixAsRowMajor(const float* const values[16]);
		Matrix4x4f Transposed() const;
		static Matrix4x4f GetTranslationMatrix(Vector3f const& v);
		static Matrix4x4f GetRotationMatrix(Vector3f const& v);
		static Matrix4x4f GetScaleMatrix(Vector3f const& v);
		//static Matrix4x4f GetTranslationMatrix(const float x, const float y, const float z);
		static Matrix4x4f GetRotationMatrix(const float x, const float y, const float z);
		//static Matrix4x4f GetScaleMatrix(const float x, const float y, const float z);
		static Matrix4x4f GetIdendityMatrix();

		static Matrix4x4f GetPerspProjMatrixDirectX(float fov, float aspectRatio, float nearPlane, float farPlane);
		float Determinant();
		Matrix4x4f Inversed();
		Matrix4x4f Adjugated();
		static Matrix4x4f GetRotationMatrixLH(const float angle, const Vector3f& axis);
		Matrix4x4f Multiply(const Matrix4x4f& m) const;
		Vector4f Multiply(Vector4f const& vec) const;

		friend Matrix4x4f operator*(float const lhs, Matrix4x4f const& rhs);
		friend Matrix4x4f operator*(Matrix4x4f const& lhs, float const rhs);

		friend Matrix4x4f operator+(Matrix4x4f const&lhs, Matrix4x4f const& rhs);

		friend bool operator==(Matrix4x4f const&lhs, Matrix4x4f const& rhs);
		friend bool operator!=(Matrix4x4f const&lhs, Matrix4x4f const& rhs);

	private:
		void M4x4_SSE(const float* A, const float* B, float* C) const;
		float mMatrix[4][4];
		/*__declspec(align(16))
		float mValues[16];*/
	};
}

#endif
