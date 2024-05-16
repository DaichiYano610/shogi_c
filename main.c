#include <ncurses.h>
#include <unistd.h>
#include <locale.h>
#include <stdlib.h>
#include "masu.h"
#include "display.h"

int option_control(int argc);
void scr_size(void);
void play(MEVENT event);
int manager (int button, int state,int x,int y);

int main(int argc,char **argv){
  MEVENT event;
  
  option_control(argc);

  setlocale(LC_ALL, ""); /* locale として環境変数を利用 */
  initscr();
  
  scr_size();

  /* マウスを利用 */
  keypad(stdscr, TRUE);
  cbreak();
  noecho();
 
  /* 全てのマウスイベントを検知 */
  mousemask(ALL_MOUSE_EVENTS, NULL);

  play(event);

  nocbreak();
  endwin();

  return 0;
}

int option_control(int argc){
  /*オプションがあった場合に終了*/
  if(argc != 1){
    fprintf(stderr,"オプションを使用せず「./shogi」だけで入力してください\n");
    exit(1);
  }
}

void play(MEVENT event){
  int state =0;
  int ch;
  /*初期化*/
  init_koma();
  print_all();
  
  /*将棋の処理*/
  while(ch != 'q' && state != 1){
    ch = getch();
    getmouse(&event);
    if(event.bstate == BUTTON1_CLICKED || event.bstate == BUTTON1_DOUBLE_CLICKED) {
        state = manager(clicked_button(event.x,event.y),state,event.x,event.y);
        print_update();
        refresh();
    }
  }
}

int manager (int button, int state,int x,int y){
  int tmp_state = state;

  if( tmp_state == 1 ||button == 1 ){
    return 1;
  }

  if(tmp_state == 2 || button == 2 ){
    mvprintw(0,29,"～player%dの勝ち～",get_teban()*2%3);
    return 0;
  }

  if(tmp_state ==0 && button == 3){/*駒の選択*/
    select_koma(masu_getX(x+1),masu_getY(y));
    print_koma_flag();
    return 3;
  }
  if(tmp_state == 3){/*成り確認*/
    if(button == 3 && check_flag(masu_getX(x),masu_getY(y)) == 1){
      set_to(masu_getX(x),masu_getY(y));
      if(check_nari() == 1){
        print_nari_button(1);
        return 4;
      }else{
        tmp_state = 5;
      }
    }else{
      allzero_flag();
      return 0;
    }
  }

  if(tmp_state ==4){/*成りボタン確認*/
    if(button == 6 || button == 7){
      if(button ==6){
        set_nari();
        print_nari_button(0);
        tmp_state = 5;
      }else{
        print_nari_button(0);
        tmp_state = 5;
      }
    }else{
      print_nari_button(0);
      allzero_flag();
      return 0;
    }
  }

  if(tmp_state ==5){/*駒を動かす*/
    tomove_koma();
    return 0;
  }

  if(tmp_state == 0 && (button == 4 || button == 5)){/*手駒の選択*/
    if(select_tegoma(tegoma_getNum(y)) == 1){
      return 6;
    }
  }

  if(tmp_state == 6 ){/*手駒を打つ*/
    if(button == 3){
      hit_tegoma(masu_getX(x),masu_getY(y));
    }
    allzero_flag();
    return 0;
  }

  if(button == 8){
    print_help();
    print_all();
    return 0;
  }

   return tmp_state;
}

void scr_size(void){
  int x,y;
  /*画面サイズの指定*/
  getmaxyx(stdscr, y, x);
  if(x != 85 || y != 23){
    mvprintw(y/2, x/4, "画面サイズを85x23にしてください" ,x,y );
    refresh();
    sleep(5);
    endwin();
    exit(1);
  }
}



