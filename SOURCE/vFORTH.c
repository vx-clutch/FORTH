// Copyright (C) 2025 vx-clutch ( owestness@gmail.com )
// See end of file for extended copyright information.

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRIMARY "\x1b[?1049l"
#define ALTERNATE "\x1b[?1049h"
#define HOME "\033[H"

char *shell(const char *prompt) {
  char buf[100];

  printf("Enter a string: ");
  if (fgets(buf, sizeof(buf), stdin)) {
    size_t length = strlen(buf);
    if (length > 0 && buf[length - 1] == '\n') {
      buf[length - 1] = '\0';
    }
    printf("You entered: %s\n", buf);
  } else {
    exit(EXIT_FAILURE);
  }

  return 0;
}

int main(int argc, char **argv) {
  printf(ALTERNATE);
  fflush(stdout);
  printf(HOME);
  printf(PRIMARY);
  fflush(stdout);
  return EXIT_SUCCESS;
}

/* vFORTH is a FORTH repl
 * Copyright (C) 2024 vx-clutch
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
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */