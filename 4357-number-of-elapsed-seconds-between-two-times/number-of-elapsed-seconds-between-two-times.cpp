class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int startSec = (((startTime[0] - '0') * 10 + (startTime[1] - '0')) * 3600) +
        (((startTime[3] - '0') * 10 + (startTime[4] - '0')) * 60) + 
        ((startTime[6] - '0') * 10 + (startTime[7] - '0'));

        int endSec = (((endTime[0] - '0') * 10 + (endTime[1] - '0')) * 3600) +
        (((endTime[3] - '0') * 10 + (endTime[4] - '0')) * 60) + 
        ((endTime[6] - '0') * 10 + (endTime[7] - '0'));
        return endSec - startSec;
    }
};