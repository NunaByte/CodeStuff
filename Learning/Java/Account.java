
public class Account 
{
	private String name;
	private double balance;
	private static int actCount;
	
	//Constructor
	public Account(String name, double balance)
	{
		actCount++;
		this.name = name;
		
		if(balance > 0.0)
		{
			this.balance += balance;
		}
		
	}
	
	
	//Method to set name
	public void setName(String name)
	{
		this.name = name;
	}
	
	//Method to return a String of name
	public String getName()
	{
		return name;
	}
	
	//Method to make a deposit into account balance
	public void deposit(double depositAmount)
	{
		if(depositAmount > 0.0)
		{
			this.balance += depositAmount;
		}
	}
	
	//Method to return account balance
	public double getBalance()
	{
		return balance;
	}
	
	
	//Method to withdraw from account balance
	public void withdraw(double amount)
	{
		if(amount < balance)
		{
			balance -= amount;
		}
		else
			System.out.println("Insufficient Balance");
	}
	
	//Method to display account details
		public static void displayAccountDetails(Account display)
		{
			System.out.println(display.getName() + " balance: " + display.getBalance());
		}
	
	//Method to display number of account holders
		public static int numberOfAccountHolders()
		{
			return actCount;
		}
}
