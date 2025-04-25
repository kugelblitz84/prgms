#include <iostream>
#include <vector>

using namespace std;

void backtrack(int index, vector<int>& nums, vector<int>& subset, vector<vector<int>>& result) {
    if (index == nums.size()) {
        result.push_back(subset);
        return;
    }
    
   
    

    // Include the current element
    subset.push_back(nums[index]);
    backtrack(index + 1, nums, subset, result);

    // Exclude the current element
    subset.pop_back();
    backtrack(index + 1, nums, subset, result);
}

vector<vector<int>> generateSubsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> subset;
    backtrack(0, nums, subset, result);
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> subsets = generateSubsets(nums);

    cout << "All subsets:\n";
    for (auto& subset : subsets) {
        cout << "{ ";
        for (int num : subset) cout << num << " ";
        cout << "}\n";
    }
    return 0;
}
