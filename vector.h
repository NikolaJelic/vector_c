
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#define ALLOCATE(type, size) malloc(sizeof(type) * size)
#define REALLOCATE(type, ptr, size) realloc(ptr, size)

typedef struct vectors {
  int *array;
  size_t length;
  size_t capacity;
} vector;

void vector_destroy(vector *vec);
int vector_at(vector *vec, int index);
void vector_clear(vector *vec);
void vector_pushback(vector *vec, int i);
void vector_construct(vector *vec);
void vector_insert(vector *vec, int index, int value);
int vector_max_size(vector *vec);
void vector_popBack(vector *vec);
