#ifndef DIRECTXMATH_H
#define DERECTXMATH_H
#include "DirectXMath.h"
#include "Vector3f.h"
#include "Matrix4x4f.h"

namespace BAME
{
	namespace MathDirectX
	{
		inline static DirectX::XMVECTOR ConvertToXMVector(const Vector3f& vector)
		{
			XMFLOAT4 temp = XMFLOAT4(vector.GetX(), vector.GetY(), vector.GetZ(), 0);
			return XMLoadFloat4(&temp);
		}

		inline static DirectX::XMFLOAT3 ConvertToXMFloat3(const Vector3f& vector)
		{
			return DirectX::XMFLOAT3(vector.GetX(), vector.GetY(), vector.GetZ());
		}

		inline static DirectX::XMMATRIX ConvertToXMMatrix(const Matrix4x4f& matrix)
		{
			XMFLOAT4X4 temp = XMFLOAT4X4(matrix.Get(0, 0), matrix.Get(0, 1), matrix.Get(0, 2), matrix.Get(0, 3),
			                             matrix.Get(1, 0), matrix.Get(1, 1), matrix.Get(1, 2), matrix.Get(1, 3),
			                             matrix.Get(2, 0), matrix.Get(2, 1), matrix.Get(2, 2), matrix.Get(2, 3),
			                             matrix.Get(3, 0), matrix.Get(3, 1), matrix.Get(3, 2), matrix.Get(3, 3));

			return XMLoadFloat4x4(&temp);
		}

		inline static Matrix4x4f ConvertToMatrix4x4f(const XMMATRIX& matrix)
		{
			XMMATRIX xmMatrix = matrix;

			XMFLOAT4X4 temp;
			XMStoreFloat4x4(&temp, xmMatrix);

			Matrix4x4f resultMatrix;

			resultMatrix.SetMatrixAsRowMajor(temp._11, temp._12, temp._13, temp._14,
			                                 temp._21, temp._22, temp._23, temp._24,
			                                 temp._31, temp._32, temp._33, temp._34,
			                                 temp._41, temp._42, temp._43, temp._44);
			return resultMatrix;
		}
	}
}

#endif
