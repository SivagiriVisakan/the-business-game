
#include "Field.h"
#include <string.h>

Field::Field(char *name)
{
    int l = strlen(name);
    this->name = new char[l];
    strcpy(this->name, name);
}
