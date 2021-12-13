#include <stdio.h>
#include <string.h>

int dfa = 0;

// func for q0 state of DFA
void start(char c)
{
    if (c== 'a') {
        dfa = 1;
    }
    else if (c == 'b') {
        dfa = 3;
    }
    else{
        dfa = -1;
    }
}

// func for q1 state of DFA

void state1(char c)
{
    if( c == 'a') {
        dfa = 2;
    }
    else if (c == 'b') {
        dfa = 3;
    }
    else {
        dfa = -1;
    }
}

// for for q2 state of DFA
void state2(char c)
{
    if (c == 'b') {
        dfa = 3;
    }
    else if (c == 'a') {
        dfa = 1;
    }
    else {
        dfa = -1;
    }

}

// func for q3 state of DFA
void state3(char c)
{
    if (c == 'b') {
        dfa = 3;
    }
    else if (c == 'a') {
        dfa = 4;
    }
    else {
        dfa = -1;
    }
}

// func for q4 state of DFA
void state4(char c)
{
    dfa = -1;
}
  
int isAccepted(char str[])
{
    // storing length of string
    int i, len = strlen(str);
  
    for (i = 0; i < len; i++) {
        if (dfa == 0)
            start(str[i]);
  
        else if (dfa == 1)
            state1(str[i]);
  
        else if (dfa == 2)
            state2(str[i]);
  
        else if (dfa == 3)
            state3(str[i]);
  
        else if (dfa == 4)
            state4(str[i]);
        else
            return 0;
    }
    if (dfa == 3)
        return 1;
    else
        return 0;
}
//  main code
int main()
{
    char str[] = "aaaaaabbbb";
    if (isAccepted(str))
        printf("String is accepted.\n");
    else
        printf("String is not accepted.\n");
    return 0;

}
