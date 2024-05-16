#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "masu.h"
#include "koma_flags.h"
#include "tegoma_flags.h"

/*盤面のデータ*/
MASU a[9][9];

/*手駒*/
int player1[9];
int player2[9];

/*手番*/
int teban = 1;

/*動かす駒*/
int sltdX;
int sltdY;

/*動かす先の場所*/
int toX;
int toY;

/*打つ駒*/
int utsu;

void init_koma(void){
    int i,j; 

    /*existの初期化*/
    for(i=0;i<9;i++){
        a[0][i].exist=2;
        a[2][i].exist=2;
        a[6][i].exist=1;
        a[8][i].exist=1;
    }

    a[1][1].exist=2;
    a[1][7].exist=2;
    a[7][1].exist=1;
    a[7][7].exist=1;

    /*nameNumの初期化*/
    for(i=0;i<9;i++){
        a[2][i].nameNum=7;/*fu*/
        a[6][i].nameNum=7;
    }
    a[1][7].nameNum=1; a[7][1].nameNum=1;/*kk*/
    a[1][1].nameNum=2; a[7][7].nameNum=2;/*hs*/
    a[0][0].nameNum=3; a[0][8].nameNum=3;a[8][0].nameNum=3; a[8][8].nameNum=3;/*ky*/
    a[0][1].nameNum=4; a[0][7].nameNum=4;a[8][1].nameNum=4; a[8][7].nameNum=4;/*ke*/
    a[0][2].nameNum=5; a[0][6].nameNum=5;a[8][2].nameNum=5; a[8][6].nameNum=5;/*gi*/
    a[0][3].nameNum=6; a[0][5].nameNum=6;a[8][3].nameNum=6; a[8][5].nameNum=6;/*ki*/
    a[0][4].nameNum=8; a[8][4].nameNum=8;/*ou*/   
}

void print_masu(void){
    int i,j;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            fprintf(stderr,"(%1d,%1d,%1d)",a[i][j].exist,a[i][j].nameNum,a[i][j].flag);
        }
        fprintf(stderr,"\n");
    }
    fprintf(stderr,"\n");
    for(i=0;i<9;i++){
        fprintf(stderr,"%d,",player1[i]);
    }
    fprintf(stderr,"\n");
    for(i=0;i<9;i++){
        fprintf(stderr,"%d,",player2[i]);
    }
    fprintf(stderr,"\n");
}

int get_nameNum(int x,int y){
    return a[y][x].nameNum;
}

int get_exist(int x, int y){
    return a[y][x].exist;
}

int get_nari(int x,int y){
    return a[y][x].nari;
}

int get_flag(int x,int y){
    return a[y][x].flag;
}

int *get_tegoma(int player){
    if(player == 1){
        return player1;
    }else{
        return player2;
    }
}

int get_teban(void){
    return teban;
}


void zero_masu(int x,int y){
    a[y][x].exist=0;
    a[y][x].nameNum=0;
    a[y][x].nari=0;
    a[y][x].flag=0;
}

void allzero_flag(void){
    int i,j;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            a[i][j].flag = 0;
        }
    }
}

void set_koma(int x,int y){
    a[y][x].exist = a[sltdY][sltdX].exist;
    a[y][x].nameNum = a[sltdY][sltdX].nameNum;
    a[y][x].nari = a[sltdY][sltdX].nari;
}

void set_to(int x,int y){
    toX=x; toY=y;
}

void set_nari(void){
    a[sltdY][sltdX].nari = 1;
}

void set_teban(void){
    do{
        if(teban == 1){
            teban = 2;
            break;
        }
        if(teban == 2){
            teban = 1;
            break;
        }
    }while(0);
}

int select_koma(int x,int y){
    sltdX = x;
    sltdY = y;
    switch(a[y][x].nameNum){
        case 1:
            kaku_flag(x,y);
            break;
        case 2:
            hisha_flag(x,y);
            break;
        case 3:
            kyou_flag(x,y);
            break;
        case 4:
            kei_flag(x,y);
            break;
        case 5:
            gin_flag(x,y);
            break;
        case 6:
            kin_flag(x,y);
            break;
        case 7:
            fu_flag(x,y);
            break;
        case 8:
            ou_flag(x,y);
            break;
    }
    return a[sltdY][sltdX].exist;
}


int check_nari(void){
    int x=toX, y=toY;
    if(a[sltdY][sltdX].nari == 0 ){
        if(a[sltdY][sltdX].exist == 1 && 0 <= y && y <= 2){
            return 1;
        }
        if(a[sltdY][sltdX].exist == 2 && 6 <= y && y <= 8){
            return 1;
        }
    }
    return 0;
}

int check_flag(int x, int y){
    if(a[y][x].flag == 1){
        return 1;
    }
    if(a[y][x].flag == 0){
        allzero_flag();
        return 0;
    }
}

void add_tegoma(int koma,int exist){
    if(exist == 1){
        player2[koma]+=1;
    }
    if(exist == 2){
        player1[koma]+=1;
    }
}

void tomove_koma(void){
    add_tegoma(a[toY][toX].nameNum,a[toY][toX].exist);
    set_koma(toX,toY);
    zero_masu(sltdX,sltdY);
    allzero_flag();
    set_teban();
}



int select_tegoma(int koma){
    if(teban == 1){
        if(player1[koma]==0){
            return 0;
        }
    }
    if(teban == 2){
        if(player2[koma]==0){
            return 0;
        }
    }

    if(koma == 3){
        tegoma_kyo_flag();
    }else if(koma == 4){
        tegoma_kei_flag();
    }else if(koma == 7){
        tegoma_fu_flag();
    }else{
        empty_masu_flag();
    }
    utsu = koma;

    return 1;
}

int hit_tegoma(int x,int y){
    if(a[y][x].flag == 0){
        return 0;
    }
    a[y][x].exist = teban;
    a[y][x].nameNum = utsu;
    if(teban ==1){
        player1[utsu]-=1;
    }
    if(teban ==2){
        player2[utsu]-=1;
    }
    allzero_flag();
    set_teban();
    return 1;
}

