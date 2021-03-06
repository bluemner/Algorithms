// ==========================================================
// Author: Brandon Bluemner
// Description: Appliction to find smallest Subset Sum
//						  Grater Than A Given Treshold
// ==========================================================
#include <stdio.h>
#include <stdlib.h>
#include <climits>

namespace betacore{
	
// ==========================================================
//
// ==========================================================
void printTable(int ** table, int * arr, int size,int target)
{
	int i, j ;
	printf("\n─────┼─────────────────────────────────────────────────────────────────────────────────\n");
	for ( i =1 ; i < size ; i++)
	{
		if ( i==1)
		{
			for ( j =1; j < target ; j++)
			{	
				if(j==1)
				{
					printf("     │ ");					
				}//End-If
				printf("%03d ",j);
			}//End-For
			printf("\n─────┼─────────────────────────────────────────────────────────────────────────────────\n");
		}//End-If
		for ( j =1; j< target ; j++)
		{			
			if(j==1)
			{
				printf("%05d│ ", arr[i-1]);
			}//End-If
			printf("%d   " ,table[i][j]);
		}//End-For
		printf("\n");
	}//End-For
}

// =================================================
// subset :: subset array
// size :: size of subset array
// This method will print out subset array to console
// ==================================================
void printSubsetTable(int * subset, int size)
{
	// Print the subset
	printf("Subset::" );
	int i;
	for(i =0; i< size; ++i)
	{
		if(subset[i] == -1)
		{
			break;
		}
		else if(i+1 <size && subset[i+1] != -1)
		{
			printf("%d + ",subset[i] );
		}
		else
		{
			printf("%d ",subset[i] );
		}			
	}
	printf("\n" );
}
// ================================================================================================
// This method will go back threw the table and find the smallest subset grater then then threshold
// ================================================================================================
void getSubSetSum(int ** table, int * arr, int size,int col, int row)
{
  int current_col = col;
  int current_row = size;
  int * subset;
  int i,j;
	//at most the size will be arry size
  subset =(int *) malloc (sizeof(int*) * (size)) ;
  for(i =0; i< size; ++i)
	{
		subset[i]=-1;
	}
	//Check array for the minCol value
  int found = -1;
  for(i=row; i< size; ++i)
	{
		if(arr[i] == col)
		{	  found = 1;
				subset[0] = col;
				break;
		}
	}	
	//If not found we will have to go threw back trace of the alogrithm 
	if( found == -1 )
	{		
			int count =0;
			for(i =current_row; i > -1; i--)
			//while ( current_row > -1)
			{
				if( arr[i]>col)
				{
					continue;
				}
				for(j = current_col; j> -1; j--)
				//while ( current_col >-1)
				{
					//B ::	arr[i-1] <= j && table[i-1][j-arr[i-1]]
				 int t = arr[i-1];
				 //int u = table[i-1][j-arr[i-1]];
				 if(arr[i-1] <= j && i-1 >-1 && j-arr[i-1] >-1 && table[i-1][j-arr[i-1]])
				 {  
					 //back trace up till on the correct row
					  while( current_row-1 >= 0 && table[current_row-1][j-arr[i-1]] )
						{
							--current_row;							
						}						
					  current_col = j-arr[i-1];
						subset[count++] = arr[current_row];
						i= current_row ;///-1;
						continue;
				 }//End-If				 
				}//End-for			 
			}//End-for
	}//End-If
				
	printSubsetTable( subset, size );  
	free( subset );
}

// =====================================================================
// table :: table of subset sums
// size :: size of array of values
// target :: Any number grater then your threshold, preferably one that in your array (upper bounds )
// Method for translating table table to .csv file usable in
//				 spreed sheet programs
// =====================================================================
void printTableCSV( int ** table, int * arr, int size,int target )
{
	int i, j ;
	for ( i =1 ; i < size ; i++)
	{
		if ( i==1)
		{
			for ( j =1; j< target ; j++)
			{	
				if(j==1)
				{
					printf(" ,");
				}
				printf("%03d,",j);
			}
			printf("\n");
		}
		for ( j =1; j< target ; j++)
		{			
			if(j==1)
			{
				printf("%05d,", arr[i-1]);
			}
			printf("%d," ,table[i][j]);
		}
		printf("\n");
	}
}

// =======================================================================================
// arr :: array of values
// size :: size of array of values
// target :: Any number grater then your threshold, preferably one that in your array (upper bounds )
// threshold :: The number you want to be grater then but cloest too
// ========================================================================================
void smallestSubsetSumGraterThanTreshold (int arr[], int size, int target, int threshold) {
  int i, j ;
  
  //Create table
  int **table ;
	
	// Allocate Memmory
  table = (int **) malloc (sizeof(int*) * (size+1));  
  // Allocate Memmory
  for ( i = 0 ; i <= size ; i ++ ) 
  {
    table[i] = (int *) malloc (sizeof(int) * (target+1));
	  //Set first row true
    table[i][0] = 1 ;
  }
  
  //Zero out table top row
  for ( j = 1 ; j <= target ; j ++ )
	{
		 table[0][j] = 0 ;
	}
	
	//values for min value and it's row
  int minValue = target;
	int firstRow = size;
	
  for ( i = 1 ; i <= size ; i ++ ) 
  {		
    for ( j = 1 ; j <= target ; j ++ )
		{
			// A: if the value above is true set this row's vale to true
			int A =  table[i-1][j];
			// B: if your are before or on the current column max (ex col 7 all the numbers to the right 7+ will be false)
			//    And the table at 
			int B = (arr[i-1] <= j && table[i-1][j-arr[i-1]] );
			//A || B
			table[i][j] =  A || B ;
			
			if ( j > threshold && j < minValue  && table[i][j] )
			{			
				 minValue = j;
				 firstRow = i+1;
			}			
		}
   
  } // End-For
	
  printf("Min Value :: %d\n", minValue );
  printf("Min row :: %d\n", firstRow );
	
	getSubSetSum( table, arr, size, minValue, firstRow );
	
  if ( target < 100 )
  {
		printTable(table, arr, size +1, target +1);
  }
  free (table) ;
}

// ==============================================
//
// ==============================================
void subsetSum (int arr[], int size, int target) {
  int i, j ;
  int **table ;
  table = (int **) malloc (sizeof(int*) * (size+1)) ;
  for ( i = 0 ; i <= size ; i ++ ) {
    table[i] = (int *) malloc (sizeof(int) * (target+1)) ;
    table[i][0] = 1 ;
  }
  for ( j = 1 ; j <= target ; j ++ )
	{
		table[0][j] = 0 ;
	}
   
  for ( i = 1 ; i <= size ; i ++ ) {
    for ( j = 1 ; j <= target ; j ++ )
		{
			table[i][j] = table[i-1][j] || ( arr[i-1] <= j && table[i-1][j-arr[i-1]] ) ;
		}
  } 
	
 // if ( table[size][target] == 1 )
 //    printf ( "\ntarget sum found\n\n" ) ; 
 // else printf ( "\nTarget sum do not found!\n\n" ) ;
 
  if ( target < 16 )
  {
		//printTable(table, arr, size +1, target +1);	  
		printTableCSV(table, arr, size +1, target +1);	
  }else
  {
	  printTableCSV(table, arr, size +1, target +1);	
  } 
  free (table) ;
}
}
int main()
{
	int i;
	int arr[] = { 2,4,7,8,13, 17};
	int size = sizeof(arr) / sizeof(arr[0]);
	//for ( i =0; i < 16; ++i)
			//subsetSum(arr, size, i); 
	
	betacore::smallestSubsetSumGraterThanTreshold(arr, size, 17, 12); 
	printf("\n\n");
	
	int arr2[] = { 2,4,7,8,17};
	size = sizeof(arr2) / sizeof(arr2[0]);
	//for ( i =0; i < 16; ++i)
	//subsetSum(arr, size, i); 
	betacore::smallestSubsetSumGraterThanTreshold(arr2, size, 17, 12); 
		
	int weights2[1500];
	for ( i=0; i < 1500; ++i )
	{
		weights2[i] = i*2;
	}
	size = sizeof(weights2) / sizeof(weights2[0]);
	//	subsetSum(weights2, size, 256); 
	printf("\nLooking for N > 16\n");
	betacore::smallestSubsetSumGraterThanTreshold( weights2, size, 256, 16);
	printf("\nLooking for N > 158 for all even #\n");
	betacore::smallestSubsetSumGraterThanTreshold( weights2, size, 256, 158);
	return 0;
}
