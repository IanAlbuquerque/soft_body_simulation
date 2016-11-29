all: tests
	g++ -o main ../src/main.cpp ../src/linalg.cpp -I../include -lm

tests:
	g++ -o TEST_Vector ../src/VectorTests.cpp ../src/Vector.cpp -I../include -lm
	g++ -o TEST_Matrix ../src/MatrixTests.cpp ../src/Matrix.cpp ../src/Vector.cpp -I../include -lm