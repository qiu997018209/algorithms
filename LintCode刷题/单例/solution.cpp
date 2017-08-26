class Solution {
public:
    /**
     * @return: The same instance of this class every time
     */
    static Solution* getInstance() {
        // write your code here
        if(pInstance == NULL){
            pInstance = new Solution();
        }
        return pInstance;
    }
    private:
        static Solution*pInstance;
};

Solution* Solution::pInstance = NULL;

