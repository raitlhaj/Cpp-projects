// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> v;
        map<int,int> mapp;
        map<int,int>::iterator it;
        int i=0,k=1;
        bool find=false;
        
       //O(n^2)
       /*   
        for(int i=0;i<nums.size();i++)
        for(int k=i+1;k<nums.size();k++)
        {
            if(nums[i]+nums[k]==target)
            { 
                v.push_back(i);  
                v.push_back(k); 
                return v;;
            }
        } */     
        
        //O(n) 
         for(int k=0;k<nums.size();k++)
        {
           it= mapp.find(target-nums[k]);
             cout<<it.ge;
           if(it!=mapp.end())
           {
                v.push_back(mapp.at(k));  
                v.push_back(k); 
                return v; 
           }
           else { mapp.insert(std::pair<int,int>(k,nums[k]));}   
        }        
       return v; 
    }
};
int main() {
    // Write C++ code here
    Solution s;
    vector<int> T{2,7,11,15};
   
    std::cout <<(s.twoSum(T,9))[0];

    return 0;
}