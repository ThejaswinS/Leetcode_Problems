class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int answer = 0;
        unordered_set<int> prefixes;
        for (int i = 31; i >=0; --i) {
            answer <<= 1;
            for (auto num : nums) prefixes.insert(num >> i);
            for (auto prefix : prefixes) {
                if (prefixes.count(answer ^ 1 ^ prefix)) {
                    ++answer;
                    break;
                }
            }
            prefixes.clear();
        }
        return answer;
    }
};