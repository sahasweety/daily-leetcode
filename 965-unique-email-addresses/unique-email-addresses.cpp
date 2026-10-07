class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {

        unordered_set<string> st;

        for (string email : emails) {

            int pos = email.find('@');

            string local = "";
            string domain = email.substr(pos);

            for (int i = 0; i < pos; i++) {

                if (email[i] == '+')
                    break;

                if (email[i] != '.')
                    local += email[i];
            }

            string finalEmail = local + domain;

            st.insert(finalEmail);
        }

        return st.size();
    }
};