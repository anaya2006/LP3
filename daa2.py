import heapq
from collections import Counter

# Huffman Node
class HuffmanNode:
    def __init__(self, ch, freq):
        self.ch = ch
        self.freq = freq
        self.left = None
        self.right = None

    def __lt__(self, other):
        return self.freq < other.freq


root = None
huffmanCodes = {}
freqMap = {}
inputText = ""


# Generate Huffman Codes
def generateCodes(node, code):

    if node is None:
        return

    # Leaf node
    if node.left is None and node.right is None:

        # Special case: only one unique character
        if code == "":
            code = "0"

        huffmanCodes[node.ch] = code
        return

    generateCodes(node.left, code + "0")
    generateCodes(node.right, code + "1")


# Build Huffman Tree
def buildHuffmanTree():

    global root, huffmanCodes

    pq = []

    # Create nodes
    for ch, freq in freqMap.items():
        heapq.heappush(pq, HuffmanNode(ch, freq))

    # Build tree
    while len(pq) > 1:

        left = heapq.heappop(pq)
        right = heapq.heappop(pq)

        parent = HuffmanNode('-', left.freq + right.freq)

        parent.left = left
        parent.right = right

        heapq.heappush(pq, parent)

    root = pq[0]

    huffmanCodes.clear()

    generateCodes(root, "")


# Display Huffman Codes
def displayCodes():

    print("\nCharacter\tFrequency\tHuffman Code")

    for ch, code in huffmanCodes.items():

        print(f"{ch}\t\t{freqMap[ch]}\t\t{code}")


# Encode Text
def encodeText():

    encoded = ""

    for c in inputText:
        encoded += huffmanCodes[c]

    print("\nOriginal Text :", inputText)
    print("Encoded Text  :", encoded)


# Main
def main():

    global inputText, freqMap

    while True:

        print("\n=== Huffman Encoding Menu ===")
        print("1. Enter input string")
        print("2. Build Huffman Tree & display codes")
        print("3. Encode the text")
        print("4. Exit")

        choice = int(input("Enter your choice: "))

        # Enter input
        if choice == 1:

            inputText = input("Enter the text: ")

            if inputText == "":
                print("Input cannot be empty!")
                continue

            freqMap = Counter(inputText)

            print("\nFrequency table created successfully.")

            print("\nCharacter\tFrequency")

            for ch, freq in freqMap.items():
                print(f"{ch}\t\t{freq}")


        # Build Huffman Tree
        elif choice == 2:

            if not freqMap:
                print("Please enter input text first!")
            else:

                buildHuffmanTree()

                print("\nHuffman Codes:")
                displayCodes()


        # Encode
        elif choice == 3:

            if not inputText:
                print("Please enter input text first!")

            elif not huffmanCodes:
                print("Please build Huffman Tree first!")

            else:
                encodeText()


        # Exit
        elif choice == 4:

            print("Exiting program. Goodbye!")
            break


        else:

            print("Invalid choice! Please try again.")


if __name__ == "__main__":
    main()