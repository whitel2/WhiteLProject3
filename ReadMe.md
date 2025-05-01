**Building the Huffman Tree**
In order to create the tree properly, you will start with a string to encode, a binary tree, and a priority queue.

1. Analyze the string, calculate the frequencies of the characters, and remove duplicates.
2. Create a node 'n' that stores the character and the frequency.
3. Sort the nodes in ascending order by frequency and store them in a queue 'q'. This is technically a priority queue with low numbers at the top.
4. Each node with a character will become a leaf node in the tree.
5. To build the tree, create an internal node 'n' and assign the two lowest frequencies to the left and right children. The value of the internal node is the sum of the children, with a special character (we can use the $).
6. Insert 'n' into 'q' in the correct place.
7. Insert 'n' into 't'.
8. Repeat steps 5 - 7 until there are no more nodes are left in q.

**Encoding**
1. You will traverse the tree to each leaf node
2. Create the encoding by assigning every left branch a value of '0' and every right branch a value of '1'
3. For each character, you will need the character and the binary code that traverses the path. You do not include internal nodes.

**Decoding**
1. Based on the Binary Code, follow the path to the leaf (0 to the left, 1 to the right) until a leaf node is reached.
2. Append the character to the end of the string.
3. Repeat until all digits from the encoding have been used.

**Project Requirements**
The user must be able to enter a single string to be encoded.
Each unique character must be placed in a node with total frequency.
The nodes must be entered into a priority queue.
The subsequent tree must be built as described previously.
The program must print out the unique characters with their corresponding code.
The program must print the encoded message.
The program must use the encoded message to decode and display the message.
Submit the Final Project as a link to your GitHub repository - again, make me a collaborator.
