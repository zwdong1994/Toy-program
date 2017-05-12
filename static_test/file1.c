//
// Created by victor on 4/10/17.
//

#include "file1.h"

void print()
{
    static int i=0;
    printf("%d\n", i++);
}