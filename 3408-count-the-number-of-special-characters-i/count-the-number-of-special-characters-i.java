class Solution {
    public int numberOfSpecialChars(String word) {
        int count = 0;
        boolean [] lowerCase = new boolean[26];
        boolean[] upperCase = new boolean [26];

        for(int i=0;i<word.length();i++){
            char ch = word.charAt(i);
            if(Character.isLowerCase(ch)){
               lowerCase[ch-'a']=true;

            }
            else if (Character.isUpperCase(ch)){
                upperCase[ch-'A']=true;
            }
        }
        for(char j=0;j<26;j++){
            if(upperCase[j] && lowerCase[j]){
                    
                count++;
                    
            }
        }
        return count;
        

        
    }
}