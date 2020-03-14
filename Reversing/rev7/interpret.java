
import java.io.*;
import java.util.Scanner;

import java.security.MessageDigest;

public class interpret {
    public static String hash_1 = "d5c67e2fc5f5f155dff8da4bdc914f41"; // masterchief
    public static String hash_2 = "264212deff89ade15661a59e7b632872d858f2c6"; // princesspeach
    public static String hash_3 = "5ebb49e499a6613e832e433a2722edd0d2947d56fdb4d684af0f06c631fdf633"; // solidsnake

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

        System.out.println(
                "Let's try some hash cracking!! I'll go easy on you the first time. The first hash we are checking is this");
        System.out.println("\t" + hash_1);
        System.out.print("Think you can crack it? If so give me the value that hashes to that!\n\t");

        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();

        String hash = hash(input, "MD5");

        if (hash.compareTo(hash_1) == 0) {
            System.out.println("Nice work! One to go ... many to come");

            System.out.print(
                    "This next one you don't get to see, if you aren't already digging into the class file you may wanna try that out!\n\t");
            input = scanner.nextLine();

            if (hash(input, "SHA1").compareTo(hash_2) == 0) {
                System.out.println("Nice work!");

                System.out.print("Alright last one...\n\t");
                input = scanner.nextLine();

                if (hash(input, "SHA-256").compareTo(hash_3) == 0) {
                    System.out.println("That's correct!");
                    scanner.close();
                    return true;
                }
            }
        }

        scanner.close();
        return false;
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
