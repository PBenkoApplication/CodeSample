#ifndef SCENENODE_H
#define SCENENODE_H
#include <map>

//TODO:Unused
namespace BAME
{
	class SceneNode
	{
	public:
		SceneNode();
		virtual ~SceneNode();

		SceneNode* Search(SceneNode* node);
		SceneNode* Search(long key);
		void Add(SceneNode* node);
		void Sub(SceneNode* node);
		long GetKey() const;
		SceneNode* GetParentNode() const;

		std::map<long, SceneNode*> const& GetChildNodeLost() const;
	protected:
		SceneNode* mParentNode;
		std::map<long, SceneNode*> mChildNodeList;
		long mKey;
		long mNextChildKey;
	};
}
#endif
