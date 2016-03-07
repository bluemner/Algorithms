// ==============================================
// 
// 
// 
// ==============================================
#include <iostream>
#include <thread>

namespace betacore
{
	
	// ----------------------------------------------
	// Thread A 
	// ----------------------------------------------
	void call_from_threadA ( )
	{
		int i = 0;
		for (; i < 100 ; ++i )
		{
			std::cout << "+ ";
		}
	}
	
	// ----------------------------------------------
	// Thread B
	// ----------------------------------------------
	void call_from_threadB ( )
	{
		int i = 0;
		for (; i < 100 ; ++i )
		{
			std::cout << "- ";
		}
	}
	
	// ----------------------------------------------
	// Thread C 
	// ----------------------------------------------
	void call_from_threadC ( )
	{
		int i = 0;
		for (; i < 100 ; ++i )
		{
			std::cout << "| ";
		}
	}

}

// ----------------------------------------------
// Main Method 
// ----------------------------------------------
int main ( int argc, char ** argv ) 
{
	std::thread thread1(betacore::call_from_threadA);
	std::thread thread2(betacore::call_from_threadB);
	std::thread thread3(betacore::call_from_threadC);

	//wait for thread;
	thread1.join();
	thread2.join();
	thread3.join();
	
	//std::cout << "" << std::endl;
    
    for ( int i = 0; i < 10 ; ++i )
    {
        int x  = i * 2;
        x =  x - 1;
    }
	

    
	return 0;
}
