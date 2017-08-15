class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //优化枚举，时间复杂度为O(n*n)  
        int size = nums.size();
        int max = -2147483648;
        for(int i = 0;i<size;i++){
            int sum = 0;
            for(int j = i;j<size;j++){
                //求子数字和
                sum += nums[j];
                if(sum>max){
                    max=sum;
                }
                
            }
            
        }
        return max;
    }
};