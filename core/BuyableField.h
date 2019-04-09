#ifndef BUYABLE_FIELD_H
#define BUYABLE_FIELD_H

#include "Field.h"

enum FieldLevel {NotUpgradable = -1, LevelOne = 1, LevelTwo = 2, LevelThree = 3}; 

class BuyableField: public Field
{
    private:
    protected:
        char *name;
        enum FieldLevel level;
        int cost; // The initial cost of the Field (for buying)

        int  ownerId;

    public:
        BuyableField(char *name);
        BuyableField(const BuyableField& bf);
        virtual ~BuyableField();

        enum FieldLevel getCurrentLevel() const {return level;}
        void setLevel(FieldLevel level) { this->level = level;}
        int getCost() const { return cost; }
        int getOwnerId() const { return ownerId; }
        void setOwner(int id) { ownerId = id;}

        virtual void setCost(int c)=0;
        virtual void calculateRent()=0;

};

#endif // BUYABLE_FIELD_H
