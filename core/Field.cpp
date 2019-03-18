
#include "Field.h"
#include <string.h>

Field::Field(char *name)
{
    int l = strlen(name);
    this->name = new char[l];
    strcpy(this->name, name);
}

Field::Field(const Field& f)
{
    level  = f.level;
    cost = f.cost;
    rent = f.rent;

    int l = strlen(f.getName());
    this->name = new char[l];
    strcpy(this->name, f.getName());
}

Field::~Field()
{
    delete name;
}