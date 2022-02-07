//Class for InvoiceTest
#include <string>

 class Invoice
 {
     public:
        //Constructor
        explicit Invoice(std::string ipartNumb, std::string ipartDes, int iitemQ, int ipricePerItem)
            : partNumb{ipartNumb}, partDes{ipartDes}, itemQ{iitemQ}, pricePerItem{ipricePerItem}
            {
                //Empty body
            }
        
        //Set and Get member functions for Part Number
        void setNumb(std::string num)
        {
            partNumb = num;
        }

        std::string getNumb()
        {
            return partNumb;
        }

        //Set and Get member functions for Part Description
        void setDes(std::string des)
        {
            partDes = des;
        }

        std::string getDes()
        {
            return partDes;
        }

        //Set and Get member functions for Item Quanitity
        void setQ(int q)
        {
            itemQ = q;
        }

        int getQ()
        {
            return itemQ;
        }

        //Set and Get member functions for Price Per Item
        void setItemPrice(int price)
        {
            pricePerItem = price;
        }

        int getItemPrice()
        {
            return itemQ;
        }

        //Member function that gives invoice details
        void displayInvoice(Invoice display)
        {
            std::cout << "############################";
            std::cout << "Part ID: " << display.partNumb << "\nPart Description: " << display.partDes << "\nQuantity: " << display.itemQ << "\nPart Price: " << display.pricePerItem
            << "$";
        }

        //Member function that calculates invoice amount
        int getInvoiceAmount()
        {
            if(itemQ < 0)
            {
                itemQ = 0;
            }
            if(pricePerItem < 0)
            {
                pricePerItem = 0;
            }
            int amount = itemQ * pricePerItem;

            return amount;

        }
        



     private:
     std::string partNumb;
     std::string partDes;
     int itemQ{0};
     int pricePerItem{0};
 };