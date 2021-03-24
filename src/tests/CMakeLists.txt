add_executable(testScanner testScanner.cpp ../scanner.cpp ../token.cpp ../scannerexception.cpp)
set_property(TARGET testScanner PROPERTY CXX_STANDARD 17)
add_test(testScanner testScanner)
