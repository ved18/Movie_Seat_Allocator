#ifndef THEATRE_H
#define THEATRE_H

#include <string>
#include <vector>

#define MAXROWS 10
#define MAXCOLS 20
#define MAXSEATS 50

using namespace std;

typedef struct row
{
    bool seats[MAXCOLS];
    int available;
} row;

typedef struct reservation
{
    string id;
    int totalSeats;
    vector<string> seatAllocations;
} reservation;

void initRows(vector<row> &rows);
vector<reservation> allocateSeat(vector<reservation> &reservations, vector<row> &rows);
#endif