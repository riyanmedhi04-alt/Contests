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
        string s;
        cin >> s;
        int n = s.size();
        bool flag = true;
        int cnt = 0;
        vector<int> prefix(n+1,0);
        vector<int> sufix(n+1,0);
        for(int i = 0; i<n; i++){
            prefix[i+1] = prefix[i];
            if(s[i] == '2'){
                prefix[i+1]++;
            }
        }
        for(int i = n-1; i>=0; i--){
            sufix[i] = sufix[i+1];
            if(s[i] == '1' || s[i] == '3'){
                sufix[i]++;
            }
        }
        for(int i = 0; i<=n; i++){
            cnt = max(cnt, prefix[i]+sufix[i]);
        }
        
        cout << n-cnt << "\n";
    }
    return 0;

}
