#include <stdio.h>
#include <locale.h>

int main() {

    setlocale(LC_ALL, "Turkish");

    int yas, cocuk, pcocuk = 0;
    float hanim, getirc, sonuc;
    char evli, hanimc, egitim;

    float dizi[20] = { 0,0.075,0.150,0.250,0.300,0.350,0.400,0.450,0.500,0.550,0.600,0.650,0.700,0.750,0.800,0.850,0.900,0.950,1.000,1.050 };


    printf("AGİ Puanı İçin Lütfen Yaşınızı Giriniz:\n");
    scanf("%d", &yas);

    if (yas <= 16) {
        printf("AGİ Alamayacak Yaştasınız\n");
    }
    else {
        printf("Evli Misiniz? Evet İse E Hayır İse H: \n");
        scanf("%s", &evli);
        if ('H' == evli) {
            hanim = 0;
        }
        else if ('E' == evli) {
            printf("Eşiniz Çalışıyor Mu? Evet İse E Hayır İse H: \n");
            scanf("%s", &hanimc);
            switch (hanimc) {
            case 'E':
                hanim = 0;
                break;                      //Burda Hem Switch Hem For Döngüsünü Biraz Karışıkda Olsa Harf Şeklinde Evet Hayır Diyerek Son Kullanıcıya Basitleştirdim
            case  'H':
                hanim = 0.10;
                break;
            default:
                printf("İstenen harflerden birini girmediniz!\n");
            }
        }
        printf("Bakmakta Yükümlü Olduğunuz Çocukların Sayısını ve Yaşları  \n");
        scanf("%d", &cocuk);
        for (int d1 = 0; d1 < cocuk; d1++) {
            printf("%d. Çocuğun Yaşını Giriniz\n", d1 + 1);
            scanf("%d", &yas);
            if (yas < 18) {
                printf("Çocuğunuz AGİ ye Dahil\n");
                pcocuk += 1;
            }                                       //Çocuklar üçe bölüm for döngüsüne sokarak daha kolay bir kullanım amaçladım
            else if (18 <= yas && yas <= 24) {
                printf("Çocuğunuz Okuyor Mu? Evet ise 'E' değil ise 'H' Diyiniz\n");
                scanf("%s", &egitim);
                switch (egitim) {
                case 'E': printf("Çocuğunuz AGİ ye Dahil\n"); pcocuk += 1; break;

                case 'H': printf("Çocuğunuz AGİ ye Dahil Değil\n"); break;

                default:  printf("İstenen harflerden birini girmediniz!\n");
                }
            }
            else {
                printf("Çocuğunuz AGİ ye Dahil Değil\n");
            }
        }
        getirc = dizi[pcocuk];

        sonuc = 0.50 + hanim + getirc;  // hanım ile getirc önceden hesaplanan eş ile çocuk hesaplamaları

        float  matrah = 12 * 2324.70 * sonuc;

        float  yil = matrah * 15 / 100;

        float  ay = yil / 12;       //Burası Matematiksel Hesaplama Kısmı

        float  brut = 2324.7 + ay;

        printf("Brüt Asgari ücretiniz:%lf", brut);
    }

    return 0;
}
