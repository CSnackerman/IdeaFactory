#include "TestFacility.h"
#include "Log.h"

struct TestLog : public Log {

    TestFacility* testFacility;

    TestLog(TestFacility* tf) : testFacility(tf) {}
    
    TEST Expected_Arg_Count() {

        // Test strings
        std::vector<std::string> testStrings(10);
        testStrings[0] = ("");
        testStrings[1] = ("%");
        testStrings[2] = (" %");
        testStrings[3] = (" % ");
        testStrings[4] = ("%%%");
        testStrings[5] = ("test; % nn asl%7%7k\\djf//%sdf");

        TestFacility::Result resultVal = TestFacility::FAIL;
        int TEST_NUMBER, EXPECTED_VAL;

        //Tests

        TEST_NUMBER = 0;
        EXPECTED_VAL = 0;
        getExpectedArgCount(testStrings[TEST_NUMBER]) == EXPECTED_VAL ? 
            resultVal = TestFacility::PASS : 
            resultVal = TestFacility::FAIL;

        testFacility->writeResult(__func__, 0, resultVal);

        //---

        TEST_NUMBER = 1;
        EXPECTED_VAL = 1;
        getExpectedArgCount(testStrings[TEST_NUMBER]) == EXPECTED_VAL ? 
            resultVal = TestFacility::PASS : 
            resultVal = TestFacility::FAIL;
            
        testFacility->writeResult(__func__, TEST_NUMBER, resultVal);

        //---

        TEST_NUMBER = 2;
        EXPECTED_VAL = 1;
        getExpectedArgCount(testStrings[TEST_NUMBER]) == EXPECTED_VAL ? 
            resultVal = TestFacility::PASS : 
            resultVal = TestFacility::FAIL;
            
        testFacility->writeResult(__func__, TEST_NUMBER, resultVal);

        //---

        TEST_NUMBER = 3;
        EXPECTED_VAL = 1;
        getExpectedArgCount(testStrings[TEST_NUMBER]) == EXPECTED_VAL ? 
            resultVal = TestFacility::PASS : 
            resultVal = TestFacility::FAIL;
            
        testFacility->writeResult(__func__, TEST_NUMBER, resultVal);

        //---

        TEST_NUMBER = 4;
        EXPECTED_VAL = 3;
        getExpectedArgCount(testStrings[TEST_NUMBER]) == EXPECTED_VAL ? 
            resultVal = TestFacility::PASS : 
            resultVal = TestFacility::FAIL;
            
        testFacility->writeResult(__func__, TEST_NUMBER, resultVal);

        //---

        TEST_NUMBER = 5;
        EXPECTED_VAL = 4;
        getExpectedArgCount(testStrings[TEST_NUMBER]) == EXPECTED_VAL ? 
            resultVal = TestFacility::PASS : 
            resultVal = TestFacility::FAIL;
            
        testFacility->writeResult(__func__, TEST_NUMBER, resultVal);

        //---
    }
};

int main() {
    TestFacility testFacility;
    TestLog testClass(&testFacility);

    TestFacility::printTestSuiteHeader("Log");

    // Run tests...
    testClass.Expected_Arg_Count();

    //Print Results
    testFacility.printTestResults();

    return 0;
}


