#include <stdio.h>
#include <string.h>
#include <math.h>

struct uyelik {
    char ad[50];
    char soyad[50];
    char cinsiyet;
    int yas;
    char uyelik_turu[50];
    int gun, ay, yil;
};

struct olcu {
    float boy; // Boyun cm cinsinden tutulması için float
    float kilo; // Kilo float olarak tutulmalı
    int boyun;
    int bel;
    int kalca;
    float vki; // Vücut Kitle İndeksi
    float yag; // Vücut Yağ Oranı
};

struct uyelik uye1;
struct olcu olcu1;

void uyelik() {
  
    printf("Adinizi giriniz: "); fgets(uye1.ad, sizeof(uye1.ad), stdin);
    uye1.ad[strcspn(uye1.ad, "\n")] = '\0'; 

    printf("Soyadinizi giriniz: "); fgets(uye1.soyad, sizeof(uye1.soyad), stdin);
    uye1.soyad[strcspn(uye1.soyad, "\n")] = '\0'; 

    while (1) {
        printf("Cinsiyet (E: Erkek / K: Kadin): "); scanf(" %c", &uye1.cinsiyet);
        
        if (uye1.cinsiyet == 'E' || uye1.cinsiyet == 'e' || uye1.cinsiyet == 'K' || uye1.cinsiyet == 'k') 
		{
    		break;
		} 
		
		else 
		{
            printf("Hatali cinsiyet girdiniz! Lutfen tekrar giriniz.\n");
        }
    }

    printf("Kac yasindasiniz?: "); scanf("%d", &uye1.yas);
    getchar();

    printf("Uyelik Turunuz: "); fgets(uye1.uyelik_turu, sizeof(uye1.uyelik_turu), stdin);
    uye1.uyelik_turu[strcspn(uye1.uyelik_turu, "\n")] = '\0'; 

    printf("Uyelik Baslangic Tarihi (gun ay yil): "); scanf("%d %d %d", &uye1.gun, &uye1.ay, &uye1.yil);
    
}

void olcu() 
{
    printf("\nNot:\n");
    printf("- Boyun olcusu girtlagin hemen altindan alinmalidir.\n");
    printf("- Bel olcusu kadinlarda belin en ince yerinden, erkeklerde ise gobek deligi hizasindan alinmalidir.\n");
    printf("- Kadinlarda kalca olcusu, kalcanin en genis yerinden alinmalidir.\n");

    printf("\nBoy (cm cinsinden): ");
    scanf("%f", &olcu1.boy);
    printf("Kilo (kg cinsinden): ");
    scanf("%f", &olcu1.kilo);
    printf("Boyun Cevresi: ");
    scanf("%d", &olcu1.boyun);
    printf("Bel Cevresi: ");
    scanf("%d", &olcu1.bel);

    // Vücut Kitle İndeksini hesaplıyorum.
    
    olcu1.vki = olcu1.kilo / ((olcu1.boy / 100) * (olcu1.boy / 100)); 

    if (uye1.cinsiyet == 'K' || uye1.cinsiyet == 'k')
	{
        printf("Kalca Cevresini giriniz: "); scanf("%d", &olcu1.kalca);
        
        if (olcu1.bel + olcu1.kalca - olcu1.boyun > 0) 
		{
            olcu1.yag = 495 / (1.29579-0.35004 * log10(olcu1.bel + olcu1.kalca - olcu1.boyun) + 0.22100 * log10(olcu1.boy)) - 450;
        } 
		
		else 
		{
            olcu1.yag = -1; 
        }
    } 
	    else if (uye1.cinsiyet == 'E' || uye1.cinsiyet == 'e') 
		{
        
			if (olcu1.bel - olcu1.boyun > 0) 
			{
            	olcu1.yag = 495 / (1.0324-0.19077 * log10(olcu1.bel - olcu1.boyun) + 0.15456 * log10(olcu1.boy)) - 450 ;
        	} 
		
			else 
			{
            	olcu1.yag = -1; 
        	}
    	}
}

