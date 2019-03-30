#ifndef FIELD_H
#define FIELD_H

enum FieldLevel {NotUpgradable = -1, LevelOne = 1, LevelTwo = 2, LevelThree = 3}; 
#include "player.h"
class Field
{
    private:
    protected:
        char *name;
        enum FieldLevel level;
        int cost; // The initial cost of the Field (for buying)
        int rent; // The rent that has to be paid if opponent lands here(changes depending on level)
        int  ownerId;

    public:
        Field(char *name);
        Field(const Field& f);
        virtual ~Field();

        enum FieldLevel getCurrentLevel() const {return level;}
        int getRent() const { return rent; }
        int getCost() const { return cost; }
        char* getName() const { return name; }
        int getOwnerId() const { return ownerId; }
        void setOwner(int id) { ownerId = id;}

        virtual void setCost(int c)=0;
        virtual void calculateRent()=0;

};

#endif // FIELD_H
