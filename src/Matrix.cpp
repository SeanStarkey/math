
#include "Matrix.h"

#include <sstream>
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

Matrix::Matrix(const string matrix)
{
    // Split into rows
    vector<string> rows;
    size_t last = 0;
    size_t next = 0;
    while ((next = matrix.find('\n', last)) != string::npos)
    {
        string row = matrix.substr(last, next-last);
        if (row.size() > 0)
        {
            rows.push_back(row);
        }
        last = next + 1;
    }
    string row = matrix.substr(last);
    if (row.size() > 0)
    {
        rows.push_back(matrix.substr(last));
    }

    // Extract the elements
    vector<vector<double>> vve(rows.size());
    for (unsigned r=0; r<rows.size(); r++)
    {
        last = 0;
        next = 0;
        while ((next = rows[r].find(' ', last)) != string::npos)
        {
            string ele = rows[r].substr(last, next-last);
            if (ele.size() > 0)
                vve[r].push_back(stod(ele));
            last = next + 1;
        }
        string ele = rows[r].substr(last);
        if (ele.size() > 0)
            vve[r].push_back(stod(ele));
    }
    elements = vve;
}


Matrix::Matrix(vector<vector<double>>& in_elements)
{
    elements = in_elements;
}


string Matrix::toString(const bool withSpaces) const
{
    stringstream results;

    if (elements.size() == 0)
        return "";
    if (elements[0].size() == 0)
        return "";

    if (withSpaces)
    {
        size_t numCol = elements[0].size();
        vector<size_t> widths(numCol);
        for (size_t r=0; r<elements.size(); r++)
        {
            for (size_t c=0; c<elements[0].size(); c++)
            {
                string e = to_string(elements[r][c]);
                if (widths[c] < e.length())
                {
                    widths[c] = e.length();
                }
            }
        }
        for (size_t r=0; r<elements.size(); r++)
        {
            for (size_t c=0; c<elements[0].size(); c++)
            {
                cout << setw(widths[c]) << elements[r][c];
                cout << "  ";
            }
            cout << endl;
        }
    }
    else
    {
        results << "{";
        for (unsigned r=0; r<elements.size(); r++)
        {
            if (r != 0)
            {
                results << ",";
            }
            results << "{";
            for (unsigned c=0; c<elements[0].size(); c++)
            {
                if (c != 0)
                {
                    results << ",";
                }
                results << elements[r][c];
            }
            results << "}";
        }
        results << "}";
    }

    return results.str();
}


Matrix Matrix::operator+ (Matrix const& m)
{
    if (elements.size() != m.elements.size())
        throw invalid_argument("Matrix dimensions not the same");
    if (elements[0].size() != m.elements[0].size())
        throw invalid_argument("Matrix dimensions not the same");

    size_t numRows = elements.size();
    size_t numCols = elements[0].size();

    vector<vector<double>> vve(numRows);
    for (size_t r=0; r<numRows; r++)
    {
        for (size_t c=0; c<numCols; c++)
        {
            double e = elements[r][c] + m.elements[r][c];
            vve[r].push_back(e);
        }
    }

    return Matrix(vve);
}


Matrix Matrix::operator* (Matrix const& m)
{
    size_t numRowsLHS = elements.size();
    size_t numColsLHS = elements[0].size();
    size_t numRowsRHS = m.elements.size();
    size_t numColsRHS = m.elements[0].size();

    if (numColsLHS != numRowsRHS)
        throw invalid_argument("Matrix dimensions not compatible");

    vector<vector<double>> vve(numRowsLHS);
    for (size_t rowLHS=0; rowLHS<numRowsLHS; rowLHS++)
    {
        for (size_t colRHS=0; colRHS<numColsRHS; colRHS++)
        {
            double e = 0;
            for (size_t x=0; x<numColsLHS; x++)
            {
                e = e + elements[rowLHS][x] * m.elements[x][colRHS];
            }
            vve[rowLHS].push_back(e);
        }
    }

    return Matrix(vve);
}

