class Solution {
public:
    vector<int>getleftMax(vector<int>&height , int n){
        vector<int>leftMax;
        int currentMax = height[0];
        for(int i = 0; i<n; i++){
            currentMax = max(currentMax , height[i]);
            leftMax.push_back(currentMax);
        }
        return leftMax;
    }
    vector<int>getrightMax(vector<int>&height, int n){
        vector<int>rightMax(n);
        int currentMax = height[n-1];
        for(int i =n-1; i>=0; i--){
            currentMax = max(currentMax , height[i]);
            rightMax[i]=currentMax;

        }
        return rightMax;

    }
    int trap(vector<int>& height) {
        int n = height.size();
        if(n==0|| n==1) return 0;
        int sum = 0;
        vector<int>leftMax = getleftMax(height, n);
        vector<int>rightMax = getrightMax(height, n);
        for(int i=0; i<n; i++){
            sum+=min(leftMax[i],rightMax[i])-height[i];
        }
        return sum;
    }
};