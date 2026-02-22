#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int start = 0;
        int end = nums.size() - 1;
        
        while(start <= end){
            
            int mid = start + (end - start) / 2;
            
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        
        return -1;
    }
};
int main() {
    Solution solution;
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 9;
    int result = solution.search(nums, target);
    cout << "Index of target: " << result << endl; // Output: Index of target: 4
    return 0;
}