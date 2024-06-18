// File Main
// Compilare con g++ -Wall ASD-token.cpp ASD-stack.cpp ASD-aritexpr.cpp ASD-aritexpr-test.cpp -o ASD-aritexpr-test

// NON MODIFICARE QUESTO FILE
#include <iostream>
#include "ASD-aritexpr.h"

using namespace std;

int main(){
	string expr;	
	int resi=0;
	int req_resi=0;
	unsigned i=1;

	expr="2";
	cout<<"*************** Test "<<i<<": "<< expr<<" ****************"<<endl;
	
	resi=compute_arithmetic_expr(expr);
	req_resi=2;
	if(resi==req_resi) cout<<"  Risultato: PASSED"<<endl;
	else{
		cout<<"  Risultato: FAILED"<<endl;
		cout<<"  Risultato aspettato: "<<req_resi<<endl;
    	cout<<"  Risultato ottenuto: "<<resi<<endl;
	}
	cout<<endl;
	++i;

	expr="45";
	cout<<"*************** Test "<<i<<": "<< expr<<" ****************"<<endl;
	
	resi=compute_arithmetic_expr(expr);
	req_resi=45;
	if(resi==req_resi) cout<<"  Risultato: PASSED"<<endl;
	else{
		cout<<"  Risultato: FAILED"<<endl;
		cout<<"  Risultato aspettato: "<<req_resi<<endl;
    	cout<<"  Risultato ottenuto: "<<resi<<endl;
	}
	cout<<endl;
	++i;

	expr="( 1 + 2 )";
	cout<<"*************** Test "<<i<<": "<< expr<<" ****************"<<endl;
	
	resi=compute_arithmetic_expr(expr);
	req_resi=3;
	if(resi==req_resi) cout<<"  Risultato: PASSED"<<endl;
	else{
		cout<<"  Risultato: FAILED"<<endl;
		cout<<"  Risultato aspettato: "<<req_resi<<endl;
    	cout<<"  Risultato ottenuto: "<<resi<<endl;
	}
	cout<<endl;
	++i;

	expr="( 2 - 4 )";
	cout<<"*************** Test "<<i<<": "<< expr<<" ****************"<<endl;
	
	resi=compute_arithmetic_expr(expr);
	req_resi=-2;
	if(resi==req_resi) cout<<"  Risultato: PASSED"<<endl;
	else{
		cout<<"  Risultato: FAILED"<<endl;
		cout<<"  Risultato aspettato: "<<req_resi<<endl;
    	cout<<"  Risultato ottenuto: "<<resi<<endl;
	}
	cout<<endl;
	++i;

	expr="( 3 * 5 )";
	cout<<"*************** Test "<<i<<": "<< expr<<" ****************"<<endl;
	
	resi=compute_arithmetic_expr(expr);
	req_resi=15;
	if(resi==req_resi) cout<<"  Risultato: PASSED"<<endl;
	else{
		cout<<"  Risultato: FAILED"<<endl;
		cout<<"  Risultato aspettato: "<<req_resi<<endl;
    	cout<<"  Risultato ottenuto: "<<resi<<endl;
	}
	cout<<endl;
	++i;

	expr="( ( 1 + 3 ) + 2 )";
	cout<<"*************** Test "<<i<<": "<< expr<<" ****************"<<endl;
	
	resi=compute_arithmetic_expr(expr);
	req_resi=6;
	if(resi==req_resi) cout<<"  Risultato: PASSED"<<endl;
	else{
		cout<<"  Risultato: FAILED"<<endl;
		cout<<"  Risultato aspettato: "<<req_resi<<endl;
    	cout<<"  Risultato ottenuto: "<<resi<<endl;
	}
	cout<<endl;
	++i;

	expr="( 3 * ( 1 + 3 ) )";
	cout<<"*************** Test "<<i<<": "<< expr<<" ****************"<<endl;
	
	resi=compute_arithmetic_expr(expr);
	req_resi=12;
	if(resi==req_resi) cout<<"  Risultato: PASSED"<<endl;
	else{
		cout<<"  Risultato: FAILED"<<endl;
		cout<<"  Risultato aspettato: "<<req_resi<<endl;
    	cout<<"  Risultato ottenuto: "<<resi<<endl;
	}
	cout<<endl;
	++i;

	expr="( ( 4 - 5 ) * 3 )";
	cout<<"*************** Test "<<i<<": "<< expr<<" ****************"<<endl;
	
	resi=compute_arithmetic_expr(expr);
	req_resi=-3;
	if(resi==req_resi) cout<<"  Risultato: PASSED"<<endl;
	else{
		cout<<"  Risultato: FAILED"<<endl;
		cout<<"  Risultato aspettato: "<<req_resi<<endl;
    	cout<<"  Risultato ottenuto: "<<resi<<endl;
	}
	cout<<endl;
	++i;

	expr="( ( 4 - 5 ) * ( 2 - 6 ) )";
	cout<<"*************** Test "<<i<<": "<< expr<<" ****************"<<endl;
	
	resi=compute_arithmetic_expr(expr);
	req_resi=4;
	if(resi==req_resi) cout<<"  Risultato: PASSED"<<endl;
	else{
		cout<<"  Risultato: FAILED"<<endl;
		cout<<"  Risultato aspettato: "<<req_resi<<endl;
    	cout<<"  Risultato ottenuto: "<<resi<<endl;
	}
	cout<<endl;
	++i;

	expr="( ( 2 * 5 ) + ( 3 * 3 ) )";
	cout<<"*************** Test "<<i<<": "<< expr<<" ****************"<<endl;
	
	resi=compute_arithmetic_expr(expr);
	req_resi=19;
	if(resi==req_resi) cout<<"  Risultato: PASSED"<<endl;
	else{
		cout<<"  Risultato: FAILED"<<endl;
		cout<<"  Risultato aspettato: "<<req_resi<<endl;
    	cout<<"  Risultato ottenuto: "<<resi<<endl;
	}
	cout<<endl;
	++i;

	expr="( ( 4 * 5 ) - ( 4 * 3 ) )";
	cout<<"*************** Test "<<i<<": "<< expr<<" ****************"<<endl;
	
	resi=compute_arithmetic_expr(expr);
	req_resi=8;
	if(resi==req_resi) cout<<"  Risultato: PASSED"<<endl;
	else{
		cout<<"  Risultato: FAILED"<<endl;
		cout<<"  Risultato aspettato: "<<req_resi<<endl;
    	cout<<"  Risultato ottenuto: "<<resi<<endl;
	}
	cout<<endl;
	++i;

	expr="( ( 4 * 5 ) * ( 3 * 6 ) )";
	cout<<"*************** Test "<<i<<": "<< expr<<" ****************"<<endl;
	
	resi=compute_arithmetic_expr(expr);
	req_resi=360;
	if(resi==req_resi) cout<<"  Risultato: PASSED"<<endl;
	else{
		cout<<"  Risultato: FAILED"<<endl;
		cout<<"  Risultato aspettato: "<<req_resi<<endl;
    	cout<<"  Risultato ottenuto: "<<resi<<endl;
	}
	cout<<endl;
	++i;

	expr="( ( 100 * 20 ) + ( 1000 - 5 ) )";
	cout<<"*************** Test "<<i<<": "<< expr<<" ****************"<<endl;
	
	resi=compute_arithmetic_expr(expr);
	req_resi=2995;
	if(resi==req_resi) cout<<"  Risultato: PASSED"<<endl;
	else{
		cout<<"  Risultato: FAILED"<<endl;
		cout<<"  Risultato aspettato: "<<req_resi<<endl;
    	cout<<"  Risultato ottenuto: "<<resi<<endl;
	}
	cout<<endl;
	++i;

	expr="( ( 100 + 11 ) * ( 1 + ( 2 + 2 ) ) )";
	cout<<"*************** Test "<<i<<": "<< expr<<" ****************"<<endl;
	
	resi=compute_arithmetic_expr(expr);
	req_resi=555;
	if(resi==req_resi) cout<<"  Risultato: PASSED"<<endl;
	else{
		cout<<"  Risultato: FAILED"<<endl;
		cout<<"  Risultato aspettato: "<<req_resi<<endl;
    	cout<<"  Risultato ottenuto: "<<resi<<endl;
	}
	cout<<endl;
	++i;

	expr="( ( ( 2 + 2 ) * ( 7 - 2 ) ) * ( ( 1 + 2 ) * ( 3 * 2 ) ) )";
	cout<<"*************** Test "<<i<<": "<< expr<<" ****************"<<endl;
	
	resi=compute_arithmetic_expr(expr);
	req_resi=360;
	if(resi==req_resi) cout<<"  Risultato: PASSED"<<endl;
	else{
		cout<<"  Risultato: FAILED"<<endl;
		cout<<"  Risultato aspettato: "<<req_resi<<endl;
    	cout<<"  Risultato ottenuto: "<<resi<<endl;
	}
	cout<<endl;
	++i;

	expr="( 0 * ( ( ( 4 + 123 ) * ( 12 - 22 ) ) * ( ( 100 + 2 ) * ( 350 * 25 ) ) ) )";
	cout<<"*************** Test "<<i<<": "<< expr<<" ****************"<<endl;
	
	resi=compute_arithmetic_expr(expr);
	req_resi=0;
	if(resi==req_resi) cout<<"  Risultato: PASSED"<<endl;
	else{
		cout<<"  Risultato: FAILED"<<endl;
		cout<<"  Risultato aspettato: "<<req_resi<<endl;
    	cout<<"  Risultato ottenuto: "<<resi<<endl;
	}
	cout<<endl;
	++i;
	
	expr="(    (    100    *     20     )    +     (    1000    - 5    )    )";
	cout<<"*************** Test "<<i<<": "<< expr<<" ****************"<<endl;
	
	resi=compute_arithmetic_expr(expr);
	req_resi=2995;
	if(resi==req_resi) cout<<"  Risultato: PASSED"<<endl;
	else{
		cout<<"  Risultato: FAILED"<<endl;
		cout<<"  Risultato aspettato: "<<req_resi<<endl;
    	cout<<"  Risultato ottenuto: "<<resi<<endl;
	}
	cout<<endl;
	++i;
	
	cout<<"*************** !!!!NEGATIVE TESTS!!!! ****************"<<endl;
	
	{
		expr="( 3 + )";
		cout<<"*************** Test "<<i<<": "<< expr<<" ****************"<<endl;
		
		string resiString = "";
		int resi = 0;
		try{
		resi=compute_arithmetic_expr(expr);
		}catch(string exp)
		{
			resiString = exp;
		}
		string req_resiString="Syntactical error";
		if(resiString==req_resiString) cout<<"  Risultato: PASSED => error detected: "<<req_resiString<<endl;
		else{
			cout<<"  Risultato: FAILED"<<endl;
			cout<<"  Risultato aspettato: "<<req_resiString<<endl;
			cout<<"  Risultato ottenuto: "<<resiString<<endl;
			cout<<"  Risultato valutazione expr: "<<resi<<endl;
		}
		cout<<endl;
		++i;
	}
	
	{
		expr="( + )";
		cout<<"*************** Test "<<i<<": "<< expr<<" ****************"<<endl;
		
		string resiString = "";
		int resi = 0;
		try{
		resi=compute_arithmetic_expr(expr);
		}catch(string exp)
		{
			resiString = exp;
		}
		string req_resiString="Syntactical error";
		if(resiString==req_resiString) cout<<"  Risultato: PASSED => error detected: "<<req_resiString<<endl;
		else{
			cout<<"  Risultato: FAILED"<<endl;
			cout<<"  Risultato aspettato: "<<req_resiString<<endl;
			cout<<"  Risultato ottenuto: "<<resiString<<endl;
			cout<<"  Risultato valutazione expr: "<<resi<<endl;
		}
		cout<<endl;
		++i;
	}
	
	{
		expr="4 + ";
		cout<<"*************** Test "<<i<<": "<< expr<<" ****************"<<endl;
		
		string resiString = "";
		int resi = 0;
		try{
		resi=compute_arithmetic_expr(expr);
		}catch(string exp)
		{
			resiString = exp;
		}
		string req_resiString="Syntactical error";
		if(resiString==req_resiString) cout<<"  Risultato: PASSED => error detected: "<<req_resiString<<endl;
		else{
			cout<<"  Risultato: FAILED"<<endl;
			cout<<"  Risultato aspettato: "<<req_resiString<<endl;
			cout<<"  Risultato ottenuto: "<<resiString<<endl;
			cout<<"  Risultato valutazione expr: "<<resi<<endl;
		}
		cout<<endl;
		++i;
	}
	
	{
		expr=" 5 + )";
		cout<<"*************** Test "<<i<<": "<< expr<<" ****************"<<endl;
		
		string resiString = "";
		int resi = 0;
		try{
		resi=compute_arithmetic_expr(expr);
		}catch(string exp)
		{
			resiString = exp;
		}
		string req_resiString="Syntactical error";
		if(resiString==req_resiString) cout<<"  Risultato: PASSED => error detected: "<<req_resiString<<endl;
		else{
			cout<<"  Risultato: FAILED"<<endl;
			cout<<"  Risultato aspettato: "<<req_resiString<<endl;
			cout<<"  Risultato ottenuto: "<<resiString<<endl;
			cout<<"  Risultato valutazione expr: "<<resi<<endl;
		}
		cout<<endl;
		++i;
	}
	
	{
		expr="( + 6 )";
		cout<<"*************** Test "<<i<<": "<< expr<<" ****************"<<endl;
		
		string resiString = "";
		int resi = 0;
		try{
		resi=compute_arithmetic_expr(expr);
		}catch(string exp)
		{
			resiString = exp;
		}
		string req_resiString="Syntactical error";
		if(resiString==req_resiString) cout<<"  Risultato: PASSED => error detected: "<<req_resiString<<endl;
		else{
			cout<<"  Risultato: FAILED"<<endl;
			cout<<"  Risultato aspettato: "<<req_resiString<<endl;
			cout<<"  Risultato ottenuto: "<<resiString<<endl;
			cout<<"  Risultato valutazione expr: "<<resi<<endl;
		}
		cout<<endl;
		++i;
	}
	
	{
		expr="7 + 7";
		cout<<"*************** Test "<<i<<": "<< expr<<" ****************"<<endl;
		
		string resiString = "";
		int resi = 0;
		try{
		resi=compute_arithmetic_expr(expr);
		}catch(string exp)
		{
			resiString = exp;
		}
		string req_resiString="Syntactical error";
		if(resiString==req_resiString) cout<<"  Risultato: PASSED => error detected: "<<req_resiString<<endl;
		else{
			cout<<"  Risultato: FAILED"<<endl;
			cout<<"  Risultato aspettato: "<<req_resiString<<endl;
			cout<<"  Risultato ottenuto: "<<resiString<<endl;
			cout<<"  Risultato valutazione expr: "<<resi<<endl;
		}
		cout<<endl;
		++i;
	}
	
	{
		expr="! + 7";
		cout<<"*************** Test "<<i<<": "<< expr<<" ****************"<<endl;
		
		string resiString = "";
		int resi = 0;
		try{
		resi=compute_arithmetic_expr(expr);
		}catch(string exp)
		{
			resiString = exp;
		}
		string req_resiString="Lexical error";
		if(resiString==req_resiString) cout<<"  Risultato: PASSED => error detected: "<<req_resiString<<endl;
		else{
			cout<<"  Risultato: FAILED"<<endl;
			cout<<"  Risultato aspettato: "<<req_resiString<<endl;
			cout<<"  Risultato ottenuto: "<<resiString<<endl;
			cout<<"  Risultato valutazione expr: "<<resi<<endl;
		}
		cout<<endl;
		++i;
	}
	
	{
		expr="(9+9)";
		cout<<"*************** Test "<<i<<": "<< expr<<" ****************"<<endl;
		
		string resiString = "";
		int resi = 0;
		try{
		resi=compute_arithmetic_expr(expr);
		}catch(string exp)
		{
			resiString = exp;
		}
		string req_resiString="Lexical error";
		if(resiString==req_resiString) cout<<"  Risultato: PASSED => error detected: "<<req_resiString<<endl;
		else{
			cout<<"  Risultato: FAILED"<<endl;
			cout<<"  Risultato aspettato: "<<req_resiString<<endl;
			cout<<"  Risultato ottenuto: "<<resiString<<endl;
			cout<<"  Risultato valutazione expr: "<<resi<<endl;
		}
		cout<<endl;
		++i;
	}
	
	{
		expr="( 9.4 + 5.6 )";
		cout<<"*************** Test "<<i<<": "<< expr<<" ****************"<<endl;
		
		string resiString = "";
		int resi = 0;
		try{
		resi=compute_arithmetic_expr(expr);
		}catch(string exp)
		{
			resiString = exp;
		}
		string req_resiString="Lexical error";
		if(resiString==req_resiString) cout<<"  Risultato: PASSED => error detected: "<<req_resiString<<endl;
		else{
			cout<<"  Risultato: FAILED"<<endl;
			cout<<"  Risultato aspettato: "<<req_resiString<<endl;
			cout<<"  Risultato ottenuto: "<<resiString<<endl;
			cout<<"  Risultato valutazione expr: "<<resi<<endl;
		}
		cout<<endl;
		++i;
	}
	
	{
		expr="( 9. + 5. )";
		cout<<"*************** Test "<<i<<": "<< expr<<" ****************"<<endl;
		
		string resiString = "";
		int resi = 0;
		try{
		resi=compute_arithmetic_expr(expr);
		}catch(string exp)
		{
			resiString = exp;
		}
		string req_resiString="Lexical error";
		if(resiString==req_resiString) cout<<"  Risultato: PASSED => error detected: "<<req_resiString<<endl;
		else{
			cout<<"  Risultato: FAILED"<<endl;
			cout<<"  Risultato aspettato: "<<req_resiString<<endl;
			cout<<"  Risultato ottenuto: "<<resiString<<endl;
			cout<<"  Risultato valutazione expr: "<<resi<<endl;
		}
		cout<<endl;
		++i;
	}
	
{
		expr="( .4 + .6 )";
		cout<<"*************** Test "<<i<<": "<< expr<<" ****************"<<endl;
		
		string resiString = "";
		int resi = 0;
		try{
		resi=compute_arithmetic_expr(expr);
		}catch(string exp)
		{
			resiString = exp;
		}
		string req_resiString="Lexical error";
		if(resiString==req_resiString) cout<<"  Risultato: PASSED => error detected: "<<req_resiString<<endl;
		else{
			cout<<"  Risultato: FAILED"<<endl;
			cout<<"  Risultato aspettato: "<<req_resiString<<endl;
			cout<<"  Risultato ottenuto: "<<resiString<<endl;
			cout<<"  Risultato valutazione expr: "<<resi<<endl;
		}
		cout<<endl;
		++i;
	}
	
{
		expr="( 40.ABC + 1 )";
		cout<<"*************** Test "<<i<<": "<< expr<<" ****************"<<endl;
		
		string resiString = "";
		int resi = 0;
		try{
		resi=compute_arithmetic_expr(expr);
		}catch(string exp)
		{
			resiString = exp;
		}
		string req_resiString="Lexical error";
		if(resiString==req_resiString) cout<<"  Risultato: PASSED => error detected: "<<req_resiString<<endl;
		else{
			cout<<"  Risultato: FAILED"<<endl;
			cout<<"  Risultato aspettato: "<<req_resiString<<endl;
			cout<<"  Risultato ottenuto: "<<resiString<<endl;
			cout<<"  Risultato valutazione expr: "<<resi<<endl;
		}
		cout<<endl;
		++i;
	}
	
}