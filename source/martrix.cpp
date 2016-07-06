#include <iostream>
#include <cmath>

namespace betacore
{
	void Matrix::normalize(float * vector, float size)
	{
		// V/||V|| sqr(v[0] * v[0] + v[2] * v[2] ... v[n] * v[n] );
		int i;
		float sum = 0.0;
		
		for ( i =0; i < size; ++i)
		{
			sum += vector[i] * vector[i];	
		}
		
		float magnatute = sqrt( sum );
		
		for ( i =0; i < size; ++i)
		{
			vector[i] = magnatute * vector[i] 
		}
		
	}
}