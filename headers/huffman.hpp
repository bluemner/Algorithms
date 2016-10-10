#ifndef _BETA_CORE_HUFFMAN_CODE_
#define _BETA_CORE_HUFFMAN_CODE_
namespace betacore {
	struct Node{
		char word;
		double freq;
		Node *left;
		Node *right;
		Node(char word, double freq){
			this->word = word;
			this->freq = freq;
		}
	};
 	void print_tree(Node *head, std::string path);
	void huffman(std::map<char, double> &Table);

	class Node_Compare{
		public: 
			bool operator()(Node* a1, Node* b1);
	};
}
#endif
