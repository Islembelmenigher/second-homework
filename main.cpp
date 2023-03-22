#include <iostream>
#include <iomanip>
#include <sstream>

class Time {
public:
    Time(int seconds = 0) {
        m_seconds = seconds;
    }

    int getSeconds() const {
        return m_seconds;
    }

    void setSeconds(int seconds) {
        m_seconds = seconds;
    }

    void display() const {
        int hours = m_seconds / 3600;
        int minutes = (m_seconds % 3600) / 60;
        int seconds = m_seconds % 60;
        std::cout << std::setfill('0') << std::setw(2) << hours << "h:"
                  << std::setfill('0') << std::setw(2) << minutes << "m:"
                  << std::setfill('0') << std::setw(2) << seconds << "s";
    }

    friend std::istream& operator>>(std::istream& is, Time& t) {
        int hours, minutes, seconds;
        char separator;
        is >> hours >> separator >> minutes >> separator >> seconds;
        t.m_seconds = hours * 3600 + minutes * 60 + seconds;
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Time& t) {
        t.display();
        return os;
    }

    Time operator+(const Time& other) const {
        return Time(m_seconds + other.m_seconds);
    }

    Time operator-(const Time& other) const {
        return Time(m_seconds - other.m_seconds);
    }

    Time operator*(int scalar) const {
        return Time(m_seconds * scalar);
    }

    operator int() const {
        return m_seconds;
    }

private:
    int m_seconds;
};
int main() {
    Time t1(200);
    std::cout << t1 << std::endl; // displays 00h:03m:20s

    Time t2;
    std::cin >> t2; // user enters 10:12:01

    Time t3 = t2 - t1;
    std::cout << t3 << std::endl; // displays 10h:08m:41s

    int t3s = t3;
    std::cout << t3s << std::endl; // displays 36521

    Time t4 = t1 * 2;
    std::cout << t4 << std::endl; // displays 00h:06m:40s

    return 0;
}
