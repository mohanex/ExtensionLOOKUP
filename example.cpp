/*
*This example code is written by AFASSI Mohamed
*
*It uses the Dirent library to search for files with specific extension in a directory
*In this example I just print out the files found but instead you could manipulate them.
*For i.e. I used this script in a project to find csv files and format them into Binary files
*
*This code is free of Licences, you can copy it, use it, modify it but alwayd keep on this header.
*/


#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <dirent.h>
#include <stdio.h>
#include <cstring>
#include <string.h>

using namespace std;

int main() {
    string directory, extension;
    string csvFiles[50];
    string csvFiles_output[50];
    int i = 0;
    string csv_extension = ".csv";
    string bin_extension = ".bin";

    DIR* di;
    char* ptr1, * ptr2;
    int retn;
    struct dirent* dir;

    cout << "What extension you search for? ";
    cin >> extension;

    cout << "Directory where you want to search for " + extension + " extension : ";
    cin >> directory;

    int length = directory.length();
    char* char_array = new char[length + 1];
    strcpy(char_array, directory.c_str());

    int length2 = extension.length();
    char* char_array2 = new char[length2 + 1];
    strcpy(char_array2, extension.c_str());

    di = opendir(char_array); //specify the directory name
    if (di)
    {
        while ((dir = readdir(di)) != NULL)
        {
            ptr1 = strtok(dir->d_name, ".");
            ptr2 = strtok(NULL, ".");
            if (ptr2 != NULL)
            {
                retn = strcmp(ptr2, char_array2);
                if (retn == 0)
                {
                    cout << ptr1 << "\n";
                }
            }
            i++;
        }
        closedir(di);
    }

    return 0;
}
