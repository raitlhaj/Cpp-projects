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
            
           if(it!=mapp.end())
           {
                v.push_back(it->second);  
                v.push_back(k); 
                return v; 
           }
           else { 
               mapp.insert(std::pair<int,int>(nums[k],k));}   
        }        
       return v; 
    }
};
int main() {
    // Write C++ code here
    Solution s;
    vector<int> T{15,7,11,2};
   
    std::cout <<"("<<(s.twoSum(T,9))[0]<<";"<<(s.twoSum(T,9))[1]<<")";

    return 0;
}