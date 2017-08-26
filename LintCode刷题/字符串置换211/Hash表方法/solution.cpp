class Solution {
public:
    /*
     * @param A: a string
     * @param B: a string
     * @return: a boolean
     */
     //思路:将字符串中的每一个值映射到hash表中,统计出现次数，然后比较是否相等
    bool Permutation(string A, string B) {
        // write your code here
        //Hash表：ASCII码一共128个字符
        int TempA[127] = {0};
        int TempB[127] = {0};
        
        if(A.size() != B.size()){
            return false;
        }
        
        //统计计数
        for(int i = 0 ;i<A.size();i++){
            //将本字符的ASCII码与空格的ASCII码相减,得到Hash的key
            TempA[A.at(i)]++;
            TempB[B.at(i)]++;
        }
        
        //比较是否相等
        for(int i = 0 ;i<A.size();i++){
            if(TempA[i] != TempB[i]){
                return false;
            }
            
        }
        return true;
    }
};

