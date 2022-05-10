class Solution {
public:
    vector<string> generatePossibleNextMoves(string currentState) {
        vector<string> result;
        for (int i = 0; i < currentState.length(); i++) {
            if (currentState[i] == '+' && i + 1 < currentState.length() && currentState[i + 1] == '+')
                result.push_back(currentState.substr(0, i) + "--" + currentState.substr(i+2));
        }
        return result;
    }
};