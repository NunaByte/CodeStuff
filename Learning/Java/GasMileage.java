package Learning.Java;
import java.util.Scanner;

public class GasMileage
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);

        double milesDriven = 0;
        double galUsed = 0;
        double milesDrivenTotal = 0;
        double galUsedTotal = 0;
        double mpg = 0;
        double mpgTotal = 0;

        while(milesDriven != -1)
        {
            System.out.print("Enter miles driven (-1 to quit): ");
            milesDriven = input.nextInt();
            milesDrivenTotal += milesDriven;

            if(milesDriven != -1)
            {
                System.out.print("Enter gallons used: ");
                galUsed = input.nextInt();
                galUsedTotal += galUsed;

                System.out.println("MPG this trip: " + milesDriven/galUsed);
                System.out.println("");
                System.out.println("Total MPG: " + milesDrivenTotal/galUsedTotal);
            }

        }
    }
}