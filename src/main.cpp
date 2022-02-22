#include <iostream>
#include <fstream>
#include <vector>
#include "io.h"
#include "theatre.h"

using namespace std;

int main(int argc, char **argv)
{
    vector<row> rows(MAXROWS);
    vector<reservation> reservations;

    //initialising seats
    initRows(rows);

    if (argc < 1)
        cout << "Too less arguments. Please provide input file path." << endl;

    //read input file
    if (!readInput(argv[1], reservations))
        cout << "Could not read input correctly. Please check file name and path";

    // for (int i = 0; i < reservations.size(); i++)
    //     cout << reservations[i].id << " " << reservations[i].totalSeats << endl;

    //allocate optimal seats for all reservations
    allocateSeat(reservations, rows);

    //create output file
    if (!printOutput(reservations))
        cout << "Could not write the output correctly. Please try again." << endl;
    cout << "Pease find the output in reservations.txt" << endl;

    return 0;
}