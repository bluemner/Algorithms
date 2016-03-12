#include <iostream>
#include <string>
#include <vector>
#include "../headers/graph.h"

namespace betacore
{
   graph::graph()
   {
	   this->nodeIdCount = 0 ;
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

}
int mainx ( int argc, char ** argv )
{
	betacore::graph G;
    
	G.addNode( 6, "A");
	G.addNode( 8, "B");
	G.addNode(10, "C");
	G.addNode(11, "D");
	
	betacore::node *n;
	if( ( n = G.getNode(0) ) != NULL)
	{
			std::cout << "[" << n->id << " , " << n->value << " , " << *(n->name) << "]" << std::endl;
	}
	
	G.addEdge(0,1,1);
	G.addEdge(0,2,1);
	G.addEdge(0,3,1);
	//G.addEdge(0,4);
	
	G.printNodes();
	G.printEdges();

}