void yazdir() 
{
    printf("\n-- Uye Bilgileri --\n\n");
    printf("- Ad: %s\n", uye1.ad);
    printf("- Soyad: %s\n", uye1.soyad);
    
	if (uye1.cinsiyet == 'E' || uye1.cinsiyet == 'e')
	{
		printf("- Cinsiyet: Erkek\n", uye1.cinsiyet);
	}
	
	else if (uye1.cinsiyet == 'K' || uye1.cinsiyet == 'k')
	{
		printf("- Cinsiyet: Kadin\n", uye1.cinsiyet);
	}
	
    printf("- Yas: %d\n", uye1.yas);
    printf("- Uyelik Turu: %s\n", uye1.uyelik_turu);
    printf("- Uyelik Baslangic Tarihi: %02d.%02d.%04d\n", uye1.gun, uye1.ay, uye1.yil);
	
	printf("\n-- Vucut Bilgileri --\n");
	
	
	if (olcu1.vki <= 0)
		printf("\n- Vucut Kitle Indeksi Hesaplanamadi , Lutfen Dogru Olculeri Girdiginizden Emin Olun.");
	
	else if (olcu1.vki <= 18.5 && olcu1.vki>0)
		printf("\n- Vucut Kitle Indeksiniz: %.2f , Zayif",olcu1.vki);
	
	else if (olcu1.vki <= 24.9 && olcu1.vki > 18.5)
		printf("\n- Vucut Kitle Indeksiniz: %.2f , Normal",olcu1.vki);
	
	else if (olcu1.vki <= 29.9 && olcu1.vki > 24.9)
		printf("\n- Vucut Kitle Indeksiniz: %.2f , Fazla Kilolu (Hafif Sisman)",olcu1.vki);
	
	else if (olcu1.vki <= 34.9 && olcu1.vki > 29.9)
		printf("\n- Vucut Kitle Indeksiniz: %.2f , 1. Derece Obez (Obezite Sinif I)",olcu1.vki);
	
	else if (olcu1.vki <= 39.9 && olcu1.vki > 34.9)
		printf("\n- Vucut Kitle Indeksiniz: %.2f , 2. Derece Obez (Obezite Sinif 2)",olcu1.vki);
	
	else if (olcu1.vki > 39.9)
		printf("\n- Vucut Kitle Indeksiniz: %.2f , 3. Derece Obez (Morbid Obezite)",olcu1.vki);
	
	printf("\n\n");
	
    if (olcu1.yag < 0) 
	{
        printf("- Yag Orani Hesaplanamadi, olculeri kontrol ediniz.\n");
        return;
    }

    if (uye1.cinsiyet == 'E' || uye1.cinsiyet == 'e') 
	{
        if (olcu1.yag <= 14)
            printf("- Vucut Yag Oraniniz: %.2f , Atletik Vucut, Dusuk yag orani\n", olcu1.yag);
        
		else if (olcu1.yag <= 17)
        {
		    printf("- Vucut Yag Oraniniz: %.2f , Fit Vucut, Saglikli\n", olcu1.yag);
    		printf("\n- Erkeklerde yag oraninin 8 ile 14 arasinda olmasi onerilmektedir. %.2f yag oranina sahip oldugunuz icin uzmanlar yag oranini azaltmanizi tavsiye etmektedir.\n",olcu1.yag);
		}
		else if (olcu1.yag <= 24)
        {
		    printf("- Vucut Yag Oraniniz: %.2f , Orta seviyede yag, Genellikle Saglikli\n", olcu1.yag);
            printf("\n- Erkeklerde yag oraninin 8 ile 14 arasinda olmasi onerilmektedir. %.2f yag oranina sahip oldugunuz icin uzmanlar yag oranini azaltmanizi tavsiye etmektedir.\n",olcu1.yag);
    	}
    	
		else
        {
		    printf("- Vucut Yag Oraniniz: %.2f , Obezite Baslangici, Dikkat edin!\n", olcu1.yag);
            printf("\n- Erkeklerde yag oraninin 8 ile 14 arasinda olmasi onerilmektedir. %.2f yag oranina sahip oldugunuz icin uzmanlar yag oranini azaltmanizi tavsiye etmektedir.\n",olcu1.yag);
		}
	} 
		else if (uye1.cinsiyet == 'K' || uye1.cinsiyet == 'k')
		{
			if (olcu1.yag <= 24)
            	{
				printf("- Vucut Yag Oraniniz: %.2f , Atletik Vucut\n", olcu1.yag);
        		printf("\n-  kadinlarda yag oraninin 20 ile 25 arasinda olmasi onerilmektedir. %.2f yag oranina sahip oldugunuz icin uzmanlar kilo alarak yag oranini artirmanizi tavsiye etmektedir.\n",olcu1.yag);
				}
			
			else if (olcu1.yag <= 31)
            	{
            	printf("- Vucut Yag Oraniniz: %.2f , Saglikli\n", olcu1.yag);
				printf("\n-  kadinlarda yag oraninin 20 ile 25 arasinda olmasi onerilmektedir. %.2f yag oranina sahip oldugunuz icin uzmanlar kilo alarak yag oranini artirmanizi tavsiye etmektedir.\n",olcu1.yag);
				}
        
			else
            	{
				printf("- Vucut Yag Oraniniz: %.2f , Obezite Baslangici\n", olcu1.yag);
    			printf("\n-  kadinlarda yag oraninin 20 ile 25 arasinda olmasi onerilmektedir. %.2f yag oranina sahip oldugunuz icin uzmanlar kilo alarak yag oranini artirmanizi tavsiye etmektedir.\n",olcu1.yag);
				}
		}
}

int main() {
    uyelik();
    printf("\n");
    
    olcu();
    printf("\n");
    
    yazdir();
    
    return 0;
}
