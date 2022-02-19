class Solution {
public:
    string minWindow(string S, string T) {
    string result;
    if(S.empty() || T.empty()){
        return result;
    }
    unordered_map<char, int> map;
    for(int i = 0; i < T.length(); i++){
        map[T[i]]++;
    }
    int minLength = INT_MAX;
    int letterCounter = 0;
    for(int slow = 0, fast = 0; fast < S.length(); fast++){
        char c = S[fast];
        if(map.find(c) != map.end()){
          
            if(map[c] > 0){
                letterCounter++;
            }
            map[c]--;
        }
        if(letterCounter >= T.length()){
            while(map.find(S[slow]) == map.end() || map[S[slow]] < 0){
                if (map.find(S[slow]) == map.end()){
                     slow++;
                }else{
                    map[S[slow]]++;
                    slow++;
                }
            }
            if(fast - slow + 1 < minLength){
                minLength = fast - slow + 1;
                result = S.substr(slow, minLength);
            }
        }
    }
    return result;
}
        

};
    