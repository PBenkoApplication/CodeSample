#ifndef BUFFERHANDLER_H
#define BUFFERHANDLER_H
#include "IBufferFactory.h"


namespace BAME
{
	class BufferHandler
	{
	public:
		static BufferHandler& Get();

		// delete copy and move constructors and assign operators
		BufferHandler(BufferHandler const&) = delete; // Copy construct
		BufferHandler(BufferHandler&&) = delete; // Move construct
		BufferHandler& operator=(BufferHandler const&) = delete; // Copy assign
		BufferHandler& operator=(BufferHandler&&) = delete; // Move assign


		void Init(IBufferFactory* bufferFactory);


		int CreateVertexBuffer(std::vector<Vertex> const& vertexList);
		int CreateVertexBuffer(std::vector<VertexBone> const& vertexList);
		int CreateIndexBuffer(std::vector<unsigned int> const& indexList);

		void DeleteVertexBuffer(int i);;

		void DeleteIndexBuffer(int i);
		void UpdateIndexBuffer(int i, std::vector<unsigned> const& indexList);;

		void UpdateVertexBuffer(int i, std::vector<Vertex> const& vertexList);

		template <typename T>
		T* GetVertexBuffer(int value)
		{
			return static_cast<T*>(mVertexBufferList[value]);
		};

		template <typename T>
		T* GetIndexBuffer(int value)
		{
			return static_cast<T*>(mIndexBufferList[value]);
		}

		void Destroy();

	protected:
		BufferHandler();

		~BufferHandler();


	private:

		IBufferFactory* mBufferFactory;
		std::vector<IVertexBuffer*> mVertexBufferList;
		std::vector<IIndexBuffer*> mIndexBufferList;
	};
}
#endif
