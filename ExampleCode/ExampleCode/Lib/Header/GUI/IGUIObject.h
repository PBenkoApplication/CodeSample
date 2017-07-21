#ifndef IGUIOBJECT_H
#define IGUIOBJECT_H
//#include "../Core/SceneGraph/Placement.h"
#include "../Mathematics/Quaternion.h"
#include "../Core/SceneGraph/Placement.h"

//#include <string>
//#include "../Core/SceneGraph/Placement.h"
//#include "../Geometry/GUIPlane.h"


//---------------------------------------------------
// IGUIObjekt Interface
// Beschreibung:
//
// Autor: Patrick Benkowitsch
//---------------------------------------------------
namespace BAME
{
	class IGUIObject
	{
	public:
		IGUIObject();

		virtual ~IGUIObject();

		virtual bool CheckHover(const float fPosX, const float fPosY) = 0;


		virtual void CheckEvent();

		virtual void OnMouseOver(void) = 0;
		virtual void OnMouseOut(void) = 0;
		virtual void OnMouseClickLeft(void) = 0;
		virtual void OnMouseClickRight(void) = 0;

		Placement* GetPlacement();

		Matrix4x4f const& GetWorldMatrix() const;

		void SetWorldMatrix(Matrix4x4f const& worldMatrix);

		void Translate(Vector3f const& vec);

		void Rotate(const float angle, Vector3f const& axis); ///TODO: Neu machen


		void Scale(Vector3f const& vec);


		//	virtual bool isOn()
		//	{
		//		return m_bisOn;
		//	}

		//	/*virtual CFloatRect getRectangle()
		//	{
		//		return m_zfrRect;
		//	}

		//	virtual void setRectangle(CFloatRect tempRect)
		//	{
		//		m_zfrRect = tempRect;
		//	}*/

		//	virtual void setLayer(const float layer) = 0;

		//	//virtual void updateRectangle(CFloatRect rect) = 0;

		//	float getLayer() const
		//	{
		//		return m_fLayer;
		//	}

		//	std::string const& getName() const
		//	{
		//		return m_sName;
		//	}
		//	void setName(const std::string& sName)
		//	{
		//		m_sName = sName;
		//	}

		//	ObjectType getType() const
		//	{
		//		return m_ObjectType;
		//	}

		//	void disable()
		//	{
		//		m_bisOn = false;
		//	}

		//	void enable()
		//	{
		//		m_bisOn = true;
		//	}

		//	//GUIPlane & GetNormalPlane() { return normalPlane; }
		//	Placement const& GetNormalPlacement() const{ return mNormalPlace; }
		//	
		//	//virtual void resize(int width, int height);
		//protected:
		//	GUIPlane normalPlane;
		//	Placement mNormalPlace;

		//	//CFloatRect m_zfrRect = CFloatRect(0, 0, 0, 0);
		//	bool m_bisOn = true;
		//	float m_fLayer = 1.0;
		//	std::string m_sName = "";
		//	ObjectType m_ObjectType;
		//Placement* GetPlacement();
		//std::vector<GUIPlane> const& GetGUIPlanes() const { return mGUIPlanes; }

	protected:
		//Verweis auf Placement
		//std::vector<GUIPlane> mGUIPlanes;
		Placement mPlacement;
		float mLayer;
		bool m_wasHover;
		//Matrix4x4f mWorldMatrix;
	};
}
#endif
