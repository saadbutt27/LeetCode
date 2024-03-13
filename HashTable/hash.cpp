#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

class MyHashSet1 {
    public:
        vector<int> set;

        MyHashSet1() {}

        void add(int keyToAdd) {
            if (contains(keyToAdd))
                return;
            
            set.push_back(keyToAdd);
        } 

        bool contains(int keyToFind) {
            for (int i=0; i<set.size(); ++i) {
                if(keyToFind == set[i]) {
                    return true;
                }
            }
            return false;
        }

        void remove(int keyToRemove) {
            if (!contains(keyToRemove)){
                cout << "The key: " << keyToRemove << " is not present in the hash set.";
                return;
            }
            int i;
            for (i=0; i<set.size(); ++i) {
                if(keyToRemove == set[i]) {
                    break;
                }
            }
            for (int j=i+1; j<set.size(); ++j) {
                set[j-1] = set[j];      
            }
            
        }

};

class MyHashSet2 {
public:
    vector<bool> set;
    MyHashSet2() {
        set = vector<bool>(1e6+1, false);
    }
    
    void add(int key) {
        set[key] = true;
    }
    
    void remove(int key) {
        set[key] = false;
    }
    
    bool contains(int key) {
        return set[key]; 
    }
};

// class MyHashMap {
// public:
//     MyHashMap() {
        
//     }
    
//     void put(int key, int value) {
        
//     }
    
//     int get(int key) {
        
//     }
    
//     void remove(int key) {
        
//     }
// };

class HashSet {
    public:
        bool containsDuplicate(vector<int>& nums) {
            // Replace Type with actual type of your key
            unordered_set<int> hashset;
            for (int key : nums) {
                if (hashset.count(key) > 0) {
                    return true;
                }
                hashset.insert(key);
            }
            return false;
        }

        int singleNumber(vector<int>& nums) {
            unordered_map<int, int> hashmap;
            for (int key : nums) {
                if (hashmap.count(key) > 0) {
                    hashmap[key] = 0;
                } else {
                    hashmap[key] = 1;
                }
            }
            for (auto k : hashmap) {
                if(k.second == 1)
                    return k.first;
            }
            return -1;
        }

        vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
            vector<int> intersection;

            unordered_set<int> hashset1;
            unordered_set<int> hashset2;

            for (int key : nums1) {
                if (hashset1.count(key) > 0) {
                    continue;
                }
                hashset1.insert(key);
            }
            for (int key : nums2) {
                if (hashset2.count(key) > 0) {
                    continue;
                }
                hashset2.insert(key);
            }
            for (int key : hashset1) {
                if (hashset2.count(key) > 0) {
                    intersection.push_back(key);
                }
            }

            return intersection;
        }

        bool isHappy(int n) {
            unordered_set<int> hashset;
            while(true) {
                int sum = 0;
                while(n != 0) {
                    sum += (n % 10) * (n % 10);
                    n = n / 10;
                }
                if (hashset.count(sum) > 0) {
                    // only cycled around 1 means happy
                    return sum == 1;
                } else {
                    hashset.insert(sum);
                }
                n = sum;
            } 
                
        }
};

class Entry {
public:
    int key;
    int value;

