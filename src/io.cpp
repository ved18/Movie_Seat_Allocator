#include "io.h"
#include <fstream>
#include <iostream>

bool readInput(string filename, vector<reservation> &reservations)
{
    ifstream File;
    File.open(filename);
    if (!File.is_open())
        return false;

    string line;
    int count = 0;
    while (!File.eof())
    {
        reservation tempReservation;

        File >> tempReservation.id >> tempReservation.totalSeats;
        // cout << tempReservation.id << " " << tempReservation.totalSeats << endl;

        reservations.push_back(tempReservation);
        count++;
    }

    File.close();

    return true;
}

bool printOutput(const vector<reservation> reservations)
{
    ofstream File;
    File.open("reservations.txt");
    if (!File.is_open())
        return false;

    for (int i = 0; i < reservations.size(); i++)
    {
        File << reservations[i].id << " ";
        for (int j = 0; j < reservations[i].seatAllocations.size(); j++)
        {
            File << " " << reservations[i].seatAllocations[j] << " ";
        }
        File << endl;
    }

    File.close();
    return true;
}