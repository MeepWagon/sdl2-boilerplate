PROJECT_NAME = Hello_SDL

INCLUDE = ./include
LIBRARY = ./lib

LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2

build:
	mkdir build
	x86_64-w64-mingw32-gcc src/*.c -I$(INCLUDE) -L$(LIBRARY) -w $(LINKER_FLAGS) -o $(PROJECT_NAME)
	mv $(PROJECT_NAME).exe ./build
	cp -r ./bin/* ./build

clean:
	rm -rf ./build