#ifndef THEATRE_H
#define THEATRE_H

#include <string>
#include <vector>

#define MAXROWS 10
#define MAXCOLS 20
#define MAXSEATS 50

using namespace std;

//data structure to store each row info in the theatre.
typedef struct row
{
    bool seats[MAXCOLS];
    int available; //no of available seats in the row
} row;

//data structure to store reservation details
//reservation id, total seats to be booked, Final seats allocated
typedef struct reservation
{
    string id;
    int totalSeats;
    vector<string> seatAllocations;
} reservation;

void initRows(vector<row> &rows);
void allocateSeat(vector<reservation> &reservations, vector<row> &rows);

#endif