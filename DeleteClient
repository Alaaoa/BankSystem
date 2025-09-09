import java.io.*;
import java.util.*;

class Client {
    String accountNumber;
    String pinCode;
    String name;
    String phone;
    double accountBalance;
    boolean markForDelete = false;

    Client(String accountNumber, String pinCode, String name, String phone, double accountBalance) {
        this.accountNumber = accountNumber;
        this.pinCode = pinCode;
        this.name = name;
        this.phone = phone;
        this.accountBalance = accountBalance;
    }
}

public class BankSystem {

    static final String ClientsFileName = "NEWFILE.txt";

    public static List<String> splitString(String s1, String delim) {
        List<String> parts = new ArrayList<>();
        int pos;
        while ((pos = s1.indexOf(delim)) != -1) {
            String word = s1.substring(0, pos);
            if (!word.isEmpty()) {
                parts.add(word);
            }
            s1 = s1.substring(pos + delim.length());
        }
        if (!s1.isEmpty()) {
            parts.add(s1);
        }
        return parts;
    }

    public static Client convertLineToRecord(String line, String sep) {
        List<String> data = splitString(line, sep);
        return new Client(
            data.get(0),
            data.get(1),
            data.get(2),
            data.get(3),
            Double.parseDouble(data.get(4))
        );
    }

    public static String convertRecordToLine(Client c, String sep) {
        return c.accountNumber + sep +
               c.pinCode + sep +
               c.name + sep +
               c.phone + sep +
               c.accountBalance;
    }

    public static List<Client> loadClientsFromFile(String fileName) {
        List<Client> clients = new ArrayList<>();
        try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {
            String line;
            while ((line = br.readLine()) != null) {
                clients.add(convertLineToRecord(line, "#//#"));
            }
        } catch (IOException e) {
            // file may not exist yet, ignore
        }
        return clients;
    }

    public static void saveClientsToFile(String fileName, List<Client> clients) {
        try (PrintWriter pw = new PrintWriter(new FileWriter(fileName))) {
            for (Client c : clients) {
                if (!c.markForDelete) {
                    pw.println(convertRecordToLine(c, "#//#"));
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void printClientCard(Client c) {
        System.out.println("\nThe following are the client details:");
        System.out.println("Account Number  : " + c.accountNumber);
        System.out.println("Pin Code        : " + c.pinCode);
        System.out.println("Name            : " + c.name);
        System.out.println("Phone           : " + c.phone);
        System.out.println("Account Balance : " + c.accountBalance);
    }

    public static Client findClientByAccountNumber(String accountNumber, List<Client> clients) {
        for (Client c : clients) {
            if (c.accountNumber.equals(accountNumber)) {
                return c;
            }
        }
        return null;
    }

    public static boolean deleteClientByAccountNumber(String accountNumber, List<Client> clients) {
        Client c = findClientByAccountNumber(accountNumber, clients);
        if (c != null) {
            printClientCard(c);
            System.out.print("\nAre you sure you want to delete this client? y/n: ");
            Scanner sc = new Scanner(System.in);
            String ans = sc.nextLine();
            if (ans.equalsIgnoreCase("y")) {
                c.markForDelete = true;
                saveClientsToFile(ClientsFileName, clients);
                System.out.println("\nClient Deleted Successfully.");
                return true;
            }
        } else {
            System.out.println("\nClient with Account Number (" + accountNumber + ") is Not Found!");
        }
        return false;
    }

    public static String readClientAccountNumber() {
        Scanner sc = new Scanner(System.in);
        System.out.print("\nPlease enter Account Number? ");
        return sc.nextLine();
    }

    public static void main(String[] args) {
        List<Client> clients = loadClientsFromFile(ClientsFileName);
        String accountNumber = readClientAccountNumber();
        deleteClientByAccountNumber(accountNumber, clients);
    }
}
