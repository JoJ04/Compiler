#ifndef PARSE_H_
#define PARSE_H_
#include "global.h"
#include "lexer.h"
#include "emitter.h"
int tok;
int lookahead;
extern FILE *output;

void parse();
void expr();
void term();
void match(int);
void factor();
void stmt();
void CS();
void Rest();
void Dec();
void Mainfun();
void Funcdec();
void B();
void if1();
void if2();
void w1();
void w2();
void w3();
void func1();
void func2();
void func3();
void main1();
void main2(); 

void parse(){
lookahead = lexan();
while (lookahead != DONE) {
	Dec();
Mainfun();
}
match(DONE);
}
void match(int t){
if (lookahead == t)
lookahead = lexan();
else error ("syntax error");
}

void Funcdec(){
match(FUNCTION);
func1();
match(ID);
match('(');
match(')');
match(BEGIN);
CS();
match(END);
func2();
}

void Dec(){
	if(lookahead == FUNCTION){
		Funcdec();
		match(';');
		Dec();
	}	
}
void Mainfun(){
	match(MAIN);
	main1();
	match('(');
	match(')');
	match(BEGIN);
	CS();
	match(END);
	main2();
}

void factor(){
switch (lookahead) {
case '(':
match ('('); expr(); match(')');
break;

case NUM:
emit(NUM, tokenval);
match(NUM); break;

case ID:
emit(ID, tokenval);
match(ID);break;

default:
error("syntax error");
}}

void stmt(){
	
	switch(lookahead){
		case ID:
		tok =tokenval;
			match(ID);
			Rest();
			break;	
		case IF:
		match(IF);
	    	match('(');
	    	expr();
	    	match(')');
	    	if1();
	    	match(THEN);
			match('[');
	    	stmt();
			match(']');
	    	if2();
	        B();
            break;
		case WHILE:
			match(WHILE);
			w1();
			match('(');
			expr();
			match(')');
			w2();
			match(DO);
			stmt();
			w3();
            break; 
		case BEGIN:
			match(BEGIN);
			CS();
			match(END);
            break;
	}
}
void Rest(){
	if(lookahead=='='){
	     match('=');
			expr();
			fprintf(output,"pop %s\n",symtable[tok].lexptr);}
	else if(lookahead=='('){
			match('(');
			match(')');
			func3();
	}
}
void CS(){
	if(lookahead==ID||lookahead==IF||lookahead==BEGIN||lookahead==WHILE){
		stmt();
		match(';');
		CS();
	}
	else 
	return; 
}
void B(){
	 if(lookahead==ELSE) {
		match(ELSE);
		match('[');
		stmt();
		match(']');
	 }	
	
}
void term(){
int t;

factor();
while(1)
 switch (lookahead) {
 case '*': case '/': case DIV: case MOD: 
t = lookahead;
match(lookahead); factor(); emit(t, NONE); 
continue;

default:
return;
}}

void expr(){
int t;
term();
while(1)
 switch (lookahead) {
 case '+': case '-':
 t = lookahead;
 match(lookahead); term(); emit(t, NONE);
 continue;
 
 default:
 return;
}
}

void if1(){
	fprintf(output,"pop r2\ncmp r2,0\nbe else\n");
}
void if2(){
	fprintf(output,"else\n");
}
void w1(){
	fprintf(output,"while\n");
}
void w2(){
	fprintf(output,"pop r2\ncmp r2,0\nbe endwhile\n");
}
void w3(){
	fprintf(output,"b while\n endwhile\n");
}
void func1(){
    fprintf(output,"%s :\n",symtable[tokenval].lexptr);
}
void func2(){
    fprintf(output,"ret\n");
}
void func3(){
   fprintf(output,"call %s :\n",symtable[tok].lexptr); 
}
void main1(){
    fprintf(output,"main:\n");
}
void main2(){
     fprintf(output,"exit\n");
}

#endif // PARSE_H_ 
 