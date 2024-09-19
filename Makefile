CC=g++
FLAGS=-c -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wmissing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -D_DEBUG -D_EJUDGE_CLIENT_SIDE -D_EJC
FILES=onegin2_main.o find_text.o find_clean_file.o conventor_of_symbol.o create_array_of_struct.o print_onegin.o read_onegin.o onegin_list_func_sort.o onegin_qsort.o 

# pathsub
# addprefix
# wildcard 

all: onegin2

onegin2: $(FILES)
	$(CC) $(FILES) -o onegin2.elf

onegin2_main.o: onegin2_main.cpp
	$(CC) $(FLAGS) onegin2_main.cpp

find_text.o: find_text.cpp
	$(CC) $(FLAGS) find_text.cpp

find_clean_file.o: find_clean_file.cpp
	$(CC) $(FLAGS) find_clean_file.cpp

read_onegin.o: read_onegin.cpp
	$(CC) $(FLAGS) read_onegin.cpp

print_onegin.o: print_onegin.cpp
	$(CC) $(FLAGS) print_onegin.cpp

create_array_of_struct.o: create_array_of_struct.cpp
	$(CC) $(FLAGS) create_array_of_struct.cpp

onegin_list_func_sort.o: onegin_list_func_sort.cpp
	$(CC) $(FLAGS) onegin_list_func_sort.cpp

conventor_of_symbol.o: conventor_of_symbol.cpp
	$(CC) $(FLAGS) conventor_of_symbol.cpp

onegin_qsort.o: onegin_qsort.cpp
	$(CC) $(FLAGS) onegin_qsort.cpp

clean:
	rm -rf *.o onegin2.elf