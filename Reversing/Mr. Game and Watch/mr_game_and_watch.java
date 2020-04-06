
import java.io.*;
import java.util.Scanner;
import java.util.Arrays;
import java.security.MessageDigest;

public class mr_game_and_watch {
    // public static String clear_1 = "masterchief";
    // public static int key_1 = 117;
    // public static String hash_2 = "264212deff89ade15661a59e7b632872d858f2c6";
    // public static String clear_2 = "princesspeach";
    // public static String hash_3 =
    // "5ebb49e499a6613e832e433a2722edd0d2947d56fdb4d684af0f06c631fdf633";
    // public static String clear_3 = "solidsnake";

    public static String secret_1 = "d5c67e2fc5f5f155dff8da4bdc914f41";
    public static int[] secret_2 = { 114, 118, 116, 114, 113, 114, 36, 37, 38, 38, 120, 121, 33, 36, 37, 113, 117, 118,
            118, 113, 33, 117, 121, 37, 119, 34, 118, 115, 114, 120, 119, 114, 36, 120, 117, 120, 38, 114, 35, 118 };
    public static int[] secret_3 = { 268, 348, 347, 347, 269, 256, 348, 269, 256, 256, 344, 271, 271, 264, 266, 348,
            257, 266, 267, 348, 269, 266, 266, 344, 267, 270, 267, 267, 348, 349, 349, 265, 349, 267, 256, 269, 270,
            349, 268, 271, 351, 349, 347, 269, 349, 271, 257, 269, 344, 351, 265, 351, 265, 271, 346, 271, 266, 264,
            351, 349, 351, 271, 266, 266 };

    public static int key_2 = 64;
    public static int key_3 = 313;

    public static void main(String[] args) {

        System.out.println("Welcome to the Land of Interpreted Languages!");
        System.out.println(
                "If you are used to doing compiled languages this might be a shock... but if you hate assembly this is the place to be!");

        System.out.println("\nUnfortunately, if you hate Java, this may suck...");

        System.out.println("Good luck!\n");

        if (crackme()) {
            print_flag();
        }
    }

    private static boolean crackme() {
        Scanner scanner = new Scanner(System.in);
        if (crack_1(scanner) && crack_2(scanner) && crack_3(scanner)) {
            System.out.println("That's correct!");
            scanner.close();
            return true;

        }
        System.out.println("Nope that's not right!");
        scanner.close();
        return false;

    }

    private static boolean crack_1(Scanner scanner) {
        System.out.println(
                "Let's try some hash cracking!! I'll go easy on you the first time. The first hash we are checking is this");
        System.out.println("\t" + secret_1);
        System.out.print("Think you can crack it? If so give me the value that hashes to that!\n\t");

        String input = scanner.nextLine();

        String hash = hash(input, "MD5");

        return hash.compareTo(secret_1) == 0;
    }

    private static boolean crack_2(Scanner scanner) {
        System.out.println("Nice work! One down, two to go ...");

        System.out.print(
                "This next one you don't get to see, if you aren't already digging into the class file you may wanna try that out!\n\t");
        String input = scanner.nextLine();
        return hash(input, "SHA1").compareTo(decrypt(secret_2, key_2)) == 0;

    }

    private static boolean crack_3(Scanner scanner) {
        System.out.print("Nice work! Here's the last one...\n\t");
        String input = scanner.nextLine();

        String hash_3 = hash(input, "SHA-256");
        int[] encrypt_3 = encrypt(hash_3, key_3);
        return Arrays.equals(encrypt_3, secret_3);
    }

    private static int[] encrypt(String input, int key) {
        int[] output = new int[input.length()];
        // System.out.print("{");
        for (int i = 0; i < input.length(); i++) {
            output[i] = (input.charAt(i) ^ key);
            // System.out.print((int) output[i]);
            // if (i + 1 < input.length()) {
            // System.out.print(", ");
            // }
        }
        // System.out.println("};");

        return output;
    }

    private static String decrypt(int[] input, int key) {
        String output = "";
        for (int i = 0; i < input.length; i++) {
            output += (char) ((input[i] ^ key));
        }
        return output;
    }

    private static void print_flag() {
        String filename = "flag.txt";
        try (BufferedReader br = new BufferedReader(new FileReader(filename))) {
            String line;
            while ((line = br.readLine()) != null) {
                System.out.println(line);
            }

        } catch (IOException ex) {
            System.out.println("Could not find file please notify admin");
        }
    }

    public static String hash(String message, String hash_alg) {
        String digest = null;
        try {
            MessageDigest md = MessageDigest.getInstance(hash_alg);
            byte[] hash = md.digest(message.getBytes("UTF-8"));

            // converting byte array to Hexadecimal String
            StringBuilder sb = new StringBuilder(2 * hash.length);
            for (byte b : hash) {
                sb.append(String.format("%02x", b & 0xff));
            }

            digest = sb.toString();
        } catch (Exception e) {
            System.out.println("broke");
        }

        return digest;
    }

}
