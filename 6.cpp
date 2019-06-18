class Solution {
public:
    string convert(string s, int numRows) {
        if(s.length() == 0 || numRows == 0) return "";
        if(numRows == 1) return s;
        string ret;
        int gap = 2 * numRows - 2;
        for(int i = 0; i < numRows; i++)
        {
            for(int j = i; j < s.length(); j+=gap)
            {
                ret += s[j];
                if(i != 0 && i != numRows - 1 && (j-i) + (gap-i) < s.length())
                    ret += s[j-i+gap-i];
            }
        }
        return ret;
    }
};