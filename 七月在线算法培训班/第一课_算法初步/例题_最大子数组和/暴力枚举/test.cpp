class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //暴力枚举，时间复杂度为O(n*n*n)  
        int size = nums.size();
        int max = -2147483648;
        for(int i = 0;i<size;i++){
            for(int j = i;j<size;j++){
                int sum = 0;
                //求子数字和
                for(int k = i;k<=j;k++){
                    sum += nums[k];
                }
                if(sum>max){
                    max=sum;
                }
                
            }
            
        }
        return max;
    }
};