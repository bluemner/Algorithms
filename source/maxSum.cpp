#include <iostream>
#include <limits>

namespace betacore
{
	void kadane( int input[], int n, int &x1, int &x2, int &max )  
	{  
		int current_sum;
		int i;  
		max = 0;  
		current_sum = 0;  
		x1 = x2 = 0;  
		int lx1, lx2;  
		lx1 = 0;  
		for( i = 0; i < n; i++ )  
		{  
			current_sum = current_sum + input[i];  
			if( max < current_sum )  
			{  
				max = current_sum;  
				x2 = i;  
				x1 = lx1;  
			}  
			if ( current_sum < 0 )  
			{  
				current_sum = 0;  
				lx1 = i + 1;  
			}  
		}  
	}
	
	template <size_t rows, size_t cols>  
	void find_max_sum( int (&input) [rows][cols] )  
	{  
		int temp[cols], n, x1, x2;  
		int current_sum, max_sum, fx1, fx2, fy1, fy2;  
		int i,j,k;  
		fx1 = fx2 = fy1 = fy2 = max_sum = current_sum = -1;  
	
		for ( i = 0; i < rows; i++ )  
		{  	//zeroing out the information
			for( k = 0 ; k < cols; k++ )
			{  
				temp[k] = 0;  
			}
			for ( j = i ; j < rows; j++ )  
			{  
				for( k = 0; k < cols ; k++ ){  
					temp[k] += input[j][k];  
				}
				kadane( temp, cols, x1, x2, current_sum );  
	
				if ( current_sum > max_sum )  
				{  
					fy1 = x1;  
					fy2 = x2;  
					fx1 = i;  
					fx2 = j;  
					max_sum = current_sum;  
				}  
			}  
		}  
		std::cout << "max Sum = " << max_sum << " from (" << fx1 << "," << fy1 << ") to ("  
			      << fx2 << "," << fy2 << ")" << std::endl;  
	}  
}

// ===================================
// Main method to run max_sum instance 
// ===================================
int main ( int argc, char ** argv )
{
	//        X  Y
	int setX [3][3] =
	{
	  { 1, 5, 7 },
	  { 4, 9, 2 },
      { 2, 3, 2 }
	};	

    betacore::find_max_sum(setX); 
    //std::cout << "Press Any Key to quit" << std::endl;
    //std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
	
	
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
	betacore::find_max_sum(gg);
    //std::cin.get();
	return 0;
}//main
