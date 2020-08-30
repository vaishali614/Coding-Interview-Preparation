string minWindow(string S, string P) {
    if(P.size() == 0 || P.size() > S.size())
        return "";

    map<char, int> mP;
    for(char c : P){
        mP[c]++;
    }

    string s = "";
    map<char, int> mS;
    int left = 0, right = 0, ans = INT_MAX;
    int count = 0;
    while(left < S.size() && right < S.size()){
        char c = S[right];
        mS[c]++;
        if(mP[c] > 0 && mS[c] <= mP[c])
            count++;

        while(count == P.size()){
            int len = right - left + 1;
            if(len < ans){
                ans = len;
                s = S.substr(left, len);
            }
            char c2 = S[left];
            mS[c2]--;
            if(mS[c2] < mP[c2])
                count--;
            left++;
        }
        right++;
    }
    return s;
}
