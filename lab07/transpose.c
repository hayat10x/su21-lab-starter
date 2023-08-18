#include "transpose.h"

/* The naive transpose function as a reference. */
void transpose_naive(int n, int blocksize, int *dst, int *src) {
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            dst[y + x * n] = src[x + y * n];
        }
    }
}

/* Implement cache blocking below. You should NOT assume that n is a
 * multiple of the block size. */
void transpose_blocking(int n, int blocksize, int *dst, int *src) {
    
    for (int x = 0; x < n; x=x+blocksize) {
        for (int y = 0; y < n; y=y+blocksize) {
            for(int i = x; i < x+blocksize && i<n; i++)
            for(int j = y; j < y+blocksize && j< n; j++)
            {
                dst[j + i * n] = src[i + j * n];
            }
        }
    }
}