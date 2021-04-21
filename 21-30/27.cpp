bool isValid(string s) {
        int n = s.length();
        if(n == 0)
            return true;
        
        stack<char> st;
        
        for(int i=0; i<n; i++){
            char c = s[i];
            if(c == '(' || c == '{' || c == '['){
                st.push(s[i]);
            }
            
            else if(st.empty() && (c == ']' || c == '}' || c == ')'))
                return false;
            
            else if(c == ']' || c == '}' || c == ')'){
                char m = st.top();
                if(!((c == ']' && m == '[') || (c == '}' && m == '{') || (c == ')' && m == '(')))
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }