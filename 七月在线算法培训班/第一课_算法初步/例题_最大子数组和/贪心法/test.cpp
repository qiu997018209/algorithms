class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //贪心法，时间复杂度为O(n)  
        int n = nums.size();
        int max = -2147483648;
        int sum = 0;        
        for(int i = 0;i<n;i++){
            sum += nums[i];
            if(sum>max){
                max = sum;
            }
            //当发现这一段子数组小于0的时候就舍弃掉，因为任何数字加上一个负数只会变的更小
            if(sum<0){
                sum = 0;
            }  
        }
        return max;
};