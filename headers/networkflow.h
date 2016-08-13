#ifndef _betcore_networkflow_h_
#define _betcore_networkflow_h_

namespace
{
	class networkflow
	{
		
		public: 
			networkflow();
			template <size_t rows, size_t cols>
			void runAlgorithm(int (&input) [rows][cols], int source, int target);
	};
}

#endif