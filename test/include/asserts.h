#include <iostream>

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

