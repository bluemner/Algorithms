// ==============================================
// 
// 
// 
// ==============================================
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

// ----------------------------------------------
//
//
// ----------------------------------------------
namespace betacore
{

	int majorVersion ()
	{
		return 0;	
	}
	
	int minorVersion ()
	{
		return 0;
	}
	
	int patchVersion()
	{
		return 0;
	}
	
	std::string about ()
	{
		std::stringstream result;
		result << "betacore v" << majorVersion () << "." << minorVersion() << "." << patchVersion() << " By Bradon Bluemner";
	
		return 	result.str ();
	}
	
	// -----------------------------------
	//
	// -----------------------------------
	void println ( std::string message )
	{
		std::cout << message << std::endl;
	}
	
	// -----------------------------------
	//
	// -----------------------------------
	void readFile ( std::string fileName )
	{
		std::string line;
		std::ifstream myfile ( fileName.c_str () ) ;
		
		if ( myfile.is_open () )
		{
			while ( getline( myfile, line ) )
			{
				std::cout << line << std::endl;
			}
						
			myfile.close ();
		}
		else
		{
			std::cout << "error" << std::endl;
		}
	}
	
	// -----------------------------------
	//
	// -----------------------------------
	void makefile ( std::string fileName, std::string context )
	{
		std::ofstream myfile;	
		myfile.open ("s.txt");
		myfile << context << std::endl;
		myfile.close ();
	}
}
// -----------------------------------
//
// -----------------------------------
int main ( int argc, char **argv )
{
	betacore::println ( "apple" );
	betacore::println ( "Application" );	
	betacore::makefile ( "s.txt","Text" );
	betacore::readFile ( "d.txt" );
	betacore::println ( betacore::about() );
	return 0;
}
