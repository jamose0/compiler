find_package(Catch2 REQUIRED)
set(OBJ_DIR ${CMAKE_SOURCE_DIR}/build/src/CMakeFiles/compiler.dir)
set(OBJS ${OBJ_DIR}/scanner.cpp.o ${OBJ_DIR}/token.cpp.o ${OBJ_DIR}/scannerexception.cpp.o)

add_executable(testHelloWorld ${OBJS} testHelloWorld.cpp testcommon.cpp)
add_executable(testOperator ${OBJS} testOperator.cpp testcommon.cpp)
set_source_files_properties(
  ${OBJS}
  PROPERTIES EXTERNAL_OBJECT true GENERATED true
  )

#add_executable(testScanner testScanner.cpp testcommon.cpp ../scanner.cpp ../token.cpp ../scannerexception.cpp)
set_property(TARGET testHelloWorld testOperator PROPERTY CXX_STANDARD 17)
target_link_libraries(testHelloWorld PRIVATE Catch2::Catch2)
target_link_libraries(testOperator PRIVATE Catch2::Catch2)
add_test(one testHelloWorld)
add_test(testOperator testOperator)
