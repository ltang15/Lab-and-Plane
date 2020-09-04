//
// Created by tangb on 3/10/2020.
//

#ifndef LABANDPLANE_PLANE_H
#define LABANDPLANE_PLANE_H
#include <iostream>
#include "2d.h"

bool** init_plane();
bool reserve(bool** & plane_system, int row, char seat);
bool cancel(bool** & plane_system, int row, char seat);
void plane_menu ();
void plane_demo ();
int num_seat ( char seat);
void show_plane (bool** & plane_system, int* sizes);


#endif //LABANDPLANE_PLANE_H
