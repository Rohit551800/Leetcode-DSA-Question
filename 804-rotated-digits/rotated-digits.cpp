class Solution {
public:
    int rotatedDigits(int n) {
        int counter = 0;
        for(int i=1;i<=n;i++){
            bool valid = true;
            bool changed = false;
            int num = i;
            while(num){
                int last = num % 10;
                num = num/10;

                if(last == 3 || last == 4 || last == 7) {
                    valid = false;
                    break;
                }

                if(last == 2 || last == 5 || last == 6 || last == 9){
                    changed = true;
                }
            }
            if(valid && changed) counter++;
        }
        return counter;
    }
};