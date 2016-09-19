#include <iostream>
#include <vector>
#define X_L 0
#define X_R 1
#define X_H 2
#define V_SIZE 3


void merge_vectors(std::vector<std::vector<int>> &X, std::vector<int> &V, std::vector<std::vector<int>> &new_x);
int getMaxHeight(std::vector<std::vector<int>> &X);



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


int getMaxHeight(std::vector<std::vector<int>> &X){

	int max = X[0][X_H];
	int i;
	for(i=1; i < X.size(); ++i){
		if(max < X[i][X_H]){
			max = max = X[i][X_H];
		}
	}
	return max;
}


template <size_t rows, size_t cols>
std::vector<std::vector<int>> merge(int (&X)[rows][cols], int size, int *V){
	int maxHeight = getMaxHeight(X,size);
	int i;
	std::vector<std::vector<int>> new_x;
	std::vector<int> v;
	v.assign(V , V + V_SIZE);
	
	if(maxHeight < V[X_H]){
		 
		//Note this is one loop that is programmed really badly...
		
		for( i= size - 1;  i > -1; --i)
		{
			if( i > 0 && X[i][X_R] < V[X_R]){
				continue;
			}
			if( i <= 0 ){ // not found
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
				// Replace XL<- with VR
				int x[3];
					x[X_L]=V[X_R];
					x[X_R]=X[i][X_R];
					x[X_H]=X[i][X_H];
					std::vector<int> x_v(x, x + sizeof x / sizeof x[0]);
				new_x.push_back(x_v);
			}
		}// End-For		
	}else{
		// V < MAX HEIGHT
		
		for(i = size -1;i > -1; --i){
		//do{
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
				std::vector<int> x_v;
				x_v.assign(x , x + V_SIZE);
				
				std::vector<int> v_v; 
				v_v.assign(t , t + V_SIZE);
				
				new_x.push_back(x_v);	
				new_x.push_back(v_v);
				
			}else if(V[X_L] < X[i][X_R])
			{
		
				int x[3];
					x[X_L]=X[i][X_L];
					x[X_R]=X[i][X_R];
					x[X_H]=X[i][X_H];
				int t[3];
					t[X_L]=V[X_L];
					t[X_R]=X[i][X_L]; 
					t[X_H]=V[X_H];
					
				std::vector<int> x_v; 
				x_v.assign(x , x + V_SIZE);
				
				std::vector<int> v_v; 
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
			
				std::vector<int> x_v(x, x + sizeof x / sizeof x[0]);			
				new_x.push_back(x_v);
				
			
			}
		//	--i;

		//	}while(i>-1);
		}
	}
	return new_x;
}

void merge_vectors(std::vector<std::vector<int>> &X, std::vector<int> &V, std::vector<std::vector<int>> &new_x){
	
	int maxHeight = getMaxHeight(X);
	int i;
	std::vector<int> v = V;
	
	if(maxHeight < V[X_H]){
		 
		//Note this is one loop that is programmed really badly...
		
		for( i= X.size() - 1;  i > -1; --i)
		{
			if( i > 0 && X[i][X_R] < V[X_R]){
				continue;
			}
			if( i <= 0 ){ // not found
				int x[3];
					x[X_L]=X[0][X_L];
					x[X_R]=V[X_L];
					x[X_H]=X[0][X_H];
					//x + sizeof x / sizeof x[0]
          		std::vector<int> x_v; //(x, x + sizeof x / sizeof x[0]);
				x_v.assign(x , x + V_SIZE);
				new_x.push_back(x_v);
				new_x.push_back(v);
				return;
			}else{
				//Ex  X -> [ [ 8 ,11, 4], [ 8 ,17, 2] ];
				//    V -> [10, 14, 7];
				// Replace XL<- with VR
				int x[3];
					x[X_L]=V[X_R];
					x[X_R]=X[i][X_R];
					x[X_H]=X[i][X_H];
					std::vector<int> x_v(x, x + sizeof x / sizeof x[0]);
				new_x.push_back(x_v);
			}
		}// End-For		
	}else{
		// V < MAX HEIGHT
		
		for(i = X.size() -1;i > -1; --i){
		//do{
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
				std::vector<int> x_v;
				x_v.assign(x , x + V_SIZE);
				
				std::vector<int> v_v; 
				v_v.assign(t , t + V_SIZE);
				
				new_x.push_back(x_v);	
				new_x.push_back(v_v);
				
			}else if(V[X_L] < X[i][X_R])
			{
		
				int x[3];
					x[X_L]=X[i][X_L];
					x[X_R]=X[i][X_R];
					x[X_H]=X[i][X_H];
				int t[3];
					t[X_L]=V[X_L];
					t[X_R]=X[i][X_L]; 
					t[X_H]=V[X_H];
				
				new_x.push_back(std::vector<int>(x , x + V_SIZE));	
				new_x.push_back(std::vector<int>(t , t + V_SIZE));
			}
			else{
				//Ex  X -> [ [ 8 ,11, 4], [ 8 ,17, 2] ];
				//    V -> [10, 14, 7];
				
				int x[3];
					x[X_L]=X[i][X_L];
					x[X_R]=X[i][X_R];
					x[X_H]=X[i][X_H];		
			
							
				new_x.push_back(std::vector<int>(x, x + sizeof x / sizeof x[0]));
				
			
			}
		//	--i;

		//	}while(i>-1);
		}
	}

}

void skyline(std::vector<std::vector<int>> &X, std::vector<std::vector<int>> &result ){   
	int n; 

	std::vector<std::vector<int>> m_n;
	
	//Get first elemnt as a vector....
	m_n.push_back(X.at(0));

	for( n=1; n<X.size(); ++n ){
				
		if(  X[n][X_L] < X[n-1][X_R] ){
			
			std::vector<std::vector<int>> new_x;
			merge_vectors( m_n, X.at(n) , new_x);			
			m_n.clear();
			m_n.insert(m_n.end(), new_x.begin(), new_x.end());
		}else{
			result.insert(result.end(), m_n.begin(), m_n.end());
			m_n.clear();
			m_n.push_back(X.at(n));
		}
	}
	result.insert(result.end(), m_n.begin(), m_n.end());
	m_n.clear();
	

}

int main(int argc, char ** argv){
	std::cout << "Case 1" <<std::endl;
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
	std::cout << "Case 2" <<std::endl;
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
	std::cout << "Case 3" <<std::endl;
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
	std::cout << "__________" <<std::endl;
	std::cout << "Case 4 " <<std::endl;
	std::cout << "__________" <<std::endl;
	// =========================
	// Case 
	// =========================
	std::vector<std::vector<int>> Case4 { // [5][V_SIZE] =
		{  2,  5, 8 },
		{  4,  7, 3 },
		{  8, 11, 4 },
		{  9, 13, 2 },
		{ 10, 14, 7 }
	};	
	result.clear();
	skyline(Case4,result);

	for (std::vector<std::vector<int>>::const_iterator i = result.begin(); i != result.end(); ++i)
    {
		for (std::vector<int>::const_iterator j = i->begin(); j != i->end(); ++j)
		{
				std::cout << *j << ' ';
		}
		std::cout<< std::endl;
	}
	return 0;
}