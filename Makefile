main_test: struct_node_pool_test.h utilities.h
	gcc -g -DRELOCATABLE_OBJ -I. -c bit_operations_2.c -o bit_operations_2.o
	gcc -g -DRELOCATABLE_OBJ -I. -c bit_oprations.c -o bit_oprations.o
	gcc -g -DRELOCATABLE_OBJ -I. -c fn_stack_frame_test.c -o fn_stack_frame_test.o
	gcc -g -DRELOCATABLE_OBJ -I. -c state_transistion.c -o state_transition_file.o
	gcc -g -DRELOCATABLE_OBJ -I. -c struct_node_pool_test.c -o struct_node_pool_test_file.o
	gcc -g -DRELOCATABLE_OBJ -I. -c utility_code_test.c -o utility_code_test_file.o
	gcc -g -DRELOCATABLE_OBJ -I. -c word_count.c -o word_count_file.o
	gcc -g -DRELOCATABLE_OBJ -I. -c var_length_test.c -o var_length_test_file.o
	gcc -g -DRELOCATABLE_OBJ -I. -c binary_search_test.c -o binary_search_test.o
	gcc -g bit_operations_2.o bit_oprations.o fn_stack_frame_test.o state_transition_file.o struct_node_pool_test_file.o utility_code_test_file.o word_count_file.o var_length_test_file.o binary_search_test.o  main_test.c -o finalmain

clean:
	rm bit_operations_2.o bit_oprations.o fn_stack_frame_test.o state_transition_file.o struct_node_pool_test_file.o utility_code_test_file.o word_count_file.o binary_search_test.o var_length_test_file.o finalmain
