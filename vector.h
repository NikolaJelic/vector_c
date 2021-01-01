
#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct vectors {
  int *array;
  size_t length;
  size_t capacity;
} vector;

void vector_destroy(vector *vec);
int vector_at(vector *vec, size_t index);
void vector_clear(vector *vec);
void vector_pushback(vector *vec, size_t i);
void vector_construct(vector *vec);
void vector_insert(vector *vec, size_t index, int value);
int vector_max_size(vector *vec);
void vector_popback(vector *vec);
