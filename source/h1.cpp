#include <iostream>


template <size_t rows, size_t cols>
int linar_c_search(int n, int (&A)[rows][cols])
{
	int i;
    int x = 0;
    int y = n - 1;
  
    while (x < y)
    {
		if( A[x][y] )
		{
			++x;
		}else{
			--y;
		}

    }
	for( i=0; i < n ; i++)
	{
		if(i != x ) // Diagnal
		{
			if( A[x][i] || !A[i][x])
			{
				return -1; // Not found
			}
		}
	}

	return x;
}
int main(int argc, char **argv)
{
    // A1.Length -> 3
    int n = 3;
    int r = -1; 
    int A1[3][3] = {
	{0, 1, 0},
	{0, 1, 0},
	{0, 1, 0}};
	r = linar_c_search(n,A1) ;
	if( r != -1)
	{
		std::cout << "CELB N("<<n<<") :: " << r <<std::endl;
	}else
	{
		std::cout << "No Celebrity Found";
	}
	

	n = 4;
    int A2[4][4] = {
	{0, 1, 0, 0},
	{0, 1, 0, 0},
	{0, 1, 0, 0},
	{0, 1, 0, 0},
    };
	r = linar_c_search(n,A2) ;
	if( r != -1)
	{
		std::cout << "CELB N("<<n<<") :: " << r <<std::endl;
	}else
	{
		std::cout << "No Celebrity Found";
	}

    n = 5;
    int A3[5][5] = {
	{0, 0, 0, 1, 0},
	{0, 0, 0, 1, 0},
	{0, 0, 0, 1, 0},
	{0, 0, 0, 1, 0},
	{0, 0, 0, 1, 0},
    };

	r = linar_c_search(n,A3) ;
	if( r != -1)
	{
		std::cout << "CELB N("<<n<<") :: " << r <<std::endl;
	}else
	{
		std::cout << "No Celebrity Found";
	}

    return 0;
}