APP_NAME = quantum

all:src/*.cpp
	gcc -o dist/$(APP_NAME) -lstdc++ $^

