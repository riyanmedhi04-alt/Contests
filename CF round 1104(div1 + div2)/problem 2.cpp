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
        vector<int> a(n), b(n);
        set<int> s;
        for(int i = 0; i<n; i++){
            cin >> a[i];
        }
        for(int i = 0; i<n; i++){
            cin >> b[i];
            s.insert(b[i]);
        }
        int ops = 0;
        bool notValid = false;
        // creating another vector c to store the lower bounds of the values in a -> 
        vector<int> c(n);
        for(int i = 0; i<n; i++){
            auto it = s.lower_bound(a[i]);
            // if lower bound not found then invalid 
            if(it == s.end()){
                notValid = true;
                break;
            }
            // once its found dont forget to erase it from the set as we need unique values in b for each values in a! 
            c[i] = *it;
            s.erase(it);
        }
        if(notValid){
            cout << -1 << "\n";
            continue;
        }
        // just count the no. of pairs for which c[i] > c[j] && j>i
        for(int i = 0; i<n-1; i++){
            for(int j = i+1; j<n; j++){
                if(c[i] > c[j]){
                    ops++;
                }
            }
        }
        cout << ops << "\n";
    }
    return 0;
}
