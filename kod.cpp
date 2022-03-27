#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Bilgilendirme: Kod dev-c derleyicisinde çalýþýrken code blocks'da hata veriyor. 
//Büþra Kurun 210601036 ve Semra Sýla Ertuð 210601033

struct ogrenci_bilgi{  //ogrenciye ait tutulacak veriler
    char *ogrenci_ad[20];
    char *ogrenci_soyad[20];
    char ogrenci_bolum[50]={'B','i','l','g','i','s','a','y','a','r', ' ','M','u','h','e','n','d','i','s','l','i','g','i' ,'\0'};
    int *ogrenci_numara;
};

struct ders_bilgi { //derslere ait tutulacak veriler
    char ders_bolum[50]={'B','i','l','g','i','s','a','y','a','r', ' ','M','u','h','e','n','d','i','s','l','i','g','i' ,'\0'};
	int ders_kodu;
	char ders_adi[75];
	int ders_kredisi;
	int ders_akts;
};

struct ders_kayit_bilgi { //ders kayýtlarýna ait veriler
    int ders_yil={2022};
	char ders_donem[5]={'B','a','h','a','r'};
	struct ogrenci_bilgi;
    struct ders_bilgi;
	float basari_notu;
};

void ogrenci_kaydi_ekle () {
	FILE *dosya;
    struct ogrenci_bilgi ogrenci;
    int n;
    int ogrenci_sayisi; //sýnýf mevcudunu tanýmlama

	printf("Kac ogrenci girisi yapilacak? Lutfen ogrenci sayisini giriniz:"); //sýnýf mevcudunu sorma
    scanf("%d" ,&ogrenci_sayisi);

    if((dosya =fopen("OgrenciBilgi_faz1.txt", "a+"))==NULL){
    puts("Ogrenci bilgi dosyasi bulunamadi");
    exit(1);
    }
     else
       fprintf(dosya, " Ogrenci Bilgileri\n");
		fprintf(dosya, "/-----------------/\n\n");

    for(n=0;n<ogrenci_sayisi;n++)
    {
        printf("%d. Ogrenci ad: " , n+1); //öðrencinin adý
        scanf("%s",&ogrenci.ogrenci_ad);
        printf("%d.Ogrenci soyadi: " , n+1);
        scanf("%s",&ogrenci.ogrenci_soyad); // öðrencinin soyadý
        printf("Ogrenci bolum: %s\n" , ogrenci.ogrenci_bolum);
        printf("%d. Ogrencinin numarasi: " , n+1); //öðrenci numarasý
        scanf("%d", &ogrenci.ogrenci_numara);


	  //alýnan verilerin dosyada yazdýrýlmasý

        fprintf(dosya, "%d.Ogrenci Bilgileri\n Ad:%s\n", n+1,ogrenci.ogrenci_ad);
        fprintf(dosya, "Soyad:%s\n", ogrenci.ogrenci_soyad);
        fprintf(dosya, "Bolum:%s\n",  ogrenci.ogrenci_bolum);
        fprintf(dosya, "Numara:%d\n\n",  ogrenci.ogrenci_numara);


        //alýnan verilerin konsola yazdýrýlmasý

		fprintf(stdout, "Ad:%s\n",ogrenci.ogrenci_ad);
        fprintf(stdout, "Soyad:%s\n", ogrenci.ogrenci_soyad);
        fprintf(stdout, "Bolum:%s\n",  ogrenci.ogrenci_bolum);
        fprintf(stdout, "Numara:%d\n\n",  ogrenci.ogrenci_numara);

}

    	printf("Ogrenci Kaydi Basariyla Tamamlanmistir! \n");


    fclose(dosya); //oluþturulan dosyanýn kapanmasý
}

int main()
{
    ogrenci_kaydi_ekle ();
  

    return 0;
}

