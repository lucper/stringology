#include "trie.hpp"
#include <iostream>

int main() {
    MultiwayTrie trie{};

    trie.insert("AND");
    trie.insert("AN");
    trie.insert("ASK");
    
    std::cout << "AND " << trie.find("AND") << std::endl;
    std::cout << "AN " << trie.find("AN") << std::endl;
    std::cout << "ASK " << trie.find("ASK") << std::endl;
    std::cout << "A " << trie.find("A") << std::endl;
    std::cout << "OIOI " << trie.find("OIOI") << std::endl;

    trie.remove("ASK");
    std::cout << "removing ASK" << std::endl;

    std::cout << "AND " << trie.find("AND") << std::endl;
    std::cout << "AN " << trie.find("AN") << std::endl;
    std::cout << "ASK " << trie.find("ASK") << std::endl;
    std::cout << "A " << trie.find("A") << std::endl;
    std::cout << "OIOI " << trie.find("OIOI") << std::endl;
}
