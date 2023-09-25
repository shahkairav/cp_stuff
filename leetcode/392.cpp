// 392. Is Subsequence

// Basic solution
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int counter = 0;
        for (int i = 0; i < t.length(); i++) {
            if (counter == s.length()) break;
            if (s[counter] == t[i]) counter++;
        }
        if (counter == s.length()) return true;
        return false;
    }
};

// For multiple strings to be queried, populate the map once a priori
class Solution {
public:
    bool isSubsequence(string s, string t) {
        unordered_map<char, vector<int>> hash;
        for (int i = 0; i < t.length(); i++) hash[t[i]].push_back(i);
        
        int prev = -1;
        for (auto c : s){
            auto it = hash.find(c);
            if (it == hash.end()) return false;
            auto vec = it->second;
            int pos = distance(vec.begin(), upper_bound(vec.begin(), vec.end(), prev));
            if (pos == vec.size()) return false;
            prev = vec[pos];
        }
        return true;
    }
};