#ifndef NODE_H
#define NODE_H
#include <vector>
#include "../Mathematics/Matrix4x4f.h"

namespace BAME
{
	class Node
	{
	public:
		Node();
		explicit Node(std::string const& name);
		~Node();

		const Node* FindNode(const char* name) const;

		void AddNode(Node const& node);;
		std::vector<Node> const& GetChildNodes() const;
		void SetTransformation(Matrix4x4f const& matrix);
		Matrix4x4f const& GetTransformation() const;

		std::string const& GetName() const;

		unsigned GetChildCount() const;
	private:
		std::vector<Node> mChildNodes;
		std::string mName;
		Matrix4x4f mTransformation;

	};
}
#endif