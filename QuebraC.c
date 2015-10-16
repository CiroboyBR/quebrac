#include <allegro.h>
#include "QC_ENGINE.h"
#include <math.h>

int campo [3][3];
BITMAP *buffer; // double buffer
BITMAP *pecas[9];

int main() {
// Inicializa a biblioteca Allegro
	allegro_init();
// Inicializa o manipulador de teclado
	install_keyboard();
	 install_mouse();
// Define a profundidade de cores para 16 bits (high color)
	set_color_depth(32);
// Define a resolução de 640x480 no modo automatico
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);

    CARREGA_IMAGENS();
    buffer = create_bitmap(800,600);
    INICIALIZA_OBJETOS();
// Fica em loop até pressionar a tecla ESC
	while(!key[KEY_ESC])
	{
        MOVE_PECAS();
        DESENHA_OBJETOS();
// Espera a sincronização vertical
		vsync();
		DUPLO_BUFFER();
	}
    FINALIZA();
	// Sai do programa
	allegro_exit();
	return 0;
}
// Esta macro converte o main para WinMain()
END_OF_MAIN();

DESENHA_OBJETOS()
{
//    blit(camp, buffer, 0, 0, 100, 100, 310, 310);
    blit(P[0].I, buffer, 0, 0,P[0].X , P[0].Y, 100, 100);
    blit(P[1].I, buffer, 0, 0,P[1].X , P[1].Y, 100, 100);
    blit(P[2].I, buffer, 0, 0,P[2].X , P[2].Y, 100, 100);
    blit(P[3].I, buffer, 0, 0,P[3].X , P[3].Y, 100, 100);
    blit(P[4].I, buffer, 0, 0,P[4].X , P[4].Y, 100, 100);
    blit(P[5].I, buffer, 0, 0,P[5].X , P[5].Y, 100, 100);
    blit(P[6].I, buffer, 0, 0,P[6].X , P[6].Y, 100, 100);
    blit(P[7].I, buffer, 0, 0,P[7].X , P[7].Y, 100, 100);
    blit(P[8].I, buffer, 0, 0,P[8].X , P[8].Y, 100, 100);
    masked_blit(cursor, buffer, 0, 0,mouse_x , mouse_y, 32, 32);
}

FINALIZA()
{
int n;
    for (n=0;n>=9;n++){
          destroy_bitmap(pecas[n]);
    }
    destroy_bitmap(camp);
}

DUPLO_BUFFER()
{
// DUPLO BUFFER, pra imagem não tremer etc...
      blit (buffer, screen, 0, 0, 0, 0, 600, 480);
      clear(buffer);
}

