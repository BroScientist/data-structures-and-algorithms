class Solution {
public:
    int dayOfYear(string date) {
        vector<int> monthDays = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 7));
        int day = stoi(date.substr(8, 10));
        int total = day;
        for (int i = 1; i < month; i++)
            total += monthDays[i];
        if (year % 4 == 0)
            if (!(year % 100 == 0 && year % 400 != 0))
                if (month > 2)
                    total++;
        return total;
    }
};