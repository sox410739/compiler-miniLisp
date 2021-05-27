%{
#include "Final.tab.h"
%}
letter	[a-z]
digit	[0-9]
%%
0|[1-9]{digit}*|[\-]?[1-9]{digit}*	{
	yylval.word = strdup(yytext); 
	return(NUMBER);
}

"print-num"	{
	yylval.word = strdup(yytext);
	return(PRINT_NUM);
}

"print-bool"	{
	yylval.word = strdup(yytext);
	return(PRINT_BOOL);
}

"define"	{
	yylval.word = strdup(yytext);
	return(DEF_HEADER);
}

"if"	{
	yylval.word = strdup(yytext);
	return(IF);
}

"mod"	{
	yylval.word = strdup(yytext);
	return(MODOP);
}

"and"	{
	yylval.word = strdup(yytext);
	return(ANDOP);
}

"or"	{
	yylval.word = strdup(yytext);
	return(OROP);
}

"not"	{
	yylval.word = strdup(yytext);
	return(NOTOP);
}

"("(" ")*"fun"		{
	yylval.word = strdup(yytext);
	return(FUNLR);
}

"("		{
	yylval.word = strdup(yytext);
	return(LR);
}

"#t"	{
	yylval.word = strdup("true");
	return(BOOLEAN);
}

"#f"	{
	yylval.word = strdup("false"); 
	return(BOOLEAN);
}

&	{return 0;}

{letter}({letter}|{digit}|"-")*	{
	int i;
	for(i=0;i<yyleng;i++){
		if(yytext[i] == '-'){
			yytext[i] = '_';
		}
	}
	yylval.word = strdup(yytext); 
	return(ID);
}

"\t"|"\n"|"\r"|" "	{}
.	{return yytext[0];}
%%