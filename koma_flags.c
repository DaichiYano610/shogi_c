#include "masu.h"

/*駒の移動可能なマスにflagを立てる--------------------------*/
void hv_flag(int x,int y){/*上下左右1マス*/
    if(y != 0 && a[y][x].exist != a[y -1][x].exist){/*上*/
        a[y - 1][x].flag = 1;
    }
    if(x != 8 && a[y][x].exist != a[y][x + 1].exist){/*右*/
        a[y][x + 1].flag = 1;
    }
    if(y != 8 && a[y][x].exist != a[y+1][x].exist){/*下*/
        a[y+1][x].flag = 1;
    }
    if(x != 0 && a[y][x].exist != a[y][x - 1].exist){/*左*/
        a[y][x-1].flag = 1;
    }
}

void diagonal_flag(int x,int y){/*斜め1マス*/
    /*左斜め上*/
    if(x != 0 && y != 0 && a[y][x].exist != a[y-1][x-1].exist){
        a[y-1][x-1].flag = 1;
    }
    /*右斜め上*/
    if(x != 8 && y != 0 && a[y][x].exist != a[y-1][x+1].exist){
        a[y-1][x+1].flag = 1;
    }
    /*左斜め下*/
    if(x != 0 && y != 8 && a[y][x].exist != a[y+1][x-1].exist){
        a[y + 1][x-1].flag = 1;
    }
    /*右斜め下*/
    if(x != 8 && y != 8 && a[y][x].exist != a[y+1][x+1].exist){
        a[y + 1][x + 1].flag = 1;
    }
}

void kaku_flag(int x,int y){
    int i=1,j=1;
    /*右上*/
    while(x + j <= 8 && y - i >=0){
        if(a[y][x].exist * a[y -i][x + j].exist == 2){
            a[y -i][x + j].flag = 1;
        }
        if(a[y - i][x + j].exist != 0){
            break;
        }
        a[y - i][x + j].flag =1; 
        i++; j++;
    }
    i=1; j=1;
    /*左上*/
    while(x - j >= 0 && y - i >=0){
        if(a[y][x].exist * a[y -i][x - j].exist == 2){
            a[y -i][x - j].flag = 1;
        }
        if(a[y - i][x - j].exist != 0){
            break;
        }
        a[y - i][x - j].flag =1;
        i++; j++;
    }
    i=1; j=1;
    /*左下*/
    while(x - j >= 0 && y + i <= 8){
        if(a[y][x].exist * a[y + i][x - j].exist == 2){
            a[y + i][x - j].flag = 1;
        }
        if(a[y + i][x - j].exist != 0){
            break;
        }
        a[y + i][x -j].flag =1;
        i++; j++;
    }
    i=1; j=1;
    /*右下*/
    while(x + j <= 8 && y + i <= 8){
        if(a[y][x].exist * a[y + i][x + j].exist == 2){
            a[y + i][x + j].flag = 1;
        }
        if(a[y + i][x + j].exist != 0){
            break;
        }
        a[y+i][x+j].flag =1;
        i++; j++;
    }
    /*馬*/
    if(a[y][x].nari == 1){
        hv_flag(x,y);
    }    
}

void hisha_flag(int x,int y){
    int i = 1;
    /*上*/
    while(y - i >=0){
        if(a[y][x].exist * a[y -i][x].exist == 2){
            a[y -i][x].flag = 1;
        }
        if(a[y - i][x].exist != 0){
            break;
        }
        a[y - i][x].flag =1; 
        i++;
    }
    i=1;
    /*下*/
    while(y + i <=8){
        if(a[y][x].exist * a[y + i][x].exist == 2){
            a[y + i][x].flag = 1;
        }
        if(a[y + i][x].exist != 0){
            break;
        }
        a[y + i][x].flag =1; 
        i++;
    }
    i=1;
    /*右*/
    while(x + i <=8){
        if(a[y][x].exist * a[y][x+i].exist == 2){
            a[y][x+i].flag = 1;
        }
        if(a[y][x+i].exist != 0){
            break;
        }
        a[y][x+i].flag =1; 
        i++;
    }
    i=1;
    /*左*/
    while(x - i >= 0){
        if(a[y][x].exist * a[y][x -i].exist == 2){
            a[y][x-i].flag = 1;
        }
        if(a[y][x-i].exist != 0){
            break;
        }
        a[y][x-i].flag =1; 
        i++;
    }
    i=1;
    /*竜*/
    if(a[y][x].nari == 1){
        diagonal_flag(x,y);
    }
}

