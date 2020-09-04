//
// Created by tangb on 3/17/2020.
//

#ifndef LABANDPLANE_1D_H
#define LABANDPLANE_1D_H
#include <iostream>
using namespace std;

template <typename T>
T* allocate1 (int size);

template <typename T>
void init1 (T* arr, int size, T value);

template <typename T>
T* find (T* arr, int size, const T& value);

template <typename T>
void print1  (T* arr, int size);

template <typename T>
void deallocate (T*arr);



template <typename T>
T* allocate1 (int size){
    return new T [size];
}

template <typename T>
void init1 (T* arr, int size, T value){
    //initialize 1d array
    T* walker = arr;
    for (int i =0; i < size; i++){
        *walker = value;
        walker ++;
    }
}

template <typename T>
T* find (T* arr, int size, const T& value) {
    //The function is looking for the address of a specific value and return the pointer

    T* walker = arr;

    for (int i = 0; i < size; i++, walker++){
        if (*walker == value)
            return walker; // return the address if the value is found
    }
    return nullptr;// if the value cannot be found
}
template <typename T>
void print1  (T* arr, int size){
    // Printing function
    T* walker = arr;

    // The loop is used to print all the elements in the array
    for ( int i =0; i < size; i++){

        cout << *walker << " ";
        walker++;
    }

}

template <typename T>
void deallocate (T*arr){
    delete [] arr;
}


#endif //LABANDPLANE_1D_H
