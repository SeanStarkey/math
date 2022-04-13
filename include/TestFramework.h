
#ifndef TESTFRAMEWORK_H
#define TESTFRAMEWORK_H

#include <iostream>
#include <string>

class TestFramework
{
private:
    int testsTaken;
    int testsPassed;
    bool printPassed;

public:
    TestFramework(const bool printPassed = false);
    bool evaluate(const std::string name, const std::string results, const std::string expected);
    bool testEquality(const std::string name, const bool results, const bool expected);
    void printResults() const;
};

#endif