    Entry(int k, int v) : key(k), value(v) {}
};
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class HashMap {
    public: 
        // vector<vector<Entry>> hashmap;
        
        // HashMap() {
        // }

        vector<int> twoSum(vector<int>& numbers, int target) {
            vector<int> result;
            unordered_map<int, int> hashmap;
            for(int i=0; i<numbers.size(); i++) {
                hashmap[numbers[i]] = i;
            }
            for(int i=0; i<numbers.size(); i++) {
                int complement = target - numbers[i];
                cout << i << " " << complement << " " << hashmap[complement] << endl;
                cout << (hashmap.count(numbers[i]) > 0) << " " << hashmap[complement] << " " << (hashmap[complement] != i) << endl;
                if(hashmap.count(numbers[i]) > 0 && hashmap[complement] && hashmap[complement] != i) {
                    result.push_back(i);
                    result.push_back(hashmap[complement]);
                    break;
                }
            }
            return result;
        }

        bool isIsomorphic(string s, string t) {
            int n = s.size();
            int m = t.size();
            if(n != m)
                return false;
            unordered_map<char, char> hashmap;
            unordered_map<char, char> hashmapRev;
            for(int i=0; i<n; i++) {
                if (hashmap.count(s[i]) == 0 && hashmapRev.count(t[i]) == 0) {
                    hashmap[s[i]] = t[i];
                    hashmapRev[t[i]] = s[i];
                    // cout << s[i] << " " << t[i] << endl;
                }
                else if(hashmap[s[i]] != t[i] || hashmapRev[t[i]] != s[i])
                    return false;
            }

            return true;
        }

        vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
            unordered_map<string, int> hashmap;
            vector<string> result;

            for (int i=0; i<list1.size(); ++i) {
                hashmap[list1[i]] = i;
            }
            int sum = INT_MAX;
            for (int j=0; j<list2.size(); ++j) {
                int interimSum = 0;
                if(hashmap.count(list2[j]) > 0) {
                    interimSum = hashmap[list2[j]] + j;
                    if(interimSum < sum) {
                        sum = interimSum;
                        result.clear();
                        result.push_back(list2[j]);
                    } else if (sum == interimSum)
                        result.push_back(list2[j]);
                }
            }
            return result;
        }

        int firstUniqChar(string s) {
            unordered_map<char, int> hashmap;
            for (char key : s) {
                hashmap[key]++;
            }
            for (int i=0; i<s.size(); ++i) {
                if (hashmap[s[i]] == 1)
                    return i;
            }
            return -1;
        }

        vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
            unordered_map<int, int> hashmap;
            vector<int> intersection;

            for (int key: nums1) {    
                hashmap[key]++;
            }

            for (int i=0; i<nums2.size(); ++i) {
                if (hashmap[nums2[i]] > 0) {
                    intersection.push_back(nums2[i]);
                    hashmap[nums2[i]]--;
                }
            }

            return intersection;
        }

        bool containsNearbyDuplicate(vector<int>& nums, int k) {
            unordered_map<int, int> hashmap;

            for (int i=0; i<nums.size(); ++i) {
                if (hashmap.count(nums[i]) > 0 && abs(i - hashmap[nums[i]] <= k)) 
                    return true;
                else    
                    hashmap[nums[i]] = i; 
            }
            return false;
        }


        int modOfStringWith10(const string& str) {
            int num = 0;
            for (char c : str) {
                num = num * 10 + (c - '0');
                num %= 10;
            }
            return num;
        }

        int hashFunction(const string& str) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end()); // Sort the characters
            int hash = 0;
            for (char c : sortedStr) {
                hash = hash * 31 + c; // Use a simple hash function
            }
            return hash;
        }

        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            unordered_map<int, vector<string>> hashmap;
            vector<vector<string>> result;

            for (string value: strs) {
                int hash = hashFunction(value);
                cout << hash << endl;
                hashmap[hash].push_back(value);
            }
            for (auto& pair : hashmap) {
                result.push_back(pair.second);
            }
            return result;
        }

        bool isValidSudoku(vector<vector<char>>& board) {
            for(int i=0; i<board.size(); ++i) {
                unordered_map<char, int> row;
                unordered_map<char, int> column;
                unordered_map<char, int> grid;   
                for (int j=0; j<board[i].size(); ++j) {
                    if(board[i][j] != '.' && row.count(board[i][j]) > 0) 
                        return false;
                    row[board[i][j]]++;

                    if(board[j][i] != '.' && column.count(board[j][i]) > 0) 
                        return false;
                    column[board[j][i]]++;

                    int row_i = 3 * (i / 3) + j / 3;
                    int col_j = 3 * (i % 3) + j % 3;
                    if (board[row_i][col_j] != '.' && grid.count(board[row_i][col_j]) > 0) {
                        return false;
                    }
                    grid[board[row_i][col_j]]++;
                }
            }
            return true;
        }

        unordered_map<string, int> hashmap;
        vector<TreeNode*> result;

        // Function to construct the hashmap from a binary tree
        string constructHashMap(TreeNode* root) {
            if (root == nullptr) {
                return ".";
            }

            string leftSubTree = constructHashMap(root->left);
            string rightSubTree = constructHashMap(root->right);

            string subTree = to_string(root->val) + "," + leftSubTree + "," + rightSubTree;
            hashmap[subTree]++; 
            if(hashmap[subTree] == 2) {
                result.push_back(root);
            }

            return subTree;
        }   

        vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
            constructHashMap(root);
            return result; 
        }

        int numJewelsInStones(string jewels, string stones) {
            int output = 0;
            unordered_set<char> hashset;
            for (char c: jewels) {
                hashset.insert(c);
            }
            for (int key : stones) {
                if (hashset.count(key) > 0) {
                    output++;
                }
            }
            return output;
        }

        int lengthOfLongestSubstring(string s) {
            unordered_set<char> hashset;
            int output = 0;
            int left, right = 0;
            while (right < s.size()) {
                if (hashset.count(s[right]) == 0) {
                    hashset.insert(s[right]);
                    output = max(output, right-left+1);
                    right++;
                } else {
                    hashset.erase(s[left++]);
                }
            }
            return output;
        }

        int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
            int output = 0;

            unordered_map<int, int> hashmap;

            for (int i: nums1) {
                for (int j: nums2) {
                    hashmap[i+j]++;
                }   
            }
            for (int i: nums3) {
                for (int j: nums4) {
                    // -(i+j) is the complement of the sums already in hashmap
                    int complement = -(i+j);
                    if (hashmap.count(complement) > 0) 
                        output += hashmap[complement];
                }   
            }

            return output;
        }

        // vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //     vector<vector<int>> result;
        //     unordered_map<int, int> hashmap;

            

        // }

        vector<int> topKFrequent(vector<int>& nums, int k) {
            unordered_map<int, int> hashmap;
            vector<int> output;

            for(int i: nums) {
                hashmap[i]++;
            }
            vector<pair<int, int>> frequency;
            
            for (auto &pair: hashmap) {
                frequency.push_back({pair.second, pair.first});
            }

            sort(frequency.rbegin(), frequency.rend());

            for (int i=0; i<k; i++) {
                output.push_back(frequency[i].second);
            } 

            return output;
        }

        int maxFrequencyElements(vector<int>& nums) {
            unordered_map<int, int> hashmap;
            int output = 0;

            for(int i: nums) {
                output = max(++hashmap[i], output);
            }
            // int max = 0;
            // for (auto &pair: hashmap) {
            //     if (pair.second > max) {
            //         max = pair.second;
            //         output = pair.second;
            //     } else if (pair.second == max) {
            //         output += pair.second;
            //     }
            // }
            return output;

        }

        void printArray(vector<int>& arr) {
            for (int i = 0; i < arr.size(); i++) {
                /* code */
                cout << arr[i]<< " ";
            }
            cout << endl;
        }
        void printArray(vector<string>& arr) {
            for (int i = 0; i < arr.size(); i++) {
                /* code */
                cout << arr[i]<< " ";
            }
            cout << endl;
        }
        void printTree(TreeNode* root) {
            if(root == NULL)
                return;
            cout << root->val << " ";
            printTree(root->left);
            printTree(root->right);
        }
        void printArray(vector<TreeNode*>& arr) {
            for (int i = 0; i < arr.size(); i++) {
                /* code */
                printTree(arr[i]);
            }
            cout << endl;
        }
        void print2DArray(vector<vector<int>>& arr) {
            for (int i = 0; i < arr.size(); i++) {
                for (int j = 0; j < arr[i].size(); j++) {
                    cout << arr[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
        void print2DArray(vector<vector<string>>& arr) {
            for (int i = 0; i < arr.size(); i++) {
                for (int j = 0; j < arr[i].size(); j++) {
                    cout << arr[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
};


int minimumLength(string s) {
    string prefixOfs;
    string suffixOfs;
    int output = 0;
    int i = 0;
    int j = s.size()-1;

    while(i < j) {
        // cout << endl << "i = " << i << " j = " << j << endl;
        int k = i;
        int l = j;
        prefixOfs = s[k++];
        // cout << prefixOfs[k-1] << " " << s[k] << endl;
        while(prefixOfs[0] == s[k] && k < l) {
            cout << prefixOfs[0] << " " << s[k] << endl;
            prefixOfs += s[k++];
        }
        // cout << "k = " << k << " l = " << l << endl;

        suffixOfs = s[l--];
        // cout << suffixOfs[l-1] << " " << s[l] << endl;
        while(suffixOfs[0] == s[l]  && k < l) {
            // cout << suffixOfs[0] << " " << s[l] << endl;
            suffixOfs += s[l--];
        }
        // cout << "k = " << k << " l = " << l << endl;
        if(prefixOfs[0] == suffixOfs[0]){
            i = k;
            j = l;
        } else 
            break;
    }
    // cout << i << " " << j << endl;
    return j-i+1;
}


string maximumOddBinaryNumber(string s) {
    int n = s.size()-1;
    int left = 0;
    int right = n; 

    while(left <= right) {
        if(s[left] == '1') 
            left++;
        
        if (s[right] == '0')
            right--;

        if(left <= right && s[left] == '0' && s[right] == '1') {
            s[left] = '1';
            s[right] = '0';
        }
        // cout << left << " " << right << " " << s << endl;
    }

    s[left-1] = '0';
    s[n] = '1';
    
    return s;
}


string customSortString(string order, string s) {
    unordered_map<char, int> hashmap;

    for (char key: s)
        hashmap[key]++;

    for (auto& pair: hashmap)
        cout << pair.first << " " << pair.second << endl;

    string result;
    for (int i=0; i<order.size(); ++i) {
        while(hashmap[order[i]]-- > 0)
            result += order[i];
    }

    for (auto& pair: hashmap) {
        while(pair.second-- > 0){
            result += pair.first; 
        }   
    }

    return result;
}

int main() {
    HashMap* hm = new HashMap();

    cout << customSortString("hucw",
"utzoampdgkalexslxoqfkdjoczajxtuhqyxvlfatmptqdsochtdzgypsfkgqwbgqbcamdqnqztaqhqanirikahtmalzqjjxtqfnh") << endl;
    // vector<int> nums = {1,2,2,3,1,4};
    // cout << hm->maxFrequencyElements(nums) << endl;
    // vector<int> result = hm->topKFrequent(nums,2);
    // hm->printArray(result);
    // vector<int> nums1 = {1,2};
    // vector<int> nums2 = {-2,-1};
    // vector<int> nums3 = {-1,2};
    // vector<int> nums4 = {0,2};
    // cout << hm->fourSumCount(nums1, nums2, nums3, nums4) << endl;

    // cout << maximumOddBinaryNumber("0101") << endl;
    // cout << hm->lengthOfLongestSubstring("pwwkew") << endl;
    // cout << hm->numJewelsInStones("z", "ZZ") << endl; 

    // Create a sample binary tree
    // TreeNode* root = new TreeNode(1);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(3);
    // root->left->left = new TreeNode(4);
    // root->left->right = nullptr;
    // root->right->left = new TreeNode(2);
    // root->right->right = new TreeNode(4);
    // root->right->left->left = new TreeNode(4);
    // hm->printTree(root);
    // cout << endl;
    // vector<TreeNode*> result = hm->findDuplicateSubtrees(root);
    // hm->printArray(result);

    // vector<vector<char>> sudoku =    {{'8','3','.','.','7','.','.','.','.'},
    //                                  {'6','.','.','1','9','5','.','.','.'},
    //                                  {'.','9','8','.','.','.','.','6','.'},
    //                                  {'8','.','.','.','6','.','.','.','3'},
    //                                  {'4','.','.','8','.','3','.','.','1'},
    //                                  {'7','.','.','.','2','.','.','.','6'},
    //                                  {'.','6','.','.','.','.','2','8','.'},
    //                                  {'.','.','.','4','1','9','.','.','5'},
    //                                  {'.','.','.','.','8','.','.','7','9'}};
    // cout << hm->isValidSudoku(sudoku) << endl;

    // cout << minimumLength("cabaabac") << endl;
    // vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    // vector<vector<string>> result = hm->groupAnagrams(strs);
    // hm->print2DArray(result);
    // cout << hm->modOfStringWit/h10("tea") << endl;
    // vector<int> nums = {1,2,3,1,2,3};
    // cout << hm->containsNearbyDuplicate(nums, 2) << endl;
    // vector<int> nums1 = {1,2,2,1};
    // vector<int> nums2 = {2,2};
    // vector<int> intersection = hm->intersect(nums1, nums2);
    // hm->printArray(intersection);
    // string s = "aabb";
    // cout << hm->firstUniqChar(s) << endl;
    // vector<string> list1 = {"happy","sad","good"};
    // vector<string> list2 = {"sad","happy","good"};
    // vector<string> result = hm->findRestaurant(list1, list2);
    // hm->printArray(result);
    // string s = "foo"; 
    // string t = "bar";
    // cout << hm->isIsomorphic(s,t) << endl; 
    // vector<int> numbers = {3,2,3};
    // vector<int> result = hm->twoSum(numbers, 6);
    // printArray(result);
    // HashSet* hs = new HashSet(); 
    // int n = 2;
    // cout << hs->isHappy(n) << endl;
    // vector<int> nums1 = {4,7,9,7,6,7};
    // vector<int> nums2 = {5,0,0,6,1,6,2,2,4};
    // vector<int> result = hs->intersection(nums1, nums2);
    // printArray(result);
    
    // MyHashSet1* myHashSet = new MyHashSet1();
    // myHashSet->add(1);      // set = [1]
    // myHashSet->add(2);      // set = [1, 2]
    // myHashSet->contains(1); // return True
    // myHashSet->contains(3); // return False, (not found)
    // myHashSet->add(2);      // set = [1, 2]
    // myHashSet->contains(2); // return True
    // myHashSet->remove(2);   // set = [1]
    // myHashSet->contains(2); // return False, (already removed)
    
    return 0;
}