class Solution {
public:
    bool isPalindrome(int x) {
        long long org = x;
        int num = 0;
        long long rev = 0;
        if(x<0){
            return false;
        }else {
        while(x!=0){
            num = x%10;
            rev = (rev*10) + num;
            x = x/10;
        }
        if(org==rev){
            return true;
        }else{
            return false;
        }
        }  
    }
};