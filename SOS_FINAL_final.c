#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

void selamat_datang(void); //Menampilkan UI Selamat Datang
void tingkat_kesulitan(void); //Pilihan Difficulty dan Menu Permainan
void keterangan_difficult(void); //Penjelasan Tentang Difficulty
void inisialisasi_papan(void);
int jumlah_pemain(void); //Pilihan untuk Bermain Melawan Komputer atau Player Lain
void satu_player(void);
void dua_player(void);
void komputer(void);
void get_nama_satu_player(void); //Player 1 Memasukkan Nama
void get_nama_dua_player(void); //Player 1 dan 2 Memasukkan Nama
void gambar_papan(void); //Tampilan Papan Permainan dan Score
void bermain_player(int player); //Player Mengisi Kotak dan Huruf
int starttime(); //Waktu Mulai Permainan
int endtime(); //Waktu Akir Permainan
int verifikasi_kotak (int);
int cari_sos(int,int,char); //Mendapatkan Kata SOS dan Menambahkan Poin
int komputer_cari_os(void); //Bot Mendapatkan Kata SOS Jika Ada Kata OS
int komputer_cari_ss(void); //Bot Mendapatkan Kata SOS Jika Ada Kata SS
int random_kotak(void);
int simbol_random(void);
int game_selesai(void); //Menentukan Akhir Permainan
void pemenang(void); //Menentukan Pemenang Permainan
void player1_kalah(void); //Menampilkan UI Player 1 Kalah
void player2_kalah(void); //Menampilkan UI Player 2 Kalah
void player1_menang(void); //Menampilkan UI Player 1 Menang
void player2_menang(void); //Menampilkan UI Player 2 Menang
void draw(void); //Menampilkan UI Seri
int main_lagi(void); //Pilihan untuk Bermain Lagi atau Tidak
void bye(); //Menampilkan UI jika Player Tidak Bermain Lagi
void buat_file(); //
void tampilan_scoreboard(); //Menampilkan Papan Skor

typedef struct scoreboard{
	int score;
	char name[50];
	char enemy[50];
	char difficult[50];
}scoreboard;

char papan[30][30];
int Player1, Player2, Computer, players, n;
char pemain1[50],pemain2[50];


int main (){
	system ("color f2");
	while(1){
    	system("cls");
    	selamat_datang();
			getch();
    	tingkat_kesulitan();
    	inisialisasi_papan();

			if(jumlah_pemain()==1){
      			players=1;
      			get_nama_satu_player();
      			satu_player();
			}
    			else{
      				players=2;
      				get_nama_dua_player();
      				dua_player();
    			}
					buat_file();
					if(game_selesai()){
      					printf("game selesai\n");
      					pemenang();

						if (!main_lagi()){
							system("cls");
							bye();

            				break;
        				}
    				}
	}
return 0;
}

//Sebelum Permainan

//Menampilkan UI Selamat Datang
void selamat_datang(){
	printf ("\t\t\t\t  ____________________________________________________________\n");
  	printf ("\t\t\t\t________________________________________________________________ \n");
  	printf ("\t\t\t    ______________________________________________________________________ \n");
  	printf ("\t\t\t    ______________________________________________________________________ \n");
	printf("\n\t\t\t\t\t ____________________________________________\n");
	printf("\t\t\t\t\t\xb3  ________________________________________  \xb3\n");
	printf("\t\t\t\t\t\xb3 \xb3                                        \xb3 \xb3\n");
	printf("\t\t\t\t\t\xb3 \xb3             SELAMAT DATANG             \xb3 \xb3\n");
	printf("\t\t\t\t\t\xb3 \xb3                   DI                   \xb3 \xb3\n");
	printf("\t\t\t\t\t\xb3 \xb3       ______    ______    ______       \xb3 \xb3\n");
	printf("\t\t\t\t\t\xb3 \xb3      |  ____|  |  __  |  |  ____|      \xb3 \xb3\n");
	printf("\t\t\t\t\t\xb3 \xb3      | |____   | |  | |  | |____       \xb3 \xb3\n");
	printf("\t\t\t\t\t\xb3 \xb3      |____  |  | |  | |  |_____ |      \xb3 \xb3\n");
	printf("\t\t\t\t\t\xb3 \xb3       ____| |  | |__| |   ____| |      \xb3 \xb3\n");
	printf("\t\t\t\t\t\xb3 \xb3      |______|  |______|  |______|      \xb3 \xb3\n");
	printf("\t\t\t\t\t\xb3 \xb3                                        \xb3 \xb3\n");
	printf("\t\t\t\t\t\xb3 \xb3               GITGUDW <3               \xb3 \xb3\n");
	printf("\t\t\t\t\t\xb3 \xb3________________________________________\xb3 \xb3\n");
	printf("\t\t\t\t\t\xb3____________________________________________\xb3\n");
	printf("\n\n\t\t\t\t\t           Press Any Key To Continue");
	printf ("\n\n\n\t\t\t    ______________________________________________________________________ \n");
  	printf ("\t\t\t    ______________________________________________________________________ \n");
  	printf ("\t\t\t\t________________________________________________________________ \n");
  	printf ("\t\t\t\t  ____________________________________________________________");
}

