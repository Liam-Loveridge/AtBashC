/*
    AtBashC - A program that uses the Atbash Cipher in C 
    Program by Liam Loveridge
    Date: June 2017
*/

// Libs needed for the program 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

//Const for size of the arrays
const int SIZE = 1000; 

// Encryption Function for Files 
void EncF(char *inpath, char *outpath, char call)
{
    //Opens files 
    FILE *srcFile = fopen(inpath, "r");
    FILE *snkFile = fopen(outpath, "w");
    
    //Arrays that hold the decrypted and encrypted data
    char dataD[SIZE] = {'\0'}; 
    char dataE[SIZE] = {'\0'}; 

    //Gets the decrypted data from the src file 
    fgets(dataD, SIZE, srcFile); 

    /* These arrays hold the alphabet

        ralpha is the reversed alphabet - This is needed as Atbash uses this to decrypt/encrypt the data
        alphaL/U is either Uppercase or lowercase
    */ 
    char alphaU[26] = {'A','B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U','V','W', 'X', 'Y', 'Z'};
    char alphaL[26] = {'a','b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u','v','w', 'x', 'y', 'z'};

    char rAlphaU[26] = {'Z', 'Y', 'X', 'W', 'V', 'U', 'T', 'S', 'R', 'Q', 'P', 'O', 'N', 'M', 'L', 'K', 'J', 'I', 'H', 'G', 'F', 'E', 'D', 'C', 'B', 'A'};
    char rAlphaL[26] = {'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q', 'p', 'o', 'n', 'm', 'l', 'k', 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'};

    // Temp variable and counter variables 
    char enc; 
    int n, i; 

    // Runs a for loop while running through the length of the data given. It picks out each character each iteration  
    for(i = 0; i < (strlen(dataD)); i++)
    {   
        n = 0; 

        //If the character is between 65 and 90 it must be an uppercase letter 
        if(dataD[i] >= 65 && dataD[i] <= 90)
        {
            //Linear search for index
            while(alphaU[n] != dataD[i])
            {
                n++;
            }

            // Uses the rAlpha array to find the substituted character
            dataE[i] = rAlphaU[n]; 
        }
        else
        {
            // If the character is between 97 and 122 it must be a lowercase letter
            if(dataD[i] >= 97 && dataD[i] <= 122)
            {
                //Linear search for index
                while(alphaL[n] != dataD[i])
                {
                    n++;
                }

                // Uses the rAlpha array to find the substituted character
                dataE[i] = rAlphaL[n]; 
            }
            else
            {
                /* 
                    This program does not encrypt other characters than the alphabet
                    Inputs the data straight into the Temp variable
                */
                dataE[i] = dataD[i];
            }
    
        }
    }

    // If the call variable is called it will print out data to the console 
    if(call == 'Y')
    {
        printf("DECRYPTED DATA: %s \n", dataD); 
        printf("ENCRYPTED DATA: %s \n", dataE); 
    }

    // Writes to outpath
    fprintf(snkFile, "%s", dataE);

    // Closes the files 
    fclose(srcFile);
    fclose(snkFile);

}

// Decryption Function for Files 
void DecF(char *inpath, char *outpath, char call)
{
    // Files that are going to be read
    FILE *srcFile = fopen(inpath, "r");
    FILE *snkFile = fopen(outpath, "w");
    
    // Array which are going to be used to hold the data; 
    char dataD[SIZE] = {'\0'}; 
    char dataE[SIZE] = {'\0'}; 

    // Reads data into the dataE from file 
    fgets(dataE, SIZE, srcFile); 

    // Arrays used in the function
    char alphaU[26] = {'A','B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U','V','W', 'X', 'Y', 'Z'};
    char alphaL[26] = {'a','b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u','v','w', 'x', 'y', 'z'};

    char rAlphaU[26] = {'Z', 'Y', 'X', 'W', 'V', 'U', 'T', 'S', 'R', 'Q', 'P', 'O', 'N', 'M', 'L', 'K', 'J', 'I', 'H', 'G', 'F', 'E', 'D', 'C', 'B', 'A'};
    char rAlphaL[26] = {'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q', 'p', 'o', 'n', 'm', 'l', 'k', 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'};

    int n, i; 

    // Runs through the length of the string from dataE
    for(i = 0; i < (strlen(dataE)); i++)
    {   
        n = 0; 

        // Uppercase
        if(dataE[i] >= 65 && dataE[i] <= 90)
        {
            //Linear search for index
            while(rAlphaU[n] != dataE[i])
            {
                n++;
            }

            // Substitues the encrypted for its decrypted counterpart
            dataD[i] = alphaU[n]; 
        }
        else
        {
            // Lowercase
            if(dataE[i] >= 97 && dataE[i] <= 122)
            {
                // Linear search for index
                while(rAlphaL[n] != dataE[i])
                {
                    n++;
                }

                // Substitues the encrypted for its decrypted counterpart
                dataD[i] = alphaL[n]; 
            }
            else
            {
                // Only works with letters
                dataD[i] = dataE[i];
            }
        }
    }

    // If the call variable is called it will print the data to the console 
    if(call == 'Y')
    {
        printf("ENCRYPTED DATA: %s \n", dataE); 
        printf("DECRYPTED DATA: %s \n", dataD); 
    }

    // Writes to outpath
    fprintf(snkFile, "%s", dataD);

    // Closes the files 
    fclose(srcFile);
    fclose(snkFile);

}

// Modules without using a file 

// Encryption Function without files 
void Enc(char *dataD, char *dataE, char call)
{

    // Variables used in the function 
    char alphaU[26] = {'A','B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U','V','W', 'X', 'Y', 'Z'};
    char alphaL[26] = {'a','b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u','v','w', 'x', 'y', 'z'};

    char rAlphaU[26] = {'Z', 'Y', 'X', 'W', 'V', 'U', 'T', 'S', 'R', 'Q', 'P', 'O', 'N', 'M', 'L', 'K', 'J', 'I', 'H', 'G', 'F', 'E', 'D', 'C', 'B', 'A'};
    char rAlphaL[26] = {'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q', 'p', 'o', 'n', 'm', 'l', 'k', 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'};

    int n, i; 

    // Takes the decrypted message and runs through its length
    for(i = 0; i < (strlen(dataD)); i++)
    {   
        n = 0; 

        // For uppercase
        if(dataD[i] >= 65 && dataD[i] <= 90)
        {
            // Linear search for index
            while(alphaU[n] != dataD[i])
            {
                n++;
            }

            // Substitutes in the encrypted character counterpart 
            dataE[i] = rAlphaU[n]; 
        }
        else
        {   
            // For lowercase 
            if(dataD[i] >= 97 && dataD[i] <= 122)
            {
                //Linear search for index
                while(alphaL[n] != dataD[i])
                {
                    n++;
                }

                // Substitutes in the encrypted character counterpart 
                dataE[i] = rAlphaL[n]; 
            }
            else
            {
                // Only works for letters
                dataE[i] = dataD[i];
            }
    
        }
    }

    // If Call is called it will output the data to console 
    if(call == 'Y')
    {
        printf("DECRYPTED DATA: %s \n", dataD); 
        printf("ENCRYPTED DATA: %s \n", dataE);
    }
}

void Dec(char *dataE char *dataD, char call)
{
    // Variables used
    char alphaU[26] = {'A','B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U','V','W', 'X', 'Y', 'Z'};
    char alphaL[26] = {'a','b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u','v','w', 'x', 'y', 'z'};

    char rAlphaU[26] = {'Z', 'Y', 'X', 'W', 'V', 'U', 'T', 'S', 'R', 'Q', 'P', 'O', 'N', 'M', 'L', 'K', 'J', 'I', 'H', 'G', 'F', 'E', 'D', 'C', 'B', 'A'};
    char rAlphaL[26] = {'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q', 'p', 'o', 'n', 'm', 'l', 'k', 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'};

    int n, i; 

    // Runs through the length of the encrypted data 
    for(i = 0; i < (strlen(dataE)); i++)
    {   
        n = 0; 
        
        // Uppercase
        if(dataE[i] >= 65 && dataE[i] <= 90)
        {
            //Linear search for index
            while(rAlphaU[n] != dataE[i])
            {
                n++;
            }

            // Substitues in the decrypted character 
            dataD[i] = alphaU[n]; 
        }
        else
        {
            // For lowercase 
            if(dataE[i] >= 97 && dataE[i] <= 122)
            {
                //Linear search for index
                while(rAlphaL[n] != dataE[i])
                {
                    n++;
                }

                // Substitues in the decrypted character
                dataD[i] = alphaL[n]; 
            }
            else
            {
                // Only works for letters 
                dataD[i] = dataE[i];
            }
        }
    }

    // If call is true it will print to the console 
    if(call == 'Y')
    {
        printf("ENCRYPTED DATA: %s \n", dataE); 
        printf("DECRYPTED DATA: %s \n", dataD); 
    }
  
}

// Main function
int main(int argc, char *argv[]) 
{   
    // Variables used 
    char ch, r;
    char call = 'N'; 
    char in[SIZE] = {'\0'};
    char out[SIZE] = {'\0'};

    int i; 
    int off = 0; 
    
    // If the user has not used the cmd line arguments it will run the usr through satisfying the parameters for the functions 
    if(argc == 1)
    {
        printf("Welcome to the Atbash Program. You can encrypt and decrypt files that use the Atbash cipher! \n"); 
        
        jump: 
        printf("Would you like to read and write to files? (Y for Yes or N for No): ");
        scanf("%c%*c", &r);
        r = toupper(r);

        if(r == 'Y')
        {
            printf("Would you like to encrypt or decrypt your file? (Type e for encrypt or d for decrypt): "); 
            scanf("%c%*c", &ch);    
            ch = tolower(ch);

            printf("What is the name of the file in which you want to either encrypt or decrypt? (You must name the path if not executed inside the same folder as the program): ");
            fgets(in, SIZE, stdin);
            in[(strlen(in)- 1)] = '\0';

            printf("What is the name of the file in which you want the encrypted or decrypted data to go? (You must name the path if not executed inside the same folder as the program): ");
            fgets(out, SIZE, stdin);
            out[(strlen(out)- 1)] = '\0';  

            printf("Would you like to see the message in the console after the program has done it's magic? (Y for Yes or N for No): ");
            scanf("%c%*c", &call);
            call = toupper(call);   
        }
        else
        {
            if(r == 'N')
            {
                printf("Please enter your message: ");
                fgets(in, SIZE, stdin);
                in[(strlen(in)-1)] = '\0';

                printf("Would you like to encrypt or decrypt this message. (Press e to encrypt or d to decrypt): ");
                scanf("%c%*c", &ch); 
                ch = tolower(ch); 

                call = 'Y'; 

                off = 1; 
            }
            else
            {
                printf("You haven't entered in the correct type: TRY AGAIN!"); 
                goto jump;
            }

        }
    }

    //For the CMD line arguments 

    for(i = 0; i < argc; i++)
    {
        //Need if-else statements due to '-' in the cmdline arguments 

        if(strcmp(argv[i], "-d") == 0)
        {
            ch = 'd';
        }
        else
        {
            if(strcmp(argv[i], "-e") == 0)
            {
                ch = 'e';
            }
            else 
            {
                if(strcmp(argv[i], "-f") == 0)
                {
                    strcpy(in, argv[i + 1]); 
                    strcpy(out, argv[i + 2]); 
                }
                else
                {
                    if(strcmp(argv[i], "-c") == 0)
                    {
                        call = 'Y'; 
                    }
                    else 
                    {
                        if(strcmp(argv[i], "-o") == 0)
                        {
                            printf("Please enter your message: ");
                            fgets(in, SIZE, stdin);
                            in[(strlen(in)-1)] = '\0';
                            call = 'Y'; 
                            off = 1; 
                        }
                        else
                        {
                             if(strcmp(argv[i], "-h") == 0)
                            {
                                printf("HELP MODE: \n");
                                printf("Encrypt [-e] \n");
                                printf("Decrypt [-d] \n"); 
                                printf("Transfer to file [-f Source Destination] \n");
                                printf("To print the results in the console [-c] \n"); 
                                printf("To not use files [-o] \n");
                                printf("Help [-h] \n"); 
                            }
                        }
                    }
                }
            }  
        }
    }

    // Validation

    if(ch == '\0')
    {
        printf("Would you like to encrypt or decrypt your file? (Type e for encrypt or d for decrypt): "); 
        scanf("%c%*c", &ch);
        ch = tolower(ch); 
    }

    jump1:
    if(!(in[0]))
    {
        printf("Would you like to use files? (Y for Yes and N for No): ");
        scanf("%c%*c", &r); 
        r = toupper(r);

        if(r == 'N')
        {
            printf("Please enter your message: ");
            fgets(in, SIZE, stdin);
            in[(strlen(in)-1)] = '\0';
            off = 1; 
        }
        else 
        {
            if(r == 'Y')
            {
                printf("What is the name of the file in which you want to either encrypt or decrypt? (You must name the path if not executed inside the same folder as the program): ");
                fgets(in, SIZE, stdin);
                in[(strlen(in)- 1)] = '\0';

                if(!(out[0]))
                {
                    printf("What is the name of the file in which you want the encrypted or decrypted data to go? (You must name the path if not executed inside the same folder as the program): ");
                    fgets(out, SIZE, stdin);
                    out[(strlen(out)- 1)] = '\0'; 
                }
            }
            else
            {
                printf("ERROR: Incorrect response. Please try again! \n");
                goto jump1; 
            }
        }
    }
    

    //To actually call the functions

    if(off == 1)
    {
        if(ch == 'e')
        {
            Enc(in, out, call); 
        }
        else
        {
           Dec(in, out, call);  
        }
    }
    else 
    {
        if(ch == 'e')
        {
            EncF(in, out, call);
        }
        else 
        {
            DecF(in, out, call); 
        }
    }

    // Allows usr to repeat the whole program 
    printf("Would you like to use this program again? (Y for Yes or anyother key for No): ");
    scanf("%c%*c", &r);

    r = toupper(r);

    if(r == 'Y')
    {
        goto jump;
    }


    return 0; 
