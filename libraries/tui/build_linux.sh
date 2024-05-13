#!/usr/bin/env bash
# target
target="./build/linux/teste_menu"
main="teste.c"
libs="tui.c -lm"
gcc -o $target $main $libs && $target