MOVE_PECAS()
{
    if (mouse_b & 1){
        if (mouse_x >= P[0].X-10 && mouse_x <= P[0].X+ 80 && mouse_y >= P[0].Y-10 && mouse_y <= P[0].Y+ 80 &&
            (DIF_PONTOS(P[0].X, P[8].X) == 0 && DIF_PONTOS( P[0].Y, P[8].Y) == 100 || DIF_PONTOS( P[0].X, P[8].X) == 100 && DIF_PONTOS( P[0].Y, P[8].Y) == 0) ){
             // Variáveis temporárias
             P[9].X = P[0].X; P[9].Y = P[0].Y;
             //Peça vai pra onde está vazio
             P[0].X = P[8].X; P[0].Y = P[8].Y;
             //Vazio vai pra onde estava a peça sacou? ;D
             P[8].X = P[9].X; P[8].Y = P[9].Y;

             textprintf_ex(buffer, font, 10, 15, makecol(255, 100, 200),-1, "Peca 1");
             }
         if (mouse_x >= P[1].X-10 && mouse_x <= P[1].X+ 80 && mouse_y >= P[1].Y-10 && mouse_y <= P[1].Y+ 80 &&
            (DIF_PONTOS(P[1].X, P[8].X) == 0 && DIF_PONTOS( P[1].Y, P[8].Y) == 100 || DIF_PONTOS( P[1].X, P[8].X) == 100 && DIF_PONTOS( P[1].Y, P[8].Y) == 0) )
             {
             textprintf_ex(buffer, font, 10, 15, makecol(255, 100, 200),-1, "Peca 2");
             P[9].X = P[1].X; P[9].Y = P[1].Y;
             P[1].X = P[8].X; P[1].Y = P[8].Y;
             P[8].X = P[9].X; P[8].Y = P[9].Y;

             }
         if (mouse_x >= P[2].X-10 && mouse_x <= P[2].X+ 80 && mouse_y >= P[2].Y-10 && mouse_y <= P[2].Y+ 80 &&
            (DIF_PONTOS(P[2].X, P[8].X) == 0 && DIF_PONTOS( P[2].Y, P[8].Y) == 100 || DIF_PONTOS( P[2].X, P[8].X) == 100 && DIF_PONTOS( P[2].Y, P[8].Y) == 0) )
             {
             textprintf_ex(buffer, font, 10, 15, makecol(255, 100, 200),-1, "Peca 3");
             P[9].X = P[2].X; P[9].Y = P[2].Y;
             P[2].X = P[8].X; P[2].Y = P[8].Y;
             P[8].X = P[9].X; P[8].Y = P[9].Y;

             }
         if (mouse_x >= P[3].X-10 && mouse_x <= P[3].X+ 80 && mouse_y >= P[3].Y-10 && mouse_y <= P[3].Y+ 80 &&
            (DIF_PONTOS(P[3].X, P[8].X) == 0 && DIF_PONTOS( P[3].Y, P[8].Y) == 100 || DIF_PONTOS( P[3].X, P[8].X) == 100 && DIF_PONTOS( P[3].Y, P[8].Y) == 0) )
             {
             textprintf_ex(buffer, font, 10, 15, makecol(255, 100, 200),-1, "Peca 4");
             P[9].X = P[3].X; P[9].Y = P[3].Y;
             P[3].X = P[8].X; P[3].Y = P[8].Y;
             P[8].X = P[9].X; P[8].Y = P[9].Y;

             }
         if (mouse_x >= P[4].X-10 && mouse_x <= P[4].X+ 80 && mouse_y >= P[4].Y-10 && mouse_y <= P[4].Y+ 80 &&
            (DIF_PONTOS(P[4].X, P[8].X) == 0 && DIF_PONTOS( P[4].Y, P[8].Y) == 100 || DIF_PONTOS( P[4].X, P[8].X) == 100 && DIF_PONTOS( P[4].Y, P[8].Y) == 0) )
             {
             textprintf_ex(buffer, font, 10, 15, makecol(255, 100, 200),-1, "Peca 5");
             P[9].X = P[4].X; P[9].Y = P[4].Y;
             P[4].X = P[8].X; P[4].Y = P[8].Y;
             P[8].X = P[9].X; P[8].Y = P[9].Y;

             }
         if (mouse_x >= P[5].X-10 && mouse_x <= P[5].X+ 80 && mouse_y >= P[5].Y-10 && mouse_y <= P[5].Y+ 80 &&
            (DIF_PONTOS(P[5].X, P[8].X) == 0 && DIF_PONTOS( P[5].Y, P[8].Y) == 100 || DIF_PONTOS( P[5].X, P[8].X) == 100 && DIF_PONTOS( P[5].Y, P[8].Y) == 0) )
             {
             textprintf_ex(buffer, font, 10, 15, makecol(255, 100, 200),-1, "Peca 6");
             P[9].X = P[5].X; P[9].Y = P[5].Y;
             P[5].X = P[8].X; P[5].Y = P[8].Y;
             P[8].X = P[9].X; P[8].Y = P[9].Y;

             }
         if (mouse_x >= P[6].X-10 && mouse_x <= P[6].X+ 80 && mouse_y >= P[6].Y-10 && mouse_y <= P[6].Y+ 80 &&
            (DIF_PONTOS(P[6].X, P[8].X) == 0 && DIF_PONTOS( P[6].Y, P[8].Y) == 100 || DIF_PONTOS( P[6].X, P[8].X) == 100 && DIF_PONTOS( P[6].Y, P[8].Y) == 0) )
             {
             textprintf_ex(buffer, font, 10, 15, makecol(255, 100, 200),-1, "Peca 7");
             P[9].X = P[6].X; P[9].Y = P[6].Y;
             P[6].X = P[8].X; P[6].Y = P[8].Y;
             P[8].X = P[9].X; P[8].Y = P[9].Y;

             }
         if (mouse_x >= P[7].X-10 && mouse_x <= P[7].X+ 80 && mouse_y >= P[7].Y-10 && mouse_y <= P[7].Y+ 80  &&
            (DIF_PONTOS(P[7].X, P[8].X) == 0 && DIF_PONTOS( P[7].Y, P[8].Y) == 100 || DIF_PONTOS( P[7].X, P[8].X) == 100 && DIF_PONTOS( P[7].Y, P[8].Y) == 0))
             {
             textprintf_ex(buffer, font, 10, 15, makecol(255, 100, 200),-1, "Peca 8");
             P[9].X = P[7].X; P[9].Y = P[7].Y;
             P[7].X = P[8].X; P[7].Y = P[8].Y;
             P[8].X = P[9].X; P[8].Y = P[9].Y;

             }
         if (mouse_x >= P[8].X-10 && mouse_x <= P[8].X+ 80 && mouse_y >= P[8].Y-10 && mouse_y <= P[8].Y+ 80 )
             {
             textprintf_ex(buffer, font, 10, 15, makecol(255, 100, 200),-1, "Peca 9");
             }

         //sleep(200);
         }
         textprintf_ex(buffer, font, 10, 15, makecol(255, 100, 200),-1, "P0 X: %.3d, Y: %.3D",P[8].X, P[8].Y );
         textprintf_ex(buffer, font, 10, 25, makecol(255, 100, 200),-1, "P1 X: %.3d, Y: %.3D ",P[0].X, P[0].Y);
         textprintf_ex(buffer, font, 10, 35, makecol(255, 100, 200),-1, "P2 X: %.3d, Y: %.3D ",P[1].X, P[1].Y);
         textprintf_ex(buffer, font, 10, 45, makecol(255, 100, 200),-1, "P3 X: %.3d, Y: %.3D ",P[2].X, P[2].Y);
         textprintf_ex(buffer, font, 10, 55, makecol(255, 100, 200),-1, "P4 X: %.3d, Y: %.3D ",P[3].X, P[3].Y);
         textprintf_ex(buffer, font, 10, 65, makecol(255, 100, 200),-1, "P5 X: %.3d, Y: %.3D ",P[4].X, P[4].Y);
         textprintf_ex(buffer, font, 10, 75, makecol(255, 100, 200),-1, "P6 X: %.3d, Y: %.3D ",P[5].X, P[5].Y);
         textprintf_ex(buffer, font, 10, 85, makecol(255, 100, 200),-1, "P7 X: %.3d, Y: %.3D ",P[6].X, P[6].Y);
         textprintf_ex(buffer, font, 10, 95, makecol(255, 100, 200),-1, "P8 X: %.3d, Y: %.3D ",P[7].X, P[7].Y);
}

int DIF_PONTOS(int a, int b){
    int dif;
    dif = a - b;
    if( dif < 0)
        dif = dif *(-1);

    return dif;
}

void VERIFICA_BATE(){

}
