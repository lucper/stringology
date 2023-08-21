#include <string>

class Node {
    public:
        bool isWord;
        Node* children[26];
        
        Node();
        ~Node();
};

class MultiwayTrie {
    public:
        Node* root;

        bool find(const std::string& word);
        void insert(const std::string& word);
        void remove(const std::string& word);
        MultiwayTrie();
        ~MultiwayTrie();
};
