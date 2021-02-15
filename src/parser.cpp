#include "parser.h"


// Just an example for how to implement class member functions
// The definition exists under parser.h

/**
 * Loads in text from a csv file
 *
 * @param filepath: the path of the CSV file
 * @return a matrix containing the comma separate values of each line of the file in each row
 */
matrix Parser::loadData(const string& filepath) {
    ifstream inFile(filepath);
    string line;
    matrix M;

    while (getline(inFile, line)) {     // read whole line of the file
        stringstream ss(line);
        vec row;
        string data;

        while (getline(ss, data, ',')) {    // read string until a comma is hit
            row.push_back(stod(data));
        }
        if (!row.empty()) {
            M.push_back(row);
        }
    }
    return M;
}

/**
 * Writes out contents of matrix created from loadData()
 *
 * @param M
 */
void Parser::displayData(const matrix &M) {
    const int width = 12;

    for (const auto& row : M) {
        for ( auto entry : row) {
            cout << setw(width) << entry << ' ';
            cout << '\n';
        }
    }
}

