import java.util.*;

public class BMICalc 
{

	public static void main(String[] args) 
	{
		//Establishing needed variables 
		int weight;
		int finalWeight;
		int height;
		int bmi;
		
		Scanner input = new Scanner(System.in);
		System.out.println("#######################################################"); //Separator
		System.out.println("WELCOME TO THE BMI CALCULATOR");
		System.out.println("#######################################################\n"); //Separator
		
		//Beginning of data capture from user
		
		System.out.print("Please Enter Your Weight(In Pounds): ");
		weight = input.nextInt();
		
		finalWeight = weight * 703; //Gets the final weight to use in BMI Calculation 
		
		System.out.print("Please Enter Your Height(In Inches): ");
		height = input.nextInt();
		
		bmi = finalWeight/(height*height); //Calculates BMI
		
		System.out.println("#######################################################"); //Separator 
		
		//Checks the BMI and matches it to correct category
		
		if(bmi < 18.5)
		{
			System.out.println("Your BMI: " + bmi + "\nCategory: Underweight");
		}
		
		if(bmi > 18.5 && bmi < 24.9)
		{
			System.out.println("Your BMI: " + bmi + "\nCategory: Normal weight");
		}
		
		if(bmi > 25 && bmi < 29.9)
		{
			System.out.println("Your BMI: " + bmi + "\nCategory: Overweight");
		}
		
		if(bmi > 30)
		{
			System.out.println("Your BMI: " + bmi + "\nCategory: Obese");
		}
		
		System.out.println("#######################################################"); //Separator
		
		//List BMI Categories
		System.out.println("BMI Categories:\nUnderwight = <18.5\nNormal weight = 18.5-24.9\nOverweight = 25-29.9\nObesity = BMI of 30 or greater");
		
		
		input.close();

	}

}