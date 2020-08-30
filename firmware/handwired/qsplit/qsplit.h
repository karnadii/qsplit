#ifndef KB_H
#define KB_H

#include "quantum.h"

#define KEYMAP( \
            LA3, LA4, LA5, LA6, LA7, LA8,      RA1, RA2, RA3, RA4, RA5, RA6, RA7, RA8, \
  LB1, LB2, LB3, LB4, LB5, LB6, LB7, LB8,      RB1, RB2, RB3, RB4, RB5, RB6, RB7, RB8, \
  LC1, LC2, LC3, LC4, LC5, LC6, LC7, LC8,      RC1, RC2, RC3, RC4, RC5, RC6, RC7, RC8, \
  LD1, LD2, LD3, LD4, LD5, LD6, LD7, LD8,      RD1, RD2, RD3, RD4, RD5, RD6, RD7, RD8, \
  LE1, LE2, LE3, LE4, LE5, LE6, LE7, LE8,      RE1, RE2, RE3, RE4, RE5, RE6, RE7, RE8 \
  ) \
  { \
    { KC_NO, KC_NO, LA3, LA4, LA5, LA6, LA7, LA8}, \
    { LB1, LB2, LB3, LB4, LB5, LB6, LB7, LB8}, \
    { LC1, LC2, LC3, LC4, LC5, LC6, LC7, LC8}, \
    { LD1, LD2, LD3, LD4, LD5, LD6, LD7, LD8 }, \
    { LE1, LE2, LE3, LE4, LE5, LE6, LE7, LE8 }, \
\
    { RA1, RA2, RA3, RA4, RA5, RA6, RA7, RA8 }, \
    { RB1, RB2, RB3, RB4, RB5, RB6, RB7, RB8 }, \
    { RC1, RC2, RC3, RC4, RC5, RC6, RC7, RC8 }, \
    { RD1, RD2, RD3, RD4, RD5, RD6, RD7, RD8 }, \
    { RE1, RE2, RE3, RE4, RE5, RE6, RE7, RE8 } \
  }


#endif
