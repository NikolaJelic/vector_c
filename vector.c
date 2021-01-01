#include "vector.h"
#include <stdio.h>

void vector_destroy(vector *vec) {
  free(vec->array);
  vec->capacity = 0;
  vec->length = 0;
  vec->array = NULL;
}
int vector_at(vector *vec, int index) {
  assert(("Index out of bounds", index >= 0 && index < vec->length));
  return vec->array[index];
}

void vector_clear(vector *vec) { vec->length = 0; }
void vector_construct(vector *vec) {
  vec->capacity = 8;
  vec->length = 0;
  vec->array = ALLOCATE(int, vec->capacity);
}
void vector_insert(vector *vec, int index, int value) {
  if (index < vec->capacity) {
    if (vec->length < vec->capacity) {
      vec->capacity++;
      vec->array = REALLOCATE(int, vec->array, vec->capacity);
    }
  } else {
    printf("Index can't be bigger than the ector size\n");
    return;
  }
  for (int i = ++vec->length; i > index; --i) {
    *(vec->array + i) = *(vec->array + i - 1);
  }
  *(vec->array + index) = value;
}

int vector_max_size(vector *vec) { return vec->capacity; }
void vector_popBack(vector *vec) {
  if (vec->length < 1) {
    vec->length--;
  } else {
    printf("No elements to pop back\n");
  }
}
void vector_pushback(vector *vec, int i) {
  if (vec->length >= vec->capacity) {
    vec->capacity *= 2;
    vec->array = REALLOCATE(int, vec->array, vec->capacity);
  }
  *(vec->array + vec->length) = i;
  vec->length += 1;
}
