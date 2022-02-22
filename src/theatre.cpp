#include "theatre.h"

void initRows(vector<row> &rows)
{
    for (int i = 0; i < rows.size(); i++)
    {
        for (int j = 0; j < MAXCOLS; j++)
            rows[i].seats[j] = false;
        rows[i].available = 5;
    }
}

vector<reservation> allocateSeat(vector<reservation> &reservations, vector<row> &rows)
{
    vector<reservation> unbooked;
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
            string error = "Could not allocate reservation.";
            reservations[reservationItr].seatAllocations.push_back(error);
            continue;
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
    return unbooked;
}