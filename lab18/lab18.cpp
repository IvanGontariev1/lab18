#include <iostream>

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:

    Time() : hours(0), minutes(0), seconds(0) {}
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
        normalize();
    }


    void normalize() {
        if (seconds >= 60) {
            minutes += seconds / 60;
            seconds = seconds % 60;
        }
        if (minutes >= 60) {
            hours += minutes / 60;
            minutes = minutes % 60;
        }
        if (seconds < 0) {
            minutes += seconds / 60;
            seconds = (seconds % 60 + 60) % 60;
        }
        if (minutes < 0) {
            hours += minutes / 60;
            minutes = (minutes % 60 + 60) % 60;
        }
        hours = (hours % 24 + 24) % 24;
    }


    Time operator+(const Time& other) const {
        return Time(hours + other.hours, minutes + other.minutes, seconds + other.seconds);
    }


    bool operator==(const Time& other) const {
        return (hours == other.hours && minutes == other.minutes && seconds == other.seconds);
    }


    bool operator<(const Time& other) const {
        if (hours < other.hours) return true;
        if (hours == other.hours && minutes < other.minutes) return true;
        if (hours == other.hours && minutes == other.minutes && seconds < other.seconds) return true;
        return false;
    }


    bool operator>(const Time& other) const {
        return !(*this < other) && !(*this == other);
    }


    Time& operator=(const Time& other) {
        if (this != &other) {
            hours = other.hours;
            minutes = other.minutes;
            seconds = other.seconds;
        }
        return *this;
    }


    void print() const {
        std::cout << (hours < 10 ? "0" : "") << hours << ":"
            << (minutes < 10 ? "0" : "") << minutes << ":"
            << (seconds < 10 ? "0" : "") << seconds << std::endl;
    }
};

int main() {
    Time t1(2, 45, 50);
    Time t2(3, 20, 30);

    std::cout << "Initial times:\n";
    t1.print();
    t2.print();


    Time t3 = t1 + t2;
    std::cout << "\nAfter addition (t1 + t2):\n";
    t3.print();

    std::cout << "\nComparison (t1 == t2): " << (t1 == t2) << std::endl;
    std::cout << "Comparison (t1 < t2): " << (t1 < t2) << std::endl;
    std::cout << "Comparison (t1 > t2): " << (t1 > t2) << std::endl;

    Time t4;
    t4 = t1;
    std::cout << "\nAfter assignment (t4 = t1):\n";
    t4.print();

    return 0;
}
