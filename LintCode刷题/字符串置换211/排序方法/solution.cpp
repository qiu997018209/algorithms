class Solution {
public:
    /*
     * @param A: a string
     * @param B: a string
     * @return: a boolean
     */
     //思路:将字符串排序后,判断排序后是否相等
    bool Permutation(string A, string B) {
        // write your code here
        
        if(A.size() != B.size()){
            return false;
        }
        
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        if(A == B){
            return true;
        }
        
        return false;
    }
};