//Pilihan Difficulty dan Menu Permainan
void tingkat_kesulitan(){
	system("cls");
	printf ("\t\t\t\t  ____________________________________________________________\n");
  	printf ("\t\t\t\t________________________________________________________________ \n");
  	printf ("\t\t\t    ______________________________________________________________________ \n");
  	printf ("\t\t\t    ______________________________________________________________________ \n");
		do{
			printf("\n\t\t\t\t       Pilih Salah Satu Difficulty atau Menu Di Bawah Ini\n");
			printf("\t\t\t _____________________________________________________________________________\n");
    		printf("\t\t\t\xb3              \xb3                \xb3              \xb3              \xb3               \xb3\n");
    		printf("\t\t\t\xb3 1.Easy (3*3) \xb3 2.Medium (6*6) \xb3 3.Hard (9*9) \xb3 4.Petunjuk   \xb3 5.Papan Score \xb3\n");
    		printf("\t\t\t\xb3______________\xb3________________\xb3______________\xb3______________\xb3_______________\xb3\n");
			printf("\n\t\t\t\tPilihan (1,2,3,4 atau 5) : ");
    		scanf("%d", &n);
				switch (n) {
			      	case 1: //Pilihan Difficulty Easy dan Papan Ukuran 3*3
			        	n=3;
			      		break;
			      	case 2: //Pilihan Difficulty Medium dan Papan Ukuran 6*6
			        	n=6;
			      		break;
			      	case 3: //Pilihan Difficulty Hard dan Papan Ukuran 9*9
			        	n=9;
              			break;
              		case 4: //Pilihan Menu Tentang Keterangan Difficulty
                		keterangan_difficult();
						printf("\n\t\t\t\tPress Any Key To Continue\n");
                		getch();
                		n=0;
                		system("cls");
			      		break;
					case 5: //Pilihan Menu untuk Menampilkan ScoreBoard
						printf("\n\t\t\tNama\t\tScore\t\tLawan\t\tDifficulty");
						tampilan_scoreboard();
						printf("\n\n\t\t\t\tPress Any Key To Continue\n");
						getch();
						n=0;
						break;
					default :
						n=0;
						if(n==0){
							printf("\n");
						}
				}
		}
		while((n==0));
return;
}

//Penjelasan Tentang Difficulty dan Waktu Pengisian
void keterangan_difficult(){
  	printf("\n\t\t\tPetunjuk :");
  	printf("\n\t\t\t1. Easy waktu mengisi kotak adalah 7 detik\n");
  	printf("\t\t\t2. Medium waktu mengisi kotak adalah 15 detik\n");
  	printf("\t\t\t3. Hard waktu mengisi kotak adalah 20 detik\n");
}

void inisialisasi_papan(){
	int baris,kolom;
		for (baris = 0; baris < n; baris++){
			for (kolom=0; kolom<n; kolom++){
				papan[baris][kolom]=' ';
			}
		}
	Player1 = 0;
	Player2 = 0;
	Computer = 0;
return;
}

