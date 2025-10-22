#include <stdio.h>
#include <stdlib.h>

//renk kodlar�

#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_ORANGE  "\x1b[38;5;208m"
#define ANSI_COLOR_DARK_GREEN "\x1b[32m" 

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() 
{
    float kar, faiz, standart_sapma, sharpe;
    int input_status; // do�ruluk de�eri i�in tan�mlama
    
    // --- Kar Girdisi ---
    do {
        printf("Elde edilen kar miktarini giriniz (%): ");
        input_status = scanf("%f", &kar);
        
        if (input_status == 0) {
            printf(ANSI_COLOR_RED "Hata: L�tfen sadece say�sal bir de�er girin.\n" ANSI_COLOR_RESET);
            clear_input_buffer();
        }
    } while (input_status != 1); // Ba�ar�l� olana kadar (1 d�nene kadar) tekrarla
    
    // girdi temizleme
    clear_input_buffer(); 

    // --- Faiz Girdisi ---
    do {
        printf("Riskli faiz miktarini giriniz (%): ");
        input_status = scanf("%f", &faiz);
        
        if (input_status == 0) { 
            printf(ANSI_COLOR_RED "Hata: L�tfen sadece say�sal bir de�er girin.\n" ANSI_COLOR_RESET);
            clear_input_buffer();
        }
    } while (input_status != 1);
    
    clear_input_buffer(); // girdi temizleme

    // --- Standart Sapma Girdisi ---
    do {
        printf("Standart sapma miktarini giriniz (%): ");
        input_status = scanf("%f", &standart_sapma);

        if (input_status == 0) { // Harf girdisi
            printf(ANSI_COLOR_RED "L�tfen sadece say�sal bir de�er girin.\n" ANSI_COLOR_RESET);
            clear_input_buffer();
        } 
        //standart sapma 0 olmas�n ve hata vermesin diye k�s�tlama
        else if (standart_sapma == 0) { 
            printf(ANSI_COLOR_RED "Standart sapma 0 olamaz.\n" ANSI_COLOR_RESET);
            input_status = 0; // D�ng�n�n tekrar etmesi i�in durumu 'ba�ar�s�z' yap
        }

    } while (input_status != 1);

    // --- ��lemler ---
    kar = (kar / 100);
    faiz = (faiz / 100);
    standart_sapma = (standart_sapma / 100);
    
    // Sharpe sisteme tan�mlama ve sonu� i�in yorum sunma
    sharpe = (kar - faiz) / standart_sapma;
    printf("Sharpe Orani: %.2f \n", sharpe);
    
    if (sharpe < 1) {
        printf(ANSI_COLOR_RED "Dusuk bir sharpe miktari\n" ANSI_COLOR_RESET);
    }
    else if (sharpe < 2) {
        printf(ANSI_COLOR_ORANGE "Ortalama bir sharpe miktari\n" ANSI_COLOR_RESET);
    }
    else if (sharpe < 3) {
        printf(ANSI_COLOR_GREEN "Iyi bir sharpe miktari\n00" ANSI_COLOR_RESET);
    }
    else {
        printf(ANSI_COLOR_DARK_GREEN "Mukemmel bir sharpe miktari\n" ANSI_COLOR_RESET);
    }

    return 0;
}
