#ifndef GLOBAL_H_
#define GLOBAL_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define BSIZE 128
#define NONE -1
#define EOS '\0'
#define NUM 256
#define DIV 257
#define MOD 258
#define ID 259
#define DONE 260
#define IF 261
#define BEGIN 262
#define END 263
#define WHILE 264
#define DO 265
#define THEN 266
#define MAIN 267
#define FUNCTION 268
#define ELSE 269

extern int lookahead;
extern int tokenval;
extern int lineno;
struct entry {
 char *lexptr;
 int token;
 };
 #endif
