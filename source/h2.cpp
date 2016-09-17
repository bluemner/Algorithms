#include <iostream>
#include <vector>
#define X_L 0
#define X_R 1
#define X_H 2
#define V_SIZE 3

struct vec { int weight[3];};

template <size_t rows, size_t cols>
int getMaxHeight(int (&X)[rows][cols], int size){
	int max = X[0][X_H];
	int i;
	for(i=1; i < size; ++i){
		if(max <  X[i][X_H]){
			max = max = X[i][X_H];
		}
	}
	return max;
}

template <size_t rows, size_t cols>
std::vector<std::vector<int>> merge(int (&X)[rows][cols], int size, int *V){
	int maxHeight = getMaxHeight(X,size);
	std::vector<std::vector<int>> new_x;
	std::vector<int> v;
	v.assign(V , V + V_SIZE);
	if(maxHeight < V[X_H]){
		int i = size - 1;
		do{
			//Wile V  dominates X move pointer 
			while(i > -1 && X[i][X_R] < V[X_R]){ 
				--i;
			}
			if( i < 0 ){ // not found
				int x[3];
					x[X_L]=X[0][X_L];
					x[X_R]=V[X_L];
					x[X_H]=X[0][X_H];
					//x + sizeof x / sizeof x[0]
          		std::vector<int> x_v; //(x, x + sizeof x / sizeof x[0]);
				x_v.assign(x , x + V_SIZE);
				new_x.push_back(x_v);
				new_x.push_back(v);
				return new_x;
			}else{
				//Ex  X -> [ [ 8 ,11, 4], [ 8 ,17, 2] ];
				//    V -> [10, 14, 7];
				int x[3];
					x[X_L]=V[X_R];
					x[X_R]=X[i][X_R];
					x[X_H]=X[i][X_H];
					std::vector<int> x_v(x, x + sizeof x / sizeof x[0]);
				new_x.push_back(x_v);
			}
			--i;

		}while(i>-1);
	}else{
		// V < MAX HEIGHT
		
		int i = size -1;
		do{
			/*while( i > -1 && X[i][X_H] > V[X_H]){ 
					--i;
			}*/
			// Found the driod
			if( V[X_L] < X[i][X_R] && V[X_L] > X[i][X_L]){ //&&   ){ // not found
				
				
				int x[3];
					x[X_L]=X[i][X_L];//X[0][X_L];
					x[X_R]=X[i][X_R];// V[X_R];//V[X_L];
					x[X_H]=X[i][X_H];
				int t[3];
					t[X_L]=X[i][X_R];//X[0][X_L];
					t[X_R]=V[X_R];// V[X_R];//V[X_L];
					t[X_H]=V[X_H];
					//x + sizeof x / sizeof x[0]
				std::vector<int> x_v; //(x, x + sizeof x / sizeof x[0]);
				x_v.assign(x , x + V_SIZE);
				
				std::vector<int> v_v; //(x, x + sizeof x / sizeof x[0]);
				v_v.assign(t , t + V_SIZE);
				new_x.push_back(x_v);	
				new_x.push_back(v_v);
				
			}else if(V[X_L] < X[i][X_R])
			{
		
				int x[3];
					x[X_L]=X[i][X_L];//X[0][X_L];
					x[X_R]=X[i][X_R];// V[X_R];//V[X_L];
					x[X_H]=X[i][X_H];
				int t[3];
					t[X_L]=X[i][X_R];//X[0][X_L];
					t[X_R]=V[X_R];// V[X_R];//V[X_L];
					t[X_H]=V[X_H];
					//x + sizeof x / sizeof x[0]
				std::vector<int> x_v; //(x, x + sizeof x / sizeof x[0]);
				x_v.assign(x , x + V_SIZE);
				
				std::vector<int> v_v; //(x, x + sizeof x / sizeof x[0]);
				v_v.assign(t , t + V_SIZE);
				new_x.push_back(x_v);	
				new_x.push_back(v_v);
			}
			else{
				//Ex  X -> [ [ 8 ,11, 4], [ 8 ,17, 2] ];
				//    V -> [10, 14, 7];
				
				int x[3];
					x[X_L]=X[i][X_L];
					x[X_R]=X[i][X_R];
					x[X_H]=X[i][X_H];
					
				// int t[3];
				// 	t[X_L]=V[X_L];//X[0][X_L];
				// 	t[X_R]=X[i][X_L]; //V[X_R];//V[X_L];
				// 	t[X_H]=V[X_H];
				// 	std::vector<int> v_v; //(x, x + sizeof x / sizeof x[0]);
				// v_v.assign(t , t + V_SIZE);
				//new_x.push_back(v_v);
			
				std::vector<int> x_v(x, x + sizeof x / sizeof x[0]);			
				new_x.push_back(x_v);
				
			
			}
			--i;

		}while(i>-1);

	}
	return new_x;
}
int main(int argc, char ** argv){
	int Case1 [1][V_SIZE] ={
		{ 2,5,8	}
	};
	int v [V_SIZE] = { 4,7,3};
	std::vector<std::vector<int>> result =merge(Case1, 1, v);
	for (std::vector<std::vector<int>>::const_iterator i = result.begin(); i != result.end(); ++i)
    {
		for (std::vector<int>::const_iterator j = i->begin(); j != i->end(); ++j)
		{
				std::cout << *j << ' ';
		}
		std::cout<< std::endl;
	}
	std::cout << "__________" <<std::endl;
	std::cout << "Case 2A" <<std::endl;
	int Case2A [2][V_SIZE] ={
		{ 8,11,4 }
	};
	v[X_L] =  9;
	v[X_R] =  13; 
	v[X_H] =  2;

	//Case Merge M2 D
	result =merge(Case2A, 1, v);
	for (std::vector<std::vector<int>>::const_iterator i = result.begin(); i != result.end(); ++i)
    {
		for (std::vector<int>::const_iterator j = i->begin(); j != i->end(); ++j)
		{
				std::cout << *j << ' ';
		}
		std::cout<< std::endl;
	}
	std::cout << "__________" <<std::endl;
	std::cout << "Case 2B" <<std::endl;
	int Case2B [1][V_SIZE] ={
		{ 2,9,7 }
	};
	v[X_L] =  1;
	v[X_R] =  3; 
	v[X_H] =  4;

	//Case Merge M2 D
	result =merge(Case2B, 1, v);
	for (std::vector<std::vector<int>>::const_iterator i = result.begin(); i != result.end(); ++i)
    {
		for (std::vector<int>::const_iterator j = i->begin(); j != i->end(); ++j)
		{
				std::cout << *j << ' ';
		}
		std::cout<< std::endl;
	}

	std::cout << "__________" <<std::endl;
	std::cout << "Case 2C" <<std::endl;
	int Case2C [2][V_SIZE] ={
		{ 1,2,4 },
		{ 2,9,7 }
	};
	v[X_L] =  7;
	v[X_R] =  14; 
	v[X_H] =  2;

	//Case Merge M2 D
	result =merge(Case2C, 2, v);
	for (std::vector<std::vector<int>>::const_iterator i = result.begin(); i != result.end(); ++i)
    {
		for (std::vector<int>::const_iterator j = i->begin(); j != i->end(); ++j)
		{
				std::cout << *j << ' ';
		}
		std::cout<< std::endl;
	}

	std::cout << "__________" <<std::endl;
	
	int Case2 [2][V_SIZE] ={
		{ 8,11,4 },
		{ 11,13,2 }
	};
	v[X_L] =  10;
	v[X_R] =  14; 
	v[X_H] =  07;

	//Case Merge M2 D
	result =merge(Case2, 2, v);
	for (std::vector<std::vector<int>>::const_iterator i = result.begin(); i != result.end(); ++i)
    {
		for (std::vector<int>::const_iterator j = i->begin(); j != i->end(); ++j)
		{
				std::cout << *j << ' ';
		}
		std::cout<< std::endl;
	}
		std::cout << "__________" <<std::endl;
	// =========================
	// Case 
	// =========================
	int Case3 [2][V_SIZE] ={
		{ 8,11,4 },
		{ 8,17,2 }
	};
	v[X_L] =  10;
	v[X_R] =  14; 
	v[X_H] =  07;
	result =merge(Case3, 2, v);

	for (std::vector<std::vector<int>>::const_iterator i = result.begin(); i != result.end(); ++i)
    {
		for (std::vector<int>::const_iterator j = i->begin(); j != i->end(); ++j)
		{
				std::cout << *j << ' ';
		}
		std::cout<< std::endl;
	}
}