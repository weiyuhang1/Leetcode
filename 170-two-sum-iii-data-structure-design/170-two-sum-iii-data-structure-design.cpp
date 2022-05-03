class TwoSum {
public:
    unordered_multiset<int64_t> nums;
    TwoSum() {
        
    }
    
    void add(int number) {
        nums.insert(number);
        
    }
    
    bool find(int value) {
        for (long i : nums) {
            if (i == value - i) {
                if (nums.count(value - i) > 1)
                    return true;
            } else if (nums.count(value - i) > 0) {
                return true;
            }
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