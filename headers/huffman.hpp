#ifndef _BETA_CORE_HUFFMAN_CODE_
#define _BETA_CORE_HUFFMAN_CODE_
namespace betacore {
	struct Node{
		char word;
		double freq;
		Node *left;
		Node *right;
		Node(char word, double freq){
		        left = right  = NULL;
			this->word = word;
			this->freq = freq;
		}
	};
 	void tree_to_map(Node *head, std::vector<bool> &shift,std::map<char,std::vector<bool>> &map);
	void huffman(std::map<char, double> &Table, std::map<char,std::vector<bool>> &map);
	void print_tree(std::map<char,std::vector<bool>> map);
	class Node_Compare{
		public: 
			bool operator()(Node* a1, Node* b1);
	};
}
#endif
