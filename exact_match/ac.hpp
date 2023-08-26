#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <iostream>

#define MAXC 26 // alphabet size -- here, assumed to be {a,b,c,...,z}

void buildAutomaton(const std::vector<std::string>& arr, int go[][MAXC], int output[], int failure[]);
int findNextState(int currentState, char nextInput, int go[][MAXC], int failure[]);
void search(const std::vector<std::string>& patterns, const std::string& text, int go[][MAXC], int output[], int failure[]);
