// Driver Code
#include "generator.h"
#include "matrix.h"
#include "parser.h"

#include <iostream>

int main() {
    // I'm using extra comments here to help illustrate how to use Parser + Matrix:
    // First we instantiate a new Parser object for a given .csv we wish to read in.
    Parser load_parser = Parser("system_load_mw.csv");

    // Parser automatically figures out how many rows and columns are in our .csv file. This is nice, because then we
    // can allocate our Matrix on the stack since we will know the row/col values before instantiation.
    std::cout << "Rows: " << load_parser.getRow() << "  Cols: " << load_parser.getCol() << std::endl;

    // Next we instantiate an empty Matrix of the type we need. In this case, system_load_mw.csv has a mix of string
    // and numeric data so we need a Matrix of strings (we can parse the load values from string -> double as needed).
    Matrix<std::string> system_load = Matrix<std::string>(load_parser.getRow(), load_parser.getCol());

    // Finally, we pass our instantiated matrix as a reference to our parser which loads the .csv data into the matrix.
    // Unfortunately it's not possible to return a stack allocated Matrix from Parser, so going this route allows us to
    // avoid heap allocation and thus avoid potential memory leaks. In theory it should make accessing data faster too.
    load_parser.loadStringData(system_load);

    // I removed the print function from Parser and made it a Matrix member function.
    // I'll print out the system_load data to show that our data was read in correctly.
    system_load.print();

    // Finally, values at specific indices can be set and retrieved.
    system_load.setValue(0, 0, "This is a test.");

    // Verify that our change was made correctly.
    std::cout << "Value at index 0, 0: " << system_load.getValue(0, 0) << std::endl;

    return 0;
}