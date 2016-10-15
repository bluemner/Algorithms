#ifndef _BETA_CORE_HUFFMAN_CODE_
#define _BETA_CORE_HUFFMAN_CODE_
namespace betacore {
	
	/**
	 * Node for huffmant code 
	 */
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
 	/**
	 * Input :: String , Result Vector<bool>
	 *  bool vector of the binary representation to ascii
	 */
	void word_to_ASCII(std::string word, std::vector<bool> &result);
	/**
	 *  Convert Huffman tree to std::map
	 */
	void tree_to_map(Node *head, std::vector<bool> &shift,std::map<char,std::vector<bool>> &map);
	
	/**
	 * Huffman Algorithm
	 */
	void huffman(std::map<char, double> &Table, std::map<char,std::vector<bool>> &map);
	/**
	 * Prints the map version of the huffman tree
	 */
	void print_tree(std::map<char,std::vector<bool>> map);
	/**
	 * Prints vector bool on one line
	 */
	void print_vector(std::vector<bool> &vec);
	/** 
	 *	Pints the map to table
	 */
	void print_map(std::map<char,double> map);
	/**
	 * Input: word, result< char , probablity>
	 * Gets the word count and calcules the probality 
	 */
	void word_count(std::string word,std::map<char,double> &result);
	/**
	 * Encodes the word using huffman code map.
	 */
	void encode(std::map<char,std::vector<bool>> map, std::string word, std::vector<bool> &result);
	/** 
	 * Compair class needed for std::priority_queue
	 */
	class Node_Compare{
		public: 
			bool operator()(Node* a1, Node* b1);
	};
}
#endif
