/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 *
 * Category: Geometry(Interval), Greedy
 */

// @lc code=start

// Solution: Greedy
//  ref: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/discuss/1686627/C%2B%2BJavaPython-6-Lines-oror-Sort-and-Greedy-oror-Image-Explanation
bool cmp(vector<int> &a, vector<int> &b) { return a[1] < b[1]; }
class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &segments)
    {
        sort(segments.begin(), segments.end(), cmp);
        int ans = 0, arrow = 0;
        for (int i = 0; i < segments.size(); i++)
        {
            if (ans == 0 || segments[i][0] > arrow)
            {
                ans++;
                arrow = segments[i][1];
            }
        }
        return ans;
    }
};

// class Solution
// {
// public:
//     // Solution: Greedy
//     //  ref: http://zxi.mytechroad.com/blog/geometry/leetcode-452-minimum-number-of-arrows-to-burst-balloons/
//     //  note: This solution will cause Time Exceed Limit, but the algorithm is correct
//     int findMinArrowShots(vector<vector<int>> &points)
//     {
//         if (points.empty())
//         {
//             return 0;
//         }
//         sort(points.begin(), points.end(),
//              [points](const vector<int> &a, const vector<int> &b)
//              {
//                  return a[1] < b[1];
//              });

//         int rightBound = points[0][1];
//         int result = 1;
//         for (const auto &p : points)
//         {
//             if (p[0] > rightBound)
//             {
//                 rightBound = p[1];
//                 ++result;
//             }
//         }

//         return result;
//     }

// };
// @lc code=end