//Pilihan untuk Bermain Melawan Komputer atau Player Lain
int jumlah_pemain(){
	system ("cls");
  	printf ("\t\t\t\t  ____________________________________________________________\n");
  	printf ("\t\t\t\t________________________________________________________________ \n");
  	printf ("\t\t\t    ______________________________________________________________________ \n");
  	printf ("\t\t\t    ______________________________________________________________________ \n");

	int jawaban;
		printf ("\n\t\t\t\tJumlah Pemain  (1 atau 2) : "); //Pilihan 1 untuk Melawan Komputer dan Pilihan 2 untuk Melawan Player Lain
  			do{
				scanf("%d",&jawaban);

				if(jawaban !=1 && jawaban !=2){
      			printf("\n\t\t\t\tMasukkin Angka (1 atau 2) : ");
    			}
  			}
			while ((jawaban<1) || (jawaban>2));
  	return jawaban;
}

void satu_player(){
	do{
	  bermain_player(1);
		if (!game_selesai()){
		  komputer();
		}
	}
	while(!game_selesai());
return;
}

void dua_player(){
	do{
   	  	bermain_player(1);
   			if(game_selesai()){
			return;
   			}
   	  	bermain_player(2);
  	}
  	while(!game_selesai());
return;
}

void komputer(){
	system("cls");
  	int kotak;
  	int baris, kolom;
  	char simbol;
		do{
    	  gambar_papan();
    		if (komputer_cari_os()){
      			kotak = komputer_cari_os();
      			simbol='S';
    		}
    		else if(komputer_cari_ss()){
      			kotak = komputer_cari_ss();
      			simbol='O';
			}
    		else{
      			kotak=random_kotak();
      			simbol=simbol_random();
      		}

		  baris =(kotak-1)/n;
		  kolom =(kotak-1)%n;
		  papan[baris][kolom]=simbol;
		  printf("Komputer Menaruh Simbol Di %c Pada Kotak %d\n",simbol,kotak);
		}
		while(cari_sos(kotak, 3, simbol) && !game_selesai());
return;
}

//Player 1 Memasukkan Nama
void get_nama_satu_player(void){
	printf("\n\t\t\t\tNama Pemain 1(disarankan 5 huruf) : ");
	scanf("%s",pemain1);
}

//Player 1 dan 2 Memasukkan Nama
void get_nama_dua_player(void){
	printf("\n\t\t\t\tNama Pemain 1(disarankan 5 huruf) : ");
	scanf("%s",pemain1);
  	printf("\n\t\t\t\tNama Pemain 2(disarankan 5 huruf) : ");
  	scanf("%s",pemain2);
}

//Tampilan Papan Permainan dan Score
void gambar_papan(){
 	system("cls");
 	printf ("\t\t\t\t  ____________________________________________________________\n");
  	printf ("\t\t\t\t________________________________________________________________ \n");
  	printf ("\t\t\t    ______________________________________________________________________ \n");
  	printf ("\t\t\t    ______________________________________________________________________ \n");

		if(players == 1){ //Tampilan Score Player 1 dan Komputer
  			printf("\n\t\t\t\tSCORE\n\t\t\t\t%s : %d poin || Komputer : %d poin\n",pemain1, Player1, Computer);
 		}
 		else if (players == 2){ //Tampilan Score Player 1 dan Player 2
  			printf("\n\t\t\t\tSCORE\n\t\t\t\t%s : %d poin || %s : %d poin\n",pemain1, Player1,pemain2, Player2);
 		}

	int baris, kolom, ii, b=1,i,j; //Tampilan Papan Permainan
 		printf("\n\t\t\t\t");
 		printf(" ");
 			for( ii=1; ii<((n*7)+2); ii++){
   				printf("-");
 			}
 		printf("\n\t\t\t\t");
 			for ( baris=0; baris<n; baris++){
    			int  a=4;
  					printf(" |");
  						for (kolom=0; kolom<n; kolom++){
      						printf("   %c  |",papan[baris][kolom]);
  						}
  					printf(" \n\t\t\t\t");
  						if (baris != n){
   							printf(" ");
   								for( ii=1; ii<((n*6)+2); ii++){
        							if (ii==a){
										if(b>9 && papan[(b-1)/n][(b-1)%n]==' '){
            								printf("%d",b);
          								}
          								else if ( b<=9 && papan[(b-1)/n][(b-1)%n]==' '){
             								printf("0%d",b);
           								}
           								else
											printf("--");
              								b++;
              								a=a+6;
									}
        							else{
          								printf("-");
        							}
   								}
   							printf(" \n\t\t\t\t");
  						}
 			}
return;
}

