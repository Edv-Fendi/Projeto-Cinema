#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define TAM 5

struct Poltrona {
    char nome[50] ;
    unsigned int cpf;
    int ocupado;
    int pago;

};

void clear (struct Poltrona poltrona[][5], int tam);
void lePoltrona (struct Poltrona poltrona [][5], int tam);
int  Opcaomenu ();
void menu ();

int main()
{

    struct Poltrona poltrona [5][5];


    clear (poltrona, TAM);



    Opcaomenu ();



}

void menu (){
    printf ("-------- Cinemux  ------\n");
    printf ("------------------------\n");
    printf ("1------- Poltronas------\n");
    printf ("2------- Reservar ------\n");
    printf ("3------- Comprar  ------\n");
    printf ("4------- Cancelar ------\n");
    printf ("5-------  Sair    ------\n");
    printf ("------------------------\n");

}

int Opcaomenu (struct Poltrona poltrona[][5]){
    int numMenu = 0;
    menu ();

    while (numMenu !=4) {

        printf ("Digite o opcao desejada: \n");
        scanf ("%d", &numMenu);

        switch (numMenu){

        case 1:
            printf ("Qual poltrona voce deseja reservar:\n");
            lePoltrona (poltrona, TAM);

            break;
        case 2:
            printf ("Qual poltrona voce deseja comprar:\n");
            lePoltrona (poltrona, TAM);
            break;
        case 3:
            printf ("Qual poltrona voce deseja cancelar:\n");
            break;

        }

    }

    return numMenu;



}
void clear (struct Poltrona poltrona[][5], int tam){
    for(int i=0; i<tam; i++) {
            for (int j=0; j < tam; j++){
        poltrona[i][j].ocupado = 0;
        poltrona[i][j].pago = 0;
            }
    }
}

void lePoltrona (struct Poltrona poltrona [][5], int tam){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    for(int i=0; i<tam; i++) {
            for (int j=0; j < tam; j++){
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            printf("[%c][%d]   ",i + 'a', j+1);
            }
            printf ("\n");
    }
    SetConsoleTextAttribute(hConsole, saved_attributes);
}
