
#include "TestFramework.h"

using namespace std;

TestFramework::TestFramework(const bool in_printPassed) : testsTaken(0), testsPassed(0), printPassed(in_printPassed)
{
}


bool TestFramework::evaluate(const string name, const string results, const string expected)
{
    testsTaken++;
    if (results == expected)
    {
        if (printPassed)
        {
            cerr << "Test: " << name << " passed!" << endl;
        }
        testsPassed++;
        return true;
    }
    else
    {
        cerr << "Test: " << name << " failed! (results: " << results << "  expected: " << expected << ")" << endl;
        return false;
    }
}


bool TestFramework::testEquality(const std::string name, const bool results, const bool expected)
{
    testsTaken++;
    if (results == expected)
    {
        if (printPassed)
        {
            cerr << "Test: " << name << " passed!" << endl;
        }
        testsPassed++;
        return true;
    }
    else
    {
        cerr << "Test: " << name << " failed! (results: " << (results ? "true" : "false") <<
            "  expected: " << (expected ? "true" : "false") << ")" << endl;
        return false;
    }
}


void TestFramework::printResults() const
{
    cerr << endl;
    cerr << "==================" << endl;
    cerr << "Tests passed: " << testsPassed << endl;
    cerr << "Tests taken: " << testsTaken << endl;
    cerr << "Successful: " << (double)testsPassed/(double)testsTaken*100 << "%" << endl;
}
