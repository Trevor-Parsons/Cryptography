package task3;

import java.util.*;
import java.security.*;
import java.math.BigInteger;


public class Task3 {

	public static void main(String[] args) throws Exception {
		String hexString;
		MessageDigest sha256 = MessageDigest.getInstance("SHA-256");
		double lowestValue = Double.MAX_VALUE;
		double currentValue = 0;
		double startTime;
		int count = 0;
		
		// Find lowest hash value in 10 seconds
		startTime = System.currentTimeMillis();
		while ((System.currentTimeMillis() - startTime) < 10000) {
			hexString = hashString(sha256.digest(UUID.randomUUID().toString().getBytes()));
			
			BigInteger currentVal = new BigInteger(hexString, 16);
			currentValue = currentVal.doubleValue();
			
			if(currentValue < lowestValue) {
				lowestValue = currentValue;
			}
			
			count++;
		}
		
		System.out.print("Number of hashes in 10 seconds: " + count + "\n");
		System.out.print("Lowest value found: " + lowestValue + "\n\n");
		
		lowestValue = Double.MAX_VALUE;
		count = 0;
		
		// Find lowest hash value in 20 seconds
		startTime = System.currentTimeMillis();
		while ((System.currentTimeMillis() - startTime) < 20000) {
			hexString = hashString(sha256.digest(UUID.randomUUID().toString().getBytes()));
			
			BigInteger currentVal = new BigInteger(hexString, 16);
			currentValue = currentVal.doubleValue();
			
			if(currentValue < lowestValue) {
				lowestValue = currentValue;
			}
			count++;
		}
		
		System.out.print("Number of hashes in 20 seconds: " + count + "\n");
		System.out.print("Lowest value found: " + lowestValue + "\n\n");
		
		lowestValue = Double.MAX_VALUE;
		count = 0;

		// Find lowest hash value in 30 seconds
		startTime = System.currentTimeMillis();
		while ((System.currentTimeMillis() - startTime) < 30000) {
			hexString = hashString(sha256.digest(UUID.randomUUID().toString().getBytes()));
			
			BigInteger currentVal = new BigInteger(hexString, 16);
			currentValue = currentVal.doubleValue();
			
			if(currentValue < lowestValue) {
				lowestValue = currentValue;
			}
			
			count++;
		}
		
		System.out.print("Number of hashes in 30 seconds: " + count + "\n");
		System.out.print("Lowest value found: " + lowestValue + "\n\n");
	}
	
	// Convert Digest Output to String
	public static String hashString(byte[] bytes) {
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
