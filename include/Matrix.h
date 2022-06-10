
#ifndef MATRIX_H
#define MATRIX_H

#include <string>
#include <vector>

using namespace std;

//
// A Matrix represents an arbitrary sized matrix filled with Elements.
//
// Matrix addition and multiplication are implemented.
//
class Matrix
{
private:
    vector<vector<double>> elements;

public:
    // Create a Matrix by parsing a string representation
    Matrix(const string matrix);

    // Create a Matrix by passing in values representing the internal values
    Matrix(vector<vector<double>>& elements);

    Matrix operator+ (Matrix const& m);
    Matrix operator* (Matrix const& m);

    // This prints the matrix as a list with braces and commas, unless
    // the withSpaces is set. If withSpaces is set, the matrix is
    // displayed with whitespace separating the elements
    string toString(const bool withSpaces=true) const;

};

#endif
