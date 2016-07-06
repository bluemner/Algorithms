#ifndef _betacore_smallest_subset_sum_grater_than_treshold_h_
#define _betacore_smallest_subset_sum_grater_than_treshold_h_

namespace betacore
{
	void printTable(int ** table, int * arr, int size,int target);
	void printSubsetTable(int * subset, int size);
	void getSubSetSum(int ** table, int * arr, int size,int col, int row);
	void printTableCSV( int ** table, int * arr, int size,int target );
	void smallestSubsetSumGraterThanTreshold (int arr[], int size, int target, int threshold);
}
#endif