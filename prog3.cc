/*********************************************************************
   PROGRAM:    CSCI 330 Assignment 3
   PROGRAMMER: Kevin Miyata
   LOGON ID:   Z1771936
   DUE DATE:   5 October 2016

   FUNCTION:   This program encrypts data from one file and outputs it to another file.
*********************************************************************/

#include "crypt.h"
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {

    // Define a variable for the name of the input file
    char* fileName;

    // Check to see if there is an input value for the file
    if(argc > 1) {
        //set the variable to the file name argument
        fileName = argv[1];
    } else {
        // Otherwise, return an error and exit
        cout << "File not found or is inaccessible" << endl;
        exit(-1);
    }

    // Open the file
    int fileDesc = open(fileName, O_RDONLY, 0755);

    // Check for an error with opening the file and exit if error is found
    if (fileDesc < 0) {
        cout << fileDesc << " isn't a valid output." << endl;
        perror("problem with open");
        exit(-1);
    }

    // Create a buffer for the contents of the file
    char buffer[1024];

    // Define a starting buffer size
    unsigned x = 1024;

    // The number of bytes read
    ssize_t nRead = read(fileDesc, buffer, x);

    // Check for a file read error
    if (nRead < 1) {
        perror("error in reading file");
        exit(1);
    }

    // Check to see if the buffer is full
    while (strlen((char*)buffer) == x) {
        x *= 2;
        char bBuf[x];
        buffer = bBuf;
        nRead = read(fileDesc, buffer, x); //double the buffer until all the data is read
    }

    // Calculate the number of characters in the file
    unsigned numChars = (nRead / sizeof(char));

    // Second buffer for the encrypted data
    char buffer2[numChars];

    // Encrypt the data from buffer and copy it into buffer2
    for (int i = 0; i < numChars; i++) {
        buffer2[i] = encrypt(buffer[i]);
    }

    // Make a pointer to the encrypted buffer
    char* p = (char*)buffer2;

    // Open an output file, create one if it doesn't exist
    int fileDesc2 = open("encryptoutput.txt", O_RDWR | O_CREAT);

    ssize_t nWrite = write(fileDesc2, p, strlen(p)); //write the encrypted data to the output file

    // Print error and exit if the write process fails
    if (nWrite < 0) {
        perror("error writing to file");
        exit(1);
    }

    // Close the input file
    int cl = close(fileDesc);

    // Exit if the file close breaks
    if (cl < 0) {
        perror("error on exiting input file");
        exit(-1);
    }

    // Close the second file
    int cl2 = close(fileDesc2);

    // Print error and exit if the file close fails
    if (cl2 < 0) {
        perror("error on closing output file");
        exit(-1);
    }

    return 0;
}

