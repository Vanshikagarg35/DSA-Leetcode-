class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> result;
        int start = 0;
        int end = arr.size() - 1;
        
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(arr[mid] < x) start = mid + 1;
            else end = mid - 1;
        }
        
        int i = start - 1;
        int j = start;
        int count = 0;

        while(count < k) {
            if (i < 0) {
                result.push_back(arr[j]);
                j++;
            } 
            else if (j >= arr.size()) {
                result.push_back(arr[i]);
                i--;
            } 
           
            else {
                if (x - arr[i] <= arr[j] - x) {
                    result.push_back(arr[i]);
                    i--;
                } else {
                    result.push_back(arr[j]);
                    j++;
                }
            }
            count++;
        }
        
        sort(result.begin(), result.end());
        return result;
    }
};