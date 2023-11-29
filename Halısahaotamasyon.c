#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct kullaniciBilgileri {
    
    char ad [20] ;
    char soyad [20] ;
    char kullaniciAdi [20] ;
    char sifre [20] ;
    int yas;
    
} kullanici ;

void Kayit()
{
    system("cls"); /* Terminal'de hata mesajlarını göstermesin diye */ 
    printf("--- Kayit Ol ----\n\n");
    
    kullanici k1;

    printf("Kullanici Adi: ");
    scanf("%s", k1.kullaniciAdi );
    printf("Ad: ");
    scanf("%s", k1.ad);
    printf("Soyad: ");
    scanf("%s", k1.soyad);
    printf("Yas: ");
    scanf("%d", &k1.yas);
    printf("Sifre: ");
    scanf("%s", k1.sifre);

    FILE *ptr =fopen("kullanicikayit.txt", "a+b");
    fwrite( &k1, sizeof(kullanici), 1 ,ptr );
    fclose(ptr);
    printf("Yeni kayit işlemi tamamlanmıştır\n");
    
}

void Giris()
{
    system("cls");
    printf("--- Giris Yap ---\n\n");
    
    kullanici k1;
    char kullaniciAdi[20];
    char sifre[20];
    printf("Kullanici Adi: ");
    scanf("%s", kullaniciAdi );
    printf("Sifre: ");
    scanf("%s", sifre);
    int sonuc=0;

    FILE *ptr =fopen ("kullanicikayit.txt", "r+b");
    
    while (fread( &k1, sizeof(kullanici), 1 ,ptr )  !=NULL )
    {
        if(strcmp( kullaniciAdi, k1.kullaniciAdi)==0  && strcmp(sifre, k1.sifre)==0 )
        {
            sonuc=1;
            break;
        }
    }
    fclose(ptr);
    if( sonuc ==0)
    printf("Hatali giris islemi\n");
    else
    {
       printf("\n\n%s %s hos geldiniz\n\n\n", k1.ad, k1.soyad);
    }





}


int menu()
{
    int secim;
	printf("----- igu Halisahasina Hosgeldiniz ----- \n \n");
    printf("1 - Kayit Ol \n");
    printf("2 - Giris Yap \n");
    printf("3 - Cikis yap \n\n");
    printf("Devam Etmek icin Yukaridaki Seceneklerden Birini Secin: ");
    scanf("%d", &secim);
    return secim;
}

int main()
{
    int secim= menu();
    
    while( secim != 0)
    {
        switch( secim )
        {
            case 1 : Kayit();break;
            case 2 : Giris();break;
            case 3 : printf("Kurtlar Vadisi Operasyonu Bitmiştir...");  return 0;
            default : printf("Hatalı Giriş Yaptınız!\n \n");
        }
        secim = menu();
    }
        
        
    
        
	return 0;
}

