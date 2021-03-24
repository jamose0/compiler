find_package(Catch2 REQUIRED)
set(OBJ_DIR ${CMAKE_SOURCE_DIR}/build/src/CMakeFiles/compiler.dir)
set(OBJS ${OBJ_DIR}/scanner.cpp.o ${OBJ_DIR}/token.cpp.o ${OBJ_DIR}/scannerexception.cpp.o)

add_executable(testScanner ${OBJS} testScanner.cpp testcommon.cpp)
set_source_files_properties(
  ${OBJS}
  PROPERTIES EXTERNAL_OBJECT true GENERATED true
  )

#add_executable(testScanner testScanner.cpp testcommon.cpp ../scanner.cpp ../token.cpp ../scannerexception.cpp)
set_property(TARGET testScanner PROPERTY CXX_STANDARD 17)
target_link_libraries(testScanner PRIVATE Catch2::Catch2)
add_test(testScanner testScanner)
