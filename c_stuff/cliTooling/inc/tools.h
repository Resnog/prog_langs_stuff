#include <stdlib.h>
#include <stdint.h>

#ifndef TOOLS_H
#define TOOLS_H

const size_t default_buffer_size = 256;

uint8_t *buf_init(const size_t buf_size);

#endif // TOOLS_H
