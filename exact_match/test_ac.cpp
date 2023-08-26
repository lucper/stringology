#include "ac.hpp"

int main() {
    //std::vector<std::string> P = {"a", "ag", "gag", "gc", "gca", "c", "caa"};
    std::vector<std::string> arr = {"he", "she", "hers", "his"};
    std::string text = "ahishers";

    int maxStates = 1;
    for (auto& s : arr) maxStates += s.length();
    
    /* go[][] -- stores next state given current state and character, i.e. follows edges of trie of words in arr[]
     * failure[] -- follows edges when current character does NOT have an edge in trie, i.e. suffix links
     * output[] -- bool array storing terminal states */
    int go[maxStates][MAXC];
    int failure[maxStates];
    int output[maxStates];

    memset(output, 0, sizeof(output));
    memset(go, -1, sizeof(go));
    memset(failure, -1, sizeof(failure));

    buildAutomaton(arr, go, output, failure);

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

    std::cout << std::endl;
    std::cout << "Output states:" << std::endl;
    for (int i = 0; i < maxStates; ++i)
        std::cout << output[i] << " ";
    std::cout << std::endl;

    std::cout << std::endl;
    search(arr, text, go, output, failure);
}
