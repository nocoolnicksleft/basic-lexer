/* 
 * File:   main.c
 * Author: bseip
 *
 * Created on May 13, 2014, 3:09 PM
 */

#include "t1.h" 

// YYSTYPE yylval;
interpstate_t is;

/*
 *  
 */
int main(int argc, char** argv) {
    int current;
    yydebug = 0;
    yyparse();
    
    while (current = yylex()) {

        // printf("[TERM %d]", current);

        switch (current) {

            case INTLIT:
                printf("[INTLIT %d]", yylval.i);
                break;

            case STRLIT:
            case STRING:
                printf("[STRLIT '%s' (%d)]", yylval.s->str, strlen(yylval.s->str));
                break;
            case FLOATLIT:
                printf("[FLOATLIT %f]", yylval.d);
                break;
            case IDENTIFIER:
                printf("[IDENTIFIER %s]", yylval.s->str);
                break;
            case SGN: printf("[SGN]");
                break;
            case LEFT: printf("[LEFT]");
                break;
            case RIGHT: printf("[RIGHT]");
                break;
            case MID: printf("[MID]");
                break;
            case _ABS: printf("[_ABS]");
                break;
            case VAL: printf("[VAL]");
                break;
            case LOG: printf("[LOG]");
                break;
            case EXP: printf("[EXP]");
                break;
            case AND: printf("[AND]");
                break;
            case ATN: printf("[ATN]");
                break;
            case COS: printf("[COS]");
                break;
            case DATA: printf("[DATA]");
                break;
            case DIM: printf("[DIM]");
                break;
            case END: printf("[END]");
                break;
            case FOR: printf("[FOR]");
                break;
            case GOSUB: printf("[GOSUB]");
                break;
            case GOTO: printf("[GOTO]");
                break;
            case IF: printf("[IF]");
                break;
            case INPUT: printf("[INPUT]");
                break;
            case INT: printf("[INT]");
                break;
            case LET: printf("[LET]");
                break;
            case NEXT: printf("[NEXT]");
                break;
            case NOT: printf("[NOT]");
                break;
            case OR: printf("[OR]");
                break;
            case PRINT: printf("[PRINT]");
                break;
            case READ: printf("[READ]");
                break;
            case RETURN: printf("[RETURN]");
                break;
            case SIN: printf("[SIN]");
                break;
            case SQR: printf("[SQR]");
                break;
            case STEP: printf("[STEP]");
                break;
            case THEN: printf("[THEN]");
                break;
            case TO: printf("[TO]");
                break;
            case USING: printf("[USING]");
                break;
            case CMP_LE: printf("[CMP_LE]");
                break;
            case CMP_GE: printf("[CMP_GE]");
                break;
            case CMP_NE: printf("[CMP_NE]");
                break;
            case RUN: printf("[RUN]");
                break;
            case NL: printf("[NL]\n");
                break;

            default:
                printf("[%c]", current);
                break;
        }

    };
    return (EXIT_SUCCESS);
}

