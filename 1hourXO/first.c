#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int pobeda(char massiv[3][3]){
    
    if ((massiv[0][0] == 'X' ) && (massiv[0][1] == 'X' ) && (massiv[0][2] == 'X' )) {return 1;}
    if ((massiv[1][0] == 'X' ) && (massiv[1][1] == 'X' ) && (massiv[1][2] == 'X' )) {return 1;}
    if ((massiv[2][0] == 'X' ) && (massiv[2][1] == 'X' ) && (massiv[2][2] == 'X' )) {return 1;}
    if ((massiv[0][0] == 'X' ) && (massiv[1][0] == 'X' ) && (massiv[2][0] == 'X' )) {return 1;}
    if ((massiv[0][1] == 'X' ) && (massiv[1][1] == 'X' ) && (massiv[2][1] == 'X' )) {return 1;}
    if ((massiv[0][2] == 'X' ) && (massiv[1][2] == 'X' ) && (massiv[2][2] == 'X' )) {return 1;}
    if ((massiv[0][0] == 'X' ) && (massiv[1][1] == 'X' ) && (massiv[2][2] == 'X' )) {return 1;}
    if ((massiv[0][2] == 'X' ) && (massiv[1][1] == 'X' ) && (massiv[2][0] == 'X' )) {return 1;}

    if ((massiv[0][0] == 'O' ) && (massiv[0][1] == 'O' ) && (massiv[0][2] == 'O' )) {return 2;}
    if ((massiv[1][0] == 'O' ) && (massiv[1][1] == 'O' ) && (massiv[1][2] == 'O' )) {return 2;}
    if ((massiv[2][0] == 'O' ) && (massiv[2][1] == 'O' ) && (massiv[2][2] == 'O' )) {return 2;}
    if ((massiv[0][0] == 'O' ) && (massiv[1][0] == 'O' ) && (massiv[2][0] == 'O' )) {return 2;}
    if ((massiv[0][1] == 'O' ) && (massiv[1][1] == 'O' ) && (massiv[2][1] == 'O' )) {return 2;}
    if ((massiv[0][2] == 'O' ) && (massiv[1][2] == 'O' ) && (massiv[2][2] == 'O' )) {return 2;}
    if ((massiv[0][0] == 'O' ) && (massiv[1][1] == 'O' ) && (massiv[2][2] == 'O' )) {return 2;}
    if ((massiv[0][2] == 'O' ) && (massiv[1][1] == 'O' ) && (massiv[2][0] == 'O' )) {return 2;}
}

int main() {
    char pole[3][3];
    int flag = 0;
    int chered = 0;
	int x, y, i, j;
	for (i=0; i<3; i++)
    {
        for (j=0; j<3; j++)
        {
            pole[i][j]=' ';
        }
    }

    //printf("_____________\n");
        printf("-------------\n");
        printf("| %c | %c | %c |\n", pole[0][0], pole[0][1], pole[0][2]);
        printf("|---|---|---|\n");
        printf("| %c | %c | %c |\n", pole[1][0], pole[1][1], pole[1][2]);
        printf("|---|---|---|\n");
        printf("| %c | %c | %c |\n", pole[2][0], pole[2][1], pole[2][2]);
        printf("-------------\n");
    

	do{
		
        

        if (chered == 0){
            printf("hod X:\n");
        }
        else{
            if (chered == 1){
                printf("hod O:\n");
            }
        }

        printf("vvedite y: ");
		scanf (" %d", &x);
        printf("vvedite x: ");
		scanf (" %d", &y);

        if (chered == 0){
            pole[x-1][y-1]='X';
            chered = 1;
            system("cls");
             //printf("_____________\n");
            printf("-------------\n");
            printf("| %c | %c | %c |\n", pole[0][0], pole[0][1], pole[0][2]);
            printf("|---|---|---|\n");
            printf("| %c | %c | %c |\n", pole[1][0], pole[1][1], pole[1][2]);
            printf("|---|---|---|\n");
            printf("| %c | %c | %c |\n", pole[2][0], pole[2][1], pole[2][2]);
            printf("-------------\n");

            if (pobeda(pole)==1)
            {
                printf("X pobedil \n");
                getch();
                exit(1);
            }
        }
        else{
            if (chered == 1){
                pole[x-1][y-1]='O';
                chered = 0;
                system("cls");
                //printf("_____________\n");
                printf("-------------\n");
                printf("| %c | %c | %c |\n", pole[0][0], pole[0][1], pole[0][2]);
                printf("|---|---|---|\n");
                printf("| %c | %c | %c |\n", pole[1][0], pole[1][1], pole[1][2]);
                printf("|---|---|---|\n");
                printf("| %c | %c | %c |\n", pole[2][0], pole[2][1], pole[2][2]);
                printf("-------------\n");
                if (pobeda(pole)==2)
                {
                    printf("O pobedil \n");
                    getch();
                    exit(1);
                }
            }
        }

       
       

	} while (1);

	getch();
    return 0;
}
