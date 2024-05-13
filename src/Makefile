CC = gcc

FLAGS = -Wall -Wextra -Werror -std=c11
LIB = s21_decimal.a

LIB_DIR = ./functions/*.c
LIB_DIR_TEST = ./test/*.c

TESTFILE = s21_test

GCOVR = -fprofile-arcs -ftest-coverage
LIBS_FOR_CHECK_PCKG = -lcheck -lsubunit -lm -lpthread 
D_OS = -D My_Linux
OS = $(shell uname -s)
ifeq ($(OS), Linux)
	LIBS_FOR_CHECK_PCKG = -lcheck -lsubunit -lm -lpthread -lrt
	D_OS = -D My_Linux
else
	LIBS_FOR_CHECK_PCKG = -lcheck -lm -lpthread
	D_OS = -D My_APPLE
endif

all: gcov_report

s21_decimal.a:
	$(CC) $(FLAGS) $(D_OS) -c  $(LIB_DIR)
	ar -rcs $(LIB) *.o
	rm -rf *.o

test: s21_decimal.a
	$(CC)  ./main.c $(LIB_DIR_TEST) -L. $(LIB) $(LIBS_FOR_CHECK_PCKG) $(GCOVR) -o test-functions

gcov_report: test
	./test-functions

	lcov -t "test-functions" -o test-functions.info -c -d .
	rm -rf
	genhtml -o report test-functions.info
	rm -rf *.gcda *.gcno

clang:
	cp ../materials/linters/.clang-format .
	clang-format -n *.c *.h 

	cp ../materials/linters/.clang-format ./functions
	clang-format -n ./functions/*.c

	cp ../materials/linters/.clang-format ./test
	clang-format -n ./test/*.c
	
format:
	clang-format -i *.c *.h ./functions/*.c ./test/*.c

clean:
	rm -f *.a *.o *.so *.out $(TESTFILE) *.info *.gcno *.gcda
	rm -f *$(TEST_LIB)*.a *$(TEST_LIB)*.o
	rm -rf report
	rm -rf .clang-format
	rm -rf function/.clang-format
	rm -rf ./test-functions
	rm -rf ./test/.clang-format
	rm -rf ./functions/.clang-format