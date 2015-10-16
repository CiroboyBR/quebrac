#include <stdio.h>
#include <allegro.h>

#include <time.h>

#define L1   105
#define L2   205
#define L3   305
#define C1   105
#define C2   205
#define C3   305

BITMAP *camp, *cursor;
//STRUTURAS
struct PECAS{
    int X;
    int Y;
    int P;
    BITMAP *I;
};
struct PECAS P[9];

INICIALIZA_OBJETOS()
{// P = peça
    //p1
    P[0].X=L1;
    P[0].Y=C1;
    P[0].P=0;
    //p2
    P[1].X=L2;
    P[1].Y=C1;
    P[1].P=1 ;
    //p3
    P[2].X=L3;
    P[2].Y=C1;
    P[2].P=2 ;
    //p4
    P[3].X=L1;
    P[3].Y=C2;
    P[3].P=3 ;
    //p5
    P[4].X=L2;
    P[4].Y=C2;
    P[4].P=4 ;
    //p6
    P[5].X=L3;
    P[5].Y=C2;
    P[5].P=5 ;
    //p7
    P[6].X=L1;
    P[6].Y=C3;
    P[6].P=6 ;
    //p8
    P[7].X=L2;
    P[7].Y=C3;
    P[7].P=7 ;
    //p9 = peça do nada
    P[8].X=L3;
    P[8].Y=C3;
    P[8].P=8 ;

}

CARREGA_IMAGENS()
{
    P[0].I=load_bmp("QC/p1.bmp", NULL);
    P[1].I=load_bmp("QC/p2.bmp", NULL);
    P[2].I=load_bmp("QC/p3.bmp", NULL);
    P[3].I=load_bmp("QC/p4.bmp", NULL);
    P[4].I=load_bmp("QC/p5.bmp", NULL);
    P[5].I=load_bmp("QC/p6.bmp", NULL);
    P[6].I=load_bmp("QC/p7.bmp", NULL);
    P[7].I=load_bmp("QC/p8.bmp", NULL);
    P[8].I=load_bmp("QC/p9.bmp", NULL);
    camp=load_bmp("QC/campo.bmp", NULL);
    cursor=load_bmp("QC/c2.bmp", NULL);
    mouse_x_focus= 16;
    mouse_y_focus= 16;
}

void SORTEIA_PECAS(int a){

    int i = rand() % 9;

    P[9].X = P[a].X ; P[9].Y = P[a].Y;
    P[a].X = P[i].X; P[a].Y = P[i].Y;
    P[i].X = P[9].X; P[i].Y = P[9].Y;

}
