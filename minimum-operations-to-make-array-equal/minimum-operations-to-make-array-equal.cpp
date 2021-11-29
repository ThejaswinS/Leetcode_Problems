class Solution {
public:
    int minOperations(int n) {
        int ans=0,it=1;
        while(it<=n){
            ans+=(n-it);
            it+=2;
        }
        return ans;
    }
};