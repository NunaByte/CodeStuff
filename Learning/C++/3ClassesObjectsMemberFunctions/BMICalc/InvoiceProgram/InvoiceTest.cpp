#include <iostream>
#include <string>
#include "Invoice.h"

using namespace std;

int main()
{
    Invoice invoice1{"4E65","LightSaber - Glow in the dark",2,55};

    invoice1.displayInvoice(invoice1);
}