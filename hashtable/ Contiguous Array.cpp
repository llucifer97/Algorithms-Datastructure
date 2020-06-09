https://www.geeksforgeeks.org/largest-subarray-with-equal-number-of-0s-and-1s/
class Solution{
public:
    int findMaxLength(vector<int>& nums) {
            int sum=0, longestContArray = 0;;
            unordered_map<int,int> m;
            for(int i=0;i<nums.size();i++){
                if(nums[i]==0){
                     sum += -1;     
                }else{
                     sum += 1;
                }
              
                if(sum == 0)
                    longestContArray = max(i+1,longestContArray);
                else if(m.find(sum) != m.end())
                    longestContArray = max(i-m[sum],longestContArray);
                else
                    m[sum] = i;
            }
            return longestContArray;
        }
};
