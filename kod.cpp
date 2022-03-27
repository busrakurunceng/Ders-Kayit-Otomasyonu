#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Bilgilendirme: Kod dev-c derleyicisinde �al���rken code blocks'da hata veriyor. 
//B��ra Kurun 210601036 ve Semra S�la Ertu� 210601033

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

struct ders_kayit_bilgi { //ders kay�tlar�na ait veriler
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
    int ogrenci_sayisi; //s�n�f mevcudunu tan�mlama

	printf("Kac ogrenci girisi yapilacak? Lutfen ogrenci sayisini giriniz:"); //s�n�f mevcudunu sorma
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
        printf("%d. Ogrenci ad: " , n+1); //��rencinin ad�
        scanf("%s",&ogrenci.ogrenci_ad);
        printf("%d.Ogrenci soyadi: " , n+1);
        scanf("%s",&ogrenci.ogrenci_soyad); // ��rencinin soyad�
        printf("Ogrenci bolum: %s\n" , ogrenci.ogrenci_bolum);
        printf("%d. Ogrencinin numarasi: " , n+1); //��renci numaras�
        scanf("%d", &ogrenci.ogrenci_numara);


	  //al�nan verilerin dosyada yazd�r�lmas�

        fprintf(dosya, "%d.Ogrenci Bilgileri\n Ad:%s\n", n+1,ogrenci.ogrenci_ad);
        fprintf(dosya, "Soyad:%s\n", ogrenci.ogrenci_soyad);
        fprintf(dosya, "Bolum:%s\n",  ogrenci.ogrenci_bolum);
        fprintf(dosya, "Numara:%d\n\n",  ogrenci.ogrenci_numara);


        //al�nan verilerin konsola yazd�r�lmas�

		fprintf(stdout, "Ad:%s\n",ogrenci.ogrenci_ad);
        fprintf(stdout, "Soyad:%s\n", ogrenci.ogrenci_soyad);
        fprintf(stdout, "Bolum:%s\n",  ogrenci.ogrenci_bolum);
        fprintf(stdout, "Numara:%d\n\n",  ogrenci.ogrenci_numara);

}

    	printf("Ogrenci Kaydi Basariyla Tamamlanmistir! \n");


    fclose(dosya); //olu�turulan dosyan�n kapanmas�
}

int main()
{
    ogrenci_kaydi_ekle ();
  

    return 0;
}

