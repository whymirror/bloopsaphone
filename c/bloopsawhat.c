//
// bloopsawhat.c
// a simple commandline player
//
#include <stdio.h>
#include "bloopsaphone.h"

static void
usage()
{
  printf("usage: bloopsawhat notes\n"
         " (ex.: bloopsawhat \"a b c d e f g + a b c\"\n");
}

int
main(int argc, char *argv[])
{
  if (argc > 1) {
    bloops *B = bloops_new();
    bloopsaphone *P = bloops_load("tone.bloo");
    bloopsasong *song = bloops_song2(B, P, argv[1]);
    printf("%s\n", bloops_song_str(song));
    bloops_play(B, song);
    bloops_destroy(B);
    return 0;
  }

  usage();
  return 0;
}
