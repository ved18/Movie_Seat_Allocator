#include <iostream>
#include <fstream>
#include <vector>

#define MAXROWS 10
#define MAXCOLS 20
#define MAXRESERVATIONS 50

using namespace std;

typedef struct reservation
{
    string id;
    int totalSeats;
    vector<string> seatAllocations;
} reservation;

typedef struct row
{
    bool seats[MAXCOLS];
    int available;
} row;

void initRows(vector<row> &rows)
{
    for (int i = 0; i < rows.size(); i++)
    {
        for (int i = 0; i < MAXCOLS; i++)
            seats[i] = false;
        rows[i].available = 5;
    }
}

void init(int seats[][MAXCOLS])
{
    for (int i = 0; i < MAXROWS; i++)
    {
        for (int j = 0; j < MAXCOLS; j++)
        {
            seats[i][j] = 0;
        }
    }
}

void readInput(string filename, vector<reservation> &reservations)
{
    ifstream File;
    File.open(filename);
    if (!File.is_open())
        cout << "File could not be opened correctly. Please try again." << endl;

    string line;
    int count = 0;
    while (!File.eof())
    {
        reservation tempReservation;
        if (count > MAXRESERVATIONS)
        {
            cout << "Max reservation capacity reached." << endl;
            break;
        }
        File >> tempReservation.id >> tempReservation.totalSeats;
        // cout << tempReservation.id << " " << tempReservation.totalSeats << endl;

        reservations.push_back(tempReservation);
        count++;
    }

    File.close();

    return;
}

// void allocateSeat(vector<reservation> &reservations, vector<row> &rows)
// {
//     int n = reservations.size();
//     for (int reservationItr = 0; reservationItr < n; reservationItr++)
//     {
//         int totalSeats = reservations[reservationItr].totalSeats;
//         char temp = 'J';
//         int rowItr = 0;

//         for (int rowItr = 0; rowItr < rows.size(); rowItr++)
//         {
//             int seatItr;
//             if (rowItr % 2 == 0)
//                 seatItr = 0;
//             else
//                 seatItr = 1;
//             while(true)
//             {
//                 if (rows[rowItr].seats[seatItr] == false)
//                 {
//                     string tempSeat = temp + seatItr.toString();
//                     reservations[reservationItr].seatAllocations.push_back(tempSeat);
//                 }
//                 seatItr+=2;
//             }

//         }
//     }
// }
int main(int argc, char **argv)
{
    vector<row> rows(MAXROWS);
    vector<reservation> reservations;
    initRows(rows);
    readInput(argv[1], reservations);
    for (int i = 0; i < reservations.size(); i++)
        cout << reservations[i].id << " " << reservations[i].totalSeats << endl;
    return 0;
}