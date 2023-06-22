#include <stdio.h>

#define STATE_A ('A')
#define STATE_B ('B')
#define STATE_C ('C')
#define STATE_D ('D')
#define STATE_E ('E')
#define STATE_J ('J') 

char state_transitions (int number, char cur_state)
{
    char state;
    state = cur_state;
    
    if (state == STATE_A)
    {
        if(number == 0)
        {
            state = STATE_C;
        }
        else
        {
           state = STATE_A;
        }
        
    }
    else if (state == STATE_C)
    {
        switch(number)
        {
            case 3:
                state = STATE_B;
                break;
            case 4:
                state = STATE_D;
                break;
            default:
                state = STATE_C;
        }
    }
    else if (state == STATE_B)
    {
        state = STATE_B;
    }
    else if (state == STATE_D)
    {
        switch (number)
        {
         case 5:
             state = STATE_E;
             break;
         case 8:
             state = STATE_J;
             break;
         default:
             state =STATE_D;
        }
    }
    else if (state == STATE_E)
    {
        switch (number)
        {
            case 6:
                state = STATE_B;
                break;
            case 4:
                state = STATE_C;
                break;
            case 10:
                state = STATE_A;
                break;
            case 8:
                state = STATE_J;
            default:
                state = STATE_E;
        }
    }
    else if ( state == STATE_J)
    {
        state = STATE_J;
    }
    return state;
}

int state_transition_main ()
{

    char state;
    state = STATE_A;
    int number;
    
    while (1)
    {
        printf ("current state is : %c\n", state);
        printf ("Enter the input: \n");
        scanf("%d", &number);
        if(number == -1)
        {
            return 0;
        }
        printf ("\n");
        state = state_transitions (number, state);
    }
    
    
    return 0;
}

#ifndef RELOCATABLE_OBJ
int main ()
{
    state_transition_main ();
}
#endif //RELOCATABLE_OBJ
