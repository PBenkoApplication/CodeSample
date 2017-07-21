#ifndef TEXT_H
#define TEXT_H

#include "IGUIObject.h"
#include "WriteChar.h"

namespace BAME
{
	class Text :public IGUIObject
	{
	public:

		Text(float width, float height, Vector2f position, std::string const& text);
		~Text();

		/*void Init(std::string const& asciiImage);*/
		void SetText(std::string const& text);
		bool CheckHover(const float fPosX, const float fPosY) override;
		void OnMouseOver() override;
		void OnMouseOut() override;
		void OnMouseClickLeft() override;
		void OnMouseClickRight() override;
		void SetPosition(Vector3f vec);
		Vector2f GetPosition() const;
	private:
		std::string mText;
		float mWidth;
		float mHeight;

		std::vector<GUIPlane> mGuiPlanes;

		/*WriteChar mA;
		WriteChar mB;
		WriteChar mC;
		WriteChar mD;
		WriteChar mE;
		WriteChar mF;
		WriteChar mG;
		WriteChar mH;
		WriteChar mI;
		WriteChar mJ;
		WriteChar mK;
		WriteChar mL;
		WriteChar mM;
		WriteChar mN;
		WriteChar mO;
		WriteChar mP;
		WriteChar mQ;
		WriteChar mR;
		WriteChar mS;
		WriteChar mT;
		WriteChar mU;
		WriteChar mV;
		WriteChar mW;
		WriteChar mX;
		WriteChar mY;
		WriteChar mZ;

		WriteChar ma;
		WriteChar mb;
		WriteChar mc;
		WriteChar md;
		WriteChar me;
		WriteChar mf;
		WriteChar mg;
		WriteChar mh;
		WriteChar mi;
		WriteChar mj;
		WriteChar mk;
		WriteChar ml;
		WriteChar mm;
		WriteChar mn;
		WriteChar mo;
		WriteChar mp;
		WriteChar mq;
		WriteChar mr;
		WriteChar ms;
		WriteChar mt;
		WriteChar mu;
		WriteChar mv;
		WriteChar mw;
		WriteChar mx;
		WriteChar my;
		WriteChar mz;*/
	};
}

#endif
