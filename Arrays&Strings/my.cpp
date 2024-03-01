#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

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

template <size_t n, size_t m>
void print2DArray(int (&a)[n][m]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << a[j] << " ";
        }
        cout << endl;
    }
}

vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    // if(mat == NULL || mat.size() == 0)
        //     return new vector<int>[0];

        int n = mat.size();
        int m = mat[0].size();
        vector<int> result;
        vector<int> intermediate;

        for (int i=0; i < n+m-1; i++) {
            intermediate.clear();

            int row = i<m ? 0 : i-m+1;
            int column = i<m ? i : m-1;

            while(row < n && column > -1) {
                intermediate.push_back(mat[row][column]);
                ++row;
                --column;
            }

            if(i%2 == 0) {
                reverse(intermediate.begin(), intermediate.end());
            }

            for(int i=0; i<intermediate.size(); i++) {
                result.push_back(intermediate[i]);
            }
        }

        return result;

}

vector<int> spiralOrder(vector<vector<int>>& mat) {
    int nRows = mat.size();
    int mCols = mat[0].size();
    vector<int> result;
    int l = 0; 
    int r = mCols-1; 
    int t = 0;
    int b = nRows-1; 

    while (l<=r && t<=b) {
        for (int i=l; i<=r; i++) {
            result.push_back(mat[t][i]);
        }
        t++;
        for (int i=t; i<=b; i++) {
            result.push_back(mat[i][r]);
        }
        r--;
        if(t<=b) {
            for (int i=r; i>=l; i--) {
                result.push_back(mat[b][i]);
            }
            b--;
        }
        if(l<=r) {
            for (int i=b; i>=t; i--) {
                result.push_back(mat[i][l]);
            }
            l++;
        }
    }

    return result;    
}

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result;
    vector<int> intermediate = {1};
    result.push_back(intermediate);
    for (int i=0; i<numRows-1; i++) {
        intermediate.clear();
        for (int j=0; j<=i+1; j++) {
            if (j==0 || j==i+1) {
                intermediate.push_back(1);
            } else {
                intermediate.push_back(result[i][j-1] + result[i][j]);
            }
        }
        result.push_back(intermediate);
    }   
    return result; 
}
// 1  2  3  4
// 5  6  7  8
// 9  10 11 12
// 13 14 15 16

string addBinary(string a, string b) {
    string result = "";
    int i = a.size()-1;
    int j = b.size()-1;
    char carry = '0';
    while (i > -1 || j > -1) {
        char aa = (i > -1) ? a[i] : '0';
        char bb = (j > -1) ? b[j] : '0';
        if (aa == '0' && bb == '0') {
            result += (carry == '1') ? '1' : '0';
            carry = '0';
        } else if((aa == '1' && bb == '0') || (aa == '0' && bb == '1')) {
            result += (carry == '1') ? '0' : '1';
        } else {
            result += (carry == '1') ? '1' : '0';
            carry = '1';
        }
        
        --i;
        --j;
    } 
    
    if(carry == '1') {
        result += '1';
    }

    reverse(result.begin(), result.end());
    return result;
}

int strStr(string haystack, string needle) {
    int index = -1;
    for (int i=0; i<haystack.size(); i++) {
        if(needle[0] == haystack[i]) {
            index = i;
            int k = i;
            for (int j=0; j<needle.size(); j++) {
                if(needle[j] == haystack[k]) {
                    k++;
                } else {
                    index = -1;
                    break;
                }
            }
            cout << "needle: " << needle << " found in a haystack: " << haystack << " at index: " << index << endl;
            if (index != -1)
                break;
        }
    }
    return index;
}

string longestCommonPrefix(vector<string>& strs) {
    if(strs.size() == 1){
        return strs[0];
    }
    string prefix = "";
    for (int i=0; i<strs[0].size(); i++) {
        char c = strs[0][i];
        bool flag = false;
        for (int j=1; j<strs.size(); j++) {
            if(c == strs[j][i]) {
                flag = true;
            } else {
                flag = false;
                break;
            }
        }
        if(flag)   
            prefix += c;
        else
            break;
    }
    return prefix; 
}

void reverseString(vector<char>& s) {
    int i = 0;
    int j = s.size() - 1;
    while (i < j) {
        s[i] = s[i] + s[j];
        s[j] = s[i] - s[j];
        s[i] = s[i] - s[j];
        
        i++;
        j--;
    }
}

vector<int> bubbleSort(vector<int>& nums) {
    vector<int> result = nums;
    for (int i=0; i< result.size(); i++) {
        for (int j=i+1; j<result.size(); j++) {
            if(result[i] > result[j]) {
                result[i] = result[i] + result[j];
                result[j] = result[i] - result[j];
                result[i] = result[i] - result[j];
            }
        } 
    }
    return result;

}

int arrayPairSum(vector<int>& nums) {
    int maximizedSum = 0;
    // vector<int> arr = bubbleSort(nums);
    sort(nums.begin(), nums.end());

    for (int i=0; i<nums.size(); i += 2) {
        maximizedSum += nums[i];
    }

    return maximizedSum;        
}

vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> result;
    for (int i=0; i<numbers.size(); i++) {
        for (int j=i+1; j<numbers.size(); j++) {
            if(numbers[i] + numbers[j] == target) {
                result.push_back(i);
                result.push_back(j);
                break;
            }
        }
    }
    return result;
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

