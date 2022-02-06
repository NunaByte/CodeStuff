//Employee Class
public class Employee 
{
    //Instance variables
    private String firstName;
    private String lastName;
    private int monthlySalary;

    //Constructor
    public Employee(String first,String last, int Sal)
    {
        firstName = first;
        lastName = last;
        
        if(Sal >= 0)
        {
            monthlySalary = Sal;
        }
    }

    //Methods for first name
    public void setFirstName(String first)
    {
        first = firstName;
    }
    public String getFirstName()
    {
        return firstName;
    }
    
    //Methods for last name
    public void setLastName(String last)
    {
        last = lastName;
    }
    public String getLastName()
    {
        return lastName;
    }

    //Methods for salary
    public void setSalary(int Sal)
    {
        if(Sal >= 0)
        {
            monthlySalary = Sal;
        }
    }
    public int getMonthlySalary()
    {
        return monthlySalary;
    }

}
