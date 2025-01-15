#!/usr/bin/env bash

args=""

for arg in "$@"; do
  args+="$arg "
done

gcc -o vforth SOURCE/main.c $args