int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    vector<int> sums(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        sums[i] = sums[i - 1] + nums[i - 1];
    }

    int minLength = n + 1;
    printArray(sums);
    for (int i = 0; i < n; ++i) {
        int right = lower_bound(sums.begin() + i, sums.end(), target + sums[i]) - sums.begin();
        // cout << "right " << right << endl;
        if (right != n + 1) {
            minLength = min(minLength, right - i);
        }
        // cout << "minLength " << minLength << endl;
    }

    return minLength == n + 1 ? 0 : minLength;
}

void rotate(vector<int>& nums, int k) {
    k %= nums.size();
    if (k<0)
        k += nums.size();
        
    int i = 0;
    int j = nums.size() - k - 1;
    while (i < j) {
        nums[i] = nums[i] + nums[j];
        nums[j] = nums[i] - nums[j];
        nums[i] = nums[i] - nums[j];
        
        i++;
        j--;
    }
    i = nums.size() - k;
    j = nums.size() - 1;
    while (i < j) {
        nums[i] = nums[i] + nums[j];
        nums[j] = nums[i] - nums[j];
        nums[i] = nums[i] - nums[j];
        
        i++;
        j--;
    }      
    i = 0;
    j = nums.size() - 1;
    while (i < j) {
        nums[i] = nums[i] + nums[j];
        nums[j] = nums[i] - nums[j];
        nums[i] = nums[i] - nums[j];
        
        i++;
        j--;
    }      
}

vector<int> getRow(int rowIndex) {
    vector<int> result(rowIndex + 1, 0);
    result[0] = 1;
    for (int i = 1; i <= rowIndex; ++i) {
        for (int j = i; j > 0; --j) {
            result[j] += result[j - 1];
        }
        // printArray(result);
    }
    return result;
}

string reverseWords(string s) {
    string word; 
    vector<string> words;
    for (int i=0; i<s.size(); i++) {
        if(s[i] == ' ' && !word.empty()) {
            words.push_back(word);
            word.clear();
            continue;
        }
        if(s[i] == ' ') {
            continue;
        }
        word += s[i];
    }
    if(!word.empty()) {
        words.push_back(word);
        word.clear();
    }
    s.clear();
    for (int i = words.size() - 1; i >= 0; --i) {
        s += words[i];
        if (i > 0) {
            s += " ";
        }
    }
    return s;
}

string reverseWords3(string s) {
    int lastIndex = -1;
    for (int startIndex=0; startIndex < s.size(); ++startIndex) {
        int j=startIndex+1;
        while (s[j] != ' ' && j != s.size()) {
            j++;
        }
        lastIndex = j-1;

        while (startIndex < lastIndex) {
            s[startIndex] = s[startIndex] + s[lastIndex];
            s[lastIndex] = s[startIndex] - s[lastIndex];
            s[startIndex] = s[startIndex] - s[lastIndex];
            
            startIndex++;
            lastIndex--;
        }

        startIndex = j;
    }
    return s;
} 

void moveZeroes(vector<int>& nums) {
    int i = 0;
    int j = 0;

    while(i<nums.size() && j<nums.size()) {
        if (nums[i] != 0) i++;
        if(nums[j] == 0) j++;
        if((i<nums.size() && j<nums.size()) && i < j) {
            nums[i] = nums[i] + nums[j];
            nums[j] = nums[i] - nums[j];
            nums[i] = nums[i] - nums[j];
        }
        j++;
    }
}

int main() {
    string s = "Let's take LeetCode contest";
    cout << s << endl;
    cout << reverseWords3(s) << endl;
    // vector<int> res = getRow(3);
    // printArray(res);
    // vector<int> arr = {1,2,3};
    // printArray(arr);
    // rotate(arr, 4);
    // printArray(arr);

    // cout << minSubArrayLen(15, arr) << endl;
    // vector<int> arr = {{3,3}};
    // vector<int> res = twoSum(arr, 6);
    // for(int i=0; i<res.size(); i++) {
    //     cout << res[i] << " ";
    // }
    // cout << arrayPairSum(arr) << endl;
    // vector<char> s = {'s', 'a', 'a', 'd'};
    // for(int i=0; i<s.size(); i++) {
    //     cout << s[i] << " ";
    // }
    // cout << endl;
    // reverseString(s);
    // for(int i=0; i<s.size(); i++) {
    //     cout << s[i] << " ";
    // }


    // vector<string> strs= {"flower", "flow", "flight"};
    // cout << longestCommonPrefix(strs) << endl;


    // string haystack = "leetcode";
    // string needle = "leeto";

    // cout << strStr(haystack, needle) << endl;

    // string a = "1010";
    // string b = "1011";
    // cout << addBinary(a, b) << endl;

    // vector<vector<int>> mat = {{2,5,8},{4,0,-1}};
    // vector<vector<int>> res = generate(5);

    // for(int i=0; i<res.size(); i++) {
    //     // cout << res[i] << " ";
    //     for(int j=0; j<res[i].size(); j++) {
    //         cout << res[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // for(int i=0; i<res.size(); i++) {
    //     cout << res[i] << " ";
    // }

    // cout << "Example I:" << endl;
    // int a[2][5] = {};
    // print2DArray(a);
    // cout << "Example II:" << endl;
    // int b[2][5] = {{1, 2, 3}};
    // print2DArray(b);
    // cout << "Example III:"<< endl;
    // int c[][5] = {1, 2, 3, 4, 5, 6, 7};
    // print2DArray(c);
    // cout << "Example IV:" << endl;
    // int d[][5] = {{1, 2, 3, 4}, {5, 6}, {7}};
    // print2DArray(d);
    // cout << "Element: " << *a[3*5+1]<< endl;
    // vector<int> nums = {4,3,9,9};
    // printArray(nums);
    // plusOne(nums);
    // printArray(nums);
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