#ifndef GUIMANAGER_H
#define GUIMANAGER_H
#include "../Graphics/Rendering/Renderer/RenderObjectFactory/RenderObjectFactory.h"
#include "../Graphics/Rendering/Renderer/RenderObject.h"
#include "../Graphics/Rendering/Renderer/RendererType.h"
#include "../GUI/IGUIObject.h"
#include <set>

namespace BAME
{
	class GUIHandler
	{
	public:
		static GUIHandler& Get();

		// delete copy and move constructors and assign operators
		GUIHandler(GUIHandler const&) = delete; // Copy construct
		GUIHandler(GUIHandler&&) = delete; // Move construct
		GUIHandler& operator=(GUIHandler const&) = delete; // Copy assign
		GUIHandler& operator=(GUIHandler&&) = delete; // Move assign

		//Fügt ein neues GUIObject hinzu
		void Add(IGUIObject* guiObject);

		void Init(RenderObjectFactory* renderObjectFactory);

		void Update();

		std::vector<RenderObject*> const& GetRenderObjectList() const;

	protected:

		GUIHandler();

		~GUIHandler();

		// And any other protected methods.

	private:


		/*struct LayerCompare {
			bool operator() (const RenderObject* l1, const RenderObject* l2) const {
				
				l1->GetGeo();
				l2->GetGeo()
				
				return l1 < l2;
			}
		};*/


		//std::vector<IGUIObject*> mGUIObjectList;
		//std::set<RenderObject*, LayerCompare> mRenderOjectList;
		std::vector<RenderObject*> mRenderOjectList;
		std::string mActiveScene;
		RendererType mRendertype;
		RenderObjectFactory* mRenderObjectFactory;
	};
}
#endif
