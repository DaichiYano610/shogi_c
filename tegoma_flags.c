#include "masu.h"

void empty_masu_flag(void){
    int i,j;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            if(a[i][j].exist == 0){
                a[i][j].flag =1;
            }
        }
    }
}

void tegoma_kyo_flag(void){
    int i,j;
    for(i=1;i<8;i++){
        for(j=0;j<9;j++){
            if(a[i][j].exist == 0){
                a[i][j].flag =1;
            }
        }
    }
    if(get_teban() == 1){
        for(j=0;j<9;j++){
            if(a[8][j].exist == 0){
                a[8][j].flag =1;
            }
        }
    }
    if(get_teban() == 2){
        for(j=0;j<9;j++){
            if(a[0][j].exist == 0){
                a[0][j].flag =1;
            }
        }
    }
}

void tegoma_kei_flag(void){
    int i,j;
    for(i=2;i<7;i++){
        for(j=0;j<9;j++){
            if(a[i][j].exist == 0){
                a[i][j].flag =1;
            }
        }
    }
    if(get_teban() == 1){
        for(j=0;j<9;j++){
            for(i=6;i<9;i++){
                if(a[i][j].exist == 0){
                    a[i][j].flag =1;
                }
            }
        }
    }
    if(get_teban() == 2){
        for(j=0;j<9;j++){
            for(i=0;i<3;i++){
                if(a[i][j].exist == 0){
                    a[i][j].flag =1;
                }
            }
        }
    }
}


void tegoma_fu_flag(void){
    int i,j,flag=0;
        for(i=0;i<9;i++){
            for(j=0;j<9;j++){
                if(a[j][i].exist == get_teban() && a[j][i].nameNum == 7 && a[j][i].nari == 0 ){
                    flag =1;
                }
            }
            if(flag == 0){
                for(j=1;j<8;j++){
                    if(a[j][i].exist == 0){
                        a[j][i].flag =1;
                    }
                }
                if(get_teban() ==1){
                    if(a[8][i].exist == 0){
                        a[8][i].flag =1;
                    }
                }
                if(get_teban() ==2){
                    if(a[0][i].exist == 0){
                        a[0][i].flag =1;
                    }
                }
            }
            flag = 0;
        }
        
}