class Solution {
public:
    int lcs(string word1, string word2, int i,int j){
        if(i<0 || j<0){
            return 0;
        }
        if(word1[i]==word2[j]){
            return 1+lcs(word1,word2,i-1,j-1);
        }
        else{
            return max(lcs(word1,word2,i-1,j),lcs(word1,word2,i,j-1));
        }
    }
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        int check=lcs(word1,word2,n-1,m-1);
        return (n-check)+(m-check);
    }
};
