%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>
char code[1024];
char allFunction[512];
char buffer[128];
struct varible{
	struct varible* next;
	int typeFlag;
	char name[];
};
struct varible* Begin = NULL;
struct function{
	struct function* next;
	struct varible* parameter;
	int paraNum;
	int stage;
	char name[10];
};
struct function* Fbegin = NULL;
struct functionStack{
	struct function* nowFun;
	struct functionStack* previous;
};
struct functionStack* top = NULL;
char funCounter = 'A';
int defineFlag = 0;

void yyerror(const char* message);
void creatVarible(char* varName, char* varValue);
void checkRedefined(char* varName);
void creatFunction(char* funName);
void addParam(char* parName);
void setFun();
void loadFunction(char* funName);
void checkParaNum();
void pushFun(struct function* fun, int sta);
void popFun(int sta);
%}
%union{
	char* word;
}
%token<word> NUMBER
%token<word> ID
%token<word> PRINT_NUM
%token<word> PRINT_BOOL
%token<word> DEF_HEADER
%token<word> BOOLEAN
%token<word> MODOP
%token<word> LR
%token<word> ANDOP
%token<word> OROP
%token<word> NOTOP
%token<word> FUNLR
%token<word> IF

%type<word> PROGRAM
%type<word> STMT
%type<word> EXP
%type<word> PRINT_STMT
%type<word> DEF_STMT

%type<word> VARIBLE

%type<word> ADDEXP
%type<word> MULTIPLYEXP
%type<word> ANDEXP
%type<word> OREXP
%type<word> EQUALEXP

%type<word> NUM_OP
%type<word> COMPARE_OP
%type<word> LOGICAL_OP

%type<word> PLUS
%type<word> MINUS
%type<word> MULTIPLY
%type<word> DIVIDE
%type<word> MODULUS

%type<word> GREATER
%type<word> SMALLER
%type<word> EQUAL

%type<word> AND
%type<word> OR
%type<word> NOT

%type<word> IF_EXP
%type<word> TEST_EXP
%type<word> THEN_EXP
%type<word> ELSE_EXP

%type<word> FUN_EXP
%type<word> FUN_IDS
%type<word> FUN_BODY
%type<word> ALLDEF
%type<word> FUN_CALL
%type<word> IDS
%type<word> PARAM
%type<word> FUN_NAME
%%
PROGRAM	:STMT			{}
		|PROGRAM STMT	{}
		;

STMT	:EXP			{sprintf(code, "%s%s;\n ", code, $1);}
		|PRINT_STMT		{sprintf(code, "%s%s;\n", code, buffer); memset(buffer, 0, strlen(buffer));}
		|DEF_STMT		{sprintf(code, "%s%s;\n", code, $1);}
		;

PRINT_STMT	:LR PRINT_NUM EXP ')'	{sprintf(buffer, "cout << %s << endl", $3);}
			|LR PRINT_BOOL EXP ')'	{sprintf(buffer, "printBool(%s)", $3);}
			;
DEF_STMT	:LR DEF_HEADER VARIBLE EXP ')'								{creatVarible($3, $4); sprintf($$, "int %s = %s", $3, $4);}
			|LR DEF_HEADER FUN_NAME {creatFunction($3);defineFlag = 1;} FUN_EXP ')'	{sprintf($$, "%s", buffer);memset(buffer, 0, sizeof(buffer));}
			;
VARIBLE		:ID	{sprintf($$, "%s", $1);}
			;
			
EXP		:NUMBER		{sprintf($$, "%s", $1);}
		|BOOLEAN	{sprintf($$, "%s", $1);}
		|VARIBLE	{checkRedefined($1); sprintf($$, "%s", $1);}
		|NUM_OP 	{sprintf($$, "%s", $1);}
		|COMPARE_OP	{sprintf($$, "%s", $1);}
		|LOGICAL_OP	{sprintf($$, "%s", $1);}
		|IF_EXP		{sprintf($$, "%s", $1);}
		|FUN_CALL	{sprintf($$, "%s", $1);}
		;

NUM_OP	:PLUS			{sprintf($$, "%s", $1);}
		|MINUS			{sprintf($$, "%s", $1);}
		|MULTIPLY		{sprintf($$, "%s", $1);}
		|DIVIDE			{sprintf($$, "%s", $1);}
		|MODULUS		{sprintf($$, "%s", $1);}
		;	
COMPARE_OP	:GREATER	{sprintf($$, "%s", $1);}
			|SMALLER	{sprintf($$, "%s", $1);}
			|EQUAL		{sprintf($$, "%s", $1);}
			;
