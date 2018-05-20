#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    使用指针函数实现C的多态

*/

typedef int (*PINT)(int);
typedef float (*PFLOAT)(float);
typedef char (*PCHAR)(char);

void fun1(int a)
{
    printf("int...\n");
    printf("data = %d\n", a);
}
void fun2(float f)
{
    printf("float...\n");
    printf("data = %f\n", f);
}
void fun3(char c)
{
    printf("char...\n");
    printf("data = %c\n", c);
}
void (*ff(char* type))(void *data)
{
    if(!strcmp(type, "int"))
	{
		void (*pInt)(int) = fun1;
		return (void (*)(void*))pInt;
	}
    else if(!strcmp(type, "float"))
	{
		void (*pFloat)(float) = fun2;
		return (void (*)(void*))pFloat;
	}
    else if(!strcmp(type, "char"))
    {
		void (*pChar)(char) = fun3;
		return (void (*)(void*))pChar;
	}
    else{
        printf("error!\n");
        exit(1);
    }
}

int main(void)
{
	PINT pInt = (PINT)ff("int");
    pInt(3);

	PFLOAT pFloat = (PFLOAT)ff("float");
	pFloat(4.4);

	PCHAR pChar = (PCHAR)ff("char");
	pChar('a');

    return 0;
}
