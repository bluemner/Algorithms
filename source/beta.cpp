// ==============================================
// 
// 
// 
// ==============================================
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "../headers/beta.h"

namespace betacore
{
   
    std::string beta::getName ()
    {
        return "Beta";  
    }// getName
    
    int beta::getNumber( int a, int b)
    {
        return a * b;
    }// getNumber
    
    int  beta::majorVersion ()
	{
		return 0;
	}// majorVersion
	
	int  beta::minorVersion ()
	{
		return 0;
	}// minorVersion
	
	int  beta::patchVersion()
	{
		return 0;
	}// patchVersion
	
	std::string  beta::about()
	{
		std::stringstream result;
		result << "betacore v" << majorVersion () << "." << minorVersion() << "." << patchVersion() << " By Bradon Bluemner";
	
		return 	result.str ();
	}// about
}// namespace

// ----------------------------------------------
//
//
// ----------------------------------------------
int main( )
{    
    betacore::beta b;
    betacore::beta* c = &b;    
       
    std::cout << b.getName( ) << std::endl ;
    std::cout << b.getNumber( 7 , 3 ) << std::endl ;
    std::cout << b.about() << std::endl ;
    
    std::cout << c->getNumber( 3 , 3 ) << std::endl ;
    
    // Pointers 
    int size = 5 ;
    
    int * foo;
    foo = new int [ size ];
    
    std::cout << foo << std::endl ; 
   
    delete foo; 
    foo = NULL;
    
    std::cout << foo << std::endl ; 
    
    return 0;
}// main