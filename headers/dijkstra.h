#ifndef _betacore_dijkstra_h_
#define _betacore_dijkstra_h_

namespace betacore
{
	class dijkstra
	{
		private:
			void iniGraph(); 
			void printSolution(int dist[], int size);
			int minDistance(int dist[], bool sptSet[], int size);
		public: 
			dijkstra();
		    
			void runAlogrithm(graph *G, node *source);
			
			template <size_t rows, size_t cols>  
			void runAlogrithm ( int (&graph) [rows][cols], int source );  
			
			template <size_t rows, size_t cols>  
			void runAlogrithm ( int (&graph) [rows][cols], int source, int target);  
	
	};
}
#endif