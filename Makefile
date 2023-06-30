C_COMPILER = gcc
CPP_COMPILER = g++
CMPLN_FLAG = -g -Wall -fPIC -I. -c

all: create_rel_obj static_lib shared_lib regular_elf_exec elf_exec_using_static_lib elf_exec_shared_lib

create_rel_obj:
	$(CPP_COMPILER) $(CMPLN_FLAG) -DRELOCATABLE_OBJ bit_operations_2.c -o bit_operations_2.o
	$(CPP_COMPILER) $(CMPLN_FLAG) -DRELOCATABLE_OBJ bit_oprations.c -o bit_oprations.o
	$(CPP_COMPILER) $(CMPLN_FLAG) -DRELOCATABLE_OBJ fn_stack_frame_test.c -o fn_stack_frame_test.o
	$(CPP_COMPILER) $(CMPLN_FLAG) -DRELOCATABLE_OBJ  state_transistion.c -o state_transition_file.o
	$(CPP_COMPILER) $(CMPLN_FLAG) -DRELOCATABLE_OBJ struct_node_pool_test.c -o struct_node_pool_test_file.o
	$(CPP_COMPILER) $(CMPLN_FLAG) -DRELOCATABLE_OBJ utility_code_test.c -o utility_code_test_file.o
	$(CPP_COMPILER) $(CMPLN_FLAG) -DRELOCATABLE_OBJ word_count.c -o word_count_file.o
	$(CPP_COMPILER) $(CMPLN_FLAG) -DRELOCATABLE_OBJ var_length_test.c -o var_length_test_file.o
	$(CPP_COMPILER) $(CMPLN_FLAG) -DRELOCATABLE_OBJ binary_search_test.c -o binary_search_test.o
	$(CPP_COMPILER) $(CMPLN_FLAG) -DRELOCATABLE_OBJ oop_concept_test.cpp -o oop_concept_test.o
	$(CPP_COMPILER) $(CMPLN_FLAG) -DRELOCATABLE_OBJ mangling_test.cpp -o mangling_test.o
	$(CPP_COMPILER) $(CMPLN_FLAG)  main_test.c -o main_test.o

regular_elf_exec: struct_node_pool_test.h utilities.h
	g++ -g bit_operations_2.o bit_oprations.o fn_stack_frame_test.o state_transition_file.o struct_node_pool_test_file.o utility_code_test_file.o word_count_file.o var_length_test_file.o binary_search_test.o oop_concept_test.o mangling_test.o  main_test.o -o finalmain

static_lib: create_rel_obj
	ar -rc libMyTestStaticLib.a bit_operations_2.o bit_oprations.o fn_stack_frame_test.o state_transition_file.o struct_node_pool_test_file.o utility_code_test_file.o word_count_file.o var_length_test_file.o binary_search_test.o oop_concept_test.o mangling_test.o

shared_lib: create_rel_obj
	g++ -shared -o libMyTestSharedLib.so bit_operations_2.o bit_oprations.o fn_stack_frame_test.o state_transition_file.o struct_node_pool_test_file.o utility_code_test_file.o word_count_file.o var_length_test_file.o binary_search_test.o oop_concept_test.o mangling_test.o
	

elf_exec_using_static_lib: static_lib
	$(CPP_COMPILER) main_test.o -L. -lMyTestStaticLib -o mainteststaticlib
	#g++ main_test.o MyTestStaticLib.a -o mainteststaticlib
	

elf_exec_shared_lib: shared_lib
	$(CPP_COMPILER) main_test.o -L. -lMyTestSharedLib -o maintestsharedlib
	#g++ main_test.o MyTestSharedLib.a -o mainteststaticlib


clean:
	rm *.o *.a *.so


