class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> days = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

        auto convert = [&](string date) {
            int month = stoi(date.substr(0, 2));
            int day = stoi(date.substr(3, 2));
            return days[month - 1] + day;
        };

        int start = max(convert(arriveAlice), convert(arriveBob));
        int end = min(convert(leaveAlice), convert(leaveBob));

        return max(0, end - start + 1);
    }
};