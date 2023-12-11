//lab6.h HEADER FILE
#include <stdio.h>
#ifndef LAB6_H
#define LAB6_H
// Function declarations
//write "string" in file
writeToFile(string);

//  "fname" check
checkFileExistence(fname);

// "fname"  read
readFromFile(fname);
#endif
//lab6.c SOURCE FILE
#include <stdio.h>
#include "lab6.h"
// Function to write a string 'th' to the file 'fname'
void writeToFile(char *th,const char *fname ) {
    FILE *fp;
    
    // Open the file in append mode
    fp = fopen(fname, "a");
    
    // Check if the file is successfully opened
    if (fp != NULL) {
        // Write the string to the file
        fprintf(fp, "%s", th);
        
        // Close the file after writing
        fclose(fp);
    } else {
        // Handle the case where the file couldn't be opened
        printf("Error opening the file for writing.\n");
    }
}

// Function to read a string from the specified file 'fname'
char* readFromFile(const char *fname) {
    char Mano[300];
    FILE *f;
    
    // Open the file in read mode
    f = fopen(fname, "r");
    
    // Check if the file is successfully opened
    if (f != NULL) {
        // Read a string from the file
        fscanf(f, "%s", Mano);
        
        // Print the string read from the file
        printf("%s\n", Mano);
        
        // Close the file after reading
        fclose(f);
    } else {
        // Handle the case where the file couldn't be opened
        printf("Error opening the file for reading.\n");
    }
    
    // Return the read string
    return Mano;
}

// Function to check the existence of the specified file 'fname'
int checkFileExistence(const char *fname) {
    FILE *file;

    // Try to open the file in read mode
    file = fopen(fname, "r");

    // Check if file exists
    if (file != NULL) {
        printf("File %s exists.\n", fname);

        // Close the file after checking
        fclose(file);
    } else {
        printf("File %s does not exist.\n", fname);
    }

    return 0;
}
//lab6code.c MAIN PROGRAM
#include <stdio.h>
#include "lab6.h"
int main() {
    writeToFile("Hello, this is a test string.");

    // Replace "fname" with the actual file path you want to check
    checkFileExistence("lab6.txt");

    // Replace "fname" with the actual file path you want to read
    char *readString = readFromFile("lab6.txt");
    
    return 0;
}
