%{
/* Parser for gnbasic
   Copyright (C) 1998 James Bowman

This file is part of gnbasic.

gnbasic is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

gnbasic is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with gnbasic; see the file COPYING.  If not, write to
the Free Software Foundation, 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  */

#define YYDEBUG 1

#include "t1.h"

extern int yyparse();

static double errline;

void yyerror(const char *message)
{
  fprintf(stderr, "Syntax error at line %g\n", errline);
  exit(1);
}

int yylex(void);

static statement_t *mkstatement(int t)
{
  statement_t *news = (statement_t *)malloc(sizeof(*news));
  news->type = t;
  return news;
}

static expression_t *mkexpression(expression_type_t t)
{
  expression_t *news = (expression_t *)malloc(sizeof(*news));
  news->type = t;
  return news;
}

static expression_t *mkop(int arity, int o)
{
  expression_t *news = mkexpression(op);
  news->parms.op.o = o;
  news->parms.op.arity = arity;
  return news;
}

/************************************************************************/

%}

/* Bison declarations */

%union {
  double d;
  int i;
  GString *s;
  GList *l;
  statement_t *statement;
  expression_t *expression;
  variable_t *variable;
}

%type <i> line program
%type <l> printlist statements exprlist varlist
%type <i> printsep e0op e1op e2op e3op e4op e5op1 e5op2 e5op3
%type <expression> expression expression0 expression1 expression2 expression3 expression4 expression5 expression6
%type <statement> statement
%type <variable> variable

%token <d> NUMBER
%token <d> FLOATLIT
%token <i> INTLIT
%token <s> STRING
%token <s> STRLIT
%token <s> IDENTIFIER

%token SGN
%token LEFT
%token RIGHT
%token MID
%token _ABS
%token VAL
%token LOG
%token EXP
%token AND
%token ATN
%token COS
%token DATA
%token DIM
%token END
%token FOR
%token GOSUB
%token GOTO
%token IF
%token INPUT
%token INT
%token LET
%token NEXT
%token NOT
%token OR
%token PRINT
%token READ
%token RETURN
%token SIN
%token SQR
%token STEP
%token THEN
%token TO
%token USING

%token RUN
%token LIST
%token CLEAR
%token SAVE
%token LOAD

%token NL


%token CMP_LE CMP_GE CMP_NE

%%
/* Grammar rules */

program:
        line
	|
	program '\n' line
	|
        program error '\n'
	;

line:   
	/* can be nothing */
        {
        }
        |
        NUMBER { errline = $1; } statements
	{
	  is.line[(int)$1] = $3;
	}
        |
        RUN { }
        |
        RUN NUMBER { }
        |
        LIST { }
        |
        LIST NUMBER { }
        | 
        LOAD STRING { }
        |
        SAVE STRING { }
	;

statements:
        statement
        {
	  $$ = g_list_prepend(NULL, $1);
        }
        |
        statement ':' statements
        {
	  $$ = g_list_prepend($3, $1);
        }
	;

statement:
	/* Can be nothing */
        {
	  $$ = NULL;
	}
	|
	DATA exprlist
        {
	  statement_t *news = mkstatement(DATA);
	  news->parms.data = $2;
	  $$ = news;
	}
	|
	DIM varlist
        {
	  statement_t *news = mkstatement(DIM);
	  news->parms.dim = $2;
	  $$ = news;
	}
        |
	END
        {
	  statement_t *news = mkstatement(END);
	  $$ = news;
	}
        |
	FOR variable '=' expression TO expression
        {
	  statement_t *news = mkstatement(FOR);
	  news->parms._for.v = $2;
	  news->parms._for.begin = $4;
	  news->parms._for.end = $6;
	  news->parms._for.step = NULL;
	  $$ = news;
	}
	|
	FOR variable '=' expression TO expression STEP expression
        {
	  statement_t *news = mkstatement(FOR);
	  news->parms._for.v = $2;
	  news->parms._for.begin = $4;
	  news->parms._for.end = $6;
	  news->parms._for.step = $8;
	  $$ = news;
	}
	|
	GOSUB expression
	{
	  statement_t *news = mkstatement(GOSUB);
	  news->parms.gosub = $2;
	  $$ = news;
	}
	|
	GOTO expression
	{
	  statement_t *news = mkstatement(GOTO);
	  news->parms._goto = $2;
	  $$ = news;
	}
	|
	INPUT printlist
        {
	  statement_t *news = mkstatement(INPUT);
	  news->parms.input = $2;
	  $$ = news;
	}
        |
	IF expression THEN NUMBER
        {
	  statement_t *news = mkstatement(IF);
	  news->parms._if.cond = $2;
	  news->parms._if.thene = NULL;
	  news->parms._if.thenl = $4;
	  $$ = news;
	}
        |
	IF expression THEN statements
        {
	  statement_t *news = mkstatement(IF);
	  news->parms._if.cond = $2;
	  news->parms._if.thene = $4;
	  news->parms._if.thenl = 0;
	  $$ = news;
	}
        |
	NEXT variable
        {
	  statement_t *news = mkstatement(NEXT);
	  news->parms.next = $2;
	  $$ = news;
	}
	|
	PRINT printlist
        {
	  statement_t *news = mkstatement(PRINT);
	  news->parms.print.usingwhich = NULL;
	  news->parms.print.l = $2;
	  $$ = news;
	}
	|
	PRINT USING expression ';' printlist
        {
	  statement_t *news = mkstatement(PRINT);
	  news->parms.print.usingwhich = $3;
	  news->parms.print.l = $5;
	  $$ = news;
	}
        |
	READ varlist
        {
	  statement_t *news = mkstatement(READ);
	  news->parms.read = $2;
	  $$ = news;
	}
        |
	RETURN
        {
	  statement_t *news = mkstatement(RETURN);
	  $$ = news;
	}
        |
        variable '=' expression
        {
	  statement_t *news = mkstatement(LET);
	  news->parms.let.lvalue = $1;
	  news->parms.let.e = $3;
	  $$ = news;
        }
	;

