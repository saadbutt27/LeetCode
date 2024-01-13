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

int findMaxConsecutiveOnes(vector<int>& nums) {
    int maxOnes = 0;
    int count=0;
    for(int i=0; i<nums.size(); ++i) {
        if (nums[i] == 1) {
            count++;
            maxOnes = max(count, maxOnes);
        } else {
            count = 0;
        }
    }
    return maxOnes;
}

vector<int> sortedSquares(vector<int>& nums) {
    // for(int i=0; i<nums.size(); i++) {
    //     nums[i] *= nums[i];
    // }
    // sort(nums.begin(), nums.end());
    vector<int> result(nums.size());
    int l = 0;
    int r = nums.size() - 1;
    for (int i=r; i>=0; i--) {
        if(abs(nums[r] < abs(nums[l]))) {
            result[i] = nums[l] * nums[l++];
        } else {
            result[i] = nums[r] * nums[r--];
        }
    }
    return result;
}

void print(vector<int>& arr) {
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

void duplicateZeros(vector<int>& arr) {
    for(int i=0; i<arr.size(); i++) {
        if(arr[i] == 0) {
            for(int j=arr.size()-2; j>=i; j--) {
                arr[j+1] = arr[j];
                print(arr);
            }
            arr[i++] = 0;
        }
        print(arr);
    }
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int r = m + n - 1;
    int m1 = m-1;
    int n1 = n-1;

    while(m1>=0 && n1>=0) {
        if (nums1[m1] > nums2[n1]) {
            nums1[r] = nums1[m1--];
        } else {
            nums1[r] = nums2[n1--];
        }
        r--;
    }
    while(n1>=0) {
        nums1[r--] = nums2[n1--];
    }
}

int removeElement(vector<int>& nums, int val) {
    int k=nums.size();
    // cout << k << endl;
    // [0,1,2,2,3,0,4,2], val = 2
    for(int i=0; i<k; i++) {
        // cout << nums[i] << endl;
        if (nums[i] == val) {
            // cout << nums[i] << " ";
            for (int j = i+1; j < nums.size(); j++) {
                nums[j-1] = nums[j];
            }
            k--;
            i--;
            // cout << " k = " << k << endl;
        }
    }
    return k;
}

int removeDuplicates(vector<int>& nums) {
    // int k=nums.size();
    // for(int i=1; i<k; i++) {
    //     if (nums[i] == nums[i-1]) {
    //         for (int j = i+1; j < nums.size(); j++) {
    //             nums[j-1] = nums[j];
    //         }
    //         k--;
    //         i--;
    //     }
    // }
    // return k;

    int k=1;
    for(int i=1; i<nums.size(); i++) {
        if (nums[i] != nums[i-1]) {
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}

bool validMountainArray(vector<int>& arr) {
     if(arr.size() < 3) return false;
        int left = 0;
        int right = arr.size()-1;
        while (left < arr.size()) {
            if (arr[left] < arr[left+1]) left++;
            else break;
        }
        while (right > 0) {
            if (arr[right-1] > arr[right]) right--;
            else break;
        }
        cout << left << " " << right << endl;
        if(left == right && left != arr.size()-1 && right != 0) return true;
        return false;
}

vector<int> replaceElements(vector<int>& arr) {
    // for(int i=0; i<arr.size(); i++) {
    //     int max = 0;
    //     for(int j=i+1; j<arr.size(); j++) {
    //         if(max < arr[j]) {
    //             max = arr[j];
    //         }
    //     }
    //     arr[i] = max;
    // } 
    // arr[arr.size()-1] = -1;
    // return arr;
    int max = -1;
    for(int i=arr.size()-1; i>=0; i--) {
        if(arr[i] > max) {
            int temp = max;
            max = arr[i];
            arr[i] = temp;
        } else {
            arr[i] = max;
        }
    }
        return arr;
}

void moveZeroes(vector<int>& nums) {
    // for(int i=0; i<nums.size(); i++) {
    //     if (nums[i] == 0) {
    //         for(int j=i+1 ; j<nums.size(); j++) {
    //             int temp = nums[j-1];
    //             nums[j-1] = nums[j];
    //             nums[j] = temp;
    //         }
    //     }
    // }
    // printArray(nums);
    // if (nums[0] != 0) return;
    // for(int j=1 ; j<nums.size(); j++) {
    //     if (nums[j+1] == 0) {
    //         int temp = nums[j-1];
    //         nums[j-1] = nums[j];
    //         nums[j] = temp;
    //     }
    // }

    // int k=1;
    // for(int i=1; i<nums.size(); i++) {
    //     if (nums[i-1] == 0) {
    //         nums[i-1] = nums[i];
    //         k++;
    //     }
    // }
    int i = 0;
    int j = 0;

    while(i<nums.size() && j<nums.size()) {
        if (nums[i] != 0) i++;
        if (nums[j] == 0) j++;
        if(i<nums.size() && j<nums.size() && i < j) {
            int temp = nums[j];
            nums[j] = nums[i];
            nums[i] = temp; 
        }
        j++;
    }
}

vector<int> sortArrayByParity(vector<int>& nums) {
    int i = 0;
    int j = 0;

    while(i<nums.size() && j<nums.size()) {
        if (nums[j]%2 == 0) {
            int temp = nums[j];
            nums[j] = nums[i];
            nums[i++] = temp; 
        }
        j++;
    }
    return nums;
}

int heightChecker(vector<int>& heights) {
    int total = 0;
    vector<int> expected = heights;
    
    for (int i=1; i<expected.size(); i++) {
        int temp = expected[i];
        int j = i-1;
        while (j >= 0 && expected[j] > temp) {
            expected[j+1] = expected[j];
            j--;
        }
        expected[j+1] = temp;
    }
    
    for(int i=0; i<heights.size(); i++) {
        if (heights[i] != expected[i]) {
            total++;
        }
    }
    
    return total;
}

int thirdMax(vector<int>& nums) {
    long long max1 = LONG_LONG_MIN;
    long long max2 = LONG_LONG_MIN;
    long long max3 = LONG_LONG_MIN;
    bool flag = false;
    cout<<LONG_LONG_MIN<<endl;
    for(int i=0; i<nums.size(); i++) {
        if (max1 == nums[i] || max2 == nums[i] || max3 == nums[i]) continue;
        if(max1 <= nums[i]) {
            max3 = max2;
            max2 = max1;
            max1 = nums[i];
        } else if (max2 <= nums[i]) {
            max3 = max2;
            max2 = nums[i];
        } else if(max3 <= nums[i]) {
            max3 = nums[i];
        }
    }
    return (max3 != LONG_LONG_MIN ? max3 : max1);    
}

bool binarySearch(vector<int>& nums, int key) {
    int start = 0;
    int end = nums.size() - 1;
    int mid;
    while(start <= end) {
        mid = (start+end)/2;
        if (nums[mid] == key) {
            return true;
        } else if (nums[mid] < key) {
            start = mid+1;
        } else if (nums[mid] > key) {
            end = mid-1;
        }
    }
    return false;
}

bool twoWayLinearSearch(vector<int>& nums, int key) {
    int start = 0;
    int end = nums.size() - 1;


    while (start <= end) {
        if (nums[start] == key){
            cout << "Element found on index: " << start << endl;
            return true;
        } else if (nums[end] == key) {
            cout << "Element found on index: " << end << endl;
            return true;
        }
        start++;
        end--;
    }
    cout << "Element not found" << endl;
    return false;
}

void printArrayBool(vector<bool>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        /* code */
        cout << arr[i]<< " ";
    }
    cout << endl;
}

vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<bool> seenElements(nums.size()+1);
    vector<int> missingNums;

    for (auto c: nums)
        seenElements[c] = true;
    printArrayBool(seenElements);

    for (int i=1; i<=nums.size(); i++) {
        if(!seenElements[i])
            missingNums.push_back(i);
    }
    return missingNums;
}
int main()
{
    vector<int> nums1 = {4,3,2,7,8,2,3,1};
    printArray(nums1);
    // cout << twoWayLinearSearch(nums1, 1) << endl;
    vector<int> missing_nums = findDisappearedNumbers(nums1);
    printArray(missing_nums);
    // cout << thirdMax(nums1) << endl;
    // sortArrayByParity(nums1);
    // printArray(nums1);
    // cout << removeElement(nums1, 3) << endl;
    // replaceElements(nums1);
    // moveZeroes(nums1);
    // printArray(nums1);
    // vector<int> nums2 = {};
    // print(nums1);   
    // print(nums2);
    // merge(nums1, 1, nums2, 0);
    // print(nums1);   

    // Declare an integer array of 10 elements.
    // int intArray[10];

    // // The array currently contains 0 elements
    // int length = 0;

    // // Add elements at the first 6 indexes of the Array.
    // for(int i = 0; i < 6; i++) {
    //     intArray[length] = i;
    //     length++;
    // }

    // for (int i = 0; i < length; i++) {
    //     cout << i << " " << intArray[i] << endl;
    // }

    // // Deleting element anywhere from the end but it is just  reducing the count for the new length, when well insert an element at the end it will overwritten to the previous one
    // length--;
    // cout<<endl;
    // for (int i = 0; i < length; i++) {
    //     cout << i << " " << intArray[i] << endl;
    // }
    // cout<<endl;

    // // Deleting element anywhere from the start
    // for (int i = 1; i < length; i++) {
    //     intArray[i-1] = intArray[i];
    // }
    // length--;
    // for (int i = 0; i < length; i++) {
    //     cout << i << " " << intArray[i] << endl;
    // }
    // cout<<endl;

    // // Deleting element anywhere in the array
    // for (int i = 3; i < length; i++) {
    //     intArray[i-1] = intArray[i];
    // }
    // length--;
    // for (int i = 0; i < length; i++) {
    //     cout << i << " " << intArray[i] << endl;
    // }
    // cout<<endl;
    




    // print(nums);
    // cout << endl;
    // duplicateZeros(nums);
    // print(nums);
    // cout << endl;


    return 0;
}