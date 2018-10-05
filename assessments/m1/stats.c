/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.h
 * @brief Preforms statistical operations on an array of numbers
 *
 * @author Duncan MacDonald
 * @date Oct 4, 2018
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

int main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
  sort_array(test, SIZE);
  print_array(test, SIZE);

  print_statistics(test, SIZE);

  return 0;
}

void print_statistics(unsigned char *data, int length) {
  printf("Maximum: %i\n", find_maximum(data, length));
  printf("Minimum: %i\n", find_minimum(data, length));
  printf("Median: %i\n", find_median(data, length));
  printf("Mean: %i\n", find_mean(data, length));
}

void print_array(unsigned char *data, int length) {
  // iterate over every index in data and print contents (with formatting)
  printf("[");
  for (int i = 0; i < length; i++) {
    if (i == length - 1) {
      printf("%i]\n", data[i]);
    } else {
      printf("%i, ", data[i]);
    }
  }
  printf("--------------\n");
}

unsigned char find_median(unsigned char *data, int length) {
  if (length % 2 == 0) {
    unsigned char mid_index = length / 2;

    return data[mid_index];
  }
  
  unsigned char mid_left = (length - 1) / 2;
  unsigned char mid_right = (length + 1) / 2;

  return (data[mid_left] + data[mid_right]) / 2;
}

unsigned char find_mean(unsigned char *data, int length) {
  int sum = 0;

  for (int i = 0; i < length; i++) {
    sum += data[i];
  }

  return sum / length;
}

unsigned char find_maximum(unsigned char *data, int length) {
  unsigned char maximum = data[0];

  for (int i = 0; i < length; i++) {
    if (data[i] > maximum) {
      maximum = data[i];
    }
  }

  return maximum;
}

unsigned char find_minimum(unsigned char *data, int length) {
  unsigned char minimum = data[0];

  for (int i = 0; i < length; i++) {
    if (data[i] < minimum) {
      minimum = data[i];
    }
  }

  return minimum;
}

void sort_array(unsigned char *data, int length) {
  for (int i = 0; i < length; i++) {
    for (int j = 0; j < length; j++) {
      if (data[i] < data[j]) {
        unsigned char tmp = data[i];
        data[i] = data[j];
        data[j] = tmp;
      }
    }
  }
}
