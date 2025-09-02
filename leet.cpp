#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        if(nums1.size() > nums2.size()) swap(nums1, nums2);
        int left = 0, right = nums1.size();
        int firstHalf = total >> 1;
        while(left < right){
            int takenFromnum1 = (left + right) >> 1;
            int takenFromnum2 = firstHalf - takenFromnum1;
             
        }
    }
};