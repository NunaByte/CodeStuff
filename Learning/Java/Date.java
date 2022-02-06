//Date Class

public class Date 
{
    //Instance Variables
    private int day;
    private int month;
    private int year;

    //Constructor
    public Date(int d, int m, int y)
    {   
        if((d < 32) && (d >=1))
        {
            day = d;
        }

        if((m < 13) && (m >=1))
        {
            month = m;
        }

        if((y < 2023) && (y >=1800))
        {
            year = y;
        }
        
    }

    //Methods for day
    public void setDay(int d)
    {
        if((d < 32) && (d >=1))
        {
            day = d;
        }
    }
    public int getDay()
    {
        return day;
    }

    //Methods for month
    public void setMonth(int m)
    {
        if((m < 13) && (m >=1))
        {
            month = m;
        }
    }
    public int getMonth()
    {
        return month;
    }

    //Methods for year
    public void setYear(int y)
    {
        if((y < 2023) && (y >=1800))
        {
            year = y;
        }
    }
    public int getYear()
    {
        return year;
    }

    //Method to display date
    public void displayDate(Date display)
    {
        System.out.println(display.getMonth() + "/" + display.getDay() + "/" + display.getYear());
    }
}
