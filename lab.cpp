//
// Created by tangb on 3/10/2020.
//
#include <iostream>
#include "2d.h"
#include "lab.h"


int** init_lab (){
    int sizes[] = {4,4,5,-1};
    int** lab = allocate <int> (sizes);
    init(lab, sizes, -1);// initialize the lab; all spots are empty with the value -1 on the map
    return lab;
}
void lab_menu (){
    cout<<endl << "log [i]n     log [o]ut       e[x]it " << endl;

}

bool login (int** & lab_system, int lab, int station, int id) {

    int full = read(lab_system, lab, station);

    if (full < 0) {
        // log in an ID to the specific lab and station if that spot is empty
        write(lab_system, lab, station, id);
        return true;
    }
    return false;

}

bool logout (int**& lab_system, int* sizes, int id) {
    int* found = search(lab_system, sizes, id);// since the search function returns a pointer, then pointer is used here

    if (found != nullptr) {
        *found = -1;//when id is found, re-initialize that location; means that spot is now empty
        return true;
    }
    return false;

}

void show_lab ( int**& lab_system, int* sizes){
    //Pointers are used here to display the lab as what I want
    // If I use the print function in 2D; it only prints out the array

    int n = get_rows (sizes);
    int** walker1 = lab_system;
    for (int i = 0; i < n; i++){
        int*walker2 = *walker1;
        cout << "lab " << i + 1 << "|| ";

        for (int j = 0; j < *sizes; j++) {

            if (*walker2 != -1) {
                cout << *walker2 << " ";
            }
            else
                cout << "*" <<" ";
            walker2++;
        }
        walker1++;
        sizes++;
        cout << endl;
    }

}

void lab_demo () {

    char ans;
    int lab, station, id;
    int sizes[] = {3, 4, 5, -1};// declare and initialize the number of elements for each row

    bool done = false;


    cout << "===Welcome to CS3A computer lab!===" << endl << endl;
    int **lab_system = init_lab();
    show_lab(lab_system, sizes);


    // The loop is for running program; it will stop when we choose exit
    do {
        lab_menu();
        cin >> ans;

        switch (ans) {
            case 'i': {
                //logged in to a specific station and lab getting from user input

                cout << "- Input the lab, the station you want to log in and your id" << endl;
                cin >> lab >> station >> id;
                bool valid =  is_valid (sizes, lab -1, station -1);

                //check if the station and lab input is valid to continue the log in process
                if (valid){

                    //check if that station of that lab is available to log in or not
                    if ( login(lab_system, lab -1, station -1, id)){
                        cout << "**The id " << id << " is successfully logged in to lab  " << lab << " and station " << station << endl << endl;
                    }
                    else
                        cout << "**This station is fulled now, choose another one." << endl << endl;
                }
                else
                    cout << "**Invalid lab and station. Try again." << endl;

                show_lab(lab_system, sizes);
                break;
            }
            case 'o': {
                // logged out an id out of the system
                cout << "- Input your id to log out" << endl;
                cin >> id;

                // check if the id is available to log out
                if (logout(lab_system, sizes, id))
                    cout << "**The person with id " << id << " is successfully logged out." << endl << endl;

                else
                    cout << "**The system couldn't find this id. " << id << endl<< endl;

                show_lab(lab_system, sizes);
                break;
            }
            case 'e':
                // exit program
                done = true;
                cout << "Thank you. See you next time." << endl;
                break;

        }
    }
    while (!done);
    deallocate(lab_system, sizes);
}
