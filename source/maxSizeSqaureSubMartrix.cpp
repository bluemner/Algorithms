#include <iostream>
#include <limits>

#include "../headers/maxSizeSqaureSubMartrix.h"

namespace betacore
{
	maxSizeSqaureSubMatrix::maxSizeSqaureSubMatrix(){
		
	}
	size_t maxSizeSqaureSubMatrix::min(size_t a, size_t b )
	{
		return (a < b)? a:b;
	}
	template <size_t rows, size_t cols>  
	void maxSizeSqaureSubMatrix::printGraph(int (&graph) [rows][cols])
	{
		for(int i=0; i < rows; ++i )
		{
			for( int j=0; j< cols; ++j)
			{
				std::cout << graph[i][j] <<"\t";
			}
			std::cout << std::endl;
		}
	}

	
	template <size_t rows, size_t cols>  
	int maxSizeSqaureSubMatrix::runAlogrithm( int (&graph) [rows][cols] )
	{
		int result = 0;
		std::cout << "Before" <<std::endl;
		printGraph(graph);
		std::cout << std::endl <<std::endl;
		int table[rows][cols];
		for(int i=0; i < rows; ++i )
		{
			for( int j=0; j< cols; ++j)
			{
				table[i][j]= 0;
			}
		}
		printGraph(table);
		std::cout << std::endl <<std::endl;
		for(int i=0; i < rows; ++i )
		{
			for( int j=0; j< cols; ++j)
			{
				if( i ==0 || j == 0 )
				{
					table[i][j] = graph[i][j];
					
				}
				else if	( graph[i][j] == 0 )
				{
					table[i][j] = 0;
				}
				else
				{
					table [i][j] = min ( table[i-1][j], min ( table[i-1][j-1], table[i][j-1] ) ) + 1;
					printGraph(table);
					std::cout << std::endl <<std::endl;
				}
				
				if(table[i][j] > result)
				{
					result = table[i][j];
				}
			}
		}
        std::cout << "After" <<std::endl;
		printGraph(table);
		std::cout << std::endl <<std::endl;
	
		return result;
	}
}

int main( int argc, char ** argv )
{
    betacore::maxSizeSqaureSubMatrix mx;
	int matrix[5][5]=
	{
	  {1, 1, 0, 1, 1},
	  {0, 1, 1, 1, 1},
	  {0, 0, 1, 1, 1},
	  {1, 1, 1, 1, 1},
	  {0, 1, 1, 1, 0}	  
	};

	int sumValue = mx.runAlogrithm( matrix );
	std::cout << "Sumvalue:" << sumValue << std::endl;
	
	return 0; 
}