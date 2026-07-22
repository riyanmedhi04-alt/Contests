#include <vector>
using namespace std;
void solve(vector<int> &nums, int target, vector<vector<int>> &ans, long long sum, int i, vector<int> v){
    if(sum == target){
        ans.push_back(v);
        return;
    }
    if(i == nums.size()){
        return;
    }
    if(nums[i] + sum <= target){
        v.push_back(nums[i]);
        solve(nums, target, ans, sum+nums[i], i+1,v);
        v.pop_back();
    }
    // for avoiding duplicates we first sorted the main nums array then skipped the duplicates nums[i] this way->
    while(i+1 < nums.size() && nums[i] == nums[i+1]){
        i++;
    }
    solve(nums, target, ans, sum, i+1,v);
    
}
vector<vector<int>> combinationSumTarget(vector<int>& nums, int target) {
    // Write your code here
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    vector<int> v;
    solve(nums, target, ans, 0, 0, v);
    return ans;
}
