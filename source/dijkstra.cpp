// ==============================================
// 
// 
// 
// =============================================
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <limits>
#include "../headers/graph.h"
#include "../headers/dijkstra.h"
namespace betacore
{
	dijkstra::dijkstra(){
		
	}
	// A utility function to print the constructed distance array
	void dijkstra::printSolution(int dist[], int size)
	{
		std::cout << "Vertex Distance from Source:" << std::endl;
		for (int i = 0; i < size; i++){
			int mx =dist[i];
			std::cout << i <<"\t"<< mx << std::endl;
		}
	}
	
	// A utility function to print the constructed distance array
	void dijkstra::printSolution(bool dist[], int size)
	{
		std::cout << "Path Source:" << std::endl;
		for (int i = 0; i < size; i++){
			bool mx =dist[i];
			if(mx)
			std::cout << i <<"\t"<< mx << std::endl;
		}
	}
	
	template <size_t rows, size_t cols>
	void dijkstra::printArray(int (&graph) [rows][cols]){
		for( int i = 0 ; i < rows; i++ ){
			for ( int j = 0 ; j < cols; j++ ){
				//if(graph[i][j]){
			//			std::cout << i << " -> "<< j << std::endl;
			//	}
			 	std::cout << graph[i][j] << "\t";
			}			
			std::cout << "" << std::endl;
		}
	}
	
	template <size_t rows, size_t cols>
	void dijkstra::printArray(bool (&graph) [rows][cols]){
		for( int i = 0 ; i < rows; i++ ){
			for ( int j = 0 ; j < cols; j++ ){
				//if(graph[i][j]){
			//			std::cout << i << " -> "<< j << std::endl;
			//	}
			 	std::cout << graph[i][j] << "\t";
			}			
			std::cout << "" << std::endl;
		}
	}
	
  	//Scan function to find min value
	int dijkstra::minDistance(int dist[], bool sptSet[], int size)
	{
		// Initialize min value
		int min = std::numeric_limits<int>::max();
		int min_index;

		for (int v = 0; v < size; v++)
		{
			if ( sptSet[v] == false && dist[v] <= min )
			{
				min = dist[v];
				min_index = v;
			}
		}

		return min_index;
	}
	void dijkstra::iniGraph(){
		
	}

/*
Wiki dijkstra psudue code 
 1  function Dijkstra(Graph, source):
 2
 3      create vertex set Q
 4
 5      for each vertex v in Graph:             // Initialization
 6          dist[v] ← INFINITY                  // Unknown distance from source to v
 7          prev[v] ← UNDEFINED                 // Previous node in optimal path from source
 8          add v to Q                          // All nodes initially in Q (unvisited nodes)
 9
10      dist[source] ← 0                        // Distance from source to source
11      
12      while Q is not empty:
13          u ← vertex in Q with min dist[u]    // Source node will be selected first
14          remove u from Q 
15          
16          for each neighbor v of u:           // where v is still in Q.
17              alt ← dist[u] + length(u, v)
18              if alt < dist[v]:               // A shorter path to v has been found
19                  dist[v] ← alt 
20                  prev[v] ← u 
21
22      return dist[], prev[]
*/
	void dijkstra::runAlogrithm( graph *G, node *source ){
		
		int i, u;
		std::vector<edge*> Q;
		int rows = G->getEdgeCount();
		int dist[rows];
		int prev[rows];
		bool spt[rows];
		
		for(i = 0; i < rows; ++i){
			dist[i] = std::numeric_limits<int>::max();
		 	spt[i] = false; //allows us to mark visted 
			prev[i] = 0;
			Q.push_back(G -> getEdge(i));
		}
		while ( Q.size() > 0)
		{
			u = minDistance(dist, spt, rows);
			spt[u] = true; //we visted the path
	
			
			Q.erase(Q.begin() + u);
			for ( int v = 0 ; v < rows ; ++v )
			{
				int pathLen =  G->pathLength(u,v);
				int alt = dist[u] + pathLen;
				
				std::cout << "Alt:" << alt <<std::endl;
				if( G->pathLength(u,v) && alt < dist[v] ){
						dist[v] = alt;
						prev[v] = u;
					}	
			}
		}
		printSolution(dist, rows);
	}//method
	
    template <size_t rows, size_t cols>  
	void dijkstra::runAlogrithm ( int (&graph) [rows][cols], int source )
	{
	
		int i , u;
		int dist[rows];
		bool spt[rows];
		
		//INI
		for (i = 0; i < rows; i++)
		{
			dist[i] = std::numeric_limits<int>::max();;
			spt[i] = false; //allows us to mark visted 
		}
		dist[source]=0; //dist from source will always be zero;
		
		for( int count = 0; count < rows; count++ )
		{
			u = minDistance(dist, spt, rows);
			spt[u] = true; //we visted the path;
			
			for ( int v = 0; v < rows ; v++ ){
				if( !spt[v] && graph[u][v] && dist[u] != std::numeric_limits<int>::max() &&
					dist[u] + graph[u][v] < dist[v] ){
						dist[v] = dist[u] + graph[u][v];
					}	
			}
		
		}
			printSolution(dist, rows);
	}//method
	
