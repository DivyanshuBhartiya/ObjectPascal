#!/bin/bash
flex lexicalAnalyzer.l
yacc -vd syntacticAnalyzer.y
cc y.tab.c lex.yy.c Type.c Scope.c Codegen.c IR.c SymbolTable.c -o op
