#lSOURCES=$(wildcard *.cxx)
sSOURCES=$(wildcard *.cpp)
HEADERS=$(wildcard *.h)
#lOBJECTS=$(lSOURCES:%.cxx=%.o)
sOBJECTS=$(sSOURCES:%.cpp=%.o)
TARGET=match.exe
LIB=KMP.a

all: $(TARGET) $(LIB)
$(TARGET): $(sOBJECTS) $(HEADERS) $(LIB)
	@echo "Now Generating $(TARGET) ..."
	g++ $(sOBJECTS) $(LIB) -o $(TARGET) -fsanitize=address -g
$(LIB): $(lOBJECTS) $(HEADERS)
	@echo "Now Generating $(LIB) ..."
	ar -rv $(LIB) $(lOBJECTS)
	ranlib $(LIB)
%.o: %.cpp $(HEADERS)
	@echo "Now Compiling $< ..."
	g++ -I. -c $< -o $@ -fsanitize=address -g
#%.o: %.cxx $(HEADERS)
#	@echo "Now Compiling $< ..."
#	g++ -I. -c $< -o $@
clean:
	rm *.o *.exe 
explain:
	@echo "Headers: $(HEADERS)"
	@echo "Lib Sources: $(lSOURCES)"
	@echo "Lib Objects: $(lOBJECTS)"
	@echo "User Sources: $(sSOURCES)"
	@echo "User Objects: $(sOBJECTS)"
	@echo "Lib: $(LIB)"
	@echo "Target: $(TARGET)"
