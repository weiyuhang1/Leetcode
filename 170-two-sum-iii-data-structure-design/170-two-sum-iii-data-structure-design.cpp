class TwoSum {
public:
    vector<int> vect;
    TwoSum() {

        
    }
    
    void add(int number) 
    {
        vect.push_back(number);
        
    }
    
    bool find(int value) {
        sort(vect.begin(), vect.end());
        int l = 0;
        int r = vect.size() - 1;
        while (l < r) {
            if (vect[l] + vect[r] == value) return true;
            if (vect[l] + vect[r] < value) l += 1;
            if (vect[l] + vect[r] > value) r -= 1;
        }
        return false;
        
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */