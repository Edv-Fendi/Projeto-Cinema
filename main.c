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
void  Opcaomenu ();
int menu ();
void comprarPoltrona (struct Poltrona poltrona [][5], int tam, int i, int j);

int main()
{

    struct Poltrona poltrona [5][5];


    clear (poltrona, TAM);



    Opcaomenu ();



}

int menu (){
    int numMenu = 0;

    printf ("-------- Cinemux  ------\n");
    printf ("------------------------\n");
    printf ("1------- Poltronas------\n");
    printf ("2------- Reservar ------\n");
    printf ("3------- Comprar  ------\n");
    printf ("4------- Cancelar ------\n");
    printf ("5-------  Sair    ------\n");
    printf ("------------------------\n");

    printf ("Digite o opcao desejada: \n");
    scanf ("%d", &numMenu);

    return numMenu;

}

void Opcaomenu (struct Poltrona poltrona[][5]){
    int aux = 0;
    aux = menu ();

    while (aux !=4) {

        menu ();

        switch (aux){

        case 1:
            lePoltrona (poltrona, TAM);
            break;

        case 2:
            lePoltrona (poltrona, TAM);


            break;
        case 3:


            printf ("Qual poltrona voce deseja Comprar:\n");
            break;

         case 4:
            printf ("Qual poltrona voce deseja cancelar:\n");
            break;

         case 5:
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

void comprarPoltrona (struct Poltrona poltrona [][5], int tam, int i, int j ){
     if(poltrona[i][j].ocupado==0){
        fflush(stdin);

        printf("Digite seu nome: ");
        gets(poltrona[i][j].nome);

       if (poltrona[i][j].ocupado=2 )

        printf("Poltrona %c%d comprada com sucesso!",i+'A', j+1);




}}
