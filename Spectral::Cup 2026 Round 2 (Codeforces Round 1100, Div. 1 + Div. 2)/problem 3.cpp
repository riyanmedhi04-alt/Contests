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
        map<long long,bool> m;
        for(int i = 0; i<n; i++){
            cin >> v[i];
            if(v[i] < 0){
                m[v[i]] = false;
            }else{
                m[v[i]] = true;
            }
        }
        long long ops = 0;
        vector<long long> ans;
        for(int i = n-1; i>=0; i--){
            if(ops%2 != 0 && m[v[i]] == false){
                ops++;
                ans.push_back(i+1);
                continue;
            }
            if(ops%2 == 0 && m[v[i]] == true){
                ops++;
                ans.push_back(i+1);
            }
        }
        cout << ops << "\n";
        for(long long x : ans){
            cout << x << " ";
        }
        cout << "\n";

    }
    return 0;

}
