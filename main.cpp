#include <iostream>
#include <fstream>
#include <vector>

#define MAXROWS 10
#define MAXCOLS 20
#define MAXSEATS 50

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
        for (int j = 0; j < MAXCOLS; j++)
            rows[i].seats[j] = false;
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

        File >> tempReservation.id >> tempReservation.totalSeats;
        // cout << tempReservation.id << " " << tempReservation.totalSeats << endl;

        reservations.push_back(tempReservation);
        count++;
    }

    File.close();

    return;
}

void allocateSeat(vector<reservation> &reservations, vector<row> &rows)
{
    int n = reservations.size();
    int allocatedSeats = 0;
    char curRow = 'J';
    int rowItr = 0;
    int seatItr = 0;
    for (int reservationItr = 0; reservationItr < n; reservationItr++)
    {
        int totalSeats = reservations[reservationItr].totalSeats;
        if (totalSeats + allocatedSeats > MAXSEATS)
        {
            cout << "";
            return;
        }
        allocatedSeats += totalSeats;
        while (totalSeats--)
        {
            rows[rowItr].available--;
            rows[rowItr].seats[seatItr] = true;

            string allocatedSeat = curRow + to_string(seatItr);
            reservations[reservationItr].seatAllocations.push_back(allocatedSeat);
            seatItr += 4;
            if (rows[rowItr].available == 0)
            {
                rowItr++;
                if (rowItr % 2 == 0)
                    seatItr = 0;
                else
                    seatItr = 1;
                curRow--;
            }
        }
    }
}
int main(int argc, char **argv)
{
    vector<row> rows(MAXROWS);
    vector<reservation> reservations;
    initRows(rows);
    readInput(argv[1], reservations);
    for (int i = 0; i < reservations.size(); i++)
        cout << reservations[i].id << " " << reservations[i].totalSeats << endl;
    allocateSeat(reservations, rows);
    for (int i = 0; i < reservations.size(); i++)
    {
        for (int j = 0; j < reservations[i].seatAllocations.size(); j++)
        {
            cout << reservations[i].seatAllocations[j] << " ";
        }
        cout << endl;
    }
    return 0;
}