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
void Opcaomenu (struct Poltrona poltrona[][5]);
int menu ();
void reservarPoltrona (struct Poltrona poltrona [][5], int i, int j );
void comprarPoltrona (struct Poltrona poltrona [][5], int i, int j);
void cancelarPoltrona (struct Poltrona poltrona [][5], int i, int j );

int main()
{

    struct Poltrona poltrona [5][5];


    clear (poltrona, TAM);



    Opcaomenu (poltrona);


    return 0;

}

int menu (){
    int numMenu = 0;

    printf ("-------- Cinemux  ------\n");
    printf ("------------------------\n");
    printf ("1------- Reservar ------\n");
    printf ("2------- Comprar  ------\n");
    printf ("3------- Cancelar ------\n");
    printf ("4-------  Sair    ------\n");
    printf ("------------------------\n");

    printf ("Digite o opcao desejada: \n");
    scanf ("%d", &numMenu);

    return numMenu;

}

void Opcaomenu (struct Poltrona poltrona[][5]){
    int i, j;

    while (1) {
        int numMenu = menu();

        switch (numMenu){

        case 1:
            lePoltrona (poltrona, TAM);

            printf ("Qual poltrona voce deseja reservar:\n");
            fflush(stdin);
            scanf ("%c%d", &i, &j);


            i = toupper(i) - 'A';
            j = j - 1;


            reservarPoltrona(poltrona, i, j);
            system("cls");
            break;

        case 2:
            lePoltrona (poltrona, TAM);
            printf ("Qual poltrona voce deseja Comprar:\n");
            fflush(stdin);
            scanf ("%c%d", &i, &j);
            i = toupper(i) - 'A';
            j = j - 1;
            comprarPoltrona (poltrona, i, j);
            system("cls");

            break;

         case 3:
            lePoltrona (poltrona, TAM);
            printf ("Qual poltrona voce deseja cancelar:\n");
            fflush(stdin);
            scanf ("%c%d", &i, &j);
            i = toupper(i) - 'A';
            j = j - 1;
            cancelarPoltrona (poltrona, i, j);
            system("cls");
            break;

         case 4:
            printf ("Obrigado por utilizar nossos servicos:\n");\
            return;

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
                    if(poltrona[i][j].ocupado == 0){
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            printf("[%c][%d]   ",i + 'a', j+1);
            } else if (poltrona[i][j].ocupado == 1){

            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_RED);
            printf("[%c][%d]   ",i + 'a', j+1);
            }
            else if (poltrona[i][j].ocupado == 2){

            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            printf("[%c][%d]   ",i + 'a', j+1);
            }

            }

            printf ("\n");
    }
    SetConsoleTextAttribute(hConsole, saved_attributes);
}

void comprarPoltrona (struct Poltrona poltrona [][5], int i, int j ){

     if(poltrona[i][j].ocupado==0){
        fflush(stdin);

        printf("Digite seu nome: ");
        gets(poltrona[i][j].nome);

        printf("Digite seu cpf: ");
        scanf("%u", &poltrona[i][j].cpf);
        poltrona[i][j].ocupado = 2;
        printf("Poltrona %c%d comprada com sucesso!!!!! \n",i+'A', j+1);
        system("pause");


        }
       else if (poltrona[i][j].ocupado==1){
            unsigned int cpf;
            printf("Digite seu CPF:");
            scanf("%u", &cpf);
          if(poltrona[i][j].cpf == cpf){
              poltrona[i][j].ocupado = 2;

              printf("Voce comprou sua poltrona reservada!! \n");


            }
            system("pause");

      } else if (poltrona[i][j].ocupado==2){
        printf ("Poltrona ja esta comprada!!! \n");
        system("pause");
      }



}

void reservarPoltrona (struct Poltrona poltrona [][5], int i, int j ){

     if(poltrona[i][j].ocupado==0){
        fflush(stdin);

        printf("Digite seu nome: ");
        gets(poltrona[i][j].nome);
        fflush(stdin);
        printf("Digite seu CPF: ");
        scanf("%u", &poltrona[i][j].cpf);
        fflush(stdin);

        poltrona[i][j].ocupado = 1;

        printf("Poltrona %c%d reservada com sucesso!!!!! \n",i+'A', j+1);
        system("pause");


     }
     else if (poltrona[i][j].ocupado==1){

        printf ("Poltrona ja esta reservada!!\n");
        system("pause");

      } else if (poltrona[i][j].ocupado==2){
        printf ("Poltrona ja esta comprada!!!\n");
        system("pause");
      }



}

void cancelarPoltrona (struct Poltrona poltrona [][5], int i, int j ){
            unsigned int cpf;
            if(poltrona[i][j].ocupado==0){
            fflush(stdin);
            printf ("Esta cadeira não esta reservada");
            system("pause");
            }

            else if(poltrona[i][j].ocupado==1){


                printf("Digite seu CPF:");
                scanf("%u", &cpf);

            if(poltrona[i][j].cpf == cpf){

                poltrona[i][j].ocupado = 0;
                printf("Voce cancelou sua reserva!! \n");
                system("pause");
            }
            }

            else if (poltrona[i][j].ocupado==2){
                printf ("Essa operacao e invalida! \n");
                system("pause");
            }



}







