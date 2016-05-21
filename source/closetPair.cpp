#include <iostream>
#include <climits>
#include <cstdlib>
 
// ==================================================
// Finds the cloest Set of numbers near the threshold
// ==================================================
void printClosest(int arr[], int size_of_array, int threshold)
{
    int result_left,
        result_right; 
 
    int left = 0,
        right = size_of_array -1,
        difference = INT_MAX;
 
    while ( right > left )
    {
       if ( arr[right] == threshold )
       {
         result_left=right;
         result_right=right;
	 	 break;
       }
       if ( arr[left] == threshold )
        {
	  	  result_left=left;
          result_right=left;
	 	  break;
	    }
       // Check if this pair is closer than the closest pair so far
       if ( abs( arr[left] + arr[right] - threshold )  < diff )
       {
           result_left = left;
           result_right = right;
           diff = abs( arr[left] + arr[right] - threshold );
       }
 
       // If this pair has a grater sum, move to smaller values.
       if ( arr[left] + arr[right] > threshold )
	   {
		   --right;
	   } else // Move to larger values
       {
		    ++left;
	   } 
    }
 
    std::cout <<" The closest pair is " << arr[result_left] << " and " << arr[result_right] << std::endl;
}
 
// Driver program to test above functions
int main()
{
    int arr[] =  {2, 4, 7, 8, 13}, x = 12;
    int n = sizeof(arr)/sizeof(arr[0]);
    printClosest(arr, n, x);
    printClosest(arr, n, 13);
    printClosest(arr, n, 3);
    return 0;
}