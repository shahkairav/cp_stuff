class Solution {
public:
    int lengthOfLastWord(string s) {
        string last_word = "";
        int ret = 0;
        for (size_t i = 0; i < s.length(); i++) {
            last_word = "";
            while (i < s.length() && !std::isspace(s[i])) {
                last_word += s[i++];
            }
            if (last_word != "") ret = last_word.length();
        }
        return ret;
    }
};