	template <size_t rows, size_t cols>  
	void dijkstra::runAlogrithm ( int (&graph) [rows][cols], int source, int target)
	{
	
		int i, j, u;
		int dist[rows];
		int prev[rows];
		bool spt[rows];		
		//bool shrtpath[rows][cols];
		int parent[rows];
		//INI
		for (i = 0; i < rows; i++)
		{
			dist[i] = std::numeric_limits<int>::max();
			spt[i] = false; //allows us to mark visted 
			prev[i] = 0;
			parent[i] = 0;
		//	for( j = 0 ; j< cols; j++ ){
		//		shrtpath[i][j] = false;
		//	}
		}
		dist[source]=0; //dist from source will always be zero;
		
		for( int count = 0; count < rows; count++ )
		{
			u = minDistance(dist, spt, rows);
			spt[u] = true; //we visted the path;
		    if(u ==target){
				
				//1  S ← empty sequence
				//2  u ← target
				//3  while prev[u] is defined:                  // Construct the shortest path with a stack S
				//4      insert u at the beginning of S         // Push the vertex onto the stack
				//5      u ← prev[u]                            // Traverse from target to source
				//6  insert u at the beginning of S             // Push the source onto the stack
	
			  //printSolution(dist, rows);
			  //printArray(shrtpath);
			  int parentIndex=0;
			  while(prev[u]){
				   parent[parentIndex++]=u;
				   u = prev[u];
			  }
			  parent[parentIndex]=u;
			 
			  std::cout << "Shortest path to " << target  <<" Length:"<< dist[target] << std::endl; 
			  std::cout << 0;
			  for(int x = parentIndex; x >=0; x--){
				  std::cout << " -> " << parent[x] ;
			  } 
			  std::cout <<std::endl;
			  return;
			}
			
			//distance vertex 
			for ( int v = 0; v < rows ; v++ ){
				if( !spt[v] && graph[u][v] && dist[u] != std::numeric_limits<int>::max() &&
					dist[u] + graph[u][v] < dist[v] ){
						dist[v] = dist[u] + graph[u][v];
						prev[v] =u;
						//parent[v] = 1;
					}			
			}
		
		}
			printSolution(dist, rows);
	}//method
	
}//namespace

//
int main ( int argc, char ** argv )
{
	betacore::graph G;	
	
	G.addNode(0, "A");
	G.addNode(1, "B");
	G.addNode(2, "C");
	G.addNode(3, "D");
	G.addNode(4, "E");
	G.addNode(5, "F");
	G.addNode(6, "G");
	G.addNode(7, "H");
	G.addNode(8, "I");
	
	// A -> B : 04
	G.addEdge(0,1,4);
	// A -> H : 08
	G.addEdge(0,7,8);
	// B -> C : 08
	G.addEdge(1,2,8);
	// B -> H : 11
	G.addEdge(1,7,11);
	// C -> D : 07
	G.addEdge(2,3,7);
	// C -> I : 02
	G.addEdge(2,8,2);
	// C -> F : 04
	G.addEdge(2,5,4);
	// D -> E : 09
	G.addEdge(3,4,9);
	// D -> F : 14
	G.addEdge(3,5,14);
	// E -> F : 10
	G.addEdge(4,5,10);
	// F -> G : 2
	G.addEdge(5,6,2);
	// G -> I : 6
	G.addEdge(6,8,6);
	// G -> H : 1
	G.addEdge(6,7,1);
	// H -> I : 7
	G.addEdge(7,8,7);
	
	
	G.printNodes();
	G.printEdges();
	
	//G.runAlogrithm(G,G.getNode(0));
	betacore::dijkstra  d;
	betacore::node* source = G.getNode(0);
	std::cout << "Running List Graph" <<std::endl;
	d.runAlogrithm(&G, source);
	
	std::cout << "Running Matrix Graph" <<std::endl;
	int gg[9][9] = {
		            {0, 4, 0, 0, 0, 0, 0, 8, 0},
					{4, 0, 8, 0, 0, 0, 0, 11, 0},
					{0, 8, 0, 7, 0, 4, 0, 0, 2},
					{0, 0, 7, 0, 9, 14, 0, 0, 0},
					{0, 0, 0, 9, 0, 10, 0, 0, 0},
					{0, 0, 4, 0, 10, 0, 2, 0, 0},
					{0, 0, 0, 14, 0, 2, 0, 1, 6},
					{8, 11, 0, 0, 0, 0, 1, 0, 7},
					{0, 0, 2, 0, 0, 0, 6, 7, 0}
					};
	d.printArray(gg);
	d.runAlogrithm(gg, 0);
	for(int i=0; i< 9; i++){
			d.runAlogrithm(gg, 0, i);
	}				

}//main
