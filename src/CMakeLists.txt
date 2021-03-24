add_executable(compiler main.cpp scanner.cpp token.cpp readfile.cpp
  scannerexception.cpp)
set_property(TARGET compiler PROPERTY CXX_STANDARD 17)
