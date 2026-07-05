class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;

        if(p.size() > s.size())
        return ans;

        unordered_map<char,int>need;
        unordered_map<char,int>window;

        for(char c : p)
            need[c]++;       

        int left=0;
        int k=p.size();

        for(int right=0;right<s.size();right++){
            window[s[right]]++;

            if(right-left +1 ==k ){
                if(window==need)
                ans.push_back(left);

                window[s[left]]--;

                if(window[s[left]] == 0)
                    window.erase(s[left]);

                left++;


            }
            
            
        }
        return ans;

        
    }
};