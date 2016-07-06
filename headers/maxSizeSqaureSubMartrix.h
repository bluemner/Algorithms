#ifndef _betacore_max_size_sqaure_sub_martrix_h_
#define _betacore_max_size_sqaure_sub_martrix_h_

namespace betacore
{
	class maxSizeSqaureSubMatrix
	{
		private: 
			
			size_t min(size_t a, size_t b );
			
			template <size_t rows, size_t cols>  
		    void printGraph(int (&graph) [rows][cols]);
								
			void printSolution(int dist[], int size);
			void printSolution(bool dist[], int size);
		public:
			maxSizeSqaureSubMatrix();			
			template <size_t rows, size_t cols>  
			int runAlogrithm ( int (&graph) [rows][cols]);  
	};
}

#endif