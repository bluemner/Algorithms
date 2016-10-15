#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <queue>
#include "../headers/huffman.hpp"
#include <bitset>

namespace betacore{

	void word_to_ASCII(std::string word, std::vector<bool> &result){
		for(auto c : word){
			for (int i = 7; i >= 0; --i) {
        		result.push_back((c & (1 << i))? 1 : 0);
    		}			
		
		}
	}

	void tree_to_map(Node *head,std::vector<bool> &shift,std::map<char,std::vector<bool>> &map){
		if(!head)
		   return;

		if(head->word !='~'){
			map[head->word] = shift;		
		}
				
		std::vector<bool> temp = shift;
		temp.push_back(false);
	
		tree_to_map(head->left ,temp, map );		
		temp.clear();

		temp = shift;
		temp.push_back(true);
		tree_to_map(head->right,temp, map );
	}

	void huffman(std::map<char, double> &Table,std::map<char,std::vector<bool>> &map){
		struct Node *left, *right, *_node;
		std::priority_queue<Node*, std::vector<Node*>, Node_Compare> pq;
		for (std::map<char,double>::iterator it=Table.begin(); it!=Table.end(); ++it){
			pq.push(new Node(it->first, it->second));
		}
		while(pq.size() != 1){
			left = pq.top();
			pq.pop();

			right = pq.top();
			pq.pop();
			//Merge
			_node =  new Node('~', left->freq + right->freq);
			_node->left = left;
			_node->right = right;
			// Back to the que you go....
			pq.push(_node);

		}
		std::vector<bool> shift;	
		tree_to_map(pq.top(), shift, map);
		
	}

	bool Node_Compare::operator()(Node* a1, Node* b1){
			 return( a1->freq > b1->freq);
	}

	void print_tree(std::map<char,std::vector<bool>> map){
		std::cout << "─┬────────────" << std::endl;
		std::cout<<"λ│code"<<std::endl;
		std::cout << "─┼────────────" << std::endl;
			for (std::map<char,std::vector<bool>>::iterator it=map.begin(); it!=map.end(); ++it){	
				std::cout  << it->first<< "│";				
				for (bool b : it->second){		
					 auto c = (b)?'1':'0';
					 std::cout << c;
				}
				std::cout<<std::endl;
				std::cout << "─┼────────────" << std::endl;
			}
	}

	void print_map(std::map<char,double> map){
		double d =0;
		std::cout << "─┬────────────" << std::endl;
		std::cout << "λ│ probability" << std::endl;
		std::cout << "─┼────────────" << std::endl;
		for (std::map<char,double>::iterator it=map.begin(); it!=map.end(); ++it){	
			std::cout << it->first<< "│";				
			std::cout << it->second;
			std::cout << std::endl;
			std::cout << "─┼────────────" << std::endl;
			d += it->second;
		}
		std::cout<<"Total Probablity::"<< d<<std::endl;
	}

	void word_count(std::string word,std::map<char,double> &result){
		for(auto c: word){
			if(result.find( c ) == result.end()){
				result[c] = 1;
			}else{
				result[c]+=1;
			}
		}
		for(std::map<char,double>::iterator it=result.begin(); it!=result.end(); ++it){
			result[it->first]= it->second/word.size();
		}
	}

	void print_vector(std::vector<bool> &vec){
		for(auto c:vec){
			std::cout<<c;
		}
		std::cout<<std::endl;
	}

	void encode(std::map<char,std::vector<bool>> map, std::string word, std::vector<bool> &result){
		for(auto c : word){
			auto val = map.at(c);
			result.insert(result.end(),val.begin(), val.end());
		}

	}

}//End-NameSpace

/**
 *
 *
 */

int main(int argc, std::string argv[]){
	
	//Set to false to just show answers;
	bool debug = true;
	std::cout<<"Bluemner HW 2 - Note ASCII IS 8 bits on computer, this will be reflected in calculations" <<std::endl;
	std::string word="what are the indications for getting a digoxin level?";
	
	std::cout<<"EX: ASCII Letter a:: ";
	betacore::word_to_ASCII("a",bits);		
	betacore::print_vector(bits);	
	bits.clear();

	// Binary bit stream (easier to see this way)
	std::vector<bool> bits;
	// Table of probabilities
	std::map<char, double> Table ;
	// Huffman Code 
	std::map<char,std::vector<bool>> map;
	
	//ASCII WORD
	betacore::word_to_ASCII(word,bits);
	if(debug){
		std::cout<<"ASCII word:: ";
		betacore::print_vector(bits);
	}

	int ascii_word_length = bits.size();
	std::cout<<"ASCII word length::"<< ascii_word_length << std::endl;
	bits.clear();	

	std::cout << "┌────────────────────────────────────────────────────────────┐"<<std::endl;
	std::cout << "│ HW Q3 - Define Huffman code with probabilities durived from│"<< std::endl;
	std::cout << "│         Each words avg word length.                        │"<< std::endl;
	std::cout << "└────────────────────────────────────────────────────────────┘"<<std::endl;

	betacore::word_count(word,Table);
	betacore::print_map(Table);
	
	betacore::huffman(Table, map);
	betacore::encode(map,word,bits);
	
	if(debug){
		betacore::print_tree(map);
		std::cout<<"Huffman Encoded:"<<std::endl;	
		betacore::print_vector(bits);
	}
	std::cout<<"Length::" << bits.size() << " bits" << std::endl;
	std::cout<<"Compression Ratio " << ((double)ascii_word_length/bits.size()) * 100 << "%" << std::endl;
	// Tear down 
	bits.clear();
	Table.clear();

	std::cout << "┌─────────────────────────────────────────────────────────┐"<<std::endl;
	std::cout << "│ HW Q4 - Table provided - Calc the probablity given the  │"<<std::endl;
	std::cout << "│         table below                                     │"<<std::endl;
	std::cout << "└─────────────────────────────────────────────────────────┘"<<std::endl;

	Table[' '] = 0.1686;
	Table['e'] = 0.1031;
	Table['t'] = 0.0796;
	Table['a'] = 0.0642;
	Table['o'] = 0.0632;
	Table['i'] = 0.0575;
	Table['n'] = 0.0574;
	Table['s'] = 0.0514;
	Table['r'] = 0.0484;
	Table['h'] = 0.0467;
	Table['l'] = 0.0321;
	Table['d'] = 0.0317;
	Table['u'] = 0.0228;
	Table['c'] = 0.0218;

	Table['f'] = 0.0208;
	Table['m'] = 0.0198;
	Table['w'] = 0.0175;
	Table['?'] = 0.0173;
	Table['y'] = 0.0164;
	Table['p'] = 0.0152;
	Table['g'] = 0.0152;
	Table['b'] = 0.0127;
	Table['v'] = 0.0083;
	Table['k'] = 0.0049;
	Table['x'] = 0.0013;
	Table['q'] = 0.0008;
	Table['j'] = 0.0008;
	Table['z'] = 0.0005;

	betacore::huffman(Table, map);	
	betacore::encode(map,word,bits);

	if(debug){
		betacore::print_tree(map);
		std::cout<<"Huffman Encoded:"<<std::endl;
		betacore::print_vector(bits);
	}

	std::cout<< "Length::" << bits.size() << " bits"<<std::endl;
	std::cout<<"Compression Ratio " << ((double) ascii_word_length/bits.size()) * 100 << "%" << std::endl;
	return 0;
}
