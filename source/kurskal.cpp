#include "./headers/graph.h"

struct subset {
	betacore::node * parent;
	int rank;
}

// beatcore::node * makeset(betacore::node n)
// {
// 	betacore::node * _n = new beatcore::node;
// 	_n.parent = n;
// 	_n.rank = 0;
// 	return _n
// }

betacore::node * find(subset s, int i, betacore::node n)
{
	// find root and make root as parent of i (path compression)
    if (subsets[i].parent.id != n.id)
        subsets[i].parent = find(subsets, ++i,subsets[i].parent);
	
    return subsets[i].parent;
}

// Input: 
//		  Connected undireted graph G = (N,E) 
//		  with edge e weight w.e
// Return: 
//		   A minium Spanning Tree
int ** krusakl (beatcore::graph G)
{	
	int i;	

	subset * set = new subset[G.getNodeCount];
	for(i = 0 ; i < G.getNodeCount; ++i)
	{
		set[i].parent = G.getNode(i); //makeset( G.getNode(i) ) );
		set[i].rank = 0;
	}

	G.sortEdgesByCost();

	for( i = 0; i < G.getEdgeCount; ++i)
	{
		if ( find(G.getEdge(i).source).id !== find(G.getEdge(i).target).id )
	}
	

	delete set;
	set = NULL;
	return 
}