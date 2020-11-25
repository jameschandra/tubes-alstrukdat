/* MODUL AKSI PREPARATION */

#ifndef MAINAKSI_H
#define MAINAKSI_H

#include "../boolean.h"
#include "../array/array.h"
#include "../mesin/mesinkar.h"
#include "../mesin/mesinkata.h"
#include "../Tree/bintree.h"
#include "../stack/stack.h"
#include "../Jam/jam.h"
#include "../matriks/matriks.h"
#include "../point/point.h"
#include "../Queue/prioqueue.h"

/* ********** AKSI ********** */
void Serve (Queue *Q, ListWahana *LWahana, Kata NamaWahana,TabInt *Kapasitas);

void Repair(MATRIKS *Map, ListWahana *LWahana);

void Detail(MATRIKS *Map, ListWahana LWahana);

/* ********** OFFICE ********** */
void MenuOffice(MATRIKS *Map, ListWahana *LWahana);

void DetailsOffice(ListWahana *LWahana);

void ReportOffice(ListWahana *LWahana);

#endif