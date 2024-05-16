shogi.exe : main.o masu.o display.o koma_flags.o tegoma_flags.o
	cc -o shogi.exe main.o masu.o display.o koma_flags.o tegoma_flags.o -lncursesw
main.o : main.c
	cc -c main.c
masu.o : masu.c
	cc -c masu.c
display.o : display.c
	cc -c display.c
koma_flags.o : koma_flags.c
	cc -c koma_flags.c
tegoma_flags.o : tegoma_flags.c
	cc -c tegoma_flags.c
clean:
	rm main.o masu.o display.o koma_flags.o tegoma_flags.o