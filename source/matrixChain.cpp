#include <iostream>
#include <limits>

namespace betacore
{	
	void printArray(int ** matrix, int rows, int cols){
		for( int i = 0 ; i < rows; i++ ){
			for ( int j = 0 ; j < cols; j++ ){
			 	std::cout << matrix[i][j] << "\t";
			}			
			std::cout << "" << std::endl;
		}
	}
	
	void optialParenthesizations ( int ** matrix, int rows, int cols, int i, int j)
	{
		if( i != j )
		{
			optialParenthesizations( matrix, rows, cols,i, matrix[i][j]);
			optialParenthesizations( matrix, rows, cols, matrix[i][j] +1,j);
			std::cout << i  << " * " << j << std::endl;
		}
	}
	
		
	void matrix_chain_order(int * dimension , int size)
	{
		int n = size - 1;
		int i,j,k,x;
		
		// Allocate memeory
		int ** m = new int*[n];
		int ** s = new int*[n];
		
		for( i = 0; i < n ; ++i)
		{
			m[i] = new int[n];
			s[i] = new int[n];
		}		
		
		//Let x be the subsequance length
		for (x =1; x < n; ++x )
		{
			for (i =0; i< n - x; i++)
			{
				int j = i + x;
				m[i][j] = std::numeric_limits<int>::max();
				for ( int k = i; k < j; k++)
				{
					int cost = m[i][k] + m[k+1][j] + dimension [i] * dimension[k+1] * dimension [j+1];
                    if (cost < m[i][j])
					{
                        m[i][j] = cost;
                        s[i][j] = k; // Index of subsequance at min cost
                    }
				}
			}
		}
		std::cout << "matrix M" << std::endl;
		printArray(m,n,n);
		std::cout << std::endl;
		std::cout << "matrix S" << std::endl;
		printArray(s,n,n);
		std::cout << std::endl;
		optialParenthesizations(s, n,n, i, n-1 );
		// Free memeory
		delete[] m;
		delete[] s;	
	}
}

int main (int argc, char** argv)
{
	//Given matrix NX1 1X2 2X3 3X4 4X5 5X6 6XN
	// We find the optial parings
	std::cout << "Running First Set" << std::endl;
	int temp[] = {1,2,3,4,5,6};
	betacore::matrix_chain_order(temp, 6);
	std::cout << std::endl;
	std::cout << "Running Second Set" << std::endl;
	int temp2[] = {2,2,2,3,3,3};
	betacore::matrix_chain_order(temp2, 6);
}