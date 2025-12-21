#ifndef SHARED_H
#define SHARED_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

extern uint8_t s_box[16];
extern uint8_t inv_s_box[16];
extern char plain[];
extern size_t plain_size;

void init_inv_s_box(void);

#endif
