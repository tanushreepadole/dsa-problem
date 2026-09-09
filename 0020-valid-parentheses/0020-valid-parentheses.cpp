class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {

            // Opening bracket
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            }

            // Closing bracket
            else {
                
                // No opening bracket to match
                if (st.empty()) {
                    return false;
                }

                
                if ((s[i] == ')' && st.top() == '(') ||
                    (s[i] == ']' && st.top() == '[') ||
                    (s[i] == '}' && st.top() == '{')) {
                    
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }

    
        return st.empty();
    }
};