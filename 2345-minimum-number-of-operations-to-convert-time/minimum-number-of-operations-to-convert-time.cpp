class Solution {
public:
    int convertTime(string current, string correct) {
        int curr=((current[0]-'0')*10+current[1]-'0')*60+(current[3]-'0')*10+current[4]-'0';
        int corr=((correct[0]-'0')*10+correct[1]-'0')*60+(correct[3]-'0')*10+correct[4]-'0';
        int rem=corr-curr;
        int count=0;
        while(rem>=60){
            rem-=60;
            count++;
        }
        while(rem>=15){
            rem-=15;
            count++;
        }
        while(rem>=5){
            rem-=5;
            count++;
        }
        while(rem>=1){
            rem-=1;
            count++;
        }
        return count;
    }
};