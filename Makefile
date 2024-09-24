CC=g++
FLAGS= -Iinclude/sort_text -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wmissing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -D_DEBUG -D_EJUDGE_CLIENT_SIDE -D_EJC
FILES=onegin2_main.o find_text.o find_clean_file.o conventor_of_symbol.o create_array_of_struct.o print_onegin.o print_original_onegin.o read_onegin.o onegin_list_func_sort.o onegin_qsort.o 

TARGET=onegin
# pathsub
# addprefix
# wildcard 

PATCHED_FILES = $(addprefix build/, $(FILES))

all: prepare $(TARGET)

prepare:
	mkdir -p build

$(TARGET): $(FILES)
	@echo "Linling..."
	@$(CC) $(FLAGS) $(PATCHED_FILES) -o $(TARGET)

onegin2_main.o: src/main_onegin/onegin2_main.cpp
	@$(CC) -c $(FLAGS) src/main_onegin/onegin2_main.cpp -o build/onegin2_main.o

find_text.o: src/find_name_files/find_text.cpp
	@$(CC) -c $(FLAGS) src/find_name_files/find_text.cpp -o build/find_text.o

find_clean_file.o: src/find_name_files/find_clean_file.cpp
	@$(CC) -c $(FLAGS) src/find_name_files/find_clean_file.cpp -o build/find_clean_file.o

read_onegin.o: src/read_text/read_onegin.cpp
	@$(CC) -c $(FLAGS) src/read_text/read_onegin.cpp -o build/read_onegin.o

print_onegin.o: src/print_text/print_onegin.cpp
	@$(CC) -c $(FLAGS) src/print_text/print_onegin.cpp -o build/print_onegin.o

print_original_onegin.o: src/print_text/print_original_onegin.cpp
	@$(CC) -c $(FLAGS) src/print_text/print_original_onegin.cpp -o build/print_original_onegin.o

create_array_of_struct.o: src/read_text/create_array_of_struct.cpp
	@$(CC) -c $(FLAGS) src/read_text/create_array_of_struct.cpp -o build/create_array_of_struct.o

onegin_list_func_sort.o: src/sort_text/onegin_list_func_sort.cpp
	@$(CC) -c $(FLAGS) src/sort_text/onegin_list_func_sort.cpp -o build/onegin_list_func_sort.o

conventor_of_symbol.o: src/sort_text/conventor_of_symbol.cpp
	@$(CC) -c $(FLAGS) src/sort_text/conventor_of_symbol.cpp -o build/conventor_of_symbol.o

onegin_qsort.o: src/sort_text/onegin_qsort.cpp
	@$(CC) -c $(FLAGS) src/sort_text/onegin_qsort.cpp -o build/onegin_qsort.o

clean:
	rm -rf $(TARGET)
	cd build && rm -rf *.o
