LD=g++
CXX=g++ -Wall -std=c++11 -g -c

EXEC_SRC=\
	testGrayLevelImage2D.cpp\
	bruit-impulsionnel.cpp\
	double-brightness.cpp\
	filtrage-median.cpp\
	histogramme.cpp\
	egalise.cpp\
	bruit-gaussien.cpp

MODULE_SRC=\
	GrayLevelImage2D.cpp\
	histogramme.cpp

MODULE_OBJ=${MODULE_SRC:.cpp=.o}
EXEC_OBJ=${EXEC_SRC:.cpp=.o}

EXEC_PRG=${EXEC_SRC:.cpp=}

all: ${EXEC_PRG} ${MODULE_OBJ} ${EXEC_OBJ}

testGrayLevelImage2D: testGrayLevelImage2D.o ${MODULE_OBJ}
	${LD} ${MODULE_OBJ} $< -o $@

bruit-impulsionnel: bruit-impulsionnel.o ${MODULE_OBJ}
	${LD} ${MODULE_OBJ} $< -o $@

double-brightness: double-brightness.o ${MODULE_OBJ}
	${LD} ${MODULE_OBJ} $< -o $@

filtrage-median: filtrage-median.o ${MODULE_OBJ}
	${LD} ${MODULE_OBJ} $< -o $@

egalise: egalise.o ${MODULE_OBJ}
	${LD} ${MODULE_OBJ} $< -o $@

bruit-gaussien: bruit-gaussien.o ${MODULE_OBJ}
	${LD} ${MODULE_OBJ} $< -o $@

.cpp.o: %.cpp %.hpp
	${CXX} $<

clean:
	rm -f ${EXEC_PRG} ${MODULE_OBJ} ${EXEC_OBJ}
	