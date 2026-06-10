#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
int solve(string s, vector<bool> &m){
    int open = 0, pairs = 0;
    for(int i = 0; i<s.size(); i++){
        if(m[i] == true){
            continue;
        }
        if(s[i] == '('){
            open++;
        }else{
            if(open>0){
                open--;
                pairs++;
            }
        }
    }
    return pairs;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> open, close;
        map<int,bool> remove;
        string ans = "";
        // precomputing the index of open and close brackets in the respective vectors->
        for(int i = 0; i<n; i++){
            if(s[i] == '('){
                open.push_back(i);
            }else{
                close.push_back(i);
            }
        }
        // for k we will serach for every possible pair of x&y where x-> the no. of first closing brackets that are going to be removed and y-> no. of y closing brackets from the end.
        int best_pairs = INT_MAX ;// refers to the best suitable pairs for a particular pair of x and y
        int best_x = 0; // to store the x we got for the best pair
        for(int x = 0; x<=k; x++){
            int y = k-x;
            vector<bool> m(n,false) ;// map for storing the indexes of the x opening brackets and y closing brackets
            for(int i = 0; i<x && i<open.size(); i++){
                m[open[i]] = true;
            }
            for(int i = 0; i<y && i<close.size(); i++){
                m[close[close.size() - 1 - i]] = true;
            }
        
            int pairs = solve(s, m); // this functions gives the the pairs for the above computed result
            if(pairs<best_pairs){
                best_pairs = pairs;
                best_x = x;
            }
        }
        // again recompute the best answer constructing the ans string->
        int best_y = k - best_x;
        for(int i = 0; i<best_x && i<open.size(); i++){
            remove[open[i]] = true;
        }
        for(int i = 0; i<best_y && i<close.size(); i++){
            remove[close[close.size() - 1- i]] = true;
        }
        for(int i = 0; i<n; i++){
            if(remove[i] == true){
                ans += '1';
            }else{
                ans += '0';
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
