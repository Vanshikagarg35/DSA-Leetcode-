class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>result;
        set<int>st;
        st.insert(nums.begin(),nums.end());
        for(int i =1; i<=nums.size();i++){
            if(st.find(i)==st.end()) result.push_back(i);
        }
        return result;
    }
};