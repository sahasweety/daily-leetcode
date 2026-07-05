class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> ans;

        int wordLen = words[0].size();
        int totalWords = words.size();

        unordered_map<string,int> need;

        for(string word : words)
            need[word]++;

        for(int offset = 0; offset < wordLen; offset++) {

            int left = offset;
            int count = 0;

            unordered_map<string,int> window;

            for(int right = offset;
                right + wordLen <= s.size();
                right += wordLen) {

                string word = s.substr(right, wordLen);

                if(need.count(word)) {

                    window[word]++;
                    count++;

                    while(window[word] > need[word]) {

                        string leftWord =
                            s.substr(left, wordLen);

                        window[leftWord]--;
                        count--;

                        left += wordLen;
                    }

                    if(count == totalWords) {

                        ans.push_back(left);

                        string leftWord =
                            s.substr(left, wordLen);

                        window[leftWord]--;
                        count--;

                        left += wordLen;
                    }
                }
                else {

                    window.clear();
                    count = 0;

                    left = right + wordLen;
                }
            }
        }

        return ans;
    }
};