//
// Created by tangb on 3/10/2020.
//
#include "plane.h"

bool empty = true;//declare and initialize the bool variable

bool** init_plane(){
    int sizes[] = {4, 4, 4, 4, 4, 4, 4,-1};
    bool** plane = allocate <bool> (sizes);
    init (plane, sizes, empty); // initialize the boolean array; all seats are empty at the beginning
    return plane;
}
void plane_menu (){
    cout << endl << "====Pick one of these options====" << endl;
    cout<<"[r]eserve     [c]ancel      e[x]it " << endl;
}
int num_seat (char seat){
    // convert from char into int since the function in 2d library take col as integer, not char
    int num;

    switch (seat){
        case 'a':
        case 'A':
            num = 0;
            break;
        case 'b':
        case 'B':
            num = 1;
            break;
        case 'c':
        case 'C':
            num = 2;
            break;
        case 'd':
        case 'D':
            num = 3;
            break;
        default:
            break;
    }
    return num; // return number for its corresponding seat

}


bool reserve(bool** & plane_system, int row, char seat){

    int col = num_seat (seat);
    bool booked = read (plane_system, row, col);

    // When the row and seat are valid in the seat map
    if (booked == empty) {
        write(plane_system, row, col, !empty);// the seat is reserved when it is available
        return true;
    }
    return false;

}


bool cancel(bool** & plane_system, int row, char seat){
    int col = num_seat (seat);
    bool found =  read (plane_system, row, col);

    if (found == !empty) {
        // The seat can be canceled if it has been reserved
        write(plane_system, row, col, empty); // empty the seat
        return true;
    }
    return false;

}


void show_plane (bool** & plane_system, int* sizes){
    int n = get_rows(sizes);
    bool** walker1 = plane_system;

    for (int i=0; i < n; i++){
        bool* walker2 = *walker1;
        cout << i + 1 << "||"; //number the row to make it easier for choosing the seat

        for (int j=0; j < *sizes; j++){
            if (*walker2 == !empty)
                // Print X for the reserved seat
                cout << " X";
            else
                // Print the letter A B, C... for the empty seat
                cout << " " << static_cast <char> ('A' + j);
            walker2 ++;
        }
        walker1++;
        sizes++;
        cout << endl;
    }

}


void plane_demo (){
    char ans;
    int row, col;
    char seat;
    bool done = false;
    int sizes[] = {4, 4, 4, 4, 4, 4, 4, -1};
    bool **plane_system = init_plane();


    cout <<"Welcome to the Flight reservation system of CS3A Airline. " << endl;
    cout << "**Seat reservation map**" << endl;
    show_plane (plane_system, sizes);// Print the initial map


    do {
        plane_menu();
        cin >> ans;

        switch (ans) {
            case 'r':
            case 'R':{
                // reserving option
                cout << "- Choosing the row, the seat you want to reserve" << endl;
                cin >> row >> seat;
                col = num_seat(seat);
                bool valid =  is_valid (sizes, row-1, col);

                if (valid){

                    if (reserve(plane_system, row - 1, seat))
                        cout << endl << "*The seat at " << row << seat << " is successfully reserved" << endl << endl;
                    else
                        cout << endl << "*This seat has been reserved. Choose another one." << endl << endl;
                }
                else
                    cout << "**Invalid row and seat. Try again." << endl;

                show_plane(plane_system, sizes);
                cout << endl<< "*Thank you for choosing us." << endl;
                break;
            }
            case 'c':
            case 'C':{
                //canceling option
                cout << "- Choosing the row and seat you want to cancel" << endl;
                cin >> row >> seat;
                col = num_seat(seat);
                bool valid =  is_valid (sizes, row-1, col);
                if (valid) {
                    if (cancel(plane_system, row - 1, seat))
                        cout << endl << "*The seat is successfully cancelled." << endl << endl;
                    else
                        cout << endl << "*You cannot cancel since this seat has not reserved yet. " << endl << endl;
                }
                else
                    cout << "**Invalid row and seat. Try again." << endl;

                show_plane(plane_system, sizes);
                break;
            }
            case 'e':
            case 'E':
                //exit the program
                done = true;
                cout << "*Thank you! See you next time. " << endl;
                break;
        }
    }
    while (!done);// The program is continued until we choose exit
    deallocate(plane_system, sizes);// free the 2D array
}