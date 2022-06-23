class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), comp);
        int sum = 0;
        priority_queue<int> pq;
        for (auto& course : courses) {
            sum += course[0];
            if (sum <= course[1]) {
                pq.push(course[0]);
                continue;
            } else {
                pq.push(course[0]);
                sum -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
        
    
        
        
        
        
    }

        static bool comp(vector<int>& vect1, vector<int>& vect2) {
            return vect1[1] < vect2[1];
        }

    
    
};