LOGICAL_OP	:AND		{sprintf($$, "%s", $1);}
			|OR			{sprintf($$, "%s", $1);}
			|NOT		{sprintf($$, "%s", $1);}
			;
			
ADDEXP	:EXP			{char temp[64]; sprintf(temp, "(%s", $1); sprintf($$, "%s", temp);}
		|ADDEXP EXP		{sprintf($$, "%s+%s", $1, $2);}
		;	
MULTIPLYEXP	:EXP		{char temp[64]; sprintf(temp, "(%s", $1); sprintf($$, "%s", temp);}
		|MULTIPLYEXP EXP{sprintf($$, "%s*%s", $1, $2);}
		;
ANDEXP	:EXP			{char temp[64]; sprintf(temp, "(%s", $1); sprintf($$, "%s", temp);}
		|ANDEXP EXP		{sprintf($$, "%s&%s", $1, $2);}
		;
OREXP	:EXP			{char temp[64]; sprintf(temp, "(%s", $1); sprintf($$, "%s", temp);}
		|OREXP EXP		{sprintf($$, "%s|%s", $1, $2);}
		;
EQUALEXP:EXP			{char temp[64]; sprintf(temp, "(%s", $1); sprintf($$, "%s", temp);}
		|EQUALEXP EXP	{sprintf($$, "%s==%s", $1, $2);}
		
		
PLUS	:LR '+' ADDEXP EXP ')'		{char temp[64]; sprintf(temp, "%s+%s)", $3, $4); $$ = strdup(temp);}
		;
MINUS	:LR '-' EXP EXP ')'			{char temp[64]; sprintf(temp, "(%s-%s)", $3, $4); $$ = strdup(temp);}
		;
MULTIPLY:LR '*'	MULTIPLYEXP EXP ')'	{char temp[64]; sprintf(temp, "%s*%s)", $3, $4); $$ = strdup(temp);}
		;
DIVIDE	:LR '/'	EXP EXP ')'			{char temp[64]; sprintf(temp, "(%s/%s)", $3, $4); $$ = strdup(temp);}
		;
MODULUS	:LR MODOP EXP EXP ')'		{char temp[64]; sprintf(temp, "(%s%%%s)", $3, $4); $$ = strdup(temp);}
		;
		
GREATER	:LR '>'	EXP EXP ')'			{char temp[64]; sprintf(temp, "(%s>%s)", $3, $4); $$ = strdup(temp);}
		;
SMALLER :LR '<'	EXP EXP ')'			{char temp[64]; sprintf(temp, "(%s<%s)", $3, $4); $$ = strdup(temp);}
		;
EQUAL	:LR '='	EQUALEXP EXP ')'	{char temp[64]; sprintf(temp, "%s==%s)", $3, $4); $$ = strdup(temp);}
		;

AND		:LR ANDOP ANDEXP EXP ')'	{char temp[64]; sprintf(temp, "%s&%s)", $3, $4); $$ = strdup(temp);}
		;
OR		:LR OROP OREXP EXP ')'		{char temp[64]; sprintf(temp, "%s|%s)", $3, $4); $$ = strdup(temp);}
		;
NOT		:LR NOTOP EXP ')'			{sprintf($$, "(!%s)", $3);}
		;
	
IF_EXP	:LR IF TEST_EXP THEN_EXP ELSE_EXP ')'	{sprintf($$, "(%s ? %s : %s)", $3, $4, $5);}
		;
TEST_EXP:EXP	{sprintf($$, "%s", $1);}
		;
THEN_EXP:EXP	{sprintf($$, "%s", $1);}
		;
ELSE_EXP:EXP	{sprintf($$, "%s", $1);}
		;
		
FUN_EXP	:FUNLR {if(!defineFlag){char temp[20]; sprintf(temp, "_%c", funCounter); funCounter++; creatFunction(temp);}defineFlag = 0;} FUN_IDS FUN_BODY ')' {setFun();}
		;FUN_IDS	:LR IDS ')'
		|LR ')'
		;
IDS		:ID			{addParam($1);}
		|IDS ID		{addParam($2);}
		;
ALLDEF	:DEF_STMT			{sprintf(buffer, "%s%s;\n", buffer, $1);}
		|ALLDEF DEF_STMT	{sprintf(buffer, "%s%s;\n ", buffer, $2);}
		;
FUN_BODY:EXP				{sprintf(buffer, "%sreturn %s;\n", buffer, $1);}
		|ALLDEF EXP			{sprintf(buffer, "%sreturn %s;\n", buffer, $2);}
		;
