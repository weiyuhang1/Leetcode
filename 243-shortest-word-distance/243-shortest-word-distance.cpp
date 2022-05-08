class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int loc1 = -1 - wordsDict.size();
        int loc2 = -1 - wordsDict.size();
        int distance = INT_MAX;
        for (int i = 0; i < wordsDict.size(); i++) {
            if (wordsDict[i] == word1) loc1 = i;
            if (wordsDict[i] == word2) loc2 = i;
            if (wordsDict[i] == word1 || wordsDict[i] == word2)
                distance = min(distance, abs(loc2 - loc1));
        }
        return distance;
        
    }
};