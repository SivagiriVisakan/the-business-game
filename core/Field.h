#ifndef FIELD_H
#define FIELD_H

#include "player.h"
class Field
{
    private:
        static int TOTAL_ID;
        int id;
    protected:
        char *name;
        int rent; // The rent that has to be paid if opponent lands here(changes depending on level)

    public:
        Field(char *name);
        Field(const Field& f);
        virtual ~Field();

        int getRent() const { return rent; }
        char* getName() const { return name; }

};

#endif // FIELD_H
