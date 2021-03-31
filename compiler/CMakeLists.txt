include_directories(ast)
include_directories(parser)
#add_subdirectory(parser)
add_executable(compiler parser/main.cpp parser/parseerror.cpp parser/parser.cpp
  parser/readfile.cpp parser/scanner.cpp parser/scannerexception.cpp
  parser/token.cpp

  ast/astnode.cpp ast/expressionast.cpp ast/ast.cpp
  )
set_property(TARGET compiler PROPERTY CXX_STANDARD 17)
