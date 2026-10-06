import java.util.*;

public class Code_A2 {

    private static HuffmanNode root;
    private static Map<Character, String> huffmanCodes = new HashMap<>();
    private static Map<Character, Integer> freqMap = new HashMap<>();
    private static String inputText = "";

    // Huffman Node
    static class HuffmanNode implements Comparable<HuffmanNode> {
        char ch;
        int freq;
        HuffmanNode left, right;

        HuffmanNode(char ch, int freq) {
            this.ch = ch;
            this.freq = freq;
        }

        @Override
        public int compareTo(HuffmanNode other) {
            return this.freq - other.freq;
        }
    }

    // Generate Huffman Codes
    private static void generateCodes(HuffmanNode node, String code) {

        if (node == null)
            return;

        // Leaf node
        if (node.left == null && node.right == null) {
            huffmanCodes.put(node.ch, code);
            return;
        }

        generateCodes(node.left, code + "0");
        generateCodes(node.right, code + "1");
    }

    // Build Huffman Tree
    private static void buildHuffmanTree() {

        PriorityQueue<HuffmanNode> pq = new PriorityQueue<>();

        for (Map.Entry<Character, Integer> entry : freqMap.entrySet()) {
            pq.add(new HuffmanNode(entry.getKey(), entry.getValue()));
        }

        while (pq.size() > 1) {

            HuffmanNode left = pq.poll();
            HuffmanNode right = pq.poll();

            HuffmanNode parent = new HuffmanNode(
                '-',
                left.freq + right.freq
            );

            parent.left = left;
            parent.right = right;

            pq.add(parent);
        }

        root = pq.peek();

        huffmanCodes.clear();
        generateCodes(root, "");
    }

    // Display Huffman Codes
    private static void displayCodes() {

        if (huffmanCodes.isEmpty()) {
            System.out.println("No Huffman codes generated yet!");
            return;
        }

        System.out.println("\nCharacter\tFrequency\tHuffman Code");

        for (Map.Entry<Character, String> entry : huffmanCodes.entrySet()) {

            char ch = entry.getKey();

            System.out.println(
                ch + "\t\t" +
                freqMap.get(ch) + "\t\t" +
                entry.getValue()
            );
        }
    }

    // Encode Input Text
    private static void encodeText() {

        if (huffmanCodes.isEmpty()) {
            System.out.println("Please build Huffman Tree first!");
            return;
        }

        StringBuilder encoded = new StringBuilder();

        for (char c : inputText.toCharArray()) {
            encoded.append(huffmanCodes.get(c));
        }

        System.out.println("\nEncoded Text: " + encoded);
    }

    // Main Method
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        while (true) {

            System.out.println("\n=== Huffman Encoding Menu ===");
            System.out.println("1. Enter input string (auto frequency)");
            System.out.println("2. Enter characters with frequencies manually");
            System.out.println("3. Build Huffman Tree & display codes");
            System.out.println("4. Encode the text");
            System.out.println("5. Exit");

            System.out.print("Enter your choice: ");
            int choice = sc.nextInt();
            sc.nextLine();

            switch (choice) {

                // Case 1: Automatically calculate frequency
                case 1:

                    System.out.print("Enter the text: ");
                    inputText = sc.nextLine();

                    freqMap.clear();

                    for (char c : inputText.toCharArray()) {
                        freqMap.put(
                            c,
                            freqMap.getOrDefault(c, 0) + 1
                        );
                    }

                    System.out.println("Frequency table created successfully.");
                    break;

                // Case 2: Manually enter characters and frequencies
                case 2:

                    freqMap.clear();
                    inputText = "";

                    System.out.print("Enter number of characters: ");
                    int n = sc.nextInt();
                    sc.nextLine();

                    for (int i = 0; i < n; i++) {

                        System.out.print("Character " + (i + 1) + ": ");
                        char c = sc.nextLine().charAt(0);

                        System.out.print("Frequency of " + c + ": ");
                        int f = sc.nextInt();
                        sc.nextLine();

                        freqMap.put(c, f);

                        inputText += String.valueOf(c).repeat(f);
                    }

                    System.out.println("Characters and frequencies added successfully.");
                    break;

                // Case 3: Build tree and display codes
                case 3:

                    if (freqMap.isEmpty()) {
                        System.out.println("Please enter input first!");
                    } else {
                        buildHuffmanTree();
                        displayCodes();
                    }

                    break;

                // Case 4: Encode text
                case 4:

                    if (inputText.isEmpty()) {
                        System.out.println("Enter input text first!");
                    } else {
                        encodeText();
                    }

                    break;

                // Case 5: Exit
                case 5:

                    System.out.println("Exiting program. Goodbye!");
                    sc.close();
                    return;

                // Invalid choice
                default:

                    System.out.println("Invalid choice! Please try again.");
            }
        }
    }
}
/* OUTPUT 
C:\Users\HP\OneDrive\Desktop\sem7>javac Code_A2.java

C:\Users\HP\OneDrive\Desktop\sem7>java Code_A2

=== Huffman Encoding Menu ===
1. Enter input string (auto frequency)
2. Enter characters with frequencies manually
3. Build Huffman Tree & display codes
4. Encode the text
5. Exit
Enter your choice: 1
Enter the text: mississippi
Frequency table created successfully.

=== Huffman Encoding Menu ===
1. Enter input string (auto frequency)
2. Enter characters with frequencies manually
3. Build Huffman Tree & display codes
4. Encode the text
5. Exit
Enter your choice: 3

Character       Frequency       Huffman Code
p               2               101
s               4               0
i               4               11
m               1               100

=== Huffman Encoding Menu ===
1. Enter input string (auto frequency)
2. Enter characters with frequencies manually
3. Build Huffman Tree & display codes
4. Encode the text
5. Exit
Enter your choice: 4

Encoded Text: 100110011001110110111

=== Huffman Encoding Menu ===
1. Enter input string (auto frequency)
2. Enter characters with frequencies manually
3. Build Huffman Tree & display codes
4. Encode the text
5. Exit
Enter your choice: 5
Exiting program. Goodbye!

C:\Users\HP\OneDrive\Desktop\sem7>*/