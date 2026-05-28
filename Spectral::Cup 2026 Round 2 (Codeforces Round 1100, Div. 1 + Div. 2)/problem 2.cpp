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
        vector<long long> a(n);
        vector<long long> b(n);
        for(int i = 0; i<n; i++){
            cin >> a[i];
        }
        long long sum = 0;
        long long need  = 0;
        for(int i = 0; i<n; i++){
            cin >> b[i];
        }
        for(int i = 0; i<n; i++){
            sum += max(a[i] , b[i]);
            need = max(need, min(a[i],b[i]));
        }

        cout << sum + need << "\n";
    }
    return 0;

}
