#include <iostream>
#include <string>
#include <vector>
#include "../headers/graph.h"
#include <algorithm>
//#include "../headers/dijkstra.h"
namespace betacore
{
   graph::graph()
   {
	   this->mode = adjacentLists;
	   this->nodeIdCount = 0 ;
   }
   
   template <size_t rows, size_t cols> 
   graph::graph( int (&graph)[rows][cols] ){
	   this->nodeIdCount = 0;
	   this->mode = NULL;
	   this->_graph = &graph;
   }  
     
   void graph::addNode( int value, std::string name )
   {
	   node *n = new node;
	   n->id = this->nodeIdCount++;
	   n->value = value;
	   n->name = new std::string(name);
	   this->nodes.push_back(n);
   }
   
   void graph::addEdge(int sourceId, int targetId, int cost)
   {
	 //TODO : add check if edge exsist  
	   
	   edge *e = new edge;
	   e->source = sourceId;
	   e->target = targetId;
	   e->cost = cost;
	   this->edges.push_back(e);
   }			
   
   node* graph::getNode(int id)
   {
	   int i;
	   for ( i = 0; i < nodes.size(); i++ )
	   {
		   node *current = nodes.at(i);
		   
		   if( current->id == id){
			   return current;
		   }
	   }
	   
	   return NULL;
   }

   edge* graph::getEdge( int index )
   {
	 return edges.at( index );   
   }
   void graph::printEdges()
   {
		int i;
		std::cout << "Edge:" << std::endl;
		for ( i =0; i < this->edges.size() ; i++ )
		{
			edge *current = edges.at(i);
			node *Source = getNode(current->source); 
			node *Target = getNode(current->target);
			std::cout << "["
					  << *Source->name
			          << " -> " 
					  << *Target->name
					  << " : "
					  << current->cost
					  << " ]"
					  << std::endl; 
		} 
	}
	
	void graph::printNodes()
	{
		int i;
		std::cout << "Node:"  << std::endl;	
		for ( i = 0; i < this->nodes.size(); i++ )
		{
			node *current = nodes.at(i);
			std::cout << "[" << current->id << " , " << current->value << " , " 
				      << *(current->name) << "]" << std::endl;
		}
	}

	bool graph::compareByCost(const edge &a, const edge &b)
	{
    	return a.cost < b.cost;
	}
	
	void graph::sortEdgesByCost()
	{
		//std::sort(this->edges.begin(), this->edges.end(),compareByCost)
		
	}
	
	int graph::getEdgeCount(){
		edges.size();
	}
	
	int graph::getNodeCount(){
		nodes.size();
	}
	int graph::pathLength( int u, int v)
	{
		for ( int i = 0; i < edges.size(); i++ )
		{
			edge* temp = edges.at(i);
			if(temp->source == u && temp->target ==v)
			{
				return temp-> cost;
			}
			  
		}
		return edges.at(u)->cost;
	}
}

int main2( int argc, char ** argv )
{
	betacore::graph G;
    
	G.addNode( 6, "A");
	G.addNode( 8, "B");
	G.addNode(10, "C");
	G.addNode(11, "D");
	
	betacore::node *n;
	if( ( n = G.getNode(0) ) != NULL )
	{
			std::cout << "[" << n->id << " , " << n->value << " , " << *(n->name) << "]" << std::endl;
	}
	
	// A -> B
	G.addEdge(0,1,1);
	// A -> C
	G.addEdge(0,2,4);
	// A -> D
	G.addEdge(0,3,2);
	
	// B -> C
	G.addEdge(1,2,3);
	
	// D -> C
	G.addEdge(3,2,1);
	
	G.printNodes();
	G.printEdges();

}