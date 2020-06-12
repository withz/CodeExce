#include <iostream>
#include <vector>

bool check_leap(int year)
{
    if (year % 100 == 0) {
        return year % 400 == 0 ? true : false;
    }
    else {
        return year % 4 == 0 ? true : false;
    }
}

int get_week_day(int year, int month, int day)
{
    int week_day = 0;
    int century = 0;

    if (month < 3) {
        month += 12;
        year--;
    }
    century = year / 100;
    year = year % 100;

    week_day = year + year / 4 + century / 4 - 2 * century + (26 * (month + 1)) 
        / 10 + day - 1;
    week_day = ((week_day) % 7 + 7) % 7;
    return week_day;
}

bool check_weekend(int year, int month, int day)
{
    // Check Saturday & Sunday
    int week_day = get_week_day(year, month, day);
    if (week_day == 0 || week_day == 6) {
        return true;
    }
    return false;
}

bool check_holiday(int year, int month, int day)
{
    // Check 1.1
    if (month == 1 && day == 1) {
        return true;
    }

    // Check 5.1-5.3
    if (month == 5) {
        if (day <= 3 && day >= 1) {
            return true;
        }
    }

    // Check 10.1-10.7
    if (month == 10) {
        if (day <= 7 && day >= 1) {
            return true;
        }
    }

    return false;
}

void date_update(int &year, int& month, int& day)
{
    if (month == 2) {
        if (day == 28) {
            if (!check_leap(year)) {
                month += 1;
                day = 0;
            }
        }
        if (day == 29) {
            month += 1;
            day = 0;
        }
    }
    else {
        if (day == 30) {
            switch (month)
            {
            case 4:
            case 6:
            case 9:
            case 11:
                month += 1;
                day = 0;
                break;
            default:
                break;
            }
        }
        if (day == 31) {
            switch (month)
            {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
                month += 1;
                day = 0;
                break;
            default:
                break;
            }
            if (month == 12) {
                year += 1;
                month = 1;
                day = 0;
            }
        }
    }
    day += 1;
}

int main()
{
    int N;

    int item, i;
    int sy, sm, sd, ey, em, ed;

    std::cin >> N;
    std::vector<int> result;
    getchar();

    for (item = 0;item < N;item++) {
        int sum_days = 0;

        std::vector<int> input_item;
        for (i = 0;i < 22;i++) {
            input_item.push_back(getchar() - '0');
        }

        sy = input_item[0] * 1000 + input_item[1] * 100 + input_item[2] * 10 + input_item[3];
        sm = input_item[5] * 10 + input_item[6];
        sd = input_item[8] * 10 + input_item[9];

        ey = input_item[11] * 1000 + input_item[12] * 100 + input_item[13] * 10 + input_item[14];
        em = input_item[16] * 10 + input_item[17];
        ed = input_item[19] * 10 + input_item[20];

        if (ey - sy < 2) {
            while (true) {
                if (!check_holiday(sy, sm, sd)) {
                    if (!check_weekend(sy, sm, sd)) {
                        sum_days++;
                    }
                }

                if (sy == ey && sm == em && sd == ed) {
                    result.push_back(sum_days);
                    break;
                }
                date_update(sy, sm, sd);
            }
        }
        else {
            // First Year
            while (true) {
                if (!check_holiday(sy, sm, sd)) {
                    if (!check_weekend(sy, sm, sd)) {
                        sum_days++;
                    }
                }

                if (sm == 12 && sd == 31) {
                    break;
                }
                date_update(sy, sm, sd);
            }
            date_update(sy, sm, sd);

            // Middle Years
            while (true) {
                sum_days += 51 * 5 - 4;
                if (check_leap(sy)) {
                    if (!check_weekend(sy, 12, 30)) {
                        sum_days++;
                    }
                }
                if (!check_weekend(sy, 12, 31)) {
                    sum_days++;
                }
                if (check_weekend(sy, 1, 1)) {
                    sum_days++;
                }
                if (check_weekend(sy, 5, 1)) {
                    sum_days++;
                }
                if (check_weekend(sy, 5, 2)) {
                    sum_days++;
                }
                if (check_weekend(sy, 5, 3)) {
                    sum_days++;
                }
                if (sy == ey - 1) {
                    break;
                }
                sy++;
            }
            sy++;
            // Last Year
            while (true) {
                if (!check_holiday(sy, sm, sd)) {
                    if (!check_weekend(sy, sm, sd)) {
                        sum_days++;
                    }
                }

                if (sy == ey && sm == em && sd == ed) {
                    result.push_back(sum_days);
                    break;
                }
                date_update(sy, sm, sd);
            }
        }
        
        
    }

    for (item = 0;item < result.size();item++) {
        std::cout << result[item] << std::endl;
    }
}
