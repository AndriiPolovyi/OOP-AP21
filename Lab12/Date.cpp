#include "Date.h"

Date Date::currentDate(1, 1, 2024);

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

void Date::setCurrentDate(int d, int m, int y) {
    currentDate = Date(d, m, y);
}

long Date::toTotalDays() const {
    return year * 365 + month * 30 + day;
}

long Date::operator-(const Date& other) const {
    return this->toTotalDays() - other.toTotalDays();
}

bool Date::operator<(const Date& other) const {
    long diff1 = std::abs(*this - currentDate); 
    long diff2 = std::abs(other - currentDate); 

    return diff1 < diff2;
}

std::ostream& operator<<(std::ostream& out, const Date& date) {
    out << date.day << "." << date.month << "." << date.year;
    return out;
}