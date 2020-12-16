%.o:	%.cpp %.hpp
	clang.exe -c $< -o $@

%.o:	%.cpp
	clang.exe -c $< -o $@

max.exe:	driver.o input.o set.o ssort.o
	clang.exe $^ -o $@

all:
	max
