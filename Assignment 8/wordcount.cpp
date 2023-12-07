// wordcount.cpp
// Rylan Clavell Caleb Fronek
// 12/7/23
// source file 
//Program to count distinct words in a file and output their frequencies.

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>

int main() {
    // Prompt the user for the filename
    std::string filename;
    std::cout << "Enter the filename: ";
    std::getline(std::cin, filename);

    // Open the file for reading
    std::ifstream infile(filename);
    if (!infile) {
        // Handle file opening error
        std::cerr << "Error opening file: " << filename << std::endl;
        return 1;
    }

    // Map to store word counts
    std::map<std::string, int> wordCount;
    std::string word;

    // Read words from the file and count them
    while (infile >> word) {
        // Increment the word count for each word
        wordCount[word]++;
    }

    // Check for file read errors not related to EOF
    if (!infile.eof()) {
        std::cerr << "Error reading file: " << filename << std::endl;
        return 1;
    }

    // Output the number of distinct words and their counts
    std::cout << "Number of distinct words: " << wordCount.size() << "\n";
    for (const auto &pair : wordCount) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
