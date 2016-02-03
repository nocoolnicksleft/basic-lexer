%x incl
%x define
%x definition
%x title

%{
/* lexical analyser for gnbasic
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

#include "t1.h"
 
 char buf[MAX_STRING_LENGTH]; 
 char *s; 

 int lineno = 1;
%}

%x STRSECT

%%
SGN			{ return SGN; }
LEFT\$			{ return LEFT; }
RIGHT\$			{ return RIGHT; }
MID\$			{ return MID; }
ABS			{ return _ABS; }
VAL			{ return VAL; }
EXP			{ return EXP; }
LOG			{ return LOG; }
ATN			{ return ATN; }
COS			{ return COS; }
SIN			{ return SIN; }
SQR			{ return SQR; }
INT			{ return INT; }
AND                     { return AND; }
DATA                    { return DATA; }
DIM                     { return DIM; }
END                     { return END; }
FOR                     { return FOR; }
GOSUB			{ return GOSUB; }
GOTO			{ return GOTO; }
IF                      { return IF; }
INPUT                   { return INPUT; }
NEXT			{ return NEXT; }
NOT			{ return NOT; }
OR			{ return OR; }
PRINT			{ return PRINT; }
READ			{ return READ; }
RETURN			{ return RETURN; }
STEP			{ return STEP; }
THEN			{ return THEN; }
TO			{ return TO; }
USING			{ return USING; }

RUN			{ return RUN; }
CLEAR			{ return CLEAR; }
LIST			{ return LIST; }
LOAD			{ return LOAD; }
SAVE			{ return SAVE; }

REM.*                   { }
\'.*                    { }
"\032"                  {
                          yyterminate();
			}
<<EOF>>		 	{
                          yyterminate();
			}
[\n]			{
                          lineno++;
 			  return '\n';
			}
[0-9]*[0-9.][0-9]*([Ee][-+]?[0-9]+)? {
                          yylval.d = atof(yytext);
                          return NUMBER;
                        }
[A-Za-z_][A-Za-z0-9_]*\$? {
                          yylval.s = g_string_new(yytext);
                          return IDENTIFIER;
                        }

\"          { 
                BEGIN STRSECT; 
                s = buf; 
            }

<STRSECT>\"  { 
                *s = 0; 
                yylval.s = g_string_new(buf);
                BEGIN 0; 
                return STRING;
            }

<STRSECT>.   { 
                *s++ = *yytext; 
            }
<STRSECT>\n  {
                printf("\nError: Unterminated string in line %d\n",lineno);
                exit(1);
            }
DEFSNG.*\n              { return '\n'; }
[ \t\r\l]		{  }
\<=                     { return CMP_LE; }
\>=                     { return CMP_GE; }
\<\>                    { return CMP_NE; }
[:,;()\^=+\-*/\<\>]     { return yytext[0]; }
%%
