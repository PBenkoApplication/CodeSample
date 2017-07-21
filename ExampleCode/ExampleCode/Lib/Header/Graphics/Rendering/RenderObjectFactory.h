#ifndef RENDEROBJECTFACTORY_H
#define RENDEROBJECTFACTORY_H
#include "RendererType.h"

namespace BAME
{
	class RenderObjectFactory
	{

	public:
		static RenderObjectFactory& Get();

		// delete copy and move constructors and assign operators
		RenderObjectFactory(RenderObjectFactory const&) = delete;             // Copy construct
		RenderObjectFactory(RenderObjectFactory&&) = delete;                  // Move construct
		RenderObjectFactory& operator=(RenderObjectFactory const&) = delete;  // Copy assign
		RenderObjectFactory& operator=(RenderObjectFactory &&) = delete;      // Move assign

		void Init(RendererType renderType)														// Any other public methods

		IRenderObject* CreateRenderObject();




	protected:

		RenderObjectFactory();

		~RenderObjectFactory();

		

	private:
		
	};
}
#endif
