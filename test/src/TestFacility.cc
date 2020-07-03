#include "TestFacility.h"

TestFacility::TestFacility() 
    :
    results(ResultMap())
{}

void TestFacility::printTestSuiteHeader(const std::string suiteName) {
    printf("=== '%s' Test Suite ===\n", suiteName.c_str());
}

void TestFacility::printTestHeader(const std::string testName) {
    printf("--- %s ---\n", testName.c_str());
}

void TestFacility::writeResult(TestName testName, TestNumber testNumber, Result result) {

    ResultVector* resultsPtr = &results[testName];

    // Resize result vector
    size_t vecSize = resultsPtr->size();
    
    if(vecSize < 1) {
        *resultsPtr = ResultVector(EXPECTED_AMT_TESTS, FAIL);
    }
    
    if(testNumber > vecSize - 1) {
        resultsPtr->resize(vecSize + 1);
        resultsPtr->at(vecSize) = FAIL;
    }

    resultsPtr->at(testNumber) = result;
}

void TestFacility::printTestResults() {

    for(ResultMap::iterator it = results.begin(); it != results.end(); ++it) {

        // Get name of test
        std::string printName = it->first;

        // Append test label
        std::string colorless = TERMINAL_COLORLESS;
        std::string blue = TERMINAL_BLUE;
        std::string appendTestLabel = blue + "[TEST] " + colorless;

        printName = appendTestLabel + printName;

        //Print results
        printf("%s\n", printName.c_str());
        printResultVector(it->second);
    }

    std::cout << std::endl;
}

void TestFacility::printResultVector(ResultVector& resultVec) {

    int testNumber = 0;
    for(Result& result : resultVec) {

        switch(result) {
            case PASS:
                setTerminalColor(TERMINAL_GREEN);
                printf("  [PASS]  ");
                break;
            
            default:
                setTerminalColor(TERMINAL_RED);
                printf("  [FAIL]  ");
        }

        setTerminalColor(TERMINAL_COLORLESS);
        printf("Test #%.2d\n", testNumber);

        ++testNumber;
    }
}

void TestFacility::setTerminalColor(const char* color) {
    printf("%s", color);
}