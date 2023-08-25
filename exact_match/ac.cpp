#include "ac.hpp"

void buildAutomaton(const std::vector<std::string>& arr, int go[][MAXC], int output[], int failure[]) {
    // We start with 1 state corresponding to the empty string
    int states = 1;

    // Build trie, i.e. fill go[][]
    for (auto& pattern : arr) {
        int currentState = 0;
        for (int i = 0; i < pattern.size(); ++i) {
            int ch = pattern[i] - 'a';
            if (go[currentState][ch] == -1)
                go[currentState][ch] = states++;
            currentState = go[currentState][ch];
        }
        output[currentState] = true;
    }

    for (int ch = 0; ch < MAXC; ++ch)
        if (go[0][ch] == -1)
            go[0][ch] = 0;

    // Now comes the failure function
    std::queue<int> Q;

    for (int ch = 0; ch < MAXC; ++ch)
        if (go[0][ch] != 0) {
            failure[go[0][ch]] = 0;
            Q.push(go[0][ch]);
        }

    while (Q.size()) {
        int state = Q.front();
        Q.pop();

        for (int ch = 0; ch <= MAXC; ++ch)
            if (go[state][ch] != -1) {
                // GOAL: find failure[go[state][ch]]

                // By IH, we already know failure[state]
                int f = failure[state];

                // Inductive step
                // Keep following failure links until go[f] for our ch exists
                while (go[f][ch] == -1)
                    f = failure[f];
                failure[go[state][ch]] = go[f][ch]; // done with GOAL
                // End of inductive step

                Q.push(go[state][ch]);
            }
    }
}

int findNextState(int currentState, char nextInput, int go[][MAXC], int failure[]) {
    int ch = nextInput -'a';

    while (go[currentState][ch] == -1)
        currentState = failure[currentState];

    return go[currentState][ch];
}
