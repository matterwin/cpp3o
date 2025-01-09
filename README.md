# cpp3o

# Grammar for cpp3o (std namespace and functional cpp focus)

Program -> (<File>)*

File -> (<Decl>)*

Decl -> <FunctionDecl>
Decl -> <VarDecl>

FunctionDecl -> <Type> <FunctionName> ( <Formals>? ) <Block>

VarDecl -> <Type> <Identifier> (, <Identifier>)* ;
VarDecl -> <Type> * <Identifier> (, <Identifier>)* ;
VarDecl -> <Type> & <Identifier> (, <Identifier>)* ;

VarDef -> <Type> <Var> = <Expr> ;
VarDef -> * <Var> = <Expr> ;
VarDef -> & <Var> = <Expr> ;
VarDef -> <Var> = <Expr> ;

Block -> { (<Stmt> | <Decl>)* }

Stmt -> <VarDef>
Stmt -> <UnaryOpStmt> ;
Stmt -> return <Expr> ;
Stmt -> if (<Expr>) <Block> (else <Block>)?
Stmt -> while (<Expr>) <Block>
Stmt -> break ;
Stmt -> ;
Stmt -> delete <Var> ;
Stmt -> <Var> = <Expr> ;

Expr -> null
Expr -> new <Type> ( <Actuals>? )
Expr -> <FunctionName> ( <Actuals>? )
Expr -> <Expr> <BinOp> <Expr>
Expr -> <UnOp> <Expr>
Expr -> <Literal>
Expr -> <Var>
Expr -> & <Var> // mem address pointer
Expr -> * <Var> // deref pointer
Expr -> ( <Expr> )
Expr -> std:: <Identifer>

Actuals -> <Expr> (, <Expr>)*
Formals -> <Type> <Identifier> (, <Type> <Identifier>)*

BinOp -> [=, +, -, *, /, %, <, >, <=, >=, ==, !=, &, &&, |, ||, ^, ~]

UnaryOpStmt -> <UnaryOp> <Var> ; 
UnOp -> [++, --, -, !, &]

Type -> void | int | bool | string | null | <Type>* | <Type>& 

Literal -> <NumLiteral> | <BoolLiteral> | <StringLiteral> | <CharLiteral> | <NullLiteral>

NumLiteral -> [+-]?([0-9]+) 
BoolLiteral -> 0 | (1-9)+
StringLiteral -> "[^"]*"
CharLiteral -> '[^']*'
NullLiteral -> null

FunctionName -> <Identifier>
Var -> <Identifier>
Identifier -> [a-zA-Z][a-zA-Z0-9_]*



future

OO

namespace {}
using namespace <Identifier>
<Identifer> :: <Identifier>




gotta do preprocessor before parser
- just traverse the #include <vector>, etc and put the header file of that in file.cpp or tmpfile.cpp

gotta correct pointers for decls
