
#include <iostream>
#include <vector>
#include <map>
#include<string>

class Solution {
public:
    bool isPalindrome(int x) {
        //by converting to string
        
        /*std::string str=std::to_string(x);
        int l=str.size();
        
        for( int i=0;i<l;i++)
        {
            if(str[i]!=str[l-i-1])
            return false;
        } */
       
       int tmp=x;
       int reversedNum=0;
       int lastDigit=tmp%10;
       
       while( tmp>0){
       lastDigit=tmp%10;
       reversedNum=reversedNum*10+lastDigit;
       tmp=tmp/10;
       }
    
     if(reversedNum==x) return true;
     else return false;
    }
};

int main()
{
    Solution s;
    std::cout<<s.isPalindrome(34522543);
    return 0;

}