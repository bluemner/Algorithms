#include <iostream>
#include <string>
#include <vector>


namespace betacore
{
    struct Node{
        char word;
    };
    struct Edge{
        Node *source;
        Node *target;
    };
    struct Graph{
        std::vector<Node*> nodes;
        std::vector<Edge*> edges;
    };
    void run(Graph &G){
       int visited [G.nodes.size()];
        for(auto v : G.nodes){
            if( v !=NULL){

            }
        }
    }
}
int main (int argc, char** argv){
    betacore::Graph G;
    betacore::Node node_a; 
                   node_a.word='A';
  

    delete node_a;
    delete node_b;
    delete node_c;
    delete node_d;


}