//Waktu Mulai Permainan
int starttime(){
	clock_t t;
	t = clock();
return t;
}

//Waktu Akhir Permainan
int endtime(){
    clock_t t;
    t = clock();
return t;
}

void bermain_player(int player){
  	int waktu,batas_waktu;
  		switch (n){
    		case 3:
      			batas_waktu=7;
    		break;
    		case 6:
      			batas_waktu=15;
    		break;
    		case 9:
      			batas_waktu=20;
    		break;
		}

	double waktu_detik;
  		int kotak;
  		int baris, kolom;
  		char simbol;
  			do{
				waktu=starttime();
				gambar_papan();
            	printf("\n\t\t\t\tPemain %d Pilih Nomor dari Kotak : ",player);
        		scanf("%d", &kotak);

					while(!verifikasi_kotak(kotak)){
      			  		printf("\n\t\t\t\tPilih Nomor yang Tersedia pada Kotak : ");
      			  		scanf("%d",&kotak);
    				}
						baris = (kotak-1)/n;
						kolom = (kotak-1)%n;
						printf("\n\t\t\t\tS atau O                        : ", kotak);
  						scanf("%c",&simbol);

					while ((simbol != 'S') && (simbol != 's') && (simbol != 'O') && (simbol != 'o')){
				  		scanf("%c",&simbol);
					}
						if((simbol == 'S') || (simbol == 's')){
				  			simbol = 'S';
						}
						else{
							simbol = 'O';
				  		}

				waktu=endtime()-waktu;
				waktu_detik=((double)waktu)/CLOCKS_PER_SEC;

					if(waktu_detik<=batas_waktu){
						papan[baris][kolom] = simbol;
				  	}
					else{
						printf("\n\t\t\t\tYah, Waktunya Habis :(");
						getch();
						break;
				  	}
			}
			while(cari_sos (kotak, player, simbol) && !game_selesai());
return;
}

int verifikasi_kotak(int kotak){
	int baris, kolom;
		if(kotak>0 && kotak<((n*n)+1)){
	    	baris = (kotak-1)/n;
	     	kolom = (kotak-1)%n;

	   			if (papan[baris][kolom] ==' '){
					return 1;
	    		}
	    		else{
		    		return 0;
	     		}
  		}
  		else{
			return 0;
		}
}

//Mendapatkan Kata SOS untuk Player dan Menambahkan Poin
int cari_sos(int kotak, int player, char simbol){
	int baris,kolom,sos;
		baris = (kotak-1)/n;
		kolom = (kotak-1)%n;
		sos = 0;
			if(simbol == 'S'){
				if ((papan[baris][kolom-2] == 'S') && (papan[baris][kolom-1] == 'O')){
					sos++;
				}
				if ((papan[baris][kolom+1]== 'O') && (papan[baris][kolom+2] == 'S')){
					sos++;
				}
				if((papan[baris+1][kolom] == 'O') && (papan[baris+2][kolom] == 'S')){
					sos++;
				}
				if((papan[baris-1][kolom] == 'O') && (papan[baris-2][kolom] == 'S')){
					sos++;
				}
				if((papan[baris+1][kolom+1] == 'O') && (papan[baris+2][kolom+2] == 'S')){
					sos++;
				}
				if((papan[baris-1][kolom-1] == 'O') && (papan[baris-2][kolom-2] == 'S')){
					sos++;
				}
				if((papan[baris+1][kolom-1] == 'O') && (papan[baris+2][kolom-2] == 'S')){
					sos++;
				}
				if((papan[baris-1][kolom+1] == 'O') && (papan[baris-2][kolom+2] == 'S')){
					sos++;
				}
  			}

  			else if(simbol == 'O'){
				if((papan[baris+1][kolom] == 'S') && (papan[baris-1][kolom] == 'S')){
					sos++;
				}
				if((papan[baris][kolom+1] == 'S') && (papan[baris][kolom-1] == 'S')){
					sos++;
				}
				if((papan[baris+1][kolom+1] == 'S') && (papan[baris-1][kolom-1] == 'S')){
					sos++;
				}
				if((papan[baris+1][kolom-1] == 'S') && (papan[baris-1][kolom+1] == 'S')){
					sos++;
				}
  			}

        	if (player == 1){ //Tambahan Poin Jika Player 1 Mendapatkan Kata SOS
            	Player1= Player1+sos;
    		}
        		else if (player == 2){ //Tambahan Poin Jika Player 2 Mendapatkan Kata SOS
                	Player2= Player2+sos;
        		}
        			else if (player == 3){ //Tambahan Poin Jika Komputer Mendapatkan Kata SOS
                		Computer= Computer+sos;
        			}

			if (sos>0){
				return 1;
			}
				else{
					return 0;
				}
}

