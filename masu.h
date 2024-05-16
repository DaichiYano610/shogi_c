
typedef struct{
    int exist; /*0は駒なし，1はplayer1 2はplayer2*/
    int nameNum; /*1=角,2=飛,3=香,4=桂,5=銀,6=金,7=歩,8=王*/
    int nari;   /*駒の成り判定*/
    int flag;   /*動けるマスへのflag*/
}MASU;

extern MASU a[9][9];

void init_koma(void);
void print_masu(void);
int get_nameNum(int x,int y);
int get_exist(int x, int y);
int get_flag(int x,int y);
int get_nari(int x,int y);
int *get_tegoma(int player);
int get_teban(void);
void zero_masu(int x,int y);
void allzero_flag(void);
void set_koma(int x,int y);
void set_nari(void);
void set_to(int x,int y);
void set_teban(void);
int select_koma(int x,int y);/*駒を選択しflagを立てる．戻り値はa[][].exist*/
int check_nari(void);
int check_flag(int x, int y);
void add_tegoma(int koma,int exist);
void tomove_koma(void);


/*持ち駒関係*/
int select_tegoma(int koma );
int hit_tegoma(int x,int y);
