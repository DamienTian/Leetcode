/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start

//#include "dummyHead.h"

class Solution {
public:
    // Solution 1: merge sort then find the kth largest element
    //  note: implement merge sort here
    // int findKthLargest(vector<int>& nums, int k) {
    //     vector<int> sort = mergeSort(nums, 0, nums.size()-1);
    //     return *(sort.begin() + (k-1));
    // }

    // Solution 2: Quick Sort
    //  ref: https://www.cnblogs.com/grandyang/p/4539757.html
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while(true){
            int pos = partition(nums, left, right);
            if(pos == k - 1)
                return nums[pos];
            if(pos < k - 1)
                left = pos + 1;
            else
                right = pos - 1;
        }
    }

private:
    int partition(vector<int>& nums, int left, int right){
        int pivot = nums[left];
        int l = left + 1;
        int r = right;
        while(l <= r){
            if(pivot > nums[l] && pivot < nums[r])
                swap(nums[l++], nums[r--]);
            if(pivot <= nums[l])
                ++l;
            if(pivot >= nums[r])
                --r;
        }
        swap(nums[left], nums[r]);
        return r;
    }

    vector<int> mergeSort(vector<int>& nums, int start, int end){
        if(start >= end){
            vector<int> single(nums.begin() + start, nums.begin() + start + 1);
            return single;
        }
        int mid = start + (end - start) / 2;
        return merge(mergeSort(nums, start, mid), mergeSort(nums, mid+1, end));
    }

    vector<int> merge(const vector<int>& l1, const vector<int>& l2){
        vector<int> result;
        int i1 = 0, i2 = 0;
        while(i1 < l1.size() && i2 < l2.size()){
            if(l1[i1] > l2[i2])
                result.push_back(l1[i1++]);
            else
                result.push_back(l2[i2++]);
        }
        while(i1 < l1.size()){
            result.push_back(l1[i1++]);
        }
        while(i2 < l2.size()){
            result.push_back(l2[i2++]);
        }
        return result;
    }



};
// @lc code=end

