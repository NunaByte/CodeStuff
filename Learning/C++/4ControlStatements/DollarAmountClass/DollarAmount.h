//Dollar amount class
#include <string>

class DollarAmount
{
    public:
        //Constructor
        explicit DollarAmount(int pen)
            : pennies{pen}
        {
            //empty block
        }

        //Member function to add DollarAmount into a DollarAmount
        void add(DollarAmount dol1)
        {
            int sum;
            sum = dol1.getPennies();
            pennies += sum;
        }

        //Member function to subtract DollarAmount from a DollarAmount
        void substract(DollarAmount dol1)
        {
            int difference;
            difference = dol1.getPennies();
            pennies -= difference;
        }

        //set and get for pennies
        void setPennies(int pen)
        {
            if(pen >= 0)
            {
                pennies = pen;
            }
        }
        int getPennies()
        {
            return pennies;
        }




    private:
        int pennies{0};
};