FUN_CALL:LR FUN_EXP {sprintf(code, "%s%s;\n ", code, buffer); memset(buffer, 0, sizeof(buffer));} PARAM ')' 	{checkParaNum(); char temp[64]; sprintf(temp, "%s)", $4); $$ = strdup(temp); popFun(1);}
		|LR FUN_EXP {sprintf(code, "%s%s;\n ", code, buffer); memset(buffer, 0, sizeof(buffer));} ')' 			{checkParaNum(); char temp[64]; sprintf(temp, "%s()", top->nowFun->name); $$ = strdup(temp); popFun(1);}
		|LR FUN_NAME {loadFunction($2);} PARAM ')' 		{checkParaNum(); sprintf($$, "%s)", $4); popFun(1);}
		|LR FUN_NAME {loadFunction($2);} ')'			{checkParaNum(); sprintf($$, "%s()", top->nowFun->name); popFun(1);}
		;
PARAM	:EXP		{top->nowFun->paraNum--; char temp[64]; sprintf(temp, "%s", $1); sprintf($$, "%s(%s", top->nowFun->name, temp);}
		|PARAM EXP	{top->nowFun->paraNum--; char temp[64]; sprintf(temp, "%s, %s", $1, $2); $$ = strdup(temp);}
		;
FUN_NAME:ID 	{sprintf($$, "%s", $1);}
		;
%%
void yyerror(const char* message){
	printf("%s\n", message);
	exit(1);
}

void creatVarible(char* varName, char* varValue){
	struct varible* temp = NULL;
	struct varible* regist = NULL;
	if(top == NULL){
		temp = Begin;
	}
	else{
		temp = top->nowFun->parameter;
	}
	while(temp != NULL){
		if(strcmp(temp->name, varName) == 0){
			printf("varible \'%s\' have been declared", varName);
			yyerror("");
		}
		if(temp->next == NULL){
			regist = temp;
		}
		temp = temp->next;
	}
	
	temp = (struct varible*)malloc(sizeof(struct varible));
	temp->next = NULL;
	sprintf(temp->name, "%s", varName);
	if(top == NULL){
		if(Begin == NULL){
			Begin = temp;
		}
		else{
			regist->next = temp;
		}
	}
	else{
		if(top->nowFun->parameter == NULL){
			top->nowFun->parameter = temp;
		}
		else{
			regist->next = temp;
		}
	}
}

void checkRedefined(char* varName){
	if(top == NULL){
		struct varible* temp = Begin;
		while(temp != NULL){
			printf("%s\n", temp->name);
			if(strcmp(temp->name, varName) == 0){
				return;
			}
			temp = temp->next;
		}

		printf("varible \'%s\' was not defined", varName);
		yyerror("");
	}
	else if(top->nowFun->stage == 0){
		
		struct functionStack* Ftemp = top;
		while(Ftemp != NULL){
			struct varible* temp = Ftemp->nowFun->parameter;
			while(temp != NULL){
				if(strcmp(temp->name, varName) == 0){
					return;
				}
				temp = temp->next;
			}
			Ftemp = Ftemp->previous;
		}

		printf("argument \'%s\' was not defined in this scope", varName);
		yyerror("");
	}
	else if(top->nowFun->stage == 1){
		struct functionStack* Ftemp = top->previous;
		while(Ftemp != NULL){
			struct varible* temp = Ftemp->nowFun->parameter;
			while(temp != NULL){
				if(strcmp(temp->name, varName) == 0){
					return;
				}
				temp = temp->next;
			}
			Ftemp = Ftemp->previous;
		}
		struct varible* temp = Begin;
		while(temp != NULL){
			//printf("%s\n", temp->name);
			if(strcmp(temp->name, varName) == 0){
				return;
			}
			temp = temp->next;
		}

		printf("argument \'%s\' was not defined in this scope", varName);
		yyerror("");
	}
}

void creatFunction(char* funName){
	struct function* temp = Fbegin;
	struct function* regist = NULL;
	while(temp != NULL){
		if(strcmp(temp->name, funName) == 0){
			printf("function \'%s\' has been defined", funName);
			yyerror("");
		}
		if(temp->next == NULL){
			regist = temp;
		}
		temp = temp->next;
	}
	
	temp = (struct function*)malloc(sizeof(struct function));
	temp->next = NULL;
	temp->parameter = NULL;
	temp->paraNum = 0;
	temp->stage = 0;
	sprintf(temp->name, "%s", funName);
	if(Fbegin == NULL){
		Fbegin = temp;
	}
	else{
		regist->next = temp;
	}
	
	pushFun(temp, 0);
}