//Bot Mendapatkan Kata SOS Jika Ada Kata OS
int komputer_cari_os(){
	int kotak;
	int ii;
  	int jj;
		for (ii=0; ii<n; ii++){

			for(jj=0; jj<n; jj++){
		   		kotak = ((ii*n) +jj)+1;

				if(verifikasi_kotak(kotak)){
					if((papan[ii][jj+1]=='O') && (papan[ii][jj+2] == 'S')){
						return kotak;
					}
                    if((papan[ii][jj-1]=='O') && (papan[ii][jj-2] == 'S')){
                        return kotak;
                    }
					if ((papan[ii+1][jj] == 'O') && (papan[ii+2][jj] =='S')){
						return kotak;
					}
                	if ((papan[ii-1][jj] == 'O') && (papan[ii-2][jj] =='S')){
                        return kotak;
                    }
					if((papan[ii+1][jj+1] == 'O') && (papan[ii+2][jj+2] == 'S')){
                        return kotak;
                    }
                    if((papan[ii-1][jj-1] == 'O') && (papan[ii-2][jj-2] == 'S')){
                        return kotak;
                    }
                    if((papan[ii+1][jj-1] == 'O') && (papan[ii+2][jj-2] == 'S')){
                        return kotak;
                    }
                    if((papan[ii-1][jj+1] == 'O') && (papan[ii-2][jj+2] == 'S'))
                    {
                        return kotak;
                    }
		  		}
			}
		}
return 0;
}

//Bot Mendapatkan Kata SOS Jika Ada Kata SS
int komputer_cari_ss(){
	int kotak;
  	int ii;
  	int jj;

		for ( ii=0; ii<n; ii++){
        	for( jj=0; jj<n; jj++){
            	kotak = ((ii*n) +jj)+1;

                if(verifikasi_kotak(kotak)){
					if((papan[ii][jj+1]=='S') && (papan[ii][jj-1] == 'S')){
                        return kotak;
                    }
                    if ((papan[ii+1][jj] == 'S') && (papan[ii-1][jj] =='S')){
                        return kotak;
                    }
                    if((papan[ii+1][jj+1] == 'S') && (papan[ii-1][jj-1] == 'S')){
                        return kotak;
                    }
                    if((papan[ii+1][jj-1] == 'S') && (papan[ii-1][jj+1] == 'S')){
                        return kotak;
                    }
                }
  			}
      	}
return 0;
}

int random_kotak(void){
	int random;
  		do{
  			random=rand()%((n*n)+1);
  		  		if(verifikasi_kotak(random)){
    				return random;
  		  		}
		}
		while(!verifikasi_kotak(random));
return 0;
}

int simbol_random(void){
  	int so[2] = {79,83};
		return so[rand()%2];
}

//Menentukan Akhir Permainan
int game_selesai(){
	int baris, kolom, a=n*n;
  	for (baris=0; baris<n; baris++){
    	for(kolom=0;kolom<n;kolom++){
      		if(a==0){
        		return 1;
      		}
      		else if (papan[baris][kolom]==' '){
        		return 0;
        		a=a-1;
     		}
    	}
	}
}

