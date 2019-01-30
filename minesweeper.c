#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void template (int array[20][20],int fail){

printf("\n\n");
int i,j,k,l;
int mines = 0;
for (i = 5 ; i < 15 ; i++){
    printf("%  d",i - 4);
    for (j = 5 ; j < 10 ; j++){
        if (array[i][j] == 0){
            printf("\to");
        }

        else if (array[i][j] == 1){
            if (fail == 1){
                printf("\tx");
            }
            else{
                printf("\to");
            }
        }
        else if (array[i][j] == 2){
            for (k = i - 1 ; k < i + 2 ; k++){
                for (l = j - 1 ; l < j + 2 ; l++){
                    if (array[k][l] == 1 || array[k][l] == 4){
                        mines++;
                    }
                }
            }
            printf("\t%d",mines);
            mines = 0;

        }
        else if (array[i][j] == 3 || array[i][j] == 4){
            printf("\t?");
        }
    }
    printf("\t%d",i - 4);
    printf("\n");
}
printf("\n");
for (i = 0 ; i < 5 ; i++){
    printf("\t%d",i + 1);
}

}

int main(){

int m,n;
printf("1.Start Game\n2.Instructions\n");
scanf("%d",&n);
if (n == 2){
    printf("***INSTRUCTIONS***\nThere are 10 mines in the field.\nTry not to hit them.\nDo not forget to clean all of your question marks and exit the question mark mode for the win.\nPress 1 to start\n");
    scanf("%d",&n);
}
while (n == 1){
    int i,j;
    int counter = 0;
    int total = 0;
    int fail = 0;
    int x = 0;
    int y = 0;
    int array[20][20];
    for (i = 0 ; i < 20 ; i++){
        for (j = 0 ; j < 20 ; j ++){
            array[i][j] = 0;
        }
    }


    srand(time(NULL));
    for (i = 0 ; i < 10 ; i++){
        x = rand()%10 + 5;
        y = rand()%5 + 5;
        while (array[x][y] == 1){
            x = rand()%10 + 5;
            y = rand()%5 + 5;
        }
        array[x][y] = 1;
    }










    while (1){
        system("@cls||clear");
        printf("\n**MINE MODE**");
        template(array,fail);
        printf("\n\n0 0 for question mark mode ");
        printf("\nenter location : ");
        scanf("%d %d",&x,&y);
        if (x == 0 && y == 0){
        // QUESTION MARK MODE
            do{
                system("@cls||clear");
                printf("\n**QUESTION MARK MODE**");
                template(array,fail);
                printf("\n\n0 0 for exit question mark mode");
                printf("\nenter location : ");
                scanf("%d %d",&x,&y);
                while (x > 10 || x < 0 || y > 5 || y < 0){
                    printf("\n\n0 0 for exit question mark mode");
                    printf("\nenter a valid location : ");
                    scanf("%d %d",&x,&y);
                }
                if (array[x + 4][y + 4] == 0 || array[x + 4][y + 4] == 1){
                    array[x + 4][y + 4] += 3;
                }
                else if (array[x + 4][y + 4] == 3 || array[x + 4][y + 4] == 4){
                    array[x + 4][y + 4] -= 3;

                }
            }while (x != 0 && y != 0);
        }
        // QUESTION MARK MODE


        while (x > 10 || x < 0 || y > 5 || y < 0){
            printf("\n\n0 0 for question mark mode");
            printf("\nenter a valid location : ");
            scanf("%d %d",&x,&y);
        }
        if (array[x + 4][y + 4] == 1 || array[x + 4][y + 4] == 4){

            system("@cls||clear");
            fail = 1;
            for (i = 5 ; i < 15 ; i++){
                for (j = 5 ; j < 10 ; j++){
                    if (array[i][j] == 4 || array[i][j] == 3){
                        array[i][j] -= 3;
                    }
                }
            }

            printf("\n**GAME OVER!**");
            template (array,fail);
            printf("\nGAME OVER!\n");
            break;
        }
        array[x + 4][y + 4] = 2;
        for (i = 5 ; i < 15 ; i++){
            for (j = 5 ; j < 10 ; j++){
                if (array[i][j] == 3 || array[i][j] == 4){
                    counter = 1;
                }
                total += array[i][j];
                if (total == 90 && counter == 0){
                    printf("\nYOU WON! \n");
                    return EXIT_SUCCESS;
                }
            }
        }
        total = 0;
        counter = 0;

        template (array,fail);

    }

    printf("1.Restart\n2.Exit\n");
    scanf("%d",&n);
}




return EXIT_SUCCESS;
}
