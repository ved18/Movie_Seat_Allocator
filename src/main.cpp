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
    initRows(rows);

    if (!readInput(argv[1], reservations))
        cout << "Could not read input correctly. Please check file name and path";
    for (int i = 0; i < reservations.size(); i++)
        cout << reservations[i].id << " " << reservations[i].totalSeats << endl;
    allocateSeat(reservations, rows);
    printOutput(reservations);
    return 0;
}