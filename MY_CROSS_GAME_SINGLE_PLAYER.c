#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clear_screen();
void assign_coat();
void assign_position();
void print_coat();
void input();
void random_update();
void checked_update_user();
void checked_update_random();
int B_element_checked();
int win_checked();
int lost_checked();
void gaming_element();

char coat[15][15];
char position[3][3];
int n,m;

int main(){
    int a,win,lost,start_again=1;
    char choice,again;
    printf("\t\tPress enter to play, otherwise any key to exit: "); /// take permission
    scanf("%c",&choice);
    if(choice=='\n'){ /// start the game
        while(start_again){
            clear_screen();
            assign_coat(); /// assign coat first time
            assign_position(); /// make initial position
            print_coat(); /// show the coat first time
            do {
                a=B_element_checked(); /// checked is any turn left
                gaming_element(); /// gaming element merge on it
                win=win_checked(); /// win checking
                lost=lost_checked(); /// lost checking
                if(win==1){
                    printf("\n\n\t....CONGRATULATION YOU WIN....\n");
                    goto label;
                }
                else if(lost==1){
                    printf("\n\n\t....Sorry YOU LOST....\n");
                    goto label;
                }
                if(B_element_checked()==1) {
                    printf("\n\n\t....MATCH TIE....\n");
                    goto label;
                }
            }while(a);
            label:
            getchar();
            printf("\n\n......PRESS E TO EXIT AND ANY KEY TO PLAY AGAIN......\n");
            scanf("%c",&again);
            if(again=='e' || again=='E') start_again--;
        }
    }
    printf("\n\n......THANKS FOR PLAYING THE GAME......\n");
    printf("\nPRESS ANY KEY TO FINISH\n");
    getchar();
    return 0;
}

void clear_screen(){ /// Previous screen clean korlam
    system("@cls||clear");
    printf("\n\t\t...GAME IS ON : ...\n\n");
}

void assign_coat(){ /// At first Coat er pattern banailam
    int i,j;
    for(i=1;i<=14;i++){
        for(j=1;j<=14;j++){
            if(i%5==0 || j%5==0) coat[i][j]='+';
            else coat[i][j]=' ';
        }
    }
}

void assign_position(){ /// At first Coat er pattern banailam
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            position[i][j]='*';
        }
    }
}

void print_coat(){ /// Game coat print korlam
    int i,j;
    for(i=1;i<=14;i++){
        for(j=1;j<=14;j++){
            printf("%c",coat[i][j]);
        }
        printf("\n");
    }
}

void input(){ /// Chal nilam
    printf("\nPlease give your turn: ");
    scanf("%d %d",&n,&m);
    if(n>2 || m>2 || position[n][m]!='*'){
        printf("Invalid, try again between (0-2)\n");
        input();
    }
    else {
        position[n][m]='a';
    }
}

void random_update(){ /// Randomly A array update kormu
    time_t t;
    srand((unsigned) time(&t));
    n=rand()%3;
    m=rand()%3;
    if(position[n][m]!='a' && position[n][m]!='b'){
        position[n][m]='b';
    }
    else{
        random_update();
    }
}

void checked_update_user(){ /// Input niya position array B update korlam by user
    if(n==0){
        if(m==0) coat[3][3]='#';
        else if(m==1) coat[3][8]='#';
        else coat[3][12]='#';
    }
    else if(n==1){
        if(m==0) coat[7][3]='#';
        else if(m==1) coat[7][8]='#';
        else coat[7][12]='#';
    }
    else{
        if(m==0) coat[12][3]='#';
        else if(m==1) coat[12][8]='#';
        else coat[12][12]='#';
    }
}

void checked_update_random(){ /// Input niya position array B update korlam by randomly
    if(n==0){
        if(m==0) coat[3][3]='O';
        else if(m==1) coat[3][8]='O';
        else coat[3][12]='O';
    }
    else if(n==1){
        if(m==0) coat[7][3]='O';
        else if(m==1) coat[7][8]='O';
        else coat[7][12]='O';
    }
    else{
        if(m==0) coat[12][3]='O';
        else if(m==1) coat[12][8]='O';
        else coat[12][12]='O';
    }
}

int B_element_checked(){ /// checked is there any element in Array B
    int i,j,count=0;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(position[i][j]=='*'){
                count++;
                break;
            }
        }
        if(count!=0){
            break;
        }
    }
    if(count==0) return 1;
    else return 2;
}

int win_checked(){ /// checking is player win
    if(position[0][0]=='a' && position[0][1]=='a' && position[0][2]=='a') return 1;
    else if(position[0][0]=='a' && position[1][0]=='a' && position[2][0]=='a') return 1;
    else if(position[0][0]=='a' && position[1][1]=='a' && position[2][2]=='a') return 1;
    else if(position[0][1]=='a' && position[1][1]=='a' && position[2][1]=='a') return 1;
    else if(position[0][2]=='a' && position[1][2]=='a' && position[2][2]=='a') return 1;
    else if(position[1][0]=='a' && position[1][1]=='a' && position[1][2]=='a') return 1;
    else if(position[2][0]=='a' && position[2][1]=='a' && position[2][2]=='a') return 1;
    else return 0;
}

int lost_checked(){ /// checking is player lost
    if(position[0][0]=='b' && position[0][1]=='b' && position[0][2]=='b') return 1;
    else if(position[0][0]=='b' && position[1][0]=='b' && position[2][0]=='b') return 1;
    else if(position[0][0]=='b' && position[1][1]=='b' && position[2][2]=='b') return 1;
    else if(position[0][1]=='b' && position[1][1]=='b' && position[2][1]=='b') return 1;
    else if(position[0][2]=='b' && position[1][2]=='b' && position[2][2]=='b') return 1;
    else if(position[1][0]=='b' && position[1][1]=='b' && position[1][2]=='b') return 1;
    else if(position[2][0]=='b' && position[2][1]=='b' && position[2][2]=='b') return 1;
    else return 0;
}

void gaming_element(){ /// binding necessary element
    input();
    clear_screen();
    checked_update_user();
    random_update();
    checked_update_random();
    print_coat();
}

