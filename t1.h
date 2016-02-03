/* 
 * File:   t1.h
 * Author: bseip
 *
 * Created on May 13, 2014, 3:38 PM
 */

#ifndef T1_H
#define	T1_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <glib.h>



#ifdef	__cplusplus
extern "C" {
        
#endif

    
extern int yylex (void);
/*
typedef union {
  double d;
  int i;
  char * s;
  
  
  // GString *s;
  // GList *l;
  // statement_t *statement;
  // expression_t *expression;
  // variable_t *variable;
  
} YYSTYPE;
 */


#define MAX_STRING_LENGTH 255
#define MAX_IDENTIFIER_LENGTH 255
/*
#define	INTLIT	257
#define	STRLIT	258
#define	FLOATLIT	296

#define	IDENTIFIER	259

#define	SGN	260
#define	LEFT	261
#define	RIGHT	262
#define	MID	263
#define	_ABS	264
#define	VAL	265
#define	LOG	266
#define	EXP	267
#define	AND	268
#define	ATN	269
#define	COS	270
#define	DATA	271
#define	DIM	272
#define	END	273
#define	FOR	274
#define	GOSUB	275
#define	GOTO	276
#define	IF	277
#define	INPUT	278
#define	INT	279
#define	LET	280
#define	NEXT	281
#define	NOT	282
#define	OR	283
#define	PRINT	284
#define	READ	285
#define	RETURN	286
#define	SIN	287
#define	SQR	288
#define	STEP	289
#define	THEN	290
#define	TO	291
#define	USING	292
#define	CMP_LE	293
#define	CMP_GE	294
#define	CMP_NE	295

#define	NL	297

#define	RUN	298
#define	LIST	299
#define	CLEAR	300
#define	SAVE	301
#define	LOAD	302
*/


typedef struct {
  GString *name;
  GList *sub;			/* subscripts, list of expressions */
} variable_t;

typedef enum { variable, number, string, op } expression_type_t;
typedef struct expression_struct {
  expression_type_t type;
  union {
    variable_t *variable;
    double number;
    GString *string;
    struct {
      int arity;
      int o;
      struct expression_struct *p[2];
    } op;
  } parms;
} expression_t;

typedef struct {
  expression_t *e;
  int sep;			/* ';' ',' or 0 */
} printitem_t;

typedef struct statement_struct {
  int type;
  union {
    GList *data;
    GList *dim;
    struct {
      variable_t *v;
      expression_t *begin, *end, *step;
    } _for;
    expression_t *gosub;
    expression_t *_goto;
    struct {
      expression_t *cond;
      GList *thene;
      int thenl;
    } _if;
    GList *input;
    struct {
      variable_t *lvalue;
      expression_t *e;
    } let;
    variable_t *next;
    struct {
      expression_t *usingwhich;
      GList *l;
    } print;
    GList *read;
  } parms;
} statement_t;


typedef struct {
  GList *head;
  variable_t *v;
  double begin, end, step;
} forcontrol_t;

typedef struct {
  GList *returnpoint;
} gosubcontrol_t;

typedef struct {
  GList *line[10000];
  GList *ps;			/* currently executing statement */
  GList *psd;			/* current 'DATA' statement */
  GList *psde;			/* current 'DATA' expression within psd */
  GTree *symbols;
  GList *forstack;		/* of forcontrol_t */
  GList *gosubstack;		/* of gosubcontrol_t */
} interpstate_t;

extern interpstate_t is;



#include "parse.tab.h"

extern YYSTYPE yylval;
extern int yydebug;


#ifdef	__cplusplus
}
#endif

#endif	/* T1_H */

