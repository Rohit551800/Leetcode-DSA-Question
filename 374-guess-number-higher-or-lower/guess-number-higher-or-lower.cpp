/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int i = 1 , j = n;

        while(i <= j){
            int middle = i + (j-i)/2;
            int x = guess(middle);
            if(x == -1){
                j = middle - 1;
            }
            else if(x == 1){
                i = middle + 1;
            }
            else{
                return middle;
            }
        }
        return j;
    }
};