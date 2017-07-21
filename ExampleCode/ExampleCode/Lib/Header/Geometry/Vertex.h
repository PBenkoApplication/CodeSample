#ifndef VERTEX_H
#define VERTEX_H
#include "../Mathematics/Vector3f.h"
#include "../Mathematics/Vector2f.h"
#include "../Graphics/Material/ColorRGB.h"

namespace BAME
{
	class Vertex
	{
	public:

		
		Vertex()
		{
		};

		Vertex(Vector3f const& pos, ColorRGB const& color, Vector2f const& texCoord, Vector3f const& normal, Vector3f const& tangent, Vector3f const& binormal);

		~Vertex();

		Vector3f const& GetPosition() const;
		Vector2f const& GetTexCoord() const;
		ColorRGB const& GetColor() const;
		bool IsEqual(Vertex const& vertex) const;
		Vector3f const& GetNormal() const;
		Vector3f const& GetTangent() const;
		Vector3f const& GetBinormal() const;
		void SetNormal(Vector3f const& normal);
		void SetTangent(Vector3f const& tangent);
		void SetBinormal(Vector3f const& binormal);
		void SetTexCoord(Vector2f const& texcoord);
		void SetPosition(Vector3f const& position);
		void SetColor(ColorRGB const& color);
		bool operator==(Vertex const& rhs) const;

	protected:
		Vector3f mPosition;
		ColorRGB mColor;
		Vector2f mTexCoord;
		Vector3f mNormal;
		Vector3f mTangent;
		Vector3f mBinormal;
	};
}
#endif
