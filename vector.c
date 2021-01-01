#include "vector.h"
#include <assert.h>
#include <stddef.h>
#include <stdio.h>

#define DEFAULT_VECTOR_SIZE 8
#define ALLOCATE(type, size) malloc(sizeof(type) * size)
#define REALLOCATE(type, ptr, size) realloc(ptr, size)

// destroy the vector, reduce its size and capacity to 0 and remove the
// pointer
void vector_destroy(vector *vec) {
  free(vec->array);
  vec->capacity = 0;
  vec->length = 0;
  vec->array = NULL;
}
// initialize the vector with default values
void vector_construct(vector *vec) {
  vec->capacity = DEFAULT_VECTOR_SIZE;
  vec->length = 0;
  vec->array = ALLOCATE(int, vec->capacity);
}

// add an element to the last place of the vector and increase its size

void vector_pushback(vector *vec, size_t i) {
  if (vec->length >= vec->capacity) {
    vec->capacity *= 2;
    vec->array = REALLOCATE(int, vec->array, vec->capacity);
  }
  vec->array[vec->length] = i;
  vec->length += 1;
}
// insert an element in the given position of the vector
void vector_insert(vector *vec, size_t index, int value) {
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
    vec->array[index] = vec->array[i - 1];
  }
  vec->array[index] = value;
}

// return the value at a given index
int vector_at(vector *vec, size_t index) {
  assert(("Index out of bounds", index >= 0 && index < vec->length));
  return vec->array[index];
}
// clear the elements of a vector without reducing its max capacity
void vector_clear(vector *vec) { vec->length = 0; }

// return the max capacity of a vector
int vector_max_size(vector *vec) { return vec->capacity; }

// remove the last element of the vector
void vector_popback(vector *vec) {
  assert(("No elements to pop back", 0 <= vec->length));
  if (vec->length < 1) {
    vec->length--;
  }
}
