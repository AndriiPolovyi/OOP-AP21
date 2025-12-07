#pragma once
#include <iostream>
#include <cmath> 

class Date {
private:
    int day;
    int month;
    int year;

    long toTotalDays() const;

public:
    static Date currentDate;

    Date(int d = 1, int m = 1, int y = 2000);

    static void setCurrentDate(int d, int m, int y);

    long operator-(const Date& other) const;

    bool operator<(const Date& other) const;

    friend std::ostream& operator<<(std::ostream& out, const Date& date);
};