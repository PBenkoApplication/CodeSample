#ifndef ISHADER_H
#define ISHADER_H
#include "../Rendering/Renderer/RenderObject.h"
#include "ShaderData.h"

namespace BAME
{
	class IShader
	{
	public:

		IShader();

		virtual ~IShader()
		{
		};

		bool IsInit() const;
		virtual void Init() =0;
		virtual void SetActive() = 0;
		virtual void Deactivate() = 0;
		virtual void Update(RenderObject const& renderObj, Matrix4x4f const& viewMatrix, Matrix4x4f const& projectionMatrix, Vector3f const& camPos, ShaderData const& renderData) =0;// Matrix4x4f const& viewMatrix, Matrix4x4f const& projectionMatrix) = 0;
		virtual void Update(Matrix4x4f const& viewMatrix, Matrix4x4f const& projectionMatrix, Vector3f const& camPos);;// Matrix4x4f const& viewMatrix, Matrix4x4f const& projectionMatrix) = 0;


	protected:
		bool mIsInit;
	};
}
#endif
