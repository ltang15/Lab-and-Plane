//
// Created by tangb on 3/10/2020.
//
#include "2d.h"


int get_rows (int* s)
{
    int row = 0;

    //counting number of elements in the array s
    while (*s != -1 ){
        s++;
        row++;
    }
    return row;
}
bool is_valid (int* sizes, int row, int col){
    int n = get_rows(sizes);

    //check if the row and col exceed what the system has
    if (row >= 0 && col >=0){
        sizes += row;
        if (row < n && col < *sizes)
            return true;
    }
    return false;

}