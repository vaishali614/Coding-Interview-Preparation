int  kmp(string S, string P){
	int n = P.size();
  int m = S.size();
  
  if(n == 0)	
    return 0;
  if(m == 0)	
    return -1;

	int prefix[n];
	prefix[0] = 0;
	int j = 0;
	for(int i = 1; i < n; ){
		if(P[j] == P[i]){
			prefix[i] = j + 1;
			j++;
			i++;
		} else {
			if(j == 0) {
				prefix[i] = 0;
				i++;
			} else 
				j = prefix[j - 1];
		}
	}
  
	// searching begins
	int i, j = 0; // iterator for the pattern
	for(i = 0; i < m; ){
		if(S[i] == P[j]){
			i++;
			j++; 
		} 
    
    if(j == n){
      return (i - j);
      j = prefix[j - 1];
    } else if(i < m && S[i] != P[j]){
			if(j == 0) 	
        i++;
      else 	
        j = prefix[j - 1];
		}
	}
	return -1;
}
