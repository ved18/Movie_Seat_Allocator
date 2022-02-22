## Problem Statement:

Implement an algorithm for assigning seats within a movie theater to
fulfill reservation requests. Design and write a seat assignment
program to maximize both customer satisfaction and customer
safety.

## Assumptions:

1. Seats would be allocated on first come first serve basis for customer satisfaction.
2. The movie theater has the seating arrangement of 10 rows x 20 seats.
3. For the purpose of public safety, we assume that a buffer of three
   seats and/or one row is required.
4. Seats far from the screen are assumed to provide a better experience.
5. Screen is nearest to row A and farthest to row J.
6. Middle seats provide a better experience than the corner seats.
7. Priority is given to the farther seats and then the middle seats.
8. If seats are not available for current reservation order, but we can accomodate next order then we allocate seats to next reservation even if the latter has higher timestamp.

## Solution:

The algorithm assigns seats greedily to the customers on basis of first come first serve strategy.
The customer who has booked the tickets first will get the better seat i.e far from the screen and in middle of the row to get a better view.

## Building the code:

1. Build

```bash
make
```

2. Execute

```bash
./main <path_to_text_file>
```

Example:

```bash
./main tests/test1
```

3. Clean

```
make clean
```

## NOTE:

All test files are present in the tests directory
The output is present in reservations.txt in the root directory.
