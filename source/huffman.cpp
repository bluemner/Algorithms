#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <queue>
#include "../headers/huffman.hpp"

namespace betacore{
	void print_tree(Node *head, std::string path)
	{
		if(!head)
		   return;

		if(head->word !='~'){
			std::cout<< head->word << ":" << path<< std::endl;
		}
		print_tree(head->left , path+"0");
		print_tree(head->right, path+"1");
	}

	void huffman(std::map<char, double> &Table){
		struct Node *left, *right, *_node;

		std::priority_queue<Node*, std::vector<Node*>, Node_Compare> pq;

		for (std::map<char,double>::iterator it=Table.begin(); it!=Table.end(); ++it){
			pq.push(new Node(it->first, it->second));
                       //std::cout  << it->first<< ":"<< it->second <<std::endl;
		}
		std::cout << "Size:" << pq.size() <<std::endl;

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
		print_tree(pq.top(), std::string(""));

	}

	bool Node_Compare::operator()(Node* a1, Node* b1){
			 return( a1->freq > b1->freq);
		}
}

/**
 *
 *
 */
int main(int argc, std::string argv[]){
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

	betacore::huffman(Table);
}
