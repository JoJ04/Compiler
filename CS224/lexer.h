#ifndef LEXER_H_
#define LEXER_H_
#include "global.h"
#include "symbol.h"
#include"error.h"
extern FILE *input;
extern struct entry symtable[];
int insert(char s[], int tok);
int lookup(char s[]);
void error(char* m);


char lexbuf[BSIZE];
int lineno = 1;
int tokenval = NONE;

int lexan(){
int t;
  while(1){
        t=getc(input);
        if(t=='^'){
            while(1){
                t=getc(input);
                if(t=='\n')
                    break;
                
                lineno++;   
            }
        t = getc(input);
        }
        
        if(t=='%'){
            while(1){
                t=getc(input);
                if(t=='\n')
                    lineno++;
                if(t == '%')
		            break;
            }
 t=getc(input);
        }
if (t == ' ' || t == '\t');
else if (t == '\n')
 lineno = lineno + 1;
 
 else if (isdigit (t)) {
 ungetc(t,input);
 fscanf(input,"%d",&tokenval);
 return NUM;
 }
 
else if (isalpha(t)) {
int p, b = 0;

while (isalnum(t)) {
lexbuf[b++] = t;
t=getc(input);
if (b >= BSIZE)
error("compiler error"); }

lexbuf[b] = EOS;
if (t != EOF)
ungetc(t, input);
p = lookup(lexbuf);
if(p == 0)
p = insert(lexbuf, ID);
tokenval = p;
return symtable[p].token;
}
else if (t == EOF)
return DONE;
else {
 tokenval = NONE;
 return t;
 }
}
}
#endif // LEXER_H
