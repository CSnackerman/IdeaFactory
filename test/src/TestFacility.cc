#include "TestFacility.h"

TestFacility::TestFacility() {
}

void TestFacility::printTestSuiteHeader(const std::string suiteName) {
    printf("=== '%s' Test Run ===\n", suiteName.c_str());
}

void TestFacility::printTestHeader(const std::string testName) {
    printf("--- %s ---\n", testName.c_str());
}