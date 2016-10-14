#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <queue>
#include "../headers/huffman.hpp"
#include <bitset>
namespace betacore{
	void tree_to_map(Node *head,std::vector<bool> &shift,std::map<char,std::vector<bool>> &map)
	{
		if(!head)
		   return;

		if(head->word !='~'){
			// std::cout<<head->word << "::";
			// for(int i=0; i<shift.size(); ++i){
			// 	std::cout << shift.at(i) ;
			// }
			// std::cout << std::endl;
			map[head->word] = shift;		
		}
		
		//if(head->left !=NULL)
		std::vector<bool> temp = shift;
		temp.push_back(false);
	
		tree_to_map(head->left ,temp, map );
		//if(head->right !=NULL)
		temp.clear();
		temp =shift;
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
			for (std::map<char,std::vector<bool>>::iterator it=map.begin(); it!=map.end(); ++it){	
				std::cout  << it->first<< ":";				
				for (bool b : it->second){		
					 auto c = (b)?'1':'0';
					 std::cout << c;
				}
				std::cout<<std::endl;
			}
	}
	void encode(std::map<char,std::vector<bool>> map, std::string word, std::vector<bool> &result){
		for(auto c : word){
			result+=map.at(c);
		}        
	}

}//End-NameSpace
/**
 *
 *
 */
int main(int argc, std::string argv[]){
	std::string word="what are the indications for getting a digoxin level?";
	std::map<char, double> Table;

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

	std::map<char,std::vector<bool>> map;

	betacore::huffman(Table, map);
	betacore::print_tree(map);

}
