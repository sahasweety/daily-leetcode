//google question
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> freq;

        for (char ch : magazine)
            freq[ch]++;

        for (char ch : ransomNote) {
            freq[ch]--;
            if (freq[ch] < 0)
                return false;
        }

        return true;
    }
};