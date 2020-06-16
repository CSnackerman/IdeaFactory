#ifndef TEST_FACILITY_H
#define TEST_FACILITY_H

#include <iostream>
#include <vector>

class TestFacility {
private:
    std::vector<int> results;

public:
    static void printTestSuiteHeader(const std::string suiteName);
    static void printTestHeader(const std::string testName);
};

#endif