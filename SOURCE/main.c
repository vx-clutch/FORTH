// Copyright (C) 2025 vx-clutch (owestness@gmail.com)
// See end of file for extended copyright information.

#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRIMARY "\x1b[?1049l"
#define ALTERNATE "\x1b[?1049h"
#define HOME "\033[H"

#define MAX_BUFFER 1024

/* utilty macro for comparisons with input_buffer */
#define cmp(str) strcmp(input_buffer, str) == 0

#define STACK_SIZE 8
int stack[STACK_SIZE];
int sp = 0; // stack pointer
int rhs;
int lhs;

char *eval(char *);
int pop();
void help();

int
main(int argc, char **argv) {
  printf(ALTERNATE);
  fflush(stdout);
  printf(HOME);
  while (1) {
    char *input_buffer = malloc(MAX_BUFFER * sizeof(char));
    if (input_buffer == NULL) {
      fprintf(stderr, "Memory allocation failed\n");
      exit(1);
    }

    printf("FTH=> ");
    if (fgets(input_buffer, MAX_BUFFER, stdin) == NULL) {
      free(input_buffer);
      continue;
    }

    // Remove trailing newline
    input_buffer[strcspn(input_buffer, "\n")] = '\0';

    if (input_buffer[0] == '\0') {
      free(input_buffer);
      continue;
    }

    if (cmp("help")) {
      help();
    }

    if (cmp("quit")) {
      free(input_buffer);
      printf("Are you sure? [Y/n] ");
      char ch = getchar();
      while (getchar() != '\n')
        ; // Consume leftover input
      ch = tolower(ch);
      if (ch != 'n') {
        break;
      } else {
        continue;
      }
    }

    if (cmp("ls")) {
      free(input_buffer);
      printf("[");
      for (size_t i = 0; i < STACK_SIZE; i++) {
        printf(" %d,", stack[i]);
      }
      printf("]\n");
      continue;
    }

    free(input_buffer);
  }
  printf(PRIMARY);
  fflush(stdout);
}

int
pop() {
  int top = stack[sp];
  sp--;
  return top;
}

typedef struct {
  char *type;
  char *value;
} token;

char *
eval(char expr[MAX_BUFFER]) {
  char *output_buffer = malloc(MAX_BUFFER * sizeof(char));
  /* lexer */
  token instructions[MAX_BUFFER];
  for (int i = 0; i < sizeof(output_buffer); i++) {
    char ch = expr[i];
  }
  return output_buffer;
}

void help() {
  while (1) {
    char *input_buffer = malloc(MAX_BUFFER * sizeof(char));
    if (input_buffer == NULL) {
      fprintf(stderr, "Memory allocation failed\n");
      exit(1);
    }

    printf("help> ");
    if (fgets(input_buffer, MAX_BUFFER, stdin) == NULL) {
      free(input_buffer);
      continue;
    }

    // Remove trailing newline
    input_buffer[strcspn(input_buffer, "\n")] = '\0';

    if (input_buffer[0] == '\0') {
      free(input_buffer);
      continue;
    }

    if (cmp("mod")) {
      free(input_buffer);
      printf("'mod' is the FORTH keyword for the modulus operation. The modulus operation takes the remainder of the top two items of the stack.\n");
      continue;
    }
    if (cmp("quit")) {
      free(input_buffer);
      break;
    }
    free(input_buffer);
  }
}

/* vFORTH is a FORTH repl
 * Copyright (C) 2025 vx-clutch
 *
 * The file is part of vFORTH.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions, and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions, and the following disclaimer in the documentation or
 * other materials provided with the distribution.
 * 3. Neither the name of vx-clutch nor the names of its contributors may be
 * used to endorse or promote products derived from this software without
 * specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HO
 */
