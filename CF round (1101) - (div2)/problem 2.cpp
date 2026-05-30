#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> v(n);
        // we set a curr variable to inf->
        long long curr = INT_MAX;
        vector<long long> ans(n);
        // initializing the prefix sum->
        long long pref = 0;
        for(int i = 0; i<n; i++){
            cin >> v[i];
            pref += v[i];
            // at every position the height (maximum) required will be the min of (prefix/i+1) {trying to level them all} && the curr possible maximum height till now ->
            curr = min(curr, pref/(i+1));
            ans[i] = curr;
        }
        for(int i = 0; i<n ; i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;

}
