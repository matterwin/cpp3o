# cpp3o

# Grammar for cpp3o (std namespace and functional cpp focus)

Program -> (<File>)*

File -> (<Decl>)*

Decl -> <FunctionDecl>
Decl -> <VarDecl>

FunctionDecl -> <Type> <FunctionName> ( <Parameters>? ) <Block>

VarDecl -> <Type> <Identifier> (, <Identifier>)* ;
VarDef -> <Type> <Identifier> (= <Expr>)? (, <Identifier> (= <Expr>)?)* ;

Block -> { (<Stmt> | <Decl>)* }

Stmt -> <Decl>
Stmt -> return (<Expr>)? ;
Stmt -> if ( <Expr> ) <Block> (else <Block>)?
Stmt -> while ( <Expr> ) <Block>
Stmt -> for ( <ForInit>? ; <Expr>? ; <ForUpdate>? ) <Block>
Stmt -> break ;
Stmt -> ;

ForInit -> <VarDef> | <Identifier> = <Expr>
ForUpdate -> <Expr>

Expr -> null
Expr -> <FunctionName> ( <Arguments>? )
Expr -> <BinOpExpr>
Expr -> <UnOpExpr>
Expr -> <Literal>
Expr -> <Var>
Expr -> ( <Expr> )
Expr -> std :: <Identifier>

BinOpExpr -> <Expr> <BinOp> <Expr>

UnOpExpr -> <UnOp> <Expr>
           | <Expr> <UnOp>

Arguments -> <Expr> (, <Expr>)*

Parameters -> <Type> <Identifier> (, <Type> <Identifier>)*

BinOp -> [=, +, -, *, /, %, <, >, <=, >=, ==, !=, &, &&, |, ||, ^, ~]

UnOp -> [++, --, -, !]

Type -> void | int | bool | string | null

Literal -> <NumLiteral> | <BoolLiteral> | <StringLiteral> | <CharLiteral> | <NullLiteral>

NumLiteral -> 0 | ([+-])? ([1-9])+
BoolLiteral -> 0 | ([-])? ([1-9])+
StringLiteral -> "[^"]*"
CharLiteral -> '[^']*'
NullLiteral -> null

FunctionName -> <Identifier>
Var -> <Identifier>
Identifier -> [a-zA-Z_][a-zA-Z0-9_]*





future

OO
dynamic memory
pointers

namespace {}
using namespace <Identifier>
<Identifer> :: <Identifier>




gotta do preprocessor before parser
- just traverse the #include <vector>, etc and put the header file of that in file.cpp or tmpfile.cpp

gotta correct pointers for decls
