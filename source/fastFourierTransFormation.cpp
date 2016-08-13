#include <iostream>
#include <climits>
#include <math.h>

int * fastFourierTransFormation(int * a,int a_size, int w)
{
	if(w == 1)
	{
		return a;	
	}
	const int n = ((int) (a_size/2))-1;
	
	int * even = new int [n];
	int *  odd = new int [n];
	int i;
	for( i = 0 ; i < a_size ; ++i)
	{
		//Current index to insert; want floor rounding
		int index = (int) i/2;
		//If even load even array 
		if( i % 2 == 0 )
		{
			even[index] = a[i];
		}else{ // load odd array
			odd[index] = a[i];
		}
	}
	//s
	even = fastFourierTransFormation( even,((int) a_size/2) , (w * w));
	//s'
	 odd = fastFourierTransFormation( odd,((int) a_size/2) , (w * w));
	
	int * r = new int[a_size];
	for( i = 0 ; i < n ; ++i) // because use use dived and conqure we only need half of the size 
	{
		r[i] = 	even[i] +  pow(w,j) * odd[j];
		r[j + n] = even[j] - pow(w,j) * odd[j]; 
	}
	return r;
} 