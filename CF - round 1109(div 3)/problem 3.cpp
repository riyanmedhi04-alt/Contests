#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
// The importance of this question is that the math behind the question i.e
// |i-j| = ax + by and to find if such a number exist for ax + by we use Bezouts identity ->
// a number n = ax + by exists only if n%(gcd(x,y)) == 0!!
int gcd (int a, int b){
    if(b == 0){
        return a;
    }
    return gcd(b, a%b);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> a(n+1);
        for(int i = 1; i<=n; i++){
            cin >> a[i];
        }
        bool valid = true;
        int g = gcd(x,y);
        for(int i = 1; i<n; i++){
            int p = abs(a[i] - i);
            if(p % g != 0){
                valid = false;
                break;
            }
        }
        if(valid){
            cout << "Yes" << "\n";
        }else{
            cout << "No" << "\n";
        }
    }
    return 0;
}
