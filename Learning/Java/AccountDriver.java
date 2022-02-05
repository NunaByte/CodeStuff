import java.util.*;
import java.io.*;


public class AccountDriver 
{

	public static void main(String[] args) 
	{
		int deposit;
		
		Scanner input = new Scanner(System.in);
		//Creation of account objects
		Account account1 = new Account("Cadarius Williams", 500);
		Account account2 = new Account("Molly Heart", 500);
		
		//Displays number of account holders
		System.out.println("Account Holders: " + Account.numberOfAccountHolders());
		System.out.println("");
		
		
		//Displays account details
		Account.displayAccountDetails(account1);
		Account.displayAccountDetails(account2);
		System.out.println();
		
		//Prompt to deposit into account 1
		System.out.print("How much would you like to deposit into account 1: ");
		deposit = input.nextInt();
		System.out.println("Deposting " + deposit + " into account 1\n");
		account1.deposit(deposit);
		
		//Displays Accounts
		Account.displayAccountDetails(account1);
		Account.displayAccountDetails(account2);
		
		input.close();

	}

}
