class Solution {
private:
    void print(vector<vector<int>>& vv){
        cout << "[" ;
        for(int i = 0; i < vv.size()-1; i++) {
            cout << "[" <<vv[i][0] << "," << vv[i][1] << "],";
        }
        int i = vv.size()  - 1;
        cout << "[" << vv[i][0] << "," << vv[i][1] << "]]" << endl;
    }

public:
    int getMaxHeight(vector<int>& left, vector<int>& right) {

        int width = right[0] - left[0];
        int height_delta = abs(right[1] - left[1]);
        int min_height = min (left[1], right[1]);

        //if the `width` is enough to have `height_delta`
        if (width >= height_delta) return min_height + (width + height_delta) / 2;

        // if the `width` is not enought have `height_delta`
        // then, the `width` is the max height we can make
        int max_height =  min_height + width;

        // if the restriction is higher then make it to right limitation.
        left[1] = min (left[1], max_height);
        right[1] = min (right[1], max_height);

        return max_height;
    }

    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1,0});
        restrictions.push_back({n, n-1});
        sort(restrictions.begin(), restrictions.end());

        //print(restrictions);

        for(int i=0; i<restrictions.size()-1; i++){
            int height = getMaxHeight(restrictions[i], restrictions[i+1]);
            //cout << "[" << restrictions[i][0] << "," << restrictions[i][1]<< "] - "
            //     << "[" << restrictions[i+1][0] << "," << restrictions[i+1][1]<< "] = "
            //     << height << endl;
        }
        cout << endl;
        int maxHeight = 0;
        for(int i= restrictions.size()-1; i>0; i--){
            int height = getMaxHeight(restrictions[i-1], restrictions[i]);
            //cout << "[" << restrictions[i-1][0] << "," << restrictions[i-1][1]<< "] - "
            //     << "[" << restrictions[i][0] << "," << restrictions[i][1]<< "] = "
            //     << height << endl;
            maxHeight = max(maxHeight, height);

        }
        // cout << endl;
        return maxHeight;
    }
};