// Copyright 2023 Muhammad Hayat
#include <stdio.h>

#define NO_WORDS 2
#define SIZE_WORDS NO_WORDS << 3

typedef struct {
  unsigned long long double_word[NO_WORDS];
} arr_t __attribute__((aligned(SIZE_WORDS)));


arr_t store_byte_data[8] ={
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 }
       };


arr_t store_byte_expected_data[8] ={
          { 0x00000000000000EF, 0x0000000000000000 },
          { 0x000000000000BE00, 0x0000000000000000 },
          { 0x0000000000AD0000, 0x0000000000000000 },
          { 0x00000000DE000000, 0x0000000000000000 },
          { 0x000000EF00000000, 0x0000000000000000 },
          { 0x0000BE0000000000, 0x0000000000000000 },
          { 0x00AD000000000000, 0x0000000000000000 },
          { 0xDE00000000000000, 0x0000000000000000 }
       };


arr_t store_half_word_data[8] ={
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 }
       };


arr_t store_half_word_expected_data[8] ={
          { 0x000000000000BEEF, 0x0000000000000000 },
          { 0x0000000000ADBE00, 0x0000000000000000 },
          { 0x00000000DEAD0000, 0x0000000000000000 },
          { 0x000000EFDE000000, 0x0000000000000000 },
          { 0x0000BEEF00000000, 0x0000000000000000 },
          { 0x00ADBE0000000000, 0x0000000000000000 },
          { 0xDEAD000000000000, 0x0000000000000000 },
          { 0xDE00000000000000, 0x00000000000000EF }
       };


arr_t store_word_data[8] ={
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 }
       };


arr_t store_word_expected_data[8] ={
          { 0x00000000DEADBEEF, 0x0000000000000000 },
          { 0x000000DEADBEEF00, 0x0000000000000000 },
          { 0x0000DEADBEEF0000, 0x0000000000000000 },
          { 0x00DEADBEEF000000, 0x0000000000000000 },
          { 0xF00DC0DE00000000, 0x0000000000000000 },
          { 0x0DC0DE0000000000, 0x00000000000000F0 },
          { 0xC0DE000000000000, 0x000000000000F00D },
          { 0xDE00000000000000, 0x0000000000F00DC0 }
       };


arr_t store_double_word_data[8] ={
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 }
       };


arr_t store_double_word_expected_data[8] ={
          { 0xDEADBEEFF00DC0DE, 0x0000000000000000 },
          { 0xADBEEFF00DC0DE00, 0x00000000000000DE },
          { 0xBEEFF00DC0DE0000, 0x000000000000DEAD },
          { 0xEFF00DC0DE000000, 0x0000000000DEADBE },
          { 0xF00DC0DE00000000, 0x00000000DEADBEEF },
          { 0x0DC0DE0000000000, 0x000000DEADBEEFF0 },
          { 0xC0DE000000000000, 0x0000DEADBEEFF00D },
          { 0xDE00000000000000, 0x00DEADBEEFF00DC0 }
       };


int store_byte_test(arr_t *p) {
  unsigned long long replacement_values[] = { 0xEF, 0xBE, 0xAD, 0xDE, 0xEF, 0xBE, 0xAD, 0xDE };
  int b = 0;
  for (int i = 0; i < 8; i++) {
  b = b + 2;
  replacement_values[i+1] = replacement_values[i+1] << ((b)*4);
}
  for (int i = 0; i < 8; i++) {
    store_byte_data[i].double_word[0] = replacement_values[i];
    store_byte_data[i].double_word[1];
}
  for (int i = 0; i < 8; i++) {
    if (store_byte_data[i].double_word[0] != store_byte_expected_data[i].double_word[0] | store_byte_data[i].double_word[1] != store_byte_expected_data[i].double_word[1]) {
      printf("Byte test failed\n");
      return 0;
}
}
  printf("Byte test Passed\n");
}

int store_half_word_test(arr_t *p ) {
unsigned long long replacement_values[] = { 0xBEEF, 0xADBE, 0xDEAD, 0xEFDE, 0xBEEF, 0xADBE, 0xDEAD, 0xDE, 0xEF};
int b = 0;
    for (int i = 0; i < 8; i++) {
    b = b + 2;
    replacement_values[i+1] = replacement_values[i+1] << ((b)*4);
    }
    // arr_t store_byte_data[8];
    for (int i = 0; i < 8; i++) {
        p->double_word[0] = replacement_values[i];
        p++;
    }
    p--;
    p->double_word[1] = replacement_values[8];
    p = p-7;
    for (int i = 0; i < 8; i++) {
       if (store_half_word_data[i].double_word[0] != store_half_word_expected_data[i].double_word[0] | store_half_word_data[i].double_word[1] != store_half_word_expected_data[i].double_word[1])
       printf("Half Word test failed");
       p++;
    }
    printf("Half Word test passed\n");
}


int store_word_test(arr_t *p ) {
unsigned long long replacement_values[] = { 0xDEADBEEF, 0xDEADBEEF, 0xDEADBEEF, 0xDEADBEEF, 0xF00DC0DE, 0xDC0DE, 0xC0DE, 0xDE, 0xF00DC0, 0xF00D, 0xF0};
int b = 0;
    for (int i = 0; i < 8; i++) {
    b = b + 2;
    replacement_values[i+1] = replacement_values[i+1] << ((b)*4);
    }
    int a = 7;
    for (int i = 0; i < 11; i++) {
        if (i <8) {
        p->double_word[0] = replacement_values[i];
        p++;} else {
         p--;
         p->double_word[1] = replacement_values[i];
         a = a-1;
        }
    }
    for (int i = 0; i < 8; i++) {
       if (store_word_data[i].double_word[0] != store_word_expected_data[i].double_word[0] | store_word_data[i].double_word[1] != store_word_expected_data[i].double_word[1]) {
       printf("store word test failed\n");
      return 0;}
       p++;
    }
    printf(" word test passed\n");
}

int store_double_word_test(arr_t *p ) {
unsigned long long replacement_values[] = { 0xDEADBEEFF00DC0DE, 0xADBEEFF00DC0DE, 0xBEEFF00DC0DE, 0xEFF00DC0DE, 0xF00DC0DE, 0xDC0DE, 0xC0DE, 0xDE, 0xDEADBEEFF00DC0, 0xDEADBEEFF00D, 0xDEADBEEFF0, 0xDEADBEEF, 0xDEADBE, 0xDEAD, 0xDE};
int b = 0;
    for (int i = 0; i < 8; i++) {
    b = b + 2;
    replacement_values[i+1] = replacement_values[i+1] << ((b)*4);
    }
    int a = 7;
    for (int i = 0; i < 15; i++) {
      if (i < 8) {
      p->double_word[0] = replacement_values[i];
      p++;} else {
      p--;
      p->double_word[1] = replacement_values[i];
      a = a-1;
        }
    }
    for (int i = 0; i < 8; i++) {
  if (store_double_word_data[i].double_word[0] != store_double_word_expected_data[i].double_word[0] | store_double_word_data[i].double_word[1] != store_double_word_expected_data[i].double_word[1]) {
       printf("Double word test failed\n");
      return 0;}
       p++;
    }
    printf("Double word test passed\n");
}



int main() {
  printf("-----Running byte test-----\n");
  store_byte_test(store_byte_data);
  printf("-----Running Half Word test-----\n");
  store_half_word_test(store_half_word_data);
  printf("-----Running  Word test-----\n");
  store_word_test(store_word_data);
  printf("-----Running Double Word test-----\n");
  store_double_word_test(store_double_word_data);
}
