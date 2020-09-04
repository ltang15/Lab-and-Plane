//
// Created by tangb on 3/10/2020.
//

#ifndef LABANDPLANE_2D_H
#define LABANDPLANE_2D_H
#include <iostream>
#include "1d.h"
using namespace std;


//---------NON-TEMPLATED FUNCTION--------
int get_rows (int* s);
bool is_valid (int* sizes, int row, int col);
//---------------TEMPLATED FUNCTIONS-------------
template <typename T>
T** allocate (int* sizes);

template <typename T>
void init (T** twoD, int* sizes, T value);

template <typename T>
void print (T** twoD, int* sizes);

template <typename T>
void write (T** twoD, int row, int col, T value);

template <typename T>
T read (T** twoD, int row, int col);

template <typename T>
T& get (T** twoD, int row, int col);

template <typename T>
T* search (T** twoD, int* sizes, const T& value);



template <typename T>
void deallocate (T** twoD, int* sizes);



//****************************************************

template <typename T>
T** allocate (int* sizes)
{

    int n = get_rows (sizes);

    T** twoD = new T* [n + 1]; // creating the array of pointers
    T** walker= twoD;

    //creating 1D array for each row
    for (int i = 0; i < n; i++){
        T* oneD = allocate1 <T> (*sizes);
        *walker = oneD;
        walker ++;
        sizes ++;

    }
    *walker = NULL;

    return twoD;
}

template <typename T>
void init (T** twoD, int* sizes, T value){

    int n = get_rows (sizes);
    T** walker1 = twoD; // walker1 walks vertically (rows)

    //initialize the 2D array, set every elements equal to a value

    for (int i=0; i < n; i++){
        T* walker2 = *walker1; // walker2 walker horizontally (cells of each row)
        init1 (walker2, *sizes, value);
        sizes++;//moves to the next element of the array sizes containing number of elements in each row
        walker1++;
    }

}

template <typename T>
void print (T** twoD, int* sizes) {
    T **walker1 = twoD;

    int n = get_rows(sizes);

    //Printing the 2D array
    for (int i = 0; i < n ; i++) {
        T *walker2 = *walker1;
        print1(walker2, *sizes);
        sizes++;
        walker1++;
        cout << endl;
    }
}

template <typename T>
T& get (T** twoD, int row, int col){

    T** row_walker = twoD;
    T** new_row = row_walker + row;// moves the walker to the desired row
    T* col_walker = *new_row;
    T* new_cell = col_walker + col;// moves the walker to the desires cell
    return  *new_cell;//return the variable at a given row and given column
}

template <typename T>
void write (T** twoD, int row, int col, T value){

    get (twoD, row, col) = value;// storing the value at one variable

}

template <typename T>
T read (T** twoD, int row, int col){
    return get(twoD, row, col);
}

template <typename T>
T* search (T** twoD, int* sizes, const T& value){
    T** walker1 = twoD;

    int n = get_rows(sizes);
    // searching for the variable holding that value

     for (int i = 0; i < n; i++) {
         T *walker2 = *walker1;
         T* found = find(walker2, *sizes, value);
         if (found != nullptr){
             return found;
         }
         sizes++;
         walker1++;
     }
     return nullptr;


}


template <typename T>
void deallocate (T** twoD, int* sizes){
    T** walker = twoD;
    int n = get_rows(sizes);

    //deleting the dynamic array to return the memory; deallocate the 2D array
    for (int i =0; i < n; i++){
       deallocate (*walker);
       walker++;
    }
    delete [] walker;
}



#endif //LABANDPLANE_2D_H
