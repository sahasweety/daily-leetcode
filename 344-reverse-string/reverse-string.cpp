//class Solution {
//public:
//    void reverseString(vector<char>& s) {
//        int left =0 ,right = s.size()-1;
//
//        while(left < right ){
//            swap(s[left], s[right]);
//          left++;
//            right--;
//        }
//    }
//};

class Solution{
    public:
        void reverseString(vector<char>& s){
            stack<char>st;
            for(int i =0; i < s.size(); i++){
                st.push(s[i]);
            }
            int i=0;
            while(!st.empty()){
                s[i]=st.top();
                st.pop();
                i++;
            }
        }
};