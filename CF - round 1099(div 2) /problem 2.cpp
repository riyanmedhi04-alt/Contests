#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
// idea is to find the maximum difference between two elements where a[i-1] > a[i].
// if difference is 0 then the array must be sorted .
// then we will check that for every inequality of a[i-1] > a[i], if even aftet adding the maximum difference to a[i] if still it remains a[i] < a[i-1] then NO else YES->

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> a(n);
        long long diff = 0;
        bool flag = true;
        for(int i = 0; i<n; i++){
            cin >> a[i];
            if(i>0 && a[i] < a[i-1]){
                diff = max(diff, a[i-1] -a[i]);
            }
        }
        if(diff == 0){
            cout << "YES" << "\n";
            continue;
        }
        for(int i = 0; i<n ;i++){
            if(i>0 && a[i] < a[i-1]){
                a[i] += diff;
                if(a[i] < a[i-1]){
                    flag = false;
                    break;
                }
            }
        }
        if(flag){
            cout << "YES" << "\n";
        }else{
            cout << "NO" << "\n";
        }
    }
    return 0;

}
