class Solution {
public:
    string frequencySort(string s) {
       unordered_map<char,int>mp;
       for(int i =0; i <s.size();i++){
        mp[s[i]]++;
       } 
       priority_queue<pair<int , char>>maxH;

       for(auto it : mp){
        int freq = it.second;
        char element = it.first;

        maxH.push({freq,element});
       }
       string ans = "";

       while(maxH.size() > 0){
        int freq= maxH.top().first;
        char element = maxH.top().second;

        for(int i=0; i < freq ; i++){
            ans += element;      //not use ans = ans + element
        }
        maxH.pop();
       }
       return ans;
    }
};