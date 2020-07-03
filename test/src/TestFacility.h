#ifndef TEST_FACILITY_H
#define TEST_FACILITY_H

#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <cctype>

typedef void TEST;

class TestFacility {

public:

    enum Result { PASS, FAIL };   


private:

    const int EXPECTED_AMT_TESTS = 1;

    typedef std::string                         SuiteName;
    typedef std::string                         TestName;
    typedef unsigned int                        TestNumber;

    typedef std::vector<Result>                 ResultVector;
    typedef std::map <TestName, ResultVector>   ResultMap;

    ResultMap results;


public:

    TestFacility();

    // Header printing functions 
    static void printTestSuiteHeader(const std::string suiteName);
    static void printTestHeader(const std::string testName);

    //Result recording and printing
    void writeResult(TestName, TestNumber, Result);
    void printTestResults();


private:

    void printResultVector(ResultVector&);


private:

    const char* TERMINAL_RED = "\u001b[31m";
    const char* TERMINAL_GREEN = "\u001b[32m";
    const char* TERMINAL_BLUE = "\u001b[34m";
    const char* TERMINAL_COLORLESS = "\033[0m";

    void setTerminalColor(const char* color);

};

#endif