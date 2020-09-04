//
// Created by tangb on 3/10/2020.
//

#ifndef LABANDPLANE_LAB_H
#define LABANDPLANE_LAB_H
#include <iostream>
#include "2d.h"

int** init_lab();
bool login(int** & lab_system, int lab, int station, int id);
bool logout(int** & lab_system, int* sizes, int value);
void lab_menu ();
void lab_demo ();
void show_lab ( int**& lab_system, int* sizes);






#endif //LABANDPLANE_LAB_H
