class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (!matrix.size() || !matrix[0].size()) return 0;
        long result = INT_MIN;
        for (int m = 0; m < matrix[0].size(); ++m) {
            vector<int> dpsum(matrix.size(), 0);
            for (int i = m; i < matrix[0].size(); ++i) {
                int sum = 0;
                set<int> sumset; sumset.insert(0);
                for (int j = 0; j < matrix.size(); ++j) {
                    dpsum[j] += matrix[j][i];
                    sum += dpsum[j];
                    auto iter = sumset.lower_bound(sum - k);
                    if (iter != sumset.end() && k-(sum-*iter) < k-result) {
                        result = sum-*iter;
                    }
                    sumset.insert(sum);
                }
            }
        }
        return result;
    }
};