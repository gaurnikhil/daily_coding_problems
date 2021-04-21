string runLengthEncoding(string s)a[
    int n = s.length();
    if(n == 0){
        return "";
    }

    string ans = "";

    int ct = 1;
    for(int i=1; i<n; i++){
        if(s[i] == s[i-1]){
            ct++;
        }
        else{
            ans = ans + to_string(ct) + s[i-1];
            ct = 1;
        }
    }

    ans = ans + to_string(ct) + s[n-1];

    return ans;
]