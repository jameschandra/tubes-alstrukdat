/* Body ADT Jam */

#include "jam.h"
#include <stdio.h>

/*------------validator Jam------------*/
boolean IsJAMValid (int H, int M, int S)
/* Mengirim true jika H,M,S dapat membentuk Jam yang valid */
{ /* Kamus Lokal */
/* Algoritma */
    return ((H >= 0 && H <= 23) && (M >= 0 && M <= 59) &&
    (S >= 0 && S <= 59));
}

JAM MakeJAM(int HH, int MM, int SS)
/* Membentuk Jam dari H, M, S yg valid */
{ /* Kamus Lokal */
    JAM J1;
    /* Algoritma */
    Hour(J1) = HH;
    Minute(J1) = MM;
    Second(J1) = SS;
    return J1;
}

void BacaJAM(JAM * J)
/* I.S. : J tak terdefinisi */
/* F.S. : J terdefinisi dan merupakan jam valid */
/* Proses : mengulang baca komponen H, M, S sehingga membentuk J yang valid */
{  /* Kamus Lokal */
    int HH, MM, SS;
    /* Algoritma */
    scanf("%d %d %d",&HH,&MM,&SS);
    while(!IsJAMValid(HH,MM,SS)){
        printf("Jam tidak valid\n");
        scanf("%d %d %d",&HH,&MM,&SS);
    }
    *J = MakeJAM(HH,MM,SS);
}

void TulisJAM (JAM J)
{   /* I.S. : J sembarang*/
    /* F.S. : J ditulis ke layar dengan format HH:MM:SS */
    /* Proses : Menulis ke layar */
    /* Kamus lokal */
    /* Algoritma */
    printf("%d:%d:%d",Hour(J),Minute(J),Second(J));
}

long JAMToDetik (JAM J)
{   /* Konversi Jam menjadi detik */
    /* Kamus Lokal */
    /* Algoritma */
    return(3600 * Hour(J) + 60 * Minute(J) + Second(J));
}

JAM DetikToJAM (long N)
{   /* Konversi detik ke Jam */
    /* Kamus Lokal */
    int sisa;
    JAM JOut;
    /* Algoritma */
    N = N % 86400; // harus ditambah ini agar valid
    Hour(JOut) = N / 3600;
    sisa = N % 3600;
    Minute(JOut) = sisa / 60;
    Second(JOut) = sisa % 60;
    return JOut;
}

boolean JEQ (JAM J1, JAM J2)
{
    return (JAMToDetik(J1)==JAMToDetik(J2));
}

boolean JNEQ (JAM J1, JAM J2)
{
    return (JAMToDetik(J1)!=JAMToDetik(J2));
}

boolean JLT (JAM J1, JAM J2)
{
    return (JAMToDetik(J1)<JAMToDetik(J2));
}

boolean JGT (JAM J1, JAM J2)
{
    return (JAMToDetik(J1)>JAMToDetik(J2));
}

JAM NextDetik (JAM J)
{/* Mengirim 1 detik setelah J dalam bentuk JAM */
    return (DetikToJAM(JAMToDetik(J)+1));
}

JAM NextNDetik (JAM J, int N)
{/* Mengirim N detik setelah J dalam bentuk JAM */
    return (DetikToJAM(JAMToDetik(J)+N));
}

JAM PrevDetik (JAM J)
{/* Mengirim 1 detik sebelum J dalam bentuk JAM */
    return (DetikToJAM(JAMToDetik(J)-1));
}

JAM PrevNDetik (JAM J, int N)
{/* Mengirim N detik sebelum J dalam bentuk JAM */
    return (DetikToJAM(JAMToDetik(J)-N));
}

long Durasi (JAM JAw, JAM JAkh)
{
    if(JAMToDetik(JAw)>JAMToDetik(JAkh))
    {
        return (JAMToDetik(JAkh)+86400-JAMToDetik(JAw));
    }
    else
    {
        return (JAMToDetik(JAkh)-JAMToDetik(JAw));
    }
    
}