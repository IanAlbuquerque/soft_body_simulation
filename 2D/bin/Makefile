all: tests
	g++ -o main ../src/main.cpp ../src/linalg.cpp -I../include -lm

tests:
	g++ -o TEST_Vector ../src/VectorTests.cpp ../src/Vector.cpp -I../include -lm
	g++ -o TEST_Matrix ../src/MatrixTests.cpp ../src/Matrix.cpp ../src/Vector.cpp -I../include -lm

windowsvis:
	g++ -o visualization ../src/2dvisualization.cpp ../src/Vector.cpp ../src/simulation.cpp -I../include -L../lib -lm -lglut32 -lopengl32 -lglu32

macvis:
	g++ -o visualization ../src/2dvisualization.cpp ../src/Vector.cpp ../src/simulation.cpp -I../include -L../lib -Wall -Wno-deprecated -lm -framework GLUT -framework OpenGL -framework Cocoa