printlist:
        {
	  $$ = NULL;
        }
        |
	expression
	{
	  printitem_t *news = (printitem_t *)malloc(sizeof(*news));

	  news->e = $1;
	  news->sep = 0;
	  $$ = g_list_prepend(NULL, news);
	}
	|
	expression printsep printlist
	{
	  printitem_t *news = (printitem_t *)malloc(sizeof(*news));

	  news->e = $1;
	  news->sep = $2;
	  $$ = g_list_prepend($3, news);
	}
	;

printsep:
	','
        {
	  $$ = ',';
	}
        |
	';'
        {
	  $$ = ';';
	}
        ;

expression: expression0 ;

expression0:
        expression1
        |
	expression0 e0op expression1
	{
	  expression_t *news = mkop(2, $2);
	  news->parms.op.p[0] = $1;
	  news->parms.op.p[1] = $3;
	  $$ = news;
	}
        ;

e0op:   AND { $$ = AND; } |
        OR  { $$ = OR;  };

expression1:
        expression2
        |
	expression1 e1op expression2
	{
	  expression_t *news = mkop(2, $2);
	  news->parms.op.p[0] = $1;
	  news->parms.op.p[1] = $3;
	  $$ = news;
	}
        ;

e1op:   '=' { $$ = '='; } |
        '<' { $$ = '<'; } |
        '>' { $$ = '>'; } |
        CMP_NE { $$ = CMP_NE; } |
        CMP_LE { $$ = CMP_LE; } |
        CMP_GE { $$ = CMP_GE; } ;

expression2:
        expression3
        |
	expression2 e2op expression3
	{
	  expression_t *news = mkop(2, $2);
	  news->parms.op.p[0] = $1;
	  news->parms.op.p[1] = $3;
	  $$ = news;
	}
        ;

e2op:   '+' { $$ = '+'; } |
        '-' { $$ = '-'; } ;

expression3:
        expression4
        |
	expression3 e3op expression4
	{
	  expression_t *news = mkop(2, $2);
	  news->parms.op.p[0] = $1;
	  news->parms.op.p[1] = $3;
	  $$ = news;
	}
        ;

e3op:   '*' { $$ = '*'; } |
        '/' { $$ = '/'; } |
        '^' { $$ = '^'; } ;

expression4:
        expression5
        |
	e4op expression5
        {
	  expression_t *news = mkop(1, $1);
	  news->parms.op.p[0] = $2;
	  $$ = news;
        }
        ;

e4op:   '-' { $$ = '-'; } |
        NOT { $$ = NOT; }
        ;

expression5:
        expression6
        |
	e5op1 '(' expression ')'
        {
	  expression_t *news = mkop(1, $1);
	  news->parms.op.p[0] = $3;
	  $$ = news;
        }
        |
	e5op2 '(' expression ',' expression ')'
        {
	  expression_t *news = mkop(2, $1);
	  news->parms.op.p[0] = $3;
	  news->parms.op.p[1] = $5;
	  $$ = news;
        }
        |
	e5op3 '(' expression ',' expression ',' expression ')'
        {
	  expression_t *news = mkop(3, $1);
	  news->parms.op.p[0] = $3;
	  news->parms.op.p[1] = $5;
	  $$ = news;
        }
        ;

e5op1:  _ABS { $$ = _ABS; } |
	VAL  { $$ = VAL; } |
	LOG  { $$ = LOG; } |
	EXP  { $$ = EXP; } |
	ATN  { $$ = ATN; } |
	COS  { $$ = COS; } |
	SIN  { $$ = SIN; } |
	SQR  { $$ = SQR; } |
	INT  { $$ = INT; } |
        SGN  { $$ = SGN; }
        ;
	
e5op2:  LEFT { $$ = LEFT; } |
        RIGHT { $$ = RIGHT; }
	;

e5op3:  MID { $$ = MID; }
	;

expression6:       
	NUMBER
	{
	  expression_t *news = mkexpression(number);
	  news->parms.number = $1;
	  $$ = news;
	}
	|
	STRING
	{
	  expression_t *news = mkexpression(string);
	  news->parms.string = $1;
	  $$ = news;
	}
        |
        variable
        {
	  expression_t *news = mkexpression(variable);
	  news->parms.variable = $1;
	  $$ = news;
        }
        |
        '(' expression ')'
        {
	  $$ = $2;
        }
	;

variable:
	IDENTIFIER
        {
	  variable_t *news = (variable_t *)malloc(sizeof(*news));
	  news->name = $1;
	  news->sub = NULL;
	  $$ = news;
        }
        |
	IDENTIFIER '(' exprlist ')'
        {
	  variable_t *news = (variable_t *)malloc(sizeof(*news));
	  news->name = $1;
	  news->sub = $3;
	  $$ = news;
        }

exprlist:
        expression
        {
	  $$ = g_list_prepend(NULL, $1);
        }
        |
        exprlist ',' expression
        {
	  $$ = g_list_append($1, $3);
        }
        ;

varlist:
        variable
        {
	  $$ = g_list_prepend(NULL, $1);
        }
        |
        varlist ',' variable
        {
	  $$ = g_list_append($1, $3);
        }
        ;

%%
