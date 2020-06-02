package task3;

import java.util.*;
import java.security.*;
import javax.crypto.*;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.SecretKeySpec;
import java.io.*;

public class Task3 {

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
		
		// Establish AES keys
		SecureRandom sec128Rand = new SecureRandom();
		SecureRandom sec256Rand = new SecureRandom();
		
		KeyGenerator key128Gen = KeyGenerator.getInstance("AES");
		KeyGenerator key256Gen = KeyGenerator.getInstance("AES");
		
		key128Gen.init(128, sec128Rand);
		key256Gen.init(256, sec256Rand);
		
		SecretKey sec128Key = key128Gen.generateKey();
		SecretKey sec256Key = key256Gen.generateKey();
		
		// Determine how many times files can be encrypted and decrypted in a second
		long startTime, endTime, totalTime = 0;
		
		// Short file, 128 bit key
		int numShort128Cycles = 0;
		while (totalTime < 1000000000) {
			startTime = System.nanoTime();
					
			AESencrypt(shortFile, sec128Key);
			AESdecrypt(shortFile, sec128Key);
			
			endTime = System.nanoTime();
			totalTime = endTime - startTime + totalTime;
			numShort128Cycles++;
		}
		
		System.out.println("Number of Short File 128-bit key AES cycles: " + numShort128Cycles);
		
		totalTime = 0; 
		
		// Short file, 256 bit key
		int numShort256Cycles = 0;
		while (totalTime < 1000000000) {
			startTime = System.nanoTime();
					
			AESencrypt(shortFile, sec256Key);
			AESdecrypt(shortFile, sec256Key);
			
			endTime = System.nanoTime();
			totalTime = endTime - startTime + totalTime;
			numShort256Cycles++;
		}
		
		System.out.println("Number of Short File 256-bit key AES cycles: " + numShort256Cycles);
		
		totalTime = 0; 
		
		// Long file, 128 bit key
		int numLong128Cycles = 0;
		while (totalTime < 1000000000) {
			startTime = System.nanoTime();
					
			AESencrypt(longFile, sec128Key);
			AESdecrypt(longFile, sec128Key);
			
			endTime = System.nanoTime();
			totalTime = endTime - startTime + totalTime;
			numLong128Cycles++;
		}
		
		System.out.println("Number of Long File 128-bit key AES cycles: " + numLong128Cycles);
		
		totalTime = 0; 
		
		// Long file, 256 bit key
		int numLong256Cycles = 0;
		while (totalTime < 1000000000) {
			startTime = System.nanoTime();
					
			AESencrypt(longFile, sec256Key);
			AESdecrypt(longFile, sec256Key);
			
			endTime = System.nanoTime();
			totalTime = endTime - startTime + totalTime;
			numLong256Cycles++;
		}
		
		System.out.println("Number of Long File 256-bit key AES cycles: " + numLong256Cycles);
		
		// Same process using RSA encryption of AES key
		KeyPairGenerator keyPairGen = KeyPairGenerator.getInstance("RSA");
		keyPairGen.initialize(2048);
		KeyPair keys = keyPairGen.generateKeyPair();
		PrivateKey privKey = keys.getPrivate();
		PublicKey pubKey = keys.getPublic();
		
		// Short file RSA
		totalTime = 0;
		int numShortRSACycles = 0;
		while (totalTime < 1000000000) {
			startTime = System.nanoTime();
					
			byte[] encryptedKey = RSAEncrypt(shortFile, sec256Key, pubKey);
			RSADecrypt(shortFile, encryptedKey, privKey);
			
			endTime = System.nanoTime();
			totalTime = endTime - startTime + totalTime;
			numShortRSACycles++;
		}
		
		System.out.println("Number of Short File RSA cycles: " + numShortRSACycles);
		
		// Long file RSA
		totalTime = 0;
		int numLongRSCycles = 0;
		while (totalTime < 1000000000) {
			startTime = System.nanoTime();
					
			byte[] encryptedKey = RSAEncrypt(longFile, sec256Key, pubKey);
			RSADecrypt(longFile, encryptedKey, privKey);
			
			endTime = System.nanoTime();
			totalTime = endTime - startTime + totalTime;
			numLongRSCycles++;
		}
		
		System.out.println("Number of Long File RSA cycles: " + numLongRSCycles); 
	}

	public static void AESencrypt(File file, SecretKey secKey) throws Exception {
		byte[] iv = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7 };
	    IvParameterSpec ivspec = new IvParameterSpec(iv);
	    
		// Read bytes from file into byte array 
		byte[] fileContents = new byte[(int) file.length()];
		
		FileInputStream fileEncryptIn = new FileInputStream(file);
		fileEncryptIn.read(fileContents);
		fileEncryptIn.close();
		
		// Set up AES encryption Cipher
		Cipher fileEncryptCipher = Cipher.getInstance("AES/CBC/PKCS5Padding");
		fileEncryptCipher.init(Cipher.ENCRYPT_MODE, secKey, ivspec);
		
		// Encrypt bytes from file
		byte[] encrypted = fileEncryptCipher.doFinal(fileContents);
		
		// Write encrypted bytes to file
		FileOutputStream fileEncryptOut = new FileOutputStream(file);
		fileEncryptOut.write(encrypted);
		fileEncryptOut.close();
	}
	
	public static void AESdecrypt(File file, SecretKey secKey) throws Exception {
		byte[] iv = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7 };
	    IvParameterSpec ivspec = new IvParameterSpec(iv);
	    
		// Read bytes from file into byte array
		byte[] fileContents = new byte[(int) file.length()];
		
		FileInputStream fileDecryptIn = new FileInputStream(file);
		fileDecryptIn.read(fileContents);
		fileDecryptIn.close();
		
		// Set up AES decryption Cipher
		Cipher fileDecryptCipher = Cipher.getInstance("AES/CBC/PKCS5Padding");
		fileDecryptCipher.init(Cipher.DECRYPT_MODE, secKey, ivspec);
		
		// Decrypt bytes from file
		byte[] decrypted = fileDecryptCipher.doFinal(fileContents);
		
		// Write decrypted bytes to file
		FileOutputStream fileDecryptOut = new FileOutputStream(file);
		fileDecryptOut.write(decrypted);
		fileDecryptOut.close();

	}
	
	public static byte[] RSAEncrypt(File file, SecretKey secKey, PublicKey pubKey) throws Exception {
		// Encrypt file with AES
		AESencrypt(file, secKey);
		
		// Set up RSA encryption Cipher
		Cipher fileEncryptCipher = Cipher.getInstance("RSA/ECB/PKCS1Padding");
		fileEncryptCipher.init(Cipher.ENCRYPT_MODE, pubKey);
		
		// Encrypt AES secret key with RSA
		byte[] encryptedSecretKey = fileEncryptCipher.doFinal(secKey.getEncoded());
		
		return encryptedSecretKey;
	}
	
	public static void RSADecrypt(File file, byte[] secKey, PrivateKey privKey) throws Exception {
		// Set up RSA decryption cipher
		Cipher fileDecryptCipher = Cipher.getInstance("RSA/ECB/PKCS1Padding");
		fileDecryptCipher.init(Cipher.DECRYPT_MODE, privKey);
		
		// Decrypt AES secret key
		byte[] decryptedSecretKey = fileDecryptCipher.doFinal(secKey);
		
		SecretKey secretKey = new SecretKeySpec(decryptedSecretKey, 0, decryptedSecretKey.length, "AES");
		
		// Decrypt file using AES
		AESdecrypt(file, secretKey);
	}
	
}

