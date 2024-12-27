# cpp3o

# Grammar for cpp3o

ProgramFile -> (<Globals>)*

Globals -> <ClassDecl>
Globals -> <MethodDecl>
Globals -> <VarDecl>
Globals -> <VarDef>

ClassDecl -> class <ClassName> <Block>
MethodDecl -> <Type> <MethodName> ( <Formals>? ) <Block>
VarDecl -> <Type> <Identifier> (, <Identifier>)* ;

Block -> { (<Stmt> | <VarDecl> | <MethodDecl> | <ClassDecl>)* }

VarDef -> <Type> <Var> = <Expr> ;
VarDef -> <Var> = <Expr> ;

Stmt -> <VarDef>
Stmt -> <UnaryOpStmt>
Stmt -> return <Expr> ;
Stmt -> if (<Expr>) <Block> (else <Block>)?
Stmt -> while (<Expr>) <Block>
Stmt -> break ;
Stmt -> <Var> ;
Stmt -> ;

Expr -> null
Expr -> new <ClassName> ( <Actuals>? )
Expr -> <Var> -> <MethodName> ( <Actuals>? )
Expr -> <Var> -> <Var>
Expr -> <Expr> ? <Expr> : <Expr>
Expr -> <Expr> <BinOp> <Expr>
Expr -> <UnOp> <Expr>
Expr -> <Literal>
Expr -> <Var>

Actuals -> <Expr> (, <Expr>)*
Formals -> <Type> <Identifier> (, <Type> <Identifier>)*

BinOp -> [=, +, -, *, /, %, <, >, <=, >=, ==, !=]

UnaryOpStmt -> <UnaryOp> <Var> ; 
UnOp -> [++, --, -, !]

Type -> void | <ClassName> | int | bool | string | null

Literal -> <Num> | <Bool> | <String>

NamespaceDecl -> namespace <Identifier> <Block>
UsingNamespace -> using namespace <Identifier> ;

ClassName -> <Identifier>
MethodName -> <Identifier>
FunctionName -> <Identifier>
Var -> <Identifier>
Num -> (0-9)+ 
String -> "[^"]*"
Identifier -> [a-zA-Z][a-zA-Z0-9_]*





notes:
- only 1 allowed global main function in all files
- there must be a global main function outside any encapsulation no exceptions


heavy:
nested classes
nested functions


light:
manual memory


future

namespace {}
using namespace <Identifier>
<Identifer> :: <Identifier>


