package task2;

import java.util.*;
import java.security.*;
import java.math.BigInteger;


public class Task2 {

	public static void main(String[] args) throws Exception {
		byte[] hash = new byte[32];
		String myBirthday = "5191992";
		String birthdayHash = "";
		boolean found1 = false; 
		boolean found2 = false;
		boolean found3 = false;  
		boolean found4 = false;  
		boolean found5 = false; 
		boolean found6 = false; 
		boolean found7 = false;
		
		MessageDigest sha256 = MessageDigest.getInstance("SHA-256");
		
		long startTime, endTime = 0;
		double totalTime = 0;
		startTime = System.currentTimeMillis();
		
		// Find Hashes that begin with the birthday value
		while (found7 == false) {
			birthdayHash = birthdayHashValue(sha256.digest(hash));
			
			// Find a hash that begins with 5
			if (birthdayHash.startsWith("5") && found1 == false) {
				System.out.println("Found 5, Time Required: " + 
						(double)(System.currentTimeMillis() - startTime) / 1000 +
						" seconds."); 
				System.out.println(birthdayHash + "\n");
				found1 = true;
			}
			
			// Find a hash that begins with 51
			if (birthdayHash.startsWith("51") && found2 == false) {
				System.out.println("Found 51, Time Required: " + 
						(double)(System.currentTimeMillis() - startTime) / 1000 +
						" seconds."); 
				System.out.println(birthdayHash + "\n");

				found2 = true;
			}
			
			// Find a hash that begins with 519
			if (birthdayHash.startsWith("519") && found3 == false) {
				System.out.println("Found 519, Time Required: " + 
						(double)(System.currentTimeMillis() - startTime) / 1000 +
						" seconds."); 
				System.out.println(birthdayHash + "\n");

				found3 = true;
			}
			
			// Find a hash that begins with 5191
			if (birthdayHash.startsWith("5191") && found4 == false) {
				System.out.println("Found 5191, Time Required: " + 
						(double)(System.currentTimeMillis() - startTime) / 1000 +
						" seconds."); 
				System.out.println(birthdayHash + "\n");

				found4 = true;
			}
			
			// Find a hash that begins with 51919
			if (birthdayHash.startsWith("51919") && found5 == false) {
				System.out.println("Found 51919, Time Required: " + 
						(double)(System.currentTimeMillis() - startTime) / 1000 +
						" seconds."); 
				System.out.println(birthdayHash + "\n");

				found5 = true;
			}
			
			// Find a hash that begins with 519199
			if (birthdayHash.startsWith("519199") && found6 == false) {
				System.out.println("Found 519199, Time Required: " + 
						(double)(System.currentTimeMillis() - startTime) / 1000 +
						" seconds."); 
				System.out.println(birthdayHash + "\n");

				found6 = true;
			}
			
			// Find a hash that begins with 5191992
			if(birthdayHash.startsWith(myBirthday)) {
				System.out.println("Found 5191992, Time Required: " + 
						(double)(System.currentTimeMillis() - startTime) / 1000 +
									" seconds"); 
				System.out.println(birthdayHash + "\n");
				
				found7 = true;
			}
			
			new Random().nextBytes(hash);
		}
		
		endTime = System.currentTimeMillis();
		totalTime = ((double)endTime - (double)startTime) / 1000;
		
		System.out.println("Total time: " + totalTime + " seconds.");
	}
		
	public static String birthdayHashValue(byte[] bytes) {
        // Convert byte array into Big Integer
        BigInteger bigInt = new BigInteger(1, bytes); 
        
        // Convert byte array into hex
        StringBuilder possibleBirthday = new StringBuilder(bigInt.toString(16));
        
        while (possibleBirthday.length() < 32) { 
        	possibleBirthday.insert(0,  '0'); 
        }
        
		return possibleBirthday.toString();
	}
}
