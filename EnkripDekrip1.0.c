#include <stdio.h>
#include <stdlib.h>
int hitung = 0; // inisiasi dengan angka 0 untuk menghitung maksimal percobaan login masuk yaitu 3
char pilihan; // untuk memilih pilihan
void menu(); //prototype
void judulprogram();//prototype
int i; // membantu looping ekripsi dekripsi Ascii
char string[100]; // inputan berupa string yang akan didekripsi atau enkripsi

FILE *hasilenkripsi;
int main()
{
	login(); // fungsi login dipanggil 
	menu(); // fungsi menu di panggil
}
void petunjukprogramEDAscii()// fungsi menu pentunjuk program enkripsi dekripsi
{
	system("cls"); // membuat layar menjadi bersih 
	printf("\n\n-------------------------------------------------------------------------------\n");
	printf("\t\t\tPETUNJUK PROGRAM ENKRIPSI DEKRIPSI Ascii							               \n");               
	printf("-------------------------------------------------------------------------------\n");
	printf("Tekan [1] Untuk melakukan Ekripsi dan Dekripsi Dengan Metode RSA \n\n");
	printf("Tekan [2] Untuk melakukan Ekripsi dan Dekripsi Dengan Metode +- Nilai Ascii\n\n");
	printf("Tekan [3] Untuk Menuju Petunjuk Program Enkripsi Dekripsi \n\n");
	printf("Tekan [4] Untuk Keluar dari Program \n\n");
	system("pause");// mendelay program sampai ada inputan
	menu(); // memanggil fungsi menu
}

void petunjukprogramED()// fungsi menu pentunjuk program enkripsi dekripsi
{
	system("cls"); // membuat layar menjadi bersih 
	printf("\n\n-------------------------------------------------------------------------------\n");
	printf("\t\t\tPETUNJUK PROGRAM ENKRIPSI DEKRIPSI							               \n");               
	printf("-------------------------------------------------------------------------------\n");
	printf("Tekan [1] Untuk melakukan Ekripsi dan Dekripsi Dengan Metode RSA \n\n");
	printf("Tekan [2] Untuk melakukan Ekripsi dan Dekripsi Dengan Metode +- Nilai Ascii\n\n");
	printf("Tekan [3] Untuk Menuju Petunjuk Program Enkripsi Dekripsi \n\n");
	printf("Tekan [4] Untuk Keluar dari Program \n\n");
	system("pause");// mendelay program sampai ada inputan
	menu(); // memanggil fungsi menu
}
void DekripsiAscii() // fungsi dekripsi nilai Ascii
{
	printf("\n\tMasukan Text:\t");
	fflush (stdin); // menghapus outputan sebelumnya
	fgets(string,100,stdin); // memeriksa inputan yang akan di enkripsi
	for(i = 0; (i < 100 && string[i] != '\0'); i++) //string akan disimpan sampai string jika kurang dari 100 dan tidak null(\0)
	{
		string[i] = string[i] - 3; //the key for encryption is 3 that is subtracted to ASCII value
	}
	printf("\n\tHasil Dekripsi: %s\n", string);
	system("pause"); // mendelay program sampai ada inputan
	menu(); // memanggil fungsi menu
}
int EnkripsiAscii() // fungsi enkripsi nilai Ascii
{	
	printf("\n\tMasukan Text:\t");
	fflush (stdin); // menghapus outputan sebelumnya
	fgets(string,100,stdin); // memeriksa inputan yang akan di enkripsi
	for(i = 0; (i < 100 && string[i] != '\0'); i++) // string akan disimpan sampai string jika kurang dari 100 dan tidak null(\0)
	{
		string[i] = string[i] + 3; //the key for encryption is 3 that is added to ASCII value
	}
	printf("\n\tHasil Dekripsi: %s\n", string);
	hasilenkripsi = fopen ("hasilenkripsi.txt", "w");  // membuka file hasilenkripsi.txt jika tidak ada maka membuatnya "w"
	if(hasilenkripsi == NULL)
	{
		printf("Hasil Enkripsi Tidak dapat disimpan ");
	}
	fprintf (hasilenkripsi, "%s", string);  // memasukan nilai di string ke hasilenkripsi
	fclose (hasilenkripsi); //menutup folder e
	system("pause"); // mendelay program sampai ada inputan
	menu(); // memanggil fungsi menu
	
}

