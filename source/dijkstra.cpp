// ==============================================
// 
// 
// 
// ==============================================
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#define maxSize 9
namespace beta
{

class shortPath{
	private:
	   
		int distance[maxSize];
		int previous[maxSize];
		int Q [maxSize];
		int visted [maxSize];
		int source;
		int numberOfVertices;
		void getPath(int i);
	public: 
		template <size_t rows, size_t cols>
		void dijkstra(int (&graph)[rows][cols]);
		template <size_t rows, size_t cols>
		void printArray(int (&array)[rows][cols]);
		void printPath();
		int getMin();
};
	//
	template <size_t rows, size_t cols>
	void shortPath::dijkstra(int (&graph)[rows][cols])
	{
		//ini 
	    shortPath::printArray(graph);	 
		int count = 0;
		int source = 0;
		int i;
		int u;
		numberOfVertices = 9;
		for( i = 0 ; i < numberOfVertices; ++i)
		{
			 distance[i] = 0;
			 previous[i] = 0;
			 Q[i] = 0;
		}
		
		//alg
		while ( count < numberOfVertices) 
		{
			u = shortPath::getMin();
			visted[++count]=u;
			Q[u] = 1;
			for( i = 1; i <= numberOfVertices; ++i)
			{
				if (graph[u][i] > 0)
				{
					if(Q[i] != 1){
						if ( distance[i] > distance[u] + graph[u][i] )
						{
							 distance[i] = distance[u] + graph[u][i] ;
							 previous[i] = u;
						}
					}
				}
			}
		}
		
		 
	}
	void shortPath::getPath( int i )
	{
		std::cout  << std::endl;
		if(i == source) //print start
		{
			std::cout<<source;
		}
		else if( previous [i] == 0 )
		{
			std::cout<< "no path from " << source <<" to "<< i;
		}
	    else
		{
			shortPath::getPath(previous[i]);
			std::cout << ".." <<i;
		}
	}
	void shortPath::printPath(){
		std::cout << "Print Path:\n"  << std::endl;
		 for(int i=1; i<= numberOfVertices; i++)
	     {
			shortPath::getPath(i);
			if(distance[i]!=999)
			{
				
				std::cout << "->(" << distance[i] << ")\n";
			}					
		 }
		 std::cout << std::endl;
		
	}
	int shortPath::getMin()
	{
		int min=999;
		int i,t;
		for( i=1 ; i <= numberOfVertices ; i++ )
		{
		if( Q[i] !=1 )
			{
				if(min >= distance[i])
				{
					min = distance[i];
					t = i;
				}
			}
		}
		return t;
	}
	//
	template <size_t rows, size_t cols>
	void shortPath::printArray(int (&array)[rows][cols])
	{
		//std::cout << __func__ << std::endl;
		for (size_t i = 0; i < rows; ++i)
		{
			
			for (size_t j = 0; j < cols; ++j){
				std::cout << array[i][j] << '\t';
			}
		 std::cout << std::endl;
		}
	}
	
			
}//namespace

//
int main ( int argc, char ** argv )
{
	//        X  Y
	int setX [3][3] =
	{
	  { 1, 5, 7 },
	  { 4, 9, 2 },
      { 2, 3, 2 }
	};	

    beta::shortPath sp;
	sp.printArray( setX );
	sp.dijkstra( setX );
	sp.printPath();
	
	
}//main