void loadFunction(char* funName){
	struct function* temp = Fbegin;
	while(temp != NULL){
		/*if(temp->name[strlen(temp->name)-1] == '!'){
			temp->name[strlen(temp->name)-1] = 0;
		}*/
		//printf("%s %zu\n", temp->name, strlen(temp->name));
		if(strcmp(temp->name, funName) == 0){
			pushFun(temp, 1);
			return;
		}
		temp = temp->next;
	}
	
	printf("function \'%s\' was not defined", funName);
	yyerror("");
}

void addParam(char* parName){
	struct varible* temp = top->nowFun->parameter;
	struct varible* regist = NULL;
	while(temp != NULL){
		if(strcmp(temp->name, parName) == 0){
			printf("redefined of \'%s\'", parName);
			yyerror("");
		}
		if(temp->next == NULL){
			regist = temp;
		}
		temp = temp->next;
	}
	
	top->nowFun->paraNum++;
	//printf("%d\n", top->nowFun->paraNum);
	temp = (struct varible*)malloc(sizeof(struct varible));
	temp->next = NULL;
	sprintf(temp->name, "%s", parName);
	if(top->nowFun->parameter == NULL){
		top->nowFun->parameter = temp;
	}
	else{
		regist->next = temp;
	}
}

void setFun(){
	char funDef[128];
	sprintf(funDef, "int %s(", top->nowFun->name);
	struct varible* temp = top->nowFun->parameter;
	if(temp == NULL){
		sprintf(funDef, "%s){\n ", funDef);
	}
	else{
		sprintf(funDef, "%sint %s", funDef, temp->name);
		temp = temp->next;
		while(temp != NULL){
			sprintf(funDef, "%s, int %s", funDef, temp->name);
			temp = temp->next;
		}
		sprintf(funDef, "%s){\n ", funDef);
	}
	sprintf(allFunction, "%s%s%s}\n\n", allFunction, funDef, buffer);
	sprintf(buffer, "%s", funDef);
	buffer[strlen(funDef)-3] = 0;
	top->nowFun->stage = 1;
	if(top->nowFun->name[0] != '_'){
		popFun(0);
	}
}

void checkParaNum(){
	//printf("%d\n", top->nowFun->paraNum);
	if(top->nowFun->paraNum < 0){
		printf("too many arguments to function");
		yyerror("");
	}
	if(top->nowFun->paraNum > 0){
		printf("too few arguments to function");
		yyerror("");
	}
	
	struct varible* temp = top->nowFun->parameter;
	while(temp != NULL){
		top->nowFun->paraNum++;
		temp = temp->next;
	}
}

void pushFun(struct function* fun, int sta){
	struct functionStack* temp = (struct functionStack*)malloc(sizeof(struct functionStack));
	if(sta == 0){
		temp->nowFun = fun;
	}
	else{
		temp->nowFun = (struct function*)malloc(sizeof(struct function));
		temp->nowFun->paraNum = fun->paraNum;
		temp->nowFun->parameter = fun->parameter;
		temp->nowFun->stage = 1;
		sprintf(temp->nowFun->name, "%s", fun->name);
		temp->nowFun->next = NULL;
	}
	
	temp->previous = top;
	top = temp;
	//printf("%d\n", sta);
	//printf("%d\n", top->nowFun->paraNum);
	//printf("%s %d push\n", top->nowFun->name, sta);
}

void popFun(int sta){
	//printf("%s %d pop\n", top->nowFun->name, sta);
	struct functionStack* temp = top;
	/*if(sta == 1){
		free(temp->nowFun);
	}*/
	top = top->previous;
	free(temp);
}

int main(int argc, char* argv[]){
	sprintf(code, "#include<iostream>\n\nusing namespace std;\nvoid printBool(int b);\n\nint main(){\n ");
	sprintf(allFunction, "void printBool(int b){\n if(b == 1){\n  cout << \"#t\" << endl;\n }else if(b == 0){\n  cout << \"#f\" << endl;\n }else{\n  cout << \"type error\" << endl;\n }\n}\n\n");
	yyparse();
	sprintf(code, "%s\n return 0;\n}", code);
	FILE* Fout;
	Fout = fopen("out.cpp", "w+t");
	//printf("%s\n\n%s\n", code, allFunction);
	fprintf(Fout, "%s\n\n%s\n", code, allFunction);
	fclose(Fout);
	return(0);
}