//Menentukan Pemenang Permainan
void pemenang(){
	system("cls");
		if ((Player1 > Player2) && (Player1 > Computer)){
			player1_menang(); //Jika Player 1 Menang
		}
		else if (Player2> Player1){
			player2_menang(); //Jika Player 2 Menang
		}
		else if (Computer > Player1){
			player1_kalah(); //Jika Komputer Menang
		}
		else{
			draw(); //Jika Seri
		}
}

//Menampilkan UI Player 1 Kalah
void player1_kalah(void){
	system ("cls");
  	printf("\n\n\n\n\n\n\n");
  	printf("\t\t\t\t ____________________%s You Are a_____________________\n",pemain1);
  	printf("\t\t\t\t ________________________________________________________\n");
  	printf("\t\t\t\t\xb3                                                        \xb3\n");
  	printf("\t\t\t\t\xb3       _        ______   ______   ______   ______       \xb3\n");
  	printf("\t\t\t\t\xb3      | |      |  __  | |  ____| |  __  | |  ____|      \xb3\n");
  	printf("\t\t\t\t\xb3      | |      | |  | | | |____  | |__| | | |           \xb3\n");
  	printf("\t\t\t\t\xb3      | |      | |  | | |____  | |  ____| | |           \xb3\n");
  	printf("\t\t\t\t\xb3      | |____  | |__| |  ____| | | |____  | |           \xb3\n");
  	printf("\t\t\t\t\xb3      |______| |______| |______| |______| |_|           \xb3\n");
  	printf("\t\t\t\t\xb3                                                        \xb3\n");
  	printf("\t\t\t\t\xb3________________________________________________________\xb3\n");
}

//Menampilkan UI Player 2 Kalah
void player2_kalah(void){
  	system ("cls");
  	printf("\n\n\n\n\n\n\n");
  	printf("\t\t\t\t ____________________%s You Are a_____________________\n",pemain2);
  	printf("\t\t\t\t ________________________________________________________\n");
  	printf("\t\t\t\t\xb3                                                        \xb3\n");
  	printf("\t\t\t\t\xb3       _        ______   ______   ______   ______       \xb3\n");
  	printf("\t\t\t\t\xb3      | |      |  __  | |  ____| |  __  | |  ____|      \xb3\n");
  	printf("\t\t\t\t\xb3      | |      | |  | | | |____  | |__| | | |           \xb3\n");
  	printf("\t\t\t\t\xb3      | |      | |  | | |____  | |  ____| | |           \xb3\n");
  	printf("\t\t\t\t\xb3      | |____  | |__| |  ____| | | |____  | |           \xb3\n");
  	printf("\t\t\t\t\xb3      |______| |______| |______| |______| |_|           \xb3\n");
  	printf("\t\t\t\t\xb3                                                        \xb3\n");
  	printf("\t\t\t\t\xb3________________________________________________________\xb3\n");
}

//Menampilkan UI Player 1 Menang
void player1_menang(void){
  	system ("cls");
  	printf("\n\n\n\n\n\n\n");
    printf("\t\t\t ______________________________________________________________________\n");
    printf("\t\t\t\xb3  __________________________________________________________________  \xb3\n");
    printf("\t\t\t\xb3 \xb3                                                                  \xb3 \xb3\n");
    printf("\t\t\t\xb3 \xb3                          %s YOU ARE                           \xb3 \xb3\n",pemain1);
    printf("\t\t\t\xb3 \xb3                                                                  \xb3 \xb3\n");
    printf("\t\t\t\xb3 \xb3                               A                                  \xb3 \xb3\n");
    printf("\t\t\t\xb3 \xb3       _       _   _   _______   _______   _______   ______       \xb3 \xb3\n");
    printf("\t\t\t\xb3 \xb3      | |     | | | | |  ___  | |  ___  | |  ___  | |  ____|      \xb3 \xb3\n");
    printf("\t\t\t\xb3 \xb3      | |  _  | | | | | |   | | | |   | | | |___| | | |           \xb3 \xb3\n");
    printf("\t\t\t\xb3 \xb3      | | | | | | | | | |   | | | |   | | |  _____| | |           \xb3 \xb3\n");
    printf("\t\t\t\xb3 \xb3      | |_| |_| | | | | |   | | | |   | | | |_____  | |           \xb3 \xb3\n");
    printf("\t\t\t\xb3 \xb3      |_________| |_| |_|   |_| |_|   |_| |_______| |_|           \xb3 \xb3\n");
    printf("\t\t\t\xb3 \xb3                                                                  \xb3 \xb3\n");
    printf("\t\t\t\xb3 \xb3__________________________________________________________________\xb3 \xb3\n");
    printf("\t\t\t\xb3______________________________________________________________________\xb3\n");
}

