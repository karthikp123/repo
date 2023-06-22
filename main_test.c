#include "utilities.h"
#include "struct_node_pool_test.h"

extern int state_transition_main ();
extern int fn_stack_frame_main ();
extern int bit_operation_main ();
extern int bit_operations_2_main ();
extern int var_length_test_main ();
extern int word_count_main ();


int main()
{
	int ch;
	printf("1.state_transition\n2.Function stack frame:\n3.Bit operations:\n4.Node pool test\n5.Utilities function\n6.word count\n7.varibale length test\n");
	printf("Enter choice:\n");
	scanf("%d", &ch);
	
	switch(ch)
	{
		case 1:
			state_transition_main ();
			break;
			
		case 2:
			fn_stack_frame_main ();
			break;
			
		case 3:
			bit_operation_main ();
			bit_operations_2_main ();
			break;
			
		case 4:
			struct_node_pool_test_main ();
			break;
			
		case 5:
			utilities_main ();
			break;
		case 6:
			word_count_main ();
			break;
		case 7:
			var_length_test_main ();
			break;
			
		default:
			printf("Invalid choice!!\n");
			break;
			
	}
	
	
	return 0;
	
}
