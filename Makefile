CC=g++
FLAGS=-c -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wmissing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -D_DEBUG -D_EJUDGE_CLIENT_SIDE -D_EJC
FILES=onegin2_main.o find_text.o find_clean_file.o conventor_of_symbol.o create_array_of_struct.o print_onegin.o print_original_onegin.o read_onegin.o onegin_list_func_sort.o onegin_qsort.o 

# pathsub
# addprefix
# wildcard 

all: onegin2

onegin2: $(FILES)
	$(CC) $(FILES) -o onegin2.elf 

onegin2_main.o: src/main_onegin/onegin2_main.cpp
	$(CC) $(FLAGS) src/main_onegin/onegin2_main.cpp

find_text.o: src/find_name_files/find_text.cpp
	$(CC) $(FLAGS) src/find_name_files/find_text.cpp

find_clean_file.o: src/find_name_files/find_clean_file.cpp
	$(CC) $(FLAGS) src/find_name_files/find_clean_file.cpp

read_onegin.o: src/read_text/read_onegin.cpp
	$(CC) $(FLAGS) src/read_text/read_onegin.cpp

print_onegin.o: src/print_text/print_onegin.cpp
	$(CC) $(FLAGS) src/print_text/print_onegin.cpp

print_original_onegin.o: src/print_text/print_original_onegin.cpp
	$(CC) $(FLAGS) src/print_text/print_original_onegin.cpp

create_array_of_struct.o: src/read_text/create_array_of_struct.cpp
	$(CC) $(FLAGS) src/read_text/create_array_of_struct.cpp

onegin_list_func_sort.o: src/sort_text/onegin_list_func_sort.cpp
	$(CC) $(FLAGS) src/sort_text/onegin_list_func_sort.cpp

conventor_of_symbol.o: src/sort_text/conventor_of_symbol.cpp
	$(CC) $(FLAGS) src/sort_text/conventor_of_symbol.cpp

onegin_qsort.o: src/sort_text/onegin_qsort.cpp
	$(CC) $(FLAGS) src/sort_text/onegin_qsort.cpp

clean:
	rm -rf *.o onegin2.elf