//Menampilkan UI Player 2 Menang
void player2_menang(void){
  	system ("cls");
 	printf("\n\n\n\n\n\n\n");
	printf("\t\t\t ______________________________________________________________________\n");
	printf("\t\t\t\xb3  __________________________________________________________________  \xb3\n");
	printf("\t\t\t\xb3 \xb3                                                                  \xb3 \xb3\n");
	printf("\t\t\t\xb3 \xb3                          %s YOU ARE                           \xb3 \xb3\n",pemain2);
	printf("\t\t\t\xb3 \xb3                                                                  \xb3 \xb3\n");
	printf("\t\t\t\xb3 \xb3                               A                                  \xb3 \xb3\n");
	printf("\t\t\t\xb3 \xb3       _       _   _   _______   _______   _______   ______       \xb3 \xb3\n");
	printf("\t\t\t\xb3 \xb3      | |     | | | | |  ___  | |  ___  | |  ___  | |  ____|      \xb3 \xb3\n");
	printf("\t\t\t\xb3 \xb3      | |  _  | | | | | |   | | | |   | | | |___| | | |           \xb3 \xb3\n");
	printf("\t\t\t\xb3 \xb3      | | | | | | | | | |   | | | |   | | |  _____| | |           \xb3 \xb3\n");
	printf("\t\t\t\xb3 \xb3      | |_| |_| | | | | |   | | | |   | | | |_____  | |           \xb3 \xb3\n");
	printf("\t\t\t\xb3 \xb3      |_________| |_| |_|   |_| |_|   |_| |_______| |_|           \xb3 \xb3\n");
	printf("\t\t\t\xb3 \xb3                                                                  \xb3 \xb3\n");
	printf("\t\t\t\xb3 \xb3__________________________________________________________________\xb3 \xb3\n");
	printf("\t\t\t\xb3______________________________________________________________________\xb3\n");
}

//Menampilkan UI Seri
void draw(void){
  	system ("cls");
  	printf("\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t ______________________________________________________\n");
	printf("\t\t\t\t\xb3  __________________________________________________  \xb3\n");
	printf("\t\t\t\t\xb3 \xb3                                                  \xb3 \xb3\n");
	printf("\t\t\t\t\xb3 \xb3            _   ______   ______   _       _       \xb3 \xb3\n");
	printf("\t\t\t\t\xb3 \xb3           | | |  ____| |____  | | |     | |      \xb3 \xb3\n");
	printf("\t\t\t\t\xb3 \xb3       ____| | | |       ____| | | |  _  | |      \xb3 \xb3\n");
	printf("\t\t\t\t\xb3 \xb3      |  __  | | |      |  __  | | | | | | |      \xb3 \xb3\n");
	printf("\t\t\t\t\xb3 \xb3      | |__| | | |      | |__| | | |_| |_| |      \xb3 \xb3\n");
	printf("\t\t\t\t\xb3 \xb3      |______| |_|      |______| |_________|      \xb3 \xb3\n");
	printf("\t\t\t\t\xb3 \xb3                                                  \xb3 \xb3\n");
	printf("\t\t\t\t\xb3 \xb3__________________________________________________\xb3 \xb3\n");
	printf("\t\t\t\t\xb3______________________________________________________\xb3\n");
}

//Pilihan untuk Bermain Lagi atau Tidak
int main_lagi(){
  	char respon;
  		printf("\n\t\t\t\t\t\tMau Main Lagi Gak? (Y/N) \n\t\t\t\t\t\t");
  			do{
    			respon = getchar();
			}
			while ((respon != 'y') && (respon != 'Y') && (respon != 'n') && (respon != 'N'));

  			if ((respon == 'y') || (respon == 'Y')){
    			return 1; //Jika Iya, Kembali ke Tampilan Awal Permainan
  			}
  			else{
    			return 0; //Jika Tidak, Menujua Tampilan UI Bye
  			}
}

