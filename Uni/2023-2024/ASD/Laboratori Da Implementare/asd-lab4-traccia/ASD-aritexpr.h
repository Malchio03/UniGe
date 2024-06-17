#ifndef ASD_ARITEXPR_H
#define ASD_ARITEXPR_H

#include<string>

/*Calcula il valore intero dell'espressione aritmetica st*/
/*se st non corrisponde ad un expression aritmetica*/
/*solleva un eccezione di tipo string*/
/*con valore: "Lexical Error" se st non è composta da tokens*/
/*e valore: "Syntactical Error" se st è ben formata*/
int compute_arithmetic_expr(const std::string& st);

#endif