void kin_flag(int x,int y){
    hv_flag(x,y);
    if(a[y][x].exist == 1){
        /*左斜め上*/
        if(x != 0 && y != 0 && a[y][x].exist != a[y-1][x-1].exist){
            a[y-1][x-1].flag = 1;
        }
        /*右斜め上*/
        if(x != 8 && y != 0 && a[y][x].exist != a[y-1][x+1].exist){
            a[y-1][x+1].flag = 1;
        }
    }
    if(a[y][x].exist == 2){
        /*左斜め下*/
        if(x != 0 && y != 8 && a[y][x].exist != a[y+1][x-1].exist){
            a[y + 1][x-1].flag = 1;
        }
        /*右斜め下*/
        if(x != 8 && y != 8 && a[y][x].exist != a[y+1][x+1].exist){
            a[y + 1][x + 1].flag = 1;
        }
    }
}

void kyou_flag(int x,int y){
    int i =1;
    if(a[y][x].exist == 1){/*上*/
        if(a[y][x].nari == 0){
            while(y - i >=0){
                if(a[y][x].exist * a[y -i][x].exist == 2){
                    a[y -i][x].flag = 1;
                }
                if(a[y - i][x].exist != 0){
                    break;
                }
                a[y - i][x].flag =1; 
                i++;
            }
        }else if(a[y][x].nari == 1){
            kin_flag(x,y);
        }
    }
    if(a[y][x].exist == 2){/*下*/
        if(a[y][x].nari == 0){
            while(y + i <=8){
                if(a[y][x].exist * a[y + i][x].exist == 2){
                    a[y + i][x].flag = 1;
                }
                if(a[y + i][x].exist != 0){
                    break;
                }
                a[y + i][x].flag =1; 
                i++;
            }
        }else if(a[y][x].nari == 1){
            kin_flag(x,y);
        }
    }
}

void kei_flag(int x,int y){
    if(a[y][x].exist == 1){
        if(a[y][x].nari == 0){
            /*左上奥*/
            if(x != 0 && y >= 2 && a[y][x].exist != a[y-2][x-1].exist){
                a[y-2][x-1].flag =1; 
            }
            /*右上奥*/
            if(x != 8 && y >= 2 && a[y][x].exist != a[y-2][x+1].exist){
                a[y-2][x+1].flag =1; 
            }
        }else if(a[y][x].nari == 1){
            kin_flag(x,y);
        }
    }
    if(a[y][x].exist == 2){
        if(a[y][x].nari == 0){
            /*左下奥*/
            if(x != 0 && y <= 6 && a[y][x].exist != a[y+2][x-1].exist){
                a[y+2][x-1].flag =1; 
            }
            /*右下奥*/
            if(x != 8 && y <= 6 && a[y][x].exist != a[y+2][x+1].exist){
                a[y+2][x+1].flag =1; 
            }
        }else if(a[y][x].nari == 1){
            kin_flag(x,y);
        }
    }
}

void fu_flag(int x,int y){
    if(a[y][x].exist == 1){
        if(a[y][x].nari == 0){
            if(y != 0 && a[y][x].exist != a[y-1][x].exist){/*上*/
                a[y - 1][x].flag = 1;
            }
        }else if(a[y][x].nari == 1){
            kin_flag(x,y);
        }
    }
    if(a[y][x].exist == 2){
        if(a[y][x].nari == 0){
            if(y != 8 && a[y][x].exist != a[y+1][x].exist){/*下*/
                a[y + 1][x].flag = 1;
            }
        }else if(a[y][x].nari == 1){
            kin_flag(x,y);
        }
    }
}

void gin_flag(int x,int y){
        if(a[y][x].nari == 0){
            fu_flag(x,y);
            diagonal_flag(x,y);
        }else if(a[y][x].nari == 1){
            kin_flag(x,y);
        }
}

void ou_flag(int x,int y){
    hv_flag(x,y);
    diagonal_flag(x,y);
}

