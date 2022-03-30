/*
 * @lc app=leetcode id=304 lang=cpp
 *
 * [304] Range Sum Query 2D - Immutable
 */

// @lc code=start

// Solution: DP
//  ref: http://zxi.mytechroad.com/blog/dynamic-programming/leetcode-304-range-sum-query-2d-immutable/
class NumMatrix
{
public:
    NumMatrix(const vector<vector<int>> &matrix)
    {
        sums_.clear();

        if (matrix.empty())
            return;

        int m = matrix.size();
        int n = matrix[0].size();

        // sums_[i][j] = sum(matrix[0][0] ~ matrix[i-1][j-1])
        sums_ = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
                sums_[i][j] = matrix[i - 1][j - 1] + sums_[i - 1][j] + sums_[i][j - 1] - sums_[i - 1][j - 1];
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return sums_[row2 + 1][col2 + 1] - sums_[row2 + 1][col1] - sums_[row1][col2 + 1] + sums_[row1][col1];
    }

private:
    vector<vector<int>> sums_;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end
