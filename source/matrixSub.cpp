#include <iostream>
#include <limits>
#include <string>
#include <map>
#include <vector>
#include <cmath>

#define _a 1
#define _b 2
#define _c 3

namespace betacore
{

void printArray(char **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
		for (int j = 0; j < cols; j++)
		{
			std::cout << matrix[i][j] << "\t";
		}
		std::cout << "" << std::endl;
    }
}

void optialParenthesizations(char **matrix, int rows, int cols, int i, int j)
{
    if (i != j)
    {
	optialParenthesizations(matrix, rows, cols, i, matrix[i][j]);
	optialParenthesizations(matrix, rows, cols, matrix[i][j] + 1, j);	
	
	std::cout << i << " * " << j << std::endl;
    }
}
bool matrix_chain_char(std::vector<char> &arr, std::map<char, std::map<char, char>>  &table, char target)
{
    int n = (int) std::pow(2.0, arr.size() * 1.0 ); // arr.size() + 1 ;
    int i, j, k, x;

    // Allocate memory
    char **m = new char *[n];
    char **s = new char *[n];
	//create blank array
    for (i = 0; i < n; ++i)
    {
		m[i] = new char[n];
		s[i] = new char[n];
		if( i > 0 )
		{
			m[i][0] = arr[i-1];
			m[0][i] = arr[i-1];
		}
	
    }
	
    for ( i = 1 ; i < n; ++i )
    {
		for( j = 1; j < n ; ++j )
		{
			
			m[i][j] = table [m[i][j-1]] [m[0][j]];
		}
	}

	std::cout << "matrix M" << std::endl;
	printArray(m,n,n);
	std::cout << std::endl;
	std::cout << "matrix S" << std::endl;
	printArray(s,n,n);
	std::cout << std::endl;
	//optialParenthesizations(s, n,n, i, n-1 );
	std::cout<< (m[0][n-1]==target) <<std::endl;
	return (m[0][n-1]==target);
}

}//namespace

int main(int argc, char *argv[])
{	
    std::map<char, std::map<char, char>> M;
	std::map<char, char> m_0;
	m_0['a']='b';
    m_0['b']='b';
	m_0['c']='a';

	std::map<char, char>  m_1;
	m_1['a']='c';
    m_1['b']='b';
	m_1['c']='a';

	std::map<char, char>  m_2;
	m_2['a']='a';
    m_2['b']='c';
	m_2['c']='c';

	M['a']=m_0;
	M['b']=m_1;
	M['c']=m_2;
	// M =
	// {
	//     {b, b, a}
	//     {c, b, a},
	//     {a, c, c}
	// };
	
	std::vector<char> dem = {'a','b','c'};
	betacore::matrix_chain_char(dem, M, 'b');
    //input
    dem = {'b', 'b', 'b', 'b', 'a', 'c'};

    //char want = _a;
    betacore::matrix_chain_char(dem, M, 'a');
	return 0;
}