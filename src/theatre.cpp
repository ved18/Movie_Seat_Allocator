#include "theatre.h"

//initialises the rows of the theatre
void initRows(vector<row> &rows)
{
    for (int i = 0; i < rows.size(); i++)
    {
        for (int j = 0; j < MAXCOLS; j++)
            rows[i].seats[j] = false;
        rows[i].available = 5;
    }
}

/*
allocate seat takes input as array of reservations and rows in the theatre.
It allocates seats to the reservation orders on FCFS basis.
*/
void allocateSeat(vector<reservation> &reservations, vector<row> &rows)
{
    int n = reservations.size();
    int allocatedSeats = 0; //total seats allocated at any point
    char curRow = 'J';      //to keep track of row alphabet
    int rowItr = 0;
    int seatItr = 9;

    //looping through all the resevation orders one by one to allocate seats
    for (int reservationItr = 0; reservationItr < n; reservationItr++)
    {
        int totalSeats = reservations[reservationItr].totalSeats;
        //if total seats to be booked are more than remaining seats
        //cannot allocate seats move on to next order

        if (totalSeats + allocatedSeats > MAXSEATS)
        {
            string error = "Could not allocate reservation.";
            reservations[reservationItr].seatAllocations.push_back(error);
            continue;
        }

        allocatedSeats += totalSeats; //increment allocated seats

        //loop to allocate seats for the reservation
        while (totalSeats--)
        {
            //if available is even => subtract else add rowItr -+ 4*(5-available)
            //this is to calculate the seat iterator for allocating best available seat.
            if (rows[rowItr].available % 2 == 0)
            {
                seatItr -= 4 * (5 - rows[rowItr].available);
            }
            else
            {
                seatItr += 4 * (5 - rows[rowItr].available);
            }
            rows[rowItr].seats[seatItr] = true;
            rows[rowItr].available--; //decrement available seats in the row

            //add allocated seat to the reservations
            string allocatedSeat = curRow + to_string(seatItr);
            reservations[reservationItr].seatAllocations.push_back(allocatedSeat);

            //if no seat available in the current row move to next row
            if (rows[rowItr].available == 0)
            {
                rowItr++;
                if (rowItr % 2 == 0)
                    seatItr = 9;
                else
                    seatItr = 10;
                curRow--;
            }
        }
    }
}