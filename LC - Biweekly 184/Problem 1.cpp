class Solution {
public:
    bool consecutiveSetBits(int n) {
        int cnt = 0;
        for(int bit = 1; bit<32; bit++){
            if((n&(1<<bit)) != 0 && (n&(1<<(bit-1))) != 0){
                cnt++;
            }
        }
        if(cnt != 1){
            return false;
        }
        return true;
    }
};