void helpEDAscii()
{
	system("cls"); // membuat layar menjadi bersih 
	printf("\n\n-------------------------------------------------------------------------------\n");
	printf("\t\tPETUNJUK PROGRAM ENKRIPSI DEKRIPSI +- NILAI ASCII					               \n");               
	printf("-------------------------------------------------------------------------------\n");
	printf("Tekan [1] Untuk melakukan Ekripsi Lalu Masukan Text yang akan di Enkripsi\n\n");
	printf("Tekan [2] Untuk melakukan Dekripsi Lalu Masukan Text yang akan di Dekripsi\n\n");
	printf("Tekan [3] Untuk Menuju Petunjuk Program Enkripsi Dekripsi \n\n");
	printf("Tekan [4] Untuk Keluar dari Program \n\n");
	system("pause");// mendelay program sampai ada inputan
	system("cls"); // membuat layar menjadi bersih 
	judulprogram(); // memanggil fungsi judulprogram
	EDAscii(); // memanggil fungsi EDAscii
}
int EDAscii() // fungsi enkripsi dekripsi dengan -+ Ascii
{
	fflush(stdin); // menghapus input sebelumnya 
	printf("\n\tSilahkan Pilih :\n");
	printf("\t\t[1] Text di Enkripsi\n");
	printf("\t\t[2] Text di Deskripsi\n");
	printf("\t\t[3] Help\n");
	printf("\t\t[4] Kembali\n");
	printf("\t\t[5] Keluar\n");
	printf("\n\t\tPilihan:");
	scanf("%d", &pilihan);
	//fgets()
	switch(pilihan)
	{
		case 1:
			EnkripsiAscii(); // memanggil fungsi EnkripsiAscii
			break;
		case 2:
	   		DekripsiAscii();// memanggil fungsi DekripsiAscii
	      	break;
		case 3:
			helpEDAscii(); // memanggil fungsi helpEDAscii
		case 4:
			menu(); // memanggil fungsi menu
			break;	
		case 5:
			exit(1); // keluar dari program	
			break;
		default:
	  		printf("\n\tHarap Masukan Pilihan Yang Benar!\n");
			system("Pause"); // mendelay program sampai ada inputan
			system("cls"); // membuat layar menjadi bersih 
			fflush(stdin); // menghapus input sebelumnya 
			judulprogram(); // memanggi fungsi judulprogram
			EDAscii(); // memanggil fungsi menu
	  		break;
	}
}
void judulprogram()
{
	printf("---------------------------------------------------------------------\n");
	printf("\t\tPROGRAM ENKRIPSI DAN DEKRIPSI\n");
	printf("\t\tDibuat Oleh Fahriza dan Samuel\n");
	printf("---------------------------------------------------------------------\n");
}
void menu() // fungsi menu pada program dekripsi dan enkripsi
{
	system("cls"); // membuat layar menjadi bersih 
	judulprogram();
	printf("\tSilahkan Pilih\n");
	printf("\t\t[1] Program Enkripsi dan Dekripsi dengan RSA\n");
	printf("\t\t[2] Program Enkripsi dan Dekripsi dengan +- Nilai ASCII\n");
	printf("\t\t[3] Help\n");
	printf("\t\t[4] Keluar\n");
	printf("\n\t\tPilihan  :");
	scanf("%d",&pilihan);
	switch(pilihan)
	{
		case 1:
      		printf("\n\t\t[Sedang Dalam Pembuatan]\n");
      		system("pause");
      		system("cls");
      		menu();
			break;
		case 2:
			EDAscii();
			break;
		case 3:
      		petunjukprogramED();
			break;
		case 4:
      		exit(1); // keluar dari program
			break;	
		default : 
			printf("\n\tHarap Masukan Pilihan Yang Benar!\n");
			system("Pause"); // mendelay program sampai ada inputan
			system("cls"); // membuat layar menjadi bersih lagi
			fflush(stdin); // menghapus input sebelumnya 
			menu();
			break;
	}
}

int login()// fungsi login untuk verifikasi data supaya lebih aman
{
	char username[15],password[15]; // type char untuk username dan password dengan ukuran data maks 10
	printf("---------------------------------------------------------------------\n");
	printf("\t\tPROGRAM ENKRIPSI DAN DEKRIPSI\n");
	printf("\t\t\t   LOGIN \n");
	printf("\t\tDibuat Oleh Fahriza dan Samuel\n");
	printf("---------------------------------------------------------------------\n");
    printf("\tMasukan Username : ");
    scanf("%s",&username);
    printf("\tMasukan Password : ");
   	scanf("%s",&password);
    if(strcmp(username,"fahrizasamuel")==0 && strcmp(password,"keren")==0)//strcmp yaitu membandingkan isi yang pada dua data
	{
        printf("\n\t\t[Login sukses]\n");
        system("pause");
        system("cls");
    }
    else
	{
		hitung = hitung+1;
        printf("\n\t[ Username dan Password tidak sama [%d] ] \n", hitung);
        if(hitung < 3)
        {
        	printf("\n\t[ Percobaan Login Maksimal 3 kali ]\n");
        	system("pause"); // mendelay program sampai ada inputan
        	system("cls"); // membuat layar menjadi bersih lagi
        	login();       
		}
		else
		{
			printf("\t[ Percobaan Login Sudah Melebihi Batas Maksimal ] \n");
			printf("\n\t[ Anda akan Keluar Otomatis ]");
			exit(1);
		}
    }	
}

