#include <iostream>
#include <unordered_set>

template<typename T>
std::ostream& operator<<(std::ostream &stream, const std::unordered_set<T> set) {
    stream << "std::unordered_set{ ";
    for(const T &el : set) {
        stream << el << " ";
    }
    stream << "}\n";
    return stream;
}
template <typename T>
bool assertEq(const T& expected, const T& actual, const std::string &testName) {
    if(expected != actual) {
        std::cout << "Test  ERROR: " << testName <<  "\n"
                  << "-- Expected value: " << expected << "\n"
                  << "-- Actual value: " << actual << std::endl;
        return false;
    }
    std::cout << "Test OK: " << testName << std::endl;
    return true;
}

