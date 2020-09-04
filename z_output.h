//
// Created by tangb on 3/15/2020.
//

#ifndef LABANDPLANE_Z_OUTPUT_H
#define LABANDPLANE_Z_OUTPUT_H
/*
***** ALL RESULTS ARE VERIFIED ******
//---------------------------------------------------------------------
// Test 1: Test for the lab program
//---------------------------------------------------------------------
log [i]n     log [o]ut       e[x]it
:i
:1 1 12
:i
:1 1 23
:i
:2 3 23
:i
:3 7 45
:i
:3 5 45
:o
:12
:o
:50
:o
:23
:o
:45
:i
:4 1 23
:e

 ------------ RESULTS --------------------
 ===Welcome to CS3A computer lab!===

lab 1|| * * *
lab 2|| * * * *
lab 3|| * * * * *

log [i]n     log [o]ut       e[x]it
i
- Input the lab, the station you want to log in and your id
1 1 12
**The id 12 is successfully logged in to lab  1 and station 1

lab 1|| 12 * *
lab 2|| * * * *
lab 3|| * * * * *

log [i]n     log [o]ut       e[x]it
i
- Input the lab, the station you want to log in and your id
1 1 23
**This station is fulled now, choose another one.

lab 1|| 12 * *
lab 2|| * * * *
lab 3|| * * * * *

log [i]n     log [o]ut       e[x]it
i
- Input the lab, the station you want to log in and your id
2 3 23
**The id 23 is successfully logged in to lab  2 and station 3

lab 1|| 12 * *
lab 2|| * * 23 *
lab 3|| * * * * *

log [i]n     log [o]ut       e[x]it
i
- Input the lab, the station you want to log in and your id
3 7 45
**Invalid lab and station. Try again.
lab 1|| 12 * *
lab 2|| * * 23 *
lab 3|| * * * * *

log [i]n     log [o]ut       e[x]it
i
- Input the lab, the station you want to log in and your id
3 5 45
**The id 45 is successfully logged in to lab  3 and station 5

lab 1|| 12 * *
lab 2|| * * 23 *
lab 3|| * * * * 45

log [i]n     log [o]ut       e[x]it
o
- Input your id to log out
12
**The person with id 12 is successfully logged out.

lab 1|| * * *
lab 2|| * * 23 *
lab 3|| * * * * 45

log [i]n     log [o]ut       e[x]it
o
- Input your id to log out
50
**The system couldn't find this id. 50

lab 1|| * * *
lab 2|| * * 23 *
lab 3|| * * * * 45

log [i]n     log [o]ut       e[x]it
o
- Input your id to log out
23
**The person with id 23 is successfully logged out.

lab 1|| * * *
lab 2|| * * * *
lab 3|| * * * * 45

log [i]n     log [o]ut       e[x]it
o
- Input your id to log out
45
**The person with id 45 is successfully logged out.

lab 1|| * * *
lab 2|| * * * *
lab 3|| * * * * *

log [i]n     log [o]ut       e[x]it
i
- Input the lab, the station you want to log in and your id
4 1 23
**Invalid lab and station. Try again.
lab 1|| * * *
lab 2|| * * * *
lab 3|| * * * * *

log [i]n     log [o]ut       e[x]it
e
Thank you. See you next time.


=========END=========


Process finished with exit code 0

 //---------------------------------------------------------------------
// Test 2: Test for the plane program
//---------------------------------------------------------------------
[r]eserve     [c]ancel      e[x]it
:r
:1 a
:R
:3 B
:R
:5 C
:R
:7 D
:R
:4 F
:R
:9 B
:R
:1 A
:C
:2 B
:C
:3 F
:C
:10 A
:C
:1 A
:C
:3 B
:C
:5 C
:C
:7 D
:E
------------ RESULTS --------------------

Welcome to the Flight reservation system of CS3A Airline.
**Seat reservation map**
1|| A B C D
2|| A B C D
3|| A B C D
4|| A B C D
5|| A B C D
6|| A B C D
7|| A B C D

====Pick one of these options====
[r]eserve     [c]ancel      e[x]it
r
- Choosing the row, the seat you want to reserve
1 a

*The seat at 1a is successfully reserved

1|| X B C D
2|| A B C D
3|| A B C D
4|| A B C D
5|| A B C D
6|| A B C D
7|| A B C D

*Thank you for choosing us.

====Pick one of these options====
[r]eserve     [c]ancel      e[x]it
R
- Choosing the row, the seat you want to reserve
3 B

*The seat at 3B is successfully reserved

1|| X B C D
2|| A B C D
3|| A X C D
4|| A B C D
5|| A B C D
6|| A B C D
7|| A B C D

*Thank you for choosing us.

====Pick one of these options====
[r]eserve     [c]ancel      e[x]it
R
- Choosing the row, the seat you want to reserve
5 C

*The seat at 5C is successfully reserved

1|| X B C D
2|| A B C D
3|| A X C D
4|| A B C D
5|| A B X D
6|| A B C D
7|| A B C D

*Thank you for choosing us.

====Pick one of these options====
[r]eserve     [c]ancel      e[x]it
R
- Choosing the row, the seat you want to reserve
7 D

*The seat at 7D is successfully reserved

1|| X B C D
2|| A B C D
3|| A X C D
4|| A B C D
5|| A B X D
6|| A B C D
7|| A B C X

*Thank you for choosing us.

====Pick one of these options====
[r]eserve     [c]ancel      e[x]it
R
- Choosing the row, the seat you want to reserve
4 F
**Invalid row and seat. Try again.
1|| X B C D
2|| A B C D
3|| A X C D
4|| A B C D
5|| A B X D
6|| A B C D
7|| A B C X

*Thank you for choosing us.

====Pick one of these options====
[r]eserve     [c]ancel      e[x]it
R
- Choosing the row, the seat you want to reserve
9 B
**Invalid row and seat. Try again.
1|| X B C D
2|| A B C D
3|| A X C D
4|| A B C D
5|| A B X D
6|| A B C D
7|| A B C X

*Thank you for choosing us.

====Pick one of these options====
[r]eserve     [c]ancel      e[x]it
R
- Choosing the row, the seat you want to reserve
1 A

*This seat has been reserved. Choose another one.

1|| X B C D
2|| A B C D
3|| A X C D
4|| A B C D
5|| A B X D
6|| A B C D
7|| A B C X

*Thank you for choosing us.

====Pick one of these options====
[r]eserve     [c]ancel      e[x]it
C
- Choosing the row and seat you want to cancel
2 B

*You cannot cancel since this seat has not reserved yet.

1|| X B C D
2|| A B C D
3|| A X C D
4|| A B C D
5|| A B X D
6|| A B C D
7|| A B C X

====Pick one of these options====
[r]eserve     [c]ancel      e[x]it
C
- Choosing the row and seat you want to cancel
3 F
**Invalid row and seat. Try again.
1|| X B C D
2|| A B C D
3|| A X C D
4|| A B C D
5|| A B X D
6|| A B C D
7|| A B C X

====Pick one of these options====
[r]eserve     [c]ancel      e[x]it
C
- Choosing the row and seat you want to cancel
10 A
**Invalid row and seat. Try again.
1|| X B C D
2|| A B C D
3|| A X C D
4|| A B C D
5|| A B X D
6|| A B C D
7|| A B C X

====Pick one of these options====
[r]eserve     [c]ancel      e[x]it
C
- Choosing the row and seat you want to cancel
1 A

*The seat is successfully cancelled.

1|| A B C D
2|| A B C D
3|| A X C D
4|| A B C D
5|| A B X D
6|| A B C D
7|| A B C X

====Pick one of these options====
[r]eserve     [c]ancel      e[x]it
C
- Choosing the row and seat you want to cancel
3 B

*The seat is successfully cancelled.

1|| A B C D
2|| A B C D
3|| A B C D
4|| A B C D
5|| A B X D
6|| A B C D
7|| A B C X

====Pick one of these options====
[r]eserve     [c]ancel      e[x]it
C
- Choosing the row and seat you want to cancel
5 C

*The seat is successfully cancelled.

1|| A B C D
2|| A B C D
3|| A B C D
4|| A B C D
5|| A B C D
6|| A B C D
7|| A B C X

====Pick one of these options====
[r]eserve     [c]ancel      e[x]it
C
- Choosing the row and seat you want to cancel
7 D

*The seat is successfully cancelled.

1|| A B C D
2|| A B C D
3|| A B C D
4|| A B C D
5|| A B C D
6|| A B C D
7|| A B C D

====Pick one of these options====
[r]eserve     [c]ancel      e[x]it
E
*Thank you! See you next time.


=========END=========



Process finished with exit code 0


*/
#endif //LABANDPLANE_Z_OUTPUT_H
