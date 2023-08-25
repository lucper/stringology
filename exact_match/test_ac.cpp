#include "ac.hpp"
#include <iostream>

int main() {
    std::vector<std::string> P = {"a", "ag", "gag", "gc", "gca", "c", "caa"};

    int maxStates = 1;
    for (auto& s : P) maxStates += s.length();
    
    /* go[][] -- stores next state given current state and character, i.e. follows edges of trie of words in arr[]
     * failure[] -- follows edges when current character does NOT have an edge in trie, i.e. suffix links
     * output[] -- bool array storing terminal states */
    int go[maxStates][MAXC];
    int failure[maxStates];
    int output[maxStates];

    memset(output, false, sizeof(output));
    memset(go, -1, sizeof(go));
    memset(failure, -1, sizeof(failure));

    buildAutomaton(P, go, output, failure);

    std::cout << "Automaton (Trie):" << std::endl;
    for (int i = 0; i < maxStates; ++i) {
        for (int j = 0; j < MAXC; ++j)
            std::cout << go[i][j] << " ";
        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Failure function:" << std::endl;
    for (int i = 0; i < maxStates; ++i)
        std::cout << failure[i] << " ";
    std::cout << std::endl;

    std::cout << findNextState(1, 'a', go, failure) << std::endl;
}
