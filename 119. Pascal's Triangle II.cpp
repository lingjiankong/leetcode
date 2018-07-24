class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res (1, 1);
        for (int i = 0; i < rowIndex; ++i) {
            // this trick is important, assign res[j] = res[j-1] + res[j] from end to beginning. This way we don't need to create a temp variable for res[j] as if we were doing the operation from beginning to end
            for (int j = i; j > 0; --j) {
                res[j] = res[j-1] + res[j];
            }
            res.push_back(1);
        }
        return res;
    }
};
