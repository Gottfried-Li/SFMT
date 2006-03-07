/* Simple and Fast MT 2006/1/21 */
#ifndef __SFMT32_ST_H__
#define __SFMT32_ST_H__

#include <stdint.h>
#include <stdio.h>

#ifndef MEXP
#define MEXP 19937
#endif

#define WORDSIZE 128
#define N (MEXP / WORDSIZE + 1)
#define MAXDEGREE (WORDSIZE * N)

struct SFMT32_TAG {
    uint32_t sfmt[4][N][4];
    uint32_t idx;
};

typedef struct SFMT32_TAG sfmt32_t;

void setup_param(unsigned int p1, unsigned int p2, unsigned int p3, 
		 unsigned int p4, unsigned int p5, unsigned int p6,
		 unsigned int p7, unsigned int p8, unsigned int p9);
unsigned int get_rnd_maxdegree(void);
unsigned int get_rnd_mexp(void);
void print_param(FILE *fp);
void print_param2(FILE *fp);

void init_gen_rand(sfmt32_t *sfmt, uint32_t seed);
void next_state128(sfmt32_t *sfmt);
uint32_t gen_rand32(sfmt32_t *sfmt);
uint64_t gen_rand64(sfmt32_t *sfmt);
uint64_t gen_rand128(sfmt32_t *sfmt, uint64_t *hi, uint64_t *low);
void add_rnd(sfmt32_t *dist, sfmt32_t *src);
void read_random_param(FILE *fp);

#endif
