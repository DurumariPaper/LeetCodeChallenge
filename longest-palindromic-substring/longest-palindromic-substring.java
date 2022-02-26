class Solution {
 public String longestPalindrome(String s) {
        // Fill a boolean DP array using "Gap Strategy" or "Diagonal Traversal".
        
        boolean[][] dp1 = new boolean[s.length()][s.length()];
        int li=0;
        int ri=0;
        for (int g = 0; g < dp1.length; g++) {
            for (int i = 0, j = g; j < dp1.length; i++, j++) {
                
                if (g==0) {
                    dp1[i][j] = true;
                    li=i;
                    ri=j;
                }

                else if (g == 1) {
                    if (s.charAt(i) == s.charAt(j)) {
                        dp1[i][j] = true;
                        li=i;
                        ri=j;
                    }
                }

                else {
                    if (s.charAt(i) == s.charAt(j)) {
                        if (dp1[i + 1][j - 1] == true) {
                            dp1[i][j] = true;
                            li=i;
                            ri=j;
                        }
                    }
                    else {
                        dp1[i][j] = false;

                    }
                }

            }
        }
        return s.substring(li,ri+1);   
    }

}



/*
    public String longestPalindrome(String s) {
    if (s == null || s.length() < 1) return "";
    int start = 0, end = 0;
    for (int i = 0; i < s.length(); i++) {
        int len1 = expandAroundCenter(s, i, i);
        int len2 = expandAroundCenter(s, i, i + 1);
        int len = Math.max(len1, len2);
        if (len > end - start) {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }
    return s.substring(start, end + 1);
}

private int expandAroundCenter(String s, int left, int right) {
    int L = left, R = right;
    while (L >= 0 && R < s.length() && s.charAt(L) == s.charAt(R)) {
        L--;
        R++;
    }
    return R - L - 1;
}*/