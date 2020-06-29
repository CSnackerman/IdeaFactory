#ifndef TEST_FACILITY_H
#define TEST_FACILITY_H

#include <iostream>
#include <vector>

#include "TestApplication.h"

class TestFacility {
private:
    TestApplication testApp;
    std::vector<int> results;

public:
    TestFacility();

    static void printTestSuiteHeader(const std::string suiteName);
    static void printTestHeader(const std::string testName);
};

#endif