SHELL:=/bin/bash
CC=g++
CFLAGS=-c -Wall -Werror -Wextra -std=c++17 
CFLAGS_BIN=$(subst -c ,,$(CFLAGS))
TESTFLAGS=-lgtest -lsubunit 
LDFLAGS=

SOURCES=$(wildcard s21_*.cpp)
TEST_SOURCES=$(wildcard tests/s21_*.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
LIBNAME=s21_matrix_oop.a
S21_DEBUG?=false
ifeq ($(S21_DEBUG),true)   
	DEBUG_FLAGS=-fsanitize=leak -fsanitize=address -fsanitize=undefined -fsanitize=unreachable -fno-sanitize-recover -fstack-protector
else
	DEBUG_FLAGS=
endif

.PHONY: all
all: $(LIBNAME)

.PHONY: $(LIBNAME)
$(LIBNAME): build clean

.PHONY: build
build: $(OBJECTS)
	ar rcs $(LIBNAME) $(OBJECTS)

.PHONY: test
test: build clean
	$(CC) $(CFLAGS_BIN) $(DEBUG_FLAGS) $(TEST_SOURCES) $(LIBNAME) -o tests/tests $(TESTFLAGS)

ifeq ($(S21_DEBUG),true)   
	./tests/tests
else
	valgrind -q -s --leak-check=full --trace-children=yes --show-leak-kinds=all --track-origins=yes  --log-file=RESULT_VALGRIND.txt ./tests/tests
endif

.PHONY: gcov_report
gcov_report: test
	$(CC) --coverage $(CFLAGS_BIN) $(DEBUG_FLAGS) $(SOURCES) $(TEST_SOURCES) -o tests/s21_test  $(TESTFLAGS) -lgcov
	./tests/s21_test
#	lcov --no-external -t "s21_test" -o tests/s21_test.info -c -d .
	lcov --ignore-errors mismatch --no-external -t "s21_test" -o tests/s21_test.info -c -d .
	genhtml -o report tests/s21_test.info

.PHONY: clean
clean:
	rm -f {.,tests}/*.o {.,tests}/*.gcda {.,tests}/*.gcno
	rm -rf report
	rm -f tests/{s21_test.info,s21_test,tests}
	rm -f RESULT_VALGRIND.txt

.PHONY: cleanall
cleanall:
	rm -f {.,tests}/*.o {.,tests}/*.gcda {.,tests}/*.gcno *.a
	rm -rf report
	rm -f tests/{s21_test.info,s21_test,tests}
	rm -f RESULT_VALGRIND.txt

.PHONY: check
check:
	cppcheck --enable=all --suppress=missingIncludeSystem ./
	find . -regex '.*\.\(cpp\|hpp\|c\|h\)' -exec clang-format -style='{BasedOnStyle: Google}' -n {} \;

.PHONY: check_fix
check_fix:
	cppcheck --enable=all --suppress=missingIncludeSystem ./
	find . -regex '.*\.\(cpp\|hpp\|c\|h\)' -exec clang-format -style='{BasedOnStyle: Google}' -i {} \;


%.o: %.c
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) $< -o $@