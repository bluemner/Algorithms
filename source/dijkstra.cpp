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
	
  	//Scan function to find min value
	int dijkstra::minDistance(int dist[], bool sptSet[], int size)
	{
		// Initialize min value
		int min = std::numeric_limits<int>::max();
		int min_index;

		for (int v = 0; v < size; v++)
			if (sptSet[v] == false && dist[v] <= min)
				min = dist[v], min_index = v;

		return min_index;
	}
	void dijkstra::iniGraph(){
		
	}
	
	
	void dijkstra::runAlogrithm( graph *G, node *source ){
		
	}
	
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
			
			//distance vertex 
			for ( int v = 0; v < rows ; v++ ){
				if( !spt[v] && graph[u][v] && dist[u] != std::numeric_limits<int>::max() &&
					dist[u] + graph[u][v] < dist[v] ){
						dist[v] = dist[u] + graph[u][v];
						if(v ==target){
							printSolution(dist, rows);
							return;
						}
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
	G.addNode(0, "B");
	G.addNode(0, "C");
	G.addNode(0, "D");
	G.addNode(0, "E");
	G.addNode(0, "F");
	G.addNode(0, "G");
	G.addNode(0, "H");
	G.addNode(0, "I");
	
	// A->B
	G.addEdge(0,1,3);
	// A->C
	G.addEdge(0,2,4);
	// B->D
	G.addEdge(1,3,7);
	// C->E
	G.addEdge(2,4,6);
	// D->E
	G.addEdge(3,4,1);
	// D->F
	G.addEdge(3,5,8);
	// E->F
	G.addEdge(4,5,9);
	// F->G
	G.addEdge(5,6,1);
	// F->H
	G.addEdge(5,7,4);
	// G->I
	G.addEdge(6,8,7);
	// H->I
	G.addEdge(7,8,3);
	
	G.printNodes();
	G.printEdges();
	
	betacore::dijkstra  d;
	//d.runAlogrithm(G,G.getNode(0));
	
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
	d.runAlogrithm(gg, 0, 5);
}//main
