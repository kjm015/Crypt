/****************************************************************
   FILE:      crypt.cc
   AUTHOR:    Kevin Miyata
   LOGON ID:  Z1771936
   DUE DATE:  5 October 2016

   PURPOSE:   This file contains the function definitions for the encryption
****************************************************************/

#include "crypt.h"

using namespace std;

/****************************************************************
   FUNCTION:   char encrypt(const char& x)

   ARGUMENTS:  const char& x | the character to be encrypted

   RETURNS:    the encrypted character

   NOTES:      This function tests its parameter to see if it is an alphabetic character, then
                encrypts it based on its case.
****************************************************************/
char encrypt(const char& x) {
    // Check to see if the character is a letter
    if (isalpha(x)) {
        // If the character is a letter, check for its ASCII value and decide which encryption function to use
        if (x >= 97 and x <= 122) {
            return encryptLower(x);
        } else {
            return encryptUpper(x);
        }
    } else {
        // If x is not a letter, do not modify it
        return x;
    }
}

/****************************************************************
   FUNCTION:   char encryptUpper(const char& x)

   ARGUMENTS:  const char& x | the character to be encrypted

   RETURNS:    (char)fun | the encrypted character

   NOTES:      This function encrypts an uppercase character to its
                ASCII value + 13, wrapping around if necessary.
****************************************************************/
char encryptUpper(const char& x) {
    // Adds 13 to the ASCII value
    int fun = x + 13;

    // Wrap around if necessary
    if (fun > 90)
        fun = (fun % 26) + 65;

    // Return the encrypted character
    return (char)fun;
}

/****************************************************************
   FUNCTION:   char encryptLower(const char& x)

   ARGUMENTS:  const char& x | the character to be encrypted

   RETURNS:    (char)fun | the encrypted character

   NOTES:      This function encrypts an lowercase character to its
                ASCII value + 13, wrapping around if necessary.
****************************************************************/
char encryptLower(const char& x) {
    // Add 13 to the ASCII value
    int fun = x + 13;

    // Wrap around if necessary
    if (fun > 122)
        fun = (fun % 26) + 97;

    // Return the encrypted character
    return (char)fun;
}

