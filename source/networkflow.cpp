#include <iostream>
#include <limits>
#include <../headers/networkflow.h>

namespace beatcore
{
	
	networkflow::networkflow()
	{
		
	}
	
	template <size_t rows, size_t cols> 
	void networkflow::runAlgorithm(int (&input) [rows][cols], int source, int target )
	{
		int f = 0;
		while ( true )		
		{
			//m,p = BFS(C,E,source,target)
			if ( m = 0){
				break;
			}
			f = f+m;
			//backtrace and write flow
			v = t 
			while (v !=s)
			{
				u = p[v];
				E[u,v] = F[u,v] + m;
				E[u,v] = F[u,v] - m;
				
			}
			 
		}
		
	}
	
}
int main ( int argc, cahr ** argv )
{
	
}