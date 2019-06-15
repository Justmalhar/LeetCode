class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0 )
            return s.size();
        int num = 0;
        int start = -1;
        vector<int> m(128, -1);
        for(int i = 0; i < s.size(); i++){
            if(m[s[i]] > start){
                start = m[s[i]];
            }
            m[s[i]] = i;
            num = max(num, i - start);
        }
        return num;
    }
};