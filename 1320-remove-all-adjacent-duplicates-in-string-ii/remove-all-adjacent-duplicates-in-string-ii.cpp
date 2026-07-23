class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        for(int i=0;i<s.size(); i++){
            if(st.empty()){
                st.push({s[i],1});
                continue;
            }

            if(st.top().first==s[i]){
                st.top().second++;
                if(st.top().second==k){
                    st.pop();
                }
                continue;
            }
            st.push({s[i],1});
        }
        string ans;
        while(!st.empty()){
            char ch = st.top().first;
            int cnt = st.top().second;

            while(cnt --){
                ans.push_back(ch);
            }
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};