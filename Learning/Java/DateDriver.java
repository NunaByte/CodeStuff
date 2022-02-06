import java.util.*;


public class DateDriver 
{
    public static void main(String[] args)
    {
        int day;
        int month;
        int year;

        //Scanner for user input
        Scanner input = new Scanner(System.in);

        //Creation of date object
        Date date1 = new Date(5,2,2022);

        //Displays date
        date1.displayDate(date1);

        //Prompt to set new date
        System.out.print("Enter day: ");
        day = input.nextInt();
        date1.setDay(day);

        System.out.print("Enter month: ");
        month = input.nextInt();
        date1.setMonth(month);

        System.out.print("Enter year: ");
        year = input.nextInt();
        date1.setYear(year);

        //Displays new date set
        date1.displayDate(date1);


    }
}
