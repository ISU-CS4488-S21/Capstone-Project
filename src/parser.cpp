#include "parser.h"

/**
 * Loads in text from a csv file
 *
 * @param filepath: the path of the CSV file
 * @return a matrix containing the comma separate values of each line of the file in each row
 */
Matrix Parser::loadData(const string& filepath) {
    ifstream inFile(filepath);
    string line;

    while (getline(inFile, line)) {     // read whole line of the file
        stringstream ss(line);
        //vec row;
        string data;

        while (getline(ss, data, ',')) {    // read string until a comma is hit
            //row.push_back(stod(data));
        }
        //if (!row.empty()) {
        //    M.push_back(row);
        //}
    }
    return Matrix(2, 2);
}
