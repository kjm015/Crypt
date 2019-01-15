/****************************************************************
   FILE:      crypt.h
   AUTHOR:    Kevin Miyata
   LOGON ID:  Z1771936
   DUE DATE:  5 October 2016

   PURPOSE:   This header file contains function declarations and libraries for the encryption process
****************************************************************/

#ifndef CRYPT_H
#define CRYPT_H

#include <fstream>
#include <cstdlib>
#include <ctype.h>
#include <cstring>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

char encrypt(const char&);
char encryptUpper(const char&);
char encryptLower(const char&);

#endif
