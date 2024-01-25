#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void printArray(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        /* code */
        cout << arr[i]<< " ";
    }
    cout << endl;
}

int pivotIndex(vector<int>& nums) {
    int n = nums.size();
    
    for (int i=0; i<n; i++) {
        int leftSum = 0;
        int sum = 0;

        for (int i=0; i<nums.size(); i++) {
            sum += nums[i];
        }

        for (int i=0; i<nums.size(); i++) {
            sum -= nums[i];
            if(sum == leftSum) {
                return i;
            }
            leftSum += nums[i]; 
        }

        return -1;

        // int n = nums.size();
        
        // for (int i=0; i<n; i++) {
        //     int l = 0;
        //     int r = 0;
        //     for (int j=i-1; j>=0; j--) {
        //         l += nums[j];
        //     }
        //     for (int j=i+1; j<n; j++) {
        //         r += nums[j];
        //     }
        //     if(l == r) {
        //         return i;
        //     }
        // }
        
        // return -1;
    }

    return -1;
}

int dominantIndex(vector<int>& nums) {
        int max = 0;
        int maxIndex = -1;
        for(int i=0; i<nums.size(); i++) {
            if(max < nums[i]) {
                max = nums[i];
                maxIndex = i;
            }
        }
        for(int i=0; i<nums.size(); i++) {
            if (i == maxIndex) continue;
            if(nums[i]*2 > max) return -1;
        }
        
        return maxIndex;
    }

vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    if(digits[n-1] < 9) {
        digits[n-1]++;
        return digits;
    }
    for(int i=n-1; i>=0; i--) {
        if(digits[i] < 9) {
            digits[i]++;
            break;
        }
        else {
            digits[i] = 0;
            if(i == 0) {
                digits.insert(digits.begin(), 1);
                break;
            }
        }
    }
    return digits; 
}

int main() {
    vector<int> nums = {4,3,9,9};
    printArray(nums);
    plusOne(nums);
    printArray(nums);
    // cout << dominantIndex(nums) << endl;
    // int b = nums.begin();
    // cout << "begin: " <<b << endl;
    // printArray(nums);
    // int pivot = pivotIndex(nums);
    // cout << "pivot index is "  << pivot << endl;
    // if(pivot != -1)
    //     cout << "element at pivot index is " << nums[pivot]  << endl;

    return 0;
}