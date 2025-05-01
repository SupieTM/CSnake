HEADERS = food.h inputHandler.h snake.h window.h
SOURCE = $(HEADERS:.h=.c) main.c
OBJ = $(SOURCE:.c=.o)
EXEC = snake.exe

$(EXEC) : $(OBJ)
	gcc $^ -o $@

clean:
	del /P *.o
	del /P *.exe
