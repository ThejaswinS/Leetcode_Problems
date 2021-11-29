class SubrectangleQueries {
public:  
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        base = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        vector<int> snap = {row1, col1, row2, col2, newValue};
        snapshots.push_back(snap);
    }
    
    int getValue(int row, int col) {
        int n = snapshots.size();
        for(int i=n-1; i>=0; i--){
            if( row >= snapshots[i][0] && row <= snapshots[i][2] 
                && col >= snapshots[i][1] && col <= snapshots[i][3] ) return snapshots[i][4];
        } return base[row][col];
    }
private:
    vector<vector<int>> snapshots;
    vector<vector<int>> base;
};
