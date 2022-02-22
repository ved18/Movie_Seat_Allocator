#ifndef IO_H

#define IO_H
#include "theatre.h"

bool readInput(string filename, vector<reservation> &reservations);
bool printOutput(const vector<reservation> reservations);

#endif