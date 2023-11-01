#ifndef MIC_H
#define MIC_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

bool mic_init();
void mic_read_data();
void mic_deinit();

#endif /* MIC_H */
