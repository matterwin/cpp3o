# cpp3o

# Grammar for cpp3o (std and functional cpp focus)

Program -> (<File>)*

File -> (<Decl>)*

Decl -> <FunctionDecl>
Decl -> <VarDecl>

FunctionDecl -> <Type> <FunctionName> ( <Formals>? ) <Block>

VarDecl -> <Type> <Identifier> (, <Identifier>)* ;

Block -> { (<Stmt> | <Decl>)* }

VarDef -> <Type> <Var> = <Expr> ;
VarDef -> * <Var> = <Expr> ;
VarDef -> <Var> = <Expr> ;

Stmt -> <VarDef>
Stmt -> <UnaryOpStmt>
Stmt -> return <Expr> ;
Stmt -> if (<Expr>) <Block> (else <Block>)?
Stmt -> while (<Expr>) <Block>
Stmt -> break ;
Stmt -> ;
Stmt -> delete <Var> ;

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

Actuals -> <Expr> (, <Expr>)*
Formals -> <Type> <Identifier> (, <Type> <Identifier>)*

BinOp -> [=, +, -, *, /, %, <, >, <=, >=, ==, !=, &, &&, |, ||, ^, ~]

UnaryOpStmt -> <UnaryOp> <Var> ; 
UnOp -> [++, --, -, !, &]

Type -> void | int | bool | string | null | <Type>*

Literal -> <Num> | <Bool> | <String>

FunctionName -> <Identifier>
Var -> <Identifier>
Num -> (0-9)+ 
String -> "[^"]*"
Identifier -> [a-zA-Z][a-zA-Z0-9_]*




heavy:
nested classes
nested functions


light:
manual memory


future

OO

namespace {}
using namespace <Identifier>
<Identifer> :: <Identifier>


