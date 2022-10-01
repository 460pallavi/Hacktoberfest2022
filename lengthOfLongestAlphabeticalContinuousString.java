class Solution {
    static int getEndingIndex(String str, int n, int i)
    {
        i++;
        while (i < n) {
            char curr = str.charAt(i);
            char prev = str.charAt(i - 1);
 
            // If the current character appears after
            // the previous character  according to
            // the given circular alphabetical order
            if ((curr - prev == 1))
                i++;
            else
                break;
        }
 
        return i - 1;
    }
 
    // Function to return the length of the longest
    // sub-string of consecutive characters from str
    static int largestSubStr(String str, int n)
    {
        int len = 0;
 
        int i = 0;
        while (i < n) {
 
            // Valid sub-string exists from index
            // i to end
            int end = getEndingIndex(str, n, i);
 
            // Update the length
            len = Math.max(end - i + 1, len);
            i = end + 1;
        }
 
        return len;
    }
    public int longestContinuousSubstring(String s) {
        int n= s.length();
        return largestSubStr(s,n);
    }
}
