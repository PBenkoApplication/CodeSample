#ifndef BUTTON_H
#define BUTTON_H
#include "../Mathematics/Vector2f.h"
#include "IGUIObject.h"
#include "../Geometry/TriangleMesh/GUIPlane.h"

namespace BAME
{
	class Button : public IGUIObject
	{
	public:
	
		Button();

		~Button()
		{
		};

		//Button(const Button& other)
		//	: IGUIObject(other),
		//	mWidth(other.mWidth),
		//	mHeight(other.mHeight),
		//	mLayer(other.mLayer),
		//	normalPlane(other.normalPlane),
		//	hoverPlane(other.hoverPlane),
		//	m_bHasHover(other.m_bHasHover),
		//	m_isActive(other.m_isActive),
		//	material(other.material),
		//	material2(other.material2)
		//{
		//	normalPlane.SetMaterial(&material);
		//	hoverPlane.SetMaterial(&material2);
		//	mPlacement.AddGeo(&normalPlane);
		//	mPlacement.AddGeo(&hoverPlane);
		//}

		/*Button(Button&& other) noexcept
			: IGUIObject(std::move(other)),
			mWidth(other.mWidth),
			mHeight(other.mHeight),
			mLayer(other.mLayer),
			normalPlane(std::move(other.normalPlane)),
			hoverPlane(std::move(other.hoverPlane)),
			m_bHasHover(other.m_bHasHover),
			m_isActive(other.m_isActive),
			material(std::move(other.material)),
			material2(std::move(other.material2))
		{
			normalPlane.SetMaterial(&material);
			hoverPlane.SetMaterial(&material2);
			mPlacement.AddGeo(&normalPlane);
			mPlacement.AddGeo(&hoverPlane);
		}*/

		/*Button& operator=(const Button& other)
		{
			if (this == &other)
				return *this;
			IGUIObject::operator =(other);
			mWidth = other.mWidth;
			mHeight = other.mHeight;
			mLayer = other.mLayer;
			normalPlane = other.normalPlane;
			hoverPlane = other.hoverPlane;
			m_bHasHover = other.m_bHasHover;
			m_isActive = other.m_isActive;
			material = other.material;
			material2 = other.material2;

			normalPlane.SetMaterial(&material);
			hoverPlane.SetMaterial(&material2);
			mPlacement.AddGeo(&normalPlane);
			mPlacement.AddGeo(&hoverPlane);
			return *this;
		}

		Button& operator=(Button&& other) noexcept
		{
			if (this == &other)
				return *this;
			IGUIObject::operator =(std::move(other));
			mWidth = other.mWidth;
			mHeight = other.mHeight;
			mLayer = other.mLayer;
			normalPlane = std::move(other.normalPlane);
			hoverPlane = std::move(other.hoverPlane);
			m_bHasHover = other.m_bHasHover;
			m_isActive = other.m_isActive;
			material = std::move(other.material);
			material2 = std::move(other.material2);

			normalPlane.SetMaterial(&material);
			hoverPlane.SetMaterial(&material2);
			mPlacement.AddGeo(&normalPlane);
			mPlacement.AddGeo(&hoverPlane);

			return *this;
		}*/

		void Init(float width, float height, std::string const& normalPfad, std::string const& hoverPfad, bool isSRGB = false);

		bool CheckHover(const float fPosX, const float fPosY) override;
		void SwitchOn();
		void SwitchOff();
		bool IsActive();
		void OnMouseOver() override;
		void OnMouseOut() override;
		void OnMouseClickLeft() override;
		void OnMouseClickRight() override;
		void SetLayer(const float layer);
		void SetPosition(Vector3f vec);
		void SetActive(bool value = true);
		Vector2f GetPosition() const;

		bool IsVisible() const;
	private:
		float mWidth;
		float mHeight;
		float mLayer;
		GUIPlane normalPlane;
		GUIPlane hoverPlane;

		bool m_bHasHover;
		bool m_isActive;

		Material material;
		Material material2;
	};
}
#endif
