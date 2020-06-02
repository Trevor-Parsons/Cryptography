package task1;

import java.util.*;
import java.security.*;
import java.io.*;
import java.math.BigInteger;


public class Task1 {

	public static void main(String[] args) throws Exception {
		// Create short file
		byte[] shortFileBytes = new byte[16];
		new Random().nextBytes(shortFileBytes);
		File shortFile = new File("shortFile.txt");
		FileOutputStream shortOut = new FileOutputStream("shortFile.txt");
		shortOut.write(shortFileBytes);
		shortOut.close();
		
		// Create long file
		byte[] longFileBytes = new byte[1000000];
		new Random().nextBytes(longFileBytes);
		File longFile = new File("longFile.txt");
		FileOutputStream longOut = new FileOutputStream("longFile.txt");
		longOut.write(longFileBytes);
		longOut.close();
		
		// Determine how many times files can be hashed in a second
		long startTime, endTime, totalTime = 0;
		int numCycles = 0;
		
		// Short file, SHA-256
		while (totalTime < 1000000000) {
			startTime = System.nanoTime();
				
			sha256Hash(shortFile);
			endTime = System.nanoTime();
			totalTime = endTime - startTime + totalTime;
			numCycles++;
		}
		
		System.out.println("SHA-256 Short File Cycles: " + numCycles);
		printHashValue(sha256Hash(shortFile));
		totalTime = 0;
		numCycles = 0;
		
		// Long file, SHA-256
		while (totalTime < 1000000000) {
			startTime = System.nanoTime();
				
			sha256Hash(longFile);
			endTime = System.nanoTime();
			totalTime = endTime - startTime + totalTime;
			numCycles++;
		}
		
		System.out.println("SHA-256 Long File Cycles: " + numCycles);
		printHashValue(sha256Hash(longFile));
		totalTime = 0;
		numCycles = 0;
				
		// Short file, MD5 (128 bit output)
		while (totalTime < 1000000000) {
			startTime = System.nanoTime();
				
			MD5Hash(shortFile);
			endTime = System.nanoTime();
			totalTime = endTime - startTime + totalTime;
			numCycles++;
		}
		
		System.out.println("MD5 Short File Cycles: " + numCycles);
		printHashValue(MD5Hash(shortFile));
		totalTime = 0;
		numCycles = 0;
		
		// Long file, MD5 (128 bit output)
		while (totalTime < 1000000000) {
			startTime = System.nanoTime();
				
			MD5Hash(longFile);
			endTime = System.nanoTime();
			totalTime = endTime - startTime + totalTime;
			numCycles++;
		}
		
		System.out.println("MD5 Long File Cycles: " + numCycles);
		printHashValue(MD5Hash(longFile));
		
		writeToFile(MD5Hash(shortFile), shortFile);
		writeToFile(MD5Hash(longFile), longFile);
	}

	public static byte[] sha256Hash(File file) throws Exception {
		// Read bytes from file into byte array 
		byte[] fileContents = new byte[(int) file.length()];
		
		FileInputStream fileEncryptIn = new FileInputStream(file);
		fileEncryptIn.read(fileContents);
		fileEncryptIn.close();
		
		// Set up hash algorithm
		MessageDigest sha256 = MessageDigest.getInstance("SHA-256");
		
		// Calculate hash value
		return sha256.digest(fileContents);
	}
	
	public static byte[] MD5Hash(File file) throws Exception {
		// Read bytes from file into byte array 
		byte[] fileContents = new byte[(int) file.length()];
		
		FileInputStream fileEncryptIn = new FileInputStream(file);
		fileEncryptIn.read(fileContents);
		fileEncryptIn.close();
		
		// Set up hash algorithm
		MessageDigest MD5 = MessageDigest.getInstance("MD5");
		
		// Calculate hash value
		return MD5.digest(fileContents);
	}
	
	public static void printHashValue(byte[] bytes) {
        // Convert byte array into Big Integer
        BigInteger bigInt = new BigInteger(1, bytes); 
        
        // Convert byte array into hex
        StringBuilder fileText = new StringBuilder(bigInt.toString(16));
        
        while (fileText.length() < 32) { 
            fileText.insert(0,  '0'); 
        }
		
		System.out.print("Hash Value: " + fileText.toString() + "\n\n");
	}
	
	public static void writeToFile(byte[] bytes, File file) throws Exception {
        // Convert byte array into Big Integer
        BigInteger bigInt = new BigInteger(1, bytes); 
        
        // Convert byte array into hex
        StringBuilder fileText = new StringBuilder(bigInt.toString(16));
        
        while (fileText.length() < 32) { 
            fileText.insert(0,  '0'); 
        }
		// Write decrypted bytes to file
		FileOutputStream fileDecryptOut = new FileOutputStream(file);
		fileDecryptOut.write(fileText.toString().getBytes());
		fileDecryptOut.close();
	}
}
