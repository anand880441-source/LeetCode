class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> arr;

        for (int i = 0; i < operations.size(); i++) {

            if (operations[i] == "C") {
                arr.pop_back();
            } else if (operations[i] == "D") {
                arr.push_back(arr.back() * 2);
            } else if (operations[i] == "+") {
                int n = arr.size();
                arr.push_back(arr[n - 1] + arr[n - 2]);
            } else {
                arr.push_back(stoi(operations[i]));
            }
        }

        int sum = 0;
        for(int i = 0; i<arr.size(); i++){
            sum += arr[i];
        }
        return sum;
        
    }
};