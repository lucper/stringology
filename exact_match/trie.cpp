#include "trie.hpp"

Node::Node() {
    isWord = false;
    for (int i = 0; i < 26; ++i)
        children[i] = nullptr;
}

Node::~Node() {
    for (int i = 0; i < 26; ++i)
        delete children[i];
}

MultiwayTrie::MultiwayTrie() {
    root = new Node();
}

MultiwayTrie::~MultiwayTrie() {
    delete root;
}

bool MultiwayTrie::find(const std::string& word) {
    Node* curr = root;
    for (int c : word)
        if (curr->children[c-65] == nullptr)
            return false;
        else
            curr = curr->children[c-65];
    return curr->isWord;
}

void MultiwayTrie::insert(const std::string& word) {
    Node* curr = root;
    for (int c : word) {
        if (curr->children[c-65] == nullptr)
            curr->children[c-65] = new Node();
        curr = curr->children[c-65];
    }
    curr->isWord = true;
}

void MultiwayTrie::remove(const std::string& word) {
    Node* curr = root;
    for (int c : word)
        if (curr->children[c-65] == nullptr)
            return;
        else
            curr = curr->children[c-65];
    curr->isWord = false;
}