//Menampilkan UI jika Player Tidak Bermain Lagi
void bye(){
	printf("\n\n\n\n\n\n");
	printf("\t\t\t\t ______________________________________________________\n");
	printf("\t\t\t\t\xb3  __________________________________________________  \xb3\n");
	printf("\t\t\t\t\xb3 \xb3                                                  \xb3 \xb3\n");
	printf("\t\t\t\t\xb3 \xb3      _         _     _   _______          _      \xb3 \xb3\n");
	printf("\t\t\t\t\xb3 \xb3     | |       | |   | | |  ___  |    _   | \\     \xb3 \xb3\n");
	printf("\t\t\t\t\xb3 \xb3     | |_____  | |___| | | |___| |   |_|   \\ \\    \xb3 \xb3\n");
	printf("\t\t\t\t\xb3 \xb3     |  ___  | |_____  | |  _____|    _     | |   \xb3 \xb3\n");
	printf("\t\t\t\t\xb3 \xb3     | |___| |  _____| | | |_____    |_|   / /    \xb3 \xb3\n");
	printf("\t\t\t\t\xb3 \xb3     |_______| |_______| |_______|        |_/     \xb3 \xb3\n");
	printf("\t\t\t\t\xb3 \xb3                                                  \xb3 \xb3\n");
	printf("\t\t\t\t\xb3 \xb3__________________________________________________\xb3 \xb3\n");
	printf("\t\t\t\t\xb3______________________________________________________\xb3\n");
}

void buat_file(){
	scoreboard *s;
	FILE *fp;
	int i=0;
	char com[50]="komputer";
	char easy[50]="Easy";
	char medium[50]="Medium";
	char hard[50]="Hard";
	s = (scoreboard*)calloc(players, sizeof(scoreboard));
	fp=fopen("scoreboard.txt","a");
		if(players==1){
			s[i].score=Player1;
			fflush(stdin);
			strcpy(s[i].name,pemain1);
			fflush(stdin);
			strcpy(s[i].enemy, com);
			fflush(stdin);

				switch(n){
					case 3:
						strcpy(s[i].difficult, easy);
					break;
					case 6 :
						strcpy(s[i].difficult, medium);
					break;
					case 9 :
						strcpy(s[i].difficult, hard);
					break;
				}
			fwrite(&s[i],sizeof(scoreboard),1,fp);
		}
		if(players==2){
			s[i].score=Player1;
			fflush(stdin);
			strcpy(s[i].name,pemain1);
			fflush(stdin);
			strcpy(s[i].enemy, pemain2);
			fflush(stdin);
				switch(n){
					case 3:
						strcpy(s[i].difficult, easy);
					break;
					case 6 :
						strcpy(s[i].difficult, medium);
					break;
					case 9 :
						strcpy(s[i].difficult, hard);
					break;
				}
			fwrite(&s[i],sizeof(scoreboard),1,fp);
			i++;
			s[i].score=Player2;
			fflush(stdin);
			strcpy(s[i].name,pemain2);
			fflush(stdin);
			strcpy(s[i].enemy, pemain1);
			fflush(stdin);
				switch(n){
					case 3:
						strcpy(s[i].difficult, easy);
					break;
					case 6 :
						strcpy(s[i].difficult, medium);
					break;
					case 9 :
						strcpy(s[i].difficult, hard);
					break;
				}
			fwrite(&s[i],sizeof(scoreboard),1,fp);
		}
	fclose(fp);
}

//Menampilkan Papan Skor
void tampilan_scoreboard(){
	scoreboard s1;
	FILE *fp;
	fp=fopen("scoreboard.txt","r");
		while(fread(&s1,sizeof(scoreboard),1,fp)){
			printf("\n\t\t\t%s\t\t%d\t\t%s\t\t%s",s1.name,s1.score,s1.enemy,s1.difficult); //Menampilkan Nama,Score,Lawan, dan Difficulty
		}
	fclose(fp);
}
