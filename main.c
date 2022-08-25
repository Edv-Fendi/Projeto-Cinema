#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define TAM 5

struct Poltrona {
    char nome[50] ;
    int cpf;
    int ocupado;
    int pago;

};
void clear (struct Poltrona poltrona[][5], int tam);

int main()
{

    struct Poltrona poltrona [5][5];
    int numMenu = 0;

    clear (poltrona, TAM);


    printf ("-------- Cinemux -------\n");
    printf ("------------------------\n");
    printf ("1------- Reservar ------\n");
    printf ("2------- Comprar -------\n");
    printf ("3------- Cancelar ------\n");
    printf ("4-------  Sair ---------\n");


    while (numMenu !=4) {
    printf ("Digite o opcao desejada: \n");
    scanf ("%d", &numMenu);

        switch (numMenu){
        case 1:
            printf ("Qual poltrona voce deseja reservar:\n");

            break;
        case 2:
            printf ("Qual poltrona voce deseja comprar:\n");
            break;
        case 3:
            printf ("Qual poltrona voce deseja cancelar:\n");
            break;
        }
    }

}
void clear (struct Poltrona poltrona[][5], int tam){
    for(int i=0; i<tam; i++) {
            for (int j=0; j < tam; j++){
        poltrona[i][j].ocupado = 0;
        poltrona[i][j].pago = 0;
            }
    }
}
