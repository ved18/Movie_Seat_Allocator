#include "io.h"
#include <fstream>
#include <iostream>

/*
reads input from the file
input contains reservation orders in ascending order of their timestamps
takes input as reservations array and returns true if file is read properly else returns false
*/

bool readInput(string filename, vector<reservation> &reservations)
{
    ifstream File;

    //open file
    File.open(filename);

    if (!File.is_open())
        return false;

    string line;
    int count = 0;
    while (!File.eof())
    {
        reservation tempReservation;

        //reading input files
        File >> tempReservation.id >> tempReservation.totalSeats;
        // cout << tempReservation.id << " " << tempReservation.totalSeats << endl;

        if (tempReservation.totalSeats <= 0)
        {
            cout << "Invalid entry in  the file." << endl;
            return false;
        }
        reservations.push_back(tempReservation);
        count++;
    }

    File.close();
    return true;
}

/*
creates a file to store the seats allocated for every reservation.
takes input reservations array and prints output in file reservations.txt
*/

bool printOutput(const vector<reservation> reservations)
{
    ofstream File;

    //output file opened
    File.open("reservations.txt");

    if (!File.is_open())
        return false;

    for (int i = 0; i < reservations.size(); i++)
    {
        File << reservations[i].id << " ";
        for (int j = 0; j < reservations[i].seatAllocations.size(); j++)
        {
            //add allocated seats to the file
            File << " " << reservations[i].seatAllocations[j] << " ";
        }
        File << endl;
    }

    File.close();
    return true;
}