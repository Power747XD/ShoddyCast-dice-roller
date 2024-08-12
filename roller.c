#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#define bitmap1 0b11000000
#define bitmap2 0b00110000
#define bitmap3 0b00001100
#define bitmap4 0b00000011

int roll(){
    uint32_t result = 0;
    uint8_t dice = 0;
    for (int i = 0; i <= 57; i++){
        uint8_t roll = (uint8_t) rand();
        dice = roll & bitmap1;
        if (!dice){
            result++;
        }
        dice = roll & bitmap2;
        if (!dice){
            result++;
        }
        dice = roll & bitmap3;
        if (!dice){
            result++;
        }
        dice = roll & bitmap4;
        if (!dice){
            result++;
        }
    } //Last step only 3 bitmaps
    uint8_t roll = (uint8_t) rand();
    dice = roll & bitmap1;
        if (!dice){
            result++;
        }
    dice = roll & bitmap2;
        if (!dice){
            result++;
        }
    dice = roll & bitmap3;
        if (!dice){
            result++;
        }
    return result;
}

int main(){
    srand((unsigned)time(NULL));
    clock_t start = clock();
    puts("Iniziato!");

    uint8_t max_roll = 0;
    for (int attempt = 1; attempt <= 1000000000; attempt++){
      uint8_t current = roll();
      if (current > max_roll){
        max_roll = current;
      }  
    }

    //uint8_t max_roll = roll();
    clock_t end = clock();
    double time_delta = ((double) end - start) / CLOCKS_PER_SEC;
    printf("Max roll: %d\n", max_roll);
    printf("Time taken: %f seconds\n", time_delta);
    return 0;
}
