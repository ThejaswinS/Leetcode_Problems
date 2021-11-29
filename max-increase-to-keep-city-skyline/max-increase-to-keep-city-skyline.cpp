class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
    vector<int> vertical(grid.front().size(), 0);
    vector<int> horizontal(grid.size(), 0);

    for (int i=0; i<grid.size(); i++) {
        for (int j=0; j<grid[i].size(); j++) {
            horizontal[i] = max(horizontal[i], grid[i][j]);
            vertical[j] = max(vertical[j], grid[i][j]);
        }
    }

    int ans = 0;
    for (int i=0; i<grid.size(); i++) {
        for (int j=0; j<grid[i].size(); j++) {
            ans += min(horizontal[i], vertical[j]) - grid[i][j];
        }
    }
    return ans;
}
};