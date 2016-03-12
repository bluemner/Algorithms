#ifndef _betacore_graph_h_
#define _betacore_graph_h_

namespace betacore
{
	struct node {
		int id;
		int value;
		std::string *name;
	};
	
	struct edge
	{
		int source;
		int target;	
		int cost;
	};
	
	class graph
	{
		private:
			std::vector<node*> nodes;
		    std::vector<edge*> edges;
			unsigned long nodeIdCount;
		public:
			graph();
			
			void addNode(int value, std::string name);
			void addEdge(int sourceId, int targetId, int cost);
			
			void printNodes();					
			void printEdges();
			
			node* getNode(int id);
					
					
	};	
}
#endif

