class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int , int> freq;

        for(int num : nums){
            freq[num]++;

            if(freq[num] == 2){
                freq.erase(num);
            }
        }

        return freq.begin()->first;
    }
};