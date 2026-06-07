class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        long long ans = 0;
        int n = nums.size();
        if(n == 1){
            if(s[0] == '1'){
                return nums[0];
            }else{
                return 0;
            }
        }
        int start = -1;
        int end = -1;
        bool flag = false;
        for(int i = 1; i<n; i++){
            if((s[i] == '1' && s[i-1] == '0') && nums[i-1] > nums[i]){
                s[i-1] = '1';
                s[i] = '0';
            }
            if(s[i] == '1' && flag == true){
                if(nums[start-1] > nums[i] && s[start-1] == '0'){
                    s[start-1] = '1';
                    s[i] = '0';
                    flag = false;
                }
            }
            if(s[i] == '1' && flag == false){
                start = i;
                flag = true;
                continue;
            }

            if(flag && s[i] == '0'){
                end = i-1;
                if((nums[start-1] >= nums[end]) && s[start-1] == '0'){
                    s[start-1] = '1';
                    s[end] = '0';
                }
                flag = false;
            }
        }
        if(flag){
            end = n-1;
            if((nums[start-1] >= nums[end]) && s[start-1] == '0'){
                s[start-1] = '1';
                s[end] = '0';
            }
        }
        for(int i = 0; i<n; i++){
            if(s[i] == '1'){
                ans += nums[i];
            }
        }
        return ans;
    }
};
