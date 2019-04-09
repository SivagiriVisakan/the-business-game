
#include "Field.h"
#include <string.h>

Field::Field(char *name)
{
    int l = strlen(name);
    this->name = new char[l];
    strcpy(this->name, name);
    id = TOTAL_ID++;
}

int Field::TOTAL_ID = 0;

Field::Field(const Field& f)
{
    int l = strlen(f.getName());
    id = f.id;
    this->name = new char[l];
    strcpy(this->name, f.getName());
}

Field::~Field()
{
    delete name;
}