#include <vector>
#include <iostream>
using namespace std;
// Find First and Last Position of Element in Sorted Array
//leetcode problem no 34
//problem link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/?utm=codolio
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans = {-1, -1};

        // Find first occurrence
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                ans[0] = mid;
                right = mid - 1; // keep going left
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // Find last occurrence
        left = 0;
        right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                ans[1] = mid;
                left = mid + 1; // keep going right
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> result = solution.searchRange(nums, target);
    cout << "First and Last Position of Target: [" << result[0] << ", " << result[1] << "]" << endl; // Output: [3, 4]
    return 0;
}
