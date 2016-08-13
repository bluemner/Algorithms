#include <iostream>
#include <climits>
#include <cstdlib>

namespace betacore
{
	int smallestSumNearThreshold( int array[], int size_of_array, int threshold )
	{
		int current_sum = 0;
		int min_len = size_of_array + 1;
		int result = 0;	
		int start = 0;
		int end   = 0;
		
		while ( end < size_of_array )
		{
			//keep adding elements while sum is smaller then threshold
			while ( current_sum <= threshold && end < threshold )
			{
				current_sum += array[ end++ ];
			} 		
			// If current_sum crosses the threshold
			while ( current_sum >= threshold && start < size_of_array )
			{
				// update min_len 			
				if( end - start < min_len )
				{
					min_len = end - start;
					result = current_sum;
				}			
				// remove starting elements
				current_sum -= array[start++];
			}
		}
		return result;
	}
}
int main (int argc , char** argv)
{
	int arr[] =  {2, 4, 7, 8, 13}, x = 12;
    int n = sizeof(arr)/sizeof(arr[0]);
	int theDriodYouAreLookingFor = betacore::smallestSumNearThreshold(arr,n,x) ;
	std::cout << "Value for:" << x << " is " << theDriodYouAreLookingFor << std::endl;
	return 0;
}