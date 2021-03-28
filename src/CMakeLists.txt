set(SOURCES main.cpp scanner.cpp token.cpp readfile.cpp scannerexception.cpp
  parser.cpp)
add_executable(compiler ${SOURCES})
set_property(TARGET compiler PROPERTY CXX_STANDARD 17)
add_subdirectory(tests)
