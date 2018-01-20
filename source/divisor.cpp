#include <iostream>
#include <vector>

int divisors(long long x)
{
	long long limit = x;
	int numberOfDivisors = 0;

	if (x == 1)
		return 1;

	for (long long i = 1; i < limit; ++i)
	{
		if (x % i == 0)
		{
			limit = x / i;
			if (limit != i)
			{
				numberOfDivisors++;
			}
			numberOfDivisors++;
		}
		if(numberOfDivisors > 8){
			break;
		}
	}

	return numberOfDivisors;
}

long long divisor2(long long n)
{
	int cnt;
	long long total = 0;
	for (long long i = 1; i < n; i++)
	{
		if(divisors(i) == 8) ++total;
	}
	//std::cout << "Total:" << total << std::endl;
	return total;
}

void divisor(long long n, int goal, std::vector<long long> &list)
{
	int cnt;
	long long total = 0;
	for (long long i = 1; i < n; i++)
	{
		cnt = 0;
		for (long long j = 1; j <= i; j++)
		{
			if (i % j == 0)
			{
				++cnt;
			}
			if (cnt > goal)
			{
				//std::cout<<"("<<i<<","<<j<<")=>"<<cnt<<std::endl;
				break;
			}
		}

		if (cnt == goal)
		{
			//list.push_back(i);
			++total;
		}
		else
		{
			//std::cout<<"("<<i<<","<<cnt<<")"<<std::endl;
		}
	}
	std::cout << "Total:" << total << std::endl;
}

int main()
{
	long n = 100;
	int goal = 8;
	std::vector<long long> the_numbers_you_are_looking_for;
	divisor(n, goal, the_numbers_you_are_looking_for);
	
	std::cout << the_numbers_you_are_looking_for.size() << std::endl;
	the_numbers_you_are_looking_for.clear();

	divisor(1000, goal, the_numbers_you_are_looking_for);
	std::cout << the_numbers_you_are_looking_for.size() << std::endl;
	the_numbers_you_are_looking_for.clear();
	
	std::cout << "big number" << divisor2(100) << std::endl;
	std::cout << "big number" << divisor2(1000) << std::endl;
	std::cout << "big number" << divisor2(1000000000000) << std::endl;
}