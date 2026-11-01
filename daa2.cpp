#include <iostream>
#include <map>
#include <queue>
#include <string>
using namespace std;

// Huffman Node
struct HuffmanNode {
    char ch;
    int freq;
    HuffmanNode *left, *right;

    HuffmanNode(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

// Comparator for Priority Queue
struct Compare {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->freq > b->freq;
    }
};

HuffmanNode* root = nullptr;
map<char, string> huffmanCodes;
map<char, int> freqMap;
string inputText = "";

// Generate Huffman Codes
void generateCodes(HuffmanNode* node, string code) {
    if (node == nullptr)
        return;

    // Leaf node
    if (node->left == nullptr && node->right == nullptr) {
        huffmanCodes[node->ch] = code;
        return;
    }

    generateCodes(node->left, code + "0");
    generateCodes(node->right, code + "1");
}

// Build Huffman Tree
void buildHuffmanTree() {

    priority_queue<HuffmanNode*,
                   vector<HuffmanNode*>,
                   Compare> pq;

    // Create nodes for each character
    for (auto x : freqMap) {
        pq.push(new HuffmanNode(x.first, x.second));
    }

    // Build tree
    while (pq.size() > 1) {

        HuffmanNode* left = pq.top();
        pq.pop();

        HuffmanNode* right = pq.top();
        pq.pop();

        HuffmanNode* parent =
            new HuffmanNode('-', left->freq + right->freq);

        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    root = pq.top();

    huffmanCodes.clear();

    generateCodes(root, "");
}

// Display Huffman Codes
void displayCodes() {

    if (huffmanCodes.empty()) {
        cout << "No Huffman codes generated yet!\n";
        return;
    }

    cout << "\nCharacter\tFrequency\tHuffman Code\n";

    for (auto x : huffmanCodes) {

        char ch = x.first;

        cout << ch << "\t\t"
             << freqMap[ch] << "\t\t"
             << x.second << endl;
    }
}

// Encode Text
void encodeText() {

    if (huffmanCodes.empty()) {
        cout << "Please build Huffman Tree first!\n";
        return;
    }

    string encoded = "";

    for (char c : inputText) {
        encoded += huffmanCodes[c];
    }

    cout << "\nEncoded Text: " << encoded << endl;
}

// Main
int main() {

    int choice;

    while (true) {

        cout << "\n=== Huffman Encoding Menu ===\n";
        cout << "1. Enter input string (auto frequency)\n";
        cout << "2. Enter characters with frequencies manually\n";
        cout << "3. Build Huffman Tree & display codes\n";
        cout << "4. Encode the text\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            // Automatically calculate frequency
            case 1: {

                cout << "Enter the text: ";
                cin.ignore();
                getline(cin, inputText);

                freqMap.clear();

                for (char c : inputText) {
                    freqMap[c]++;
                }

                cout << "Frequency table created successfully.\n";

                break;
            }

            // Manually enter characters and frequencies
            case 2: {

                freqMap.clear();
                inputText = "";

                int n;

                cout << "Enter number of characters: ";
                cin >> n;

                for (int i = 0; i < n; i++) {

                    char c;
                    int f;

                    cout << "Character " << i + 1 << ": ";
                    cin >> c;

                    cout << "Frequency of " << c << ": ";
                    cin >> f;

                    freqMap[c] = f;

                    // Create input text using the given frequency
                    for (int j = 0; j < f; j++) {
                        inputText += c;
                    }
                }

                cout << "Characters and frequencies added successfully.\n";

                break;
            }

            // Build tree
            case 3:

                if (freqMap.empty()) {
                    cout << "Please enter input first!\n";
                }
                else {
                    buildHuffmanTree();
                    displayCodes();
                }

                break;

            // Encode
            case 4:

                if (inputText.empty()) {
                    cout << "Enter input text first!\n";
                }
                else {
                    encodeText();
                }

                break;

            // Exit
            case 5:

                cout << "Exiting program. Goodbye!\n";
                return 0;

            default:

                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}