#include <iostream>
#include <tuple> 
#include <utility>
#include <map>

#define _X 12
#define _Y 14

typedef std::pair<int , int> kp_t;
typedef std::map<kp_t, int> mp_t;


namespace betacore{
 int max(int a, int b){
     return (a>b)? a: b;
 }
 int cloth(mp_t products, int X, int Y, int(&value) [_X][_Y] ){

    int mxValue = 0;
 
    if( X < 1 || Y <1 )
    {
       // std::cout<< "(" << X << "," <<Y <<")"<<std::endl;
        return mxValue;
    }
    int current = products[kp_t(X,Y)];
    if( X==2 && Y ==1 ){
        std::cout<<"Here" << products[kp_t(X,Y)] <<std::endl;
    }
    int y_2 = (int) Y/2;
    int x_2 = (int) X/2;
    //TODO Check if cloth[X][Y] is -1 if not then take value else we will need to calulate the value
    if(value[X][y_2] ==-1){
        cloth(products, X, y_2 , value);
    }
    if(value[x_2][Y] == -1){
        cloth(products, x_2, Y, value);
    }
    mxValue = max( (value[X][y_2]+ value[X][y_2]) ,value[x_2][Y] + value[x_2][Y] );
    value[X][Y] = mxValue;
        std::cout<< "(" << X << "," <<Y <<")=>"<< mxValue<<std::endl;
    //std::cout<<"here:"<<mxValue <<std::endl;
    return mxValue;     
 }

}

int main (int argc , char * argv[])
{
    int vals[_X][_Y] ;
    //INI Vals
    for(int i=0; i<_X; ++i){
        for(int j=0; j<_Y; ++j){
            vals[i][j] = -1;
        }
    }
    mp_t products;
    products[kp_t(2,1)] = 1;
    products[kp_t(1,2)] = 2;
    products[kp_t(4,1)] = 3;
    products[kp_t(4,2)] = 4;

    std::cout<< products[kp_t(2,1)] <<std::endl;
    std::cout<< products[kp_t(1,2)] <<std::endl;
    //products.insert(kp_t(1,2), 2);
   // ab (1,2);
    //prodcu   ts[ab] = 2;
    int x = betacore::cloth(products, 12,14, vals);
     std::cout<< "const::" << x <<std::endl;
    return 0;
}