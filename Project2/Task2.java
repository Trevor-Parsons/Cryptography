package proj2;

import java.util.*;
import java.security.*;

public class main {
	public static void main(String[] args) throws Exception {
		
		// Create Random and SecureRandom instances
		Random badRandom = new Random();
		SecureRandom goodRandom = new SecureRandom();
		
		double gcdIs1 = 0;
		double gcdIsNot1 = 0;
		double gcdIs1Probability;
		double piValue;
		
		// Calculate value of Pi using Random (LCG)
		for (double i = 0; i < 10000000; i++) {
			int firstRandom = badRandom.nextInt(Integer.MAX_VALUE);
			int secondRandom = badRandom.nextInt(Integer.MAX_VALUE);
			
			if (firstRandom > secondRandom) {
				if (GCD(firstRandom, secondRandom) == 1) gcdIs1++;
				else gcdIsNot1++;
			} else {
				if (GCD(secondRandom, firstRandom) == 1) gcdIs1++;
				else gcdIsNot1++;
			}
		}
		
		gcdIs1Probability = gcdIsNot1 / gcdIs1;
		piValue = Math.sqrt((double)6.0 / gcdIs1Probability);
	
		System.out.println("Estimated value of Pi for LCG Random Generator: " + piValue);
		
		gcdIs1 = 0; 
		gcdIsNot1 = 0;
		
		// Calculate value of Pi using SecureRandom
		for (double i = 0; i < 10000000; i++) {
			int firstRandom = goodRandom.nextInt(Integer.MAX_VALUE);
			int secondRandom = goodRandom.nextInt(Integer.MAX_VALUE);
			
			if (firstRandom > secondRandom) {
				if (GCD(firstRandom, secondRandom) == 1) gcdIs1++;
				else gcdIsNot1++;
			} else {
				if (GCD(secondRandom, firstRandom) == 1) gcdIs1++;
				else gcdIsNot1++;
			}
		}
		
		gcdIs1Probability = gcdIsNot1 / gcdIs1;
		piValue = Math.sqrt((double)6.0 / gcdIs1Probability);
	
		System.out.println("Estimated value of Pi for Secure Random Generator: " + piValue);
	}
	
	// GCD Function
	public static int GCD(int x, int y) {
	   int remainder = 0;
		
		while (y != 0) {
			remainder = y;
			y = x % y;
			x = remainder;
		}
		
		return x;
	}
}
