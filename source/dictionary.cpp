#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>
namespace betacore
{
/**
 *
 */
void read_file(std::string file_name, std::unordered_map<std::string, int> &dict)
{
    std::string line;
    std::ifstream myfile(file_name.c_str());
    if (myfile.is_open())
    {
		while (getline(myfile, line))
		{
			//std::cout << line << std::endl;
			dict[line] = 1;
		}
		myfile.close();
    }
	else
	{
		std::cout << "error" << std::endl;
	}
}

std::string recover_word(std::string croupted_text, std::unordered_map<std::string, int> &dict)
{
	int i=0; 
	int j=0;
	int l=croupted_text.length();
    int M[l][l];
    for (i = 0; i < l; ++i)
    {
		for (j = 0; j < l; ++j)
		{
			M[i][j]=0;
		}
    }

    for (i = 0; i < l; ++i)
    {
		for(j=0; j< i; ++j){
			std::cout << "x\t";
		}
		for (j = i; j < l; ++j)
		{
			
			auto _w = croupted_text.substr(i, j-i+1);
			//std::cout << _w << "\t";
			M[i][j] = dict[_w];
			std::cout <<M[i][j] << "\t";
		}
			std::cout <<std::endl;
    }
	std::string result = "";
	int max = 0;
	for(i=0; i < l; ++i){
		j=i;
		max = i;
		for(;j< l; ++j){
			if(M[i][j] == 1){
				max = j;
			}
		
		}
		auto _w = croupted_text.substr(i, max-i+1);
		result+=_w +"_";
		std::cout <<i<<"::"<<result <<std::endl;
		i=max;
	}
	std::cout <<"result::"<<result <<std::endl;
	
	return result;
}

} //end-namespace

int main(int argc, char *argv[])
{
	std::string path="..";
	if(argc>1){
		path =argv[1];
	}
    std::unordered_map<std::string, int> dict;
	std::cout << "A::"<< dict.size() << std::endl;
    betacore::read_file(path+"/data/words.txt", dict);
	std::cout << "B::"<< dict.size() << std::endl;
    std::string result = betacore::recover_word("itwasthebestoftimes", dict);
	return 0;
}