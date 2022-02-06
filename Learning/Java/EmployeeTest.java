//Employee Class Tester
import java.util.*;


public class EmployeeTest 
{

    public static void main(String[] args)
    {
        //Creation of employee objects
        Employee employee1 = new Employee("John", "Henry", 5000);
        Employee employee2 = new Employee("Mary", "Sue", 4000);

        //Display of current monthly salary
        System.out.println(employee1.getFirstName() + " " +  employee1.getLastName() + " has a monthly salary of: " + employee1.getMonthlySalary());
        System.out.println(employee2.getFirstName() + " " +  employee2.getLastName() + " has a monthly salary of: " + employee2.getMonthlySalary());
        System.out.println("");

        //Display after a 5% and 10% raise
        double raise1, raise2;
        raise1 = (employee1.getMonthlySalary()/100) * 105; 
        raise2 = (employee2.getMonthlySalary()/100) * 110;

        System.out.println("After a raise was given");
        System.out.println(employee1.getFirstName() + " " +  employee1.getLastName() + " has a monthly salary of: " + raise1);
        System.out.println(employee2.getFirstName() + " " +  employee2.getLastName() + " has a monthly salary of: " + raise2);
    }
}
