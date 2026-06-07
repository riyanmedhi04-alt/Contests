class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        long long ans = 0, res = 0;
        set<int> s;
        int req = 0;
        req = (brightness+2)/3;
        sort(intervals.begin(),intervals.end());
        int m = intervals.size();

        int max_a, max_b;
        int sz = 0;
        for(int i = 0; i<m; i++){
            int x = intervals[i][0];
            int y = intervals[i][1];
            if(i == 0){
                max_a = x;
                max_b = y;
                sz = max_b-max_a+1;
                continue;
            }
            if(x <= max_b){
                max_b = max(y,max_b);
                max_a = min(x,max_a);
                sz = max_b-max_a+1;
            }else{
                ans += sz;
                max_a = x;
                max_b = y;
                sz = max_b- max_a+1;
            }
                
        }
        ans += sz;
        res = req*ans;
        return res;
    }
};
