/* 
 * Project: Lab and plane
 * Purpose: Using 1D and 2D library to build a lab application and a plane application
 * Notes: Inputting the option in the menu; the sizes and required information for each program:
            lab (number of lab, number of station and ID)
            plane (number of row, letter of seat)
*/
#include <iostream>
#include "lab.h"
#include "plane.h"


int main() {
    cout << endl << endl;
    lab_demo ();// the lab program
    //plane_demo ();// the plane program
    cout << endl << endl << "=========END=========" << endl << endl;
    return 0;
}
