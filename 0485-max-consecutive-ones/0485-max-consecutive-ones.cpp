class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxcount = 0;
//loop chl rha hai and 1s ko count kr rha hai
        for(int num :nums){
            if(num==1){
                count++;
                maxcount = max(maxcount , count);
            } //agr 1 nhi mila to fir count ko 0 krdo
            else{
                count = 0;
            }
        }
        return maxcount;
    }
};