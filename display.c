#include <ncurses.h>
#include "masu.h"

void print_masu_frame(void){
    int x,y;
    int i=0,j=0;

    getmaxyx(stdscr, y, x);
    y=2; x=x/4;
    for(j=0;j<10;j++){
        for(i=x+2;i<=x+27;i+=3){
            mvprintw(y+j*2,i,"―");
            mvprintw(y+j*2,i+1,"十");
        }
        for(i=y+1;i<=y+18;i+=2){
            mvprintw(i,x+j*4,"｜");
        }
        mvprintw(y+j*2,x,"十");
    }
}

int masu_getX(int x){
    return (x-23)/4;
}

int masu_getY(int y){
    return (y-3)/2;
}

int tegoma_getNum(int y){
  if(3 <= y && y <= 9){
    return (y-2)%8;
  }
  if(13 <= y && y <= 19){
    return (y-12)%8;
  }
  return -1;
}

void print_koma(void){
  int i,j,x,y;
  getmaxyx(stdscr, y, x);
  y=2; x=x/4;
  for(j=1;j<19;j+=2){
      for(i=2;i<38;i+=4){
        switch(get_nameNum(masu_getX(x + i),masu_getY(y + j))){
            case 1:
                if(get_exist(masu_getX(x + i),masu_getY(y + j))==1){
                  if(get_nari(masu_getX(x + i),masu_getY(y + j))==1){
                    mvprintw(y + j,x + i,"馬");
                  }else{
                    mvprintw(y + j,x + i,"角");
                  }
                }else{
                  if(get_nari(masu_getX(x + i),masu_getY(y + j))==1){
                    mvprintw(y + j,x + i,"UM");
                  }else{
                    mvprintw(y + j,x + i,"kk");
                  }
                }
                break;
            case 2:
                if(get_exist(masu_getX(x + i),masu_getY(y + j))==1){
                  if(get_nari(masu_getX(x + i),masu_getY(y + j))==1){
                    mvprintw(y + j,x + i,"竜");
                  }else{
                    mvprintw(y + j,x + i,"飛");
                  }
                }else{
                  if(get_nari(masu_getX(x + i),masu_getY(y + j))==1){
                    mvprintw(y + j,x + i,"RY");
                  }else{
                    mvprintw(y + j,x + i,"hs");
                  }
                }
                break;
            case 3:
                if(get_exist(masu_getX(x + i),masu_getY(y + j))==1){
                  if(get_nari(masu_getX(x + i),masu_getY(y + j))==1){
                    mvprintw(y + j,x + i,"よ");
                  }else{
                    mvprintw(y + j,x + i,"香");
                  }
                }else{
                  if(get_nari(masu_getX(x + i),masu_getY(y + j))==1){
                    mvprintw(y + j,x + i,"KY");
                  }else{
                    mvprintw(y + j,x + i,"ky");
                  }
                }
                break;
            case 4:
                if(get_exist(masu_getX(x + i),masu_getY(y + j))==1){
                  if(get_nari(masu_getX(x + i),masu_getY(y + j))==1){
                    mvprintw(y + j,x + i,"け");
                  }else{
                    mvprintw(y + j,x + i,"桂");
                  }
                }else{
                  if(get_nari(masu_getX(x + i),masu_getY(y + j))==1){
                    mvprintw(y + j,x + i,"KE");
                  }else{
                    mvprintw(y + j,x + i,"ke");
                  }
                }
                break;
            case 5:
                if(get_exist(masu_getX(x + i),masu_getY(y + j))==1){
                  if(get_nari(masu_getX(x + i),masu_getY(y + j))==1){
                    mvprintw(y + j,x + i,"ぎ");
                  }else{
                    mvprintw(y + j,x + i,"銀");
                  }
                }else{
                  if(get_nari(masu_getX(x + i),masu_getY(y + j))==1){
                    mvprintw(y + j,x + i,"GI");
                  }else{
                    mvprintw(y + j,x + i,"gi");
                  }
                }
                break;
            case 6:
                if(get_exist(masu_getX(x + i),masu_getY(y + j))==1){
                  mvprintw(y + j,x + i,"金");
                }else{
                  mvprintw(y + j,x + i,"ki");
                }
                break;
            case 7:
                if(get_exist(masu_getX(x + i),masu_getY(y + j))==1){
                  if(get_nari(masu_getX(x + i),masu_getY(y + j))==1){
                    mvprintw(y + j,x + i,"と");
                  }else{
                    mvprintw(y + j,x + i,"歩");
                  }
                }else{
                  if(get_nari(masu_getX(x + i),masu_getY(y + j))==1){
                    mvprintw(y + j,x + i,"To");
                  }else{
                    mvprintw(y + j,x + i,"fu");
                  }
                }
                break;
            case 8:
                if(get_exist(masu_getX(x + i),masu_getY(y + j))==1){
                  mvprintw(y + j,x + i,"王");
                }else{
                  mvprintw(y + j,x + i,"ou");
                }
                break;
            default:
                mvprintw(y + j,x + i,"  ");
        }
      }   
  }
}

void print_box(int x, int y, int width, int height){
  int i;
  int cwidth = (width-1)*2;
  int cheight = height -1;
  mvprintw(y,x,"十");
  mvprintw(y,x + cwidth,"十");
  mvprintw(y + cheight,x,"十");
  mvprintw(y + cheight,x + cwidth,"十");
  for(i=2; i<cwidth; i+=2){
    mvprintw(y,x + i,"―");
    mvprintw(y + cheight,x + i,"―");
  }
  for(i=1;i<cheight;i++){
    mvprintw(y + i,x,"｜");
    mvprintw(y + i,x + cwidth,"｜");
  }
}

void erase_box(int x,int y, int width,int height){
  int i,j;
  int cwidth = (width-1)*2;
  int cheight = height -1;
  for(i=0;i<=cheight;i++){
    for(j=0;j<=cwidth;j+=2){
      mvprintw(y+i,x+j,"  ");
    }
  }
}

void print_tegoma_button(void){
  int *p;
  int x,y,i;
  x = 9; y =2; i = 1;
  p = get_tegoma(2);
  print_box(x,y,5,9);
  x+=2;
  mvprintw(y+i++,x,"kk x%d",*++p);
  mvprintw(y+i++,x,"hs x%d",*++p);
  mvprintw(y+i++,x,"ky x%d",*++p);
  mvprintw(y+i++,x,"ke x%d",*++p);
  mvprintw(y+i++,x,"gi x%d",*++p);
  mvprintw(y+i++,x,"ki x%d",*++p);
  mvprintw(y+i++,x,"fu x%d",*++p);

  x = 61; y=12; i=1;
  p = get_tegoma(1);
  print_box(x,y,5,9);
  x+=2;
  mvprintw(y+i++,x,"角 x%d",*++p);
  mvprintw(y+i++,x,"飛 x%d",*++p);
  mvprintw(y+i++,x,"香 x%d",*++p);
  mvprintw(y+i++,x,"桂 x%d",*++p);
  mvprintw(y+i++,x,"銀 x%d",*++p);
  mvprintw(y+i++,x,"金 x%d",*++p);
  mvprintw(y+i++,x,"歩 x%d",*++p);
}

void print_teban(void){
  int x = 3, y = 17;
  print_box(x,y,8,4);
  mvprintw(y+2,x+2,"player1");
  mvprintw(y+1,x+2,"player2");
  if(get_teban() == 1){
    mvprintw(y+2,x+10,"←");
    mvprintw(y+1,x+10,"  ");
  }
  if(get_teban() == 2){
    mvprintw(y+1,x+10,"←");
    mvprintw(y+2,x+10,"  ");
  }
}

void print_exit_button(void){
  int x = 63, y = 2;
  print_box(x,y,4,3);
  mvprintw(y+1,x+2,"終了");
}

void print_toryo_button(void){
  int x = 63, y = 5;
  print_box(x,y,4,3);
  mvprintw(y+1,x+2,"投了");
}

void print_nari_button(int flag){
  int x = 3, y = 11;
  if(flag ==1){
    print_box(x,y,6,3);
    mvprintw(y+1,x+2,"  成る");
    y += 3;
    print_box(x,y,6,3);
    mvprintw(y+1,x+2,"成らない");
  }else{
    erase_box(x,y,6,6);
  }
}

void print_help_button(void){
  int x = 63, y = 8;
  print_box(x,y,4,3);
  mvprintw(y+1,x+2,"help");
}

void print_koma_flag(void){
  int i,j,x,y;
  getmaxyx(stdscr, y, x);
  y=2; x=x/4;
  for(j=1;j<19;j+=2){
      for(i=2;i<38;i+=4){
        if(get_flag(masu_getX(x + i),masu_getY(y + j)) == 1){
          mvprintw(y+j,x+i,"○");
        }
      }
  }
}

void print_all(void){
  print_masu_frame();
  print_koma();
  print_tegoma_button();
  print_teban();
  print_exit_button();
  print_toryo_button();
  print_help_button();
}

void print_update(void){
  print_koma();
  print_tegoma_button();
  print_teban();
  print_koma_flag();
}

int clicked_button(int x,int y){
  /*終了=1 投了=2 盤面=3 手駒player1 =4 手駒player2 =5 成る=6 成らない= 7  help =8 それ以外=0*/

  if( 64 <= x && x<=69 && 2 <= y && y <= 4){/*終了*/
    return 1;
  }
  if( 64 <= x && x<=69 && 5 <= y && y <= 7){/*投了*/
    return 2;
  }
  if(22<=x && x<=56 && 3 <= y && y <= 19){/*盤面*/
    return 3;
  }
  if( 62 <= x && x<=69 &&  13 <= y && y<= 19 ){/*手駒player1*/
    return 4;
  }
  if( 10 <= x && x<=17 &&  3 <= y && y<= 9 ){/*手駒player2*/
    return 5;
  }
  if( 4 <= x && x<=13 &&  11 <=y  && y <= 13 ){/*成るボタン*/
    return 6;
  }
  if( 4 <= x && x<=13 &&  14 <=y  && y <= 16 ){/*成るボタン*/
    return 7;
  }
  if( 64 <= x && x<=69 && 8 <= y && y <= 10){/*helpボタン*/
    return 8;
  }
  
  return 0;
}

void print_help(void){
  char fname[] = "help.txt";
  FILE *fp;
  char tmp[100];
  int ch;
  int i = 7;

  clear();
  /*ファイルの読み込み*/
  if((fp = fopen(fname,"r")) == NULL){
    mvprintw(11,28,"ファイル%sがありません。\n",fname);
  }else{
    while( fscanf(fp,"%s",tmp) != EOF) {
      mvprintw(i++,20,"%s",tmp);
    }
  }
  refresh();
  while(ch != 'q'){
    ch = getch();
  }
  clear();
  fclose(fp);
}