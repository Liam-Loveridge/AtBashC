#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>


void EncF(char *inpath, char *outpath, char call)
{
    FILE *srcFile = fopen(inpath, "r");
    FILE *snkFile = fopen(outpath, "w");
    
    char dataD[128] = {'\0'}; 
    char dataE[128] = {'\0'}; 

    fgets(dataD, 128, srcFile); 

    char alphaU[26] = {'A','B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U','V','W', 'X', 'Y', 'Z'};
    char alphaL[26] = {'a','b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u','v','w', 'x', 'y', 'z'};

    char ralphaU[26] = {'Z', 'Y', 'X', 'W', 'V', 'U', 'T', 'S', 'R', 'Q', 'P', 'O', 'N', 'M', 'L', 'K', 'J', 'I', 'H', 'G', 'F', 'E', 'D', 'C', 'B', 'A'};
    char ralphaL[26] = {'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q', 'p', 'o', 'n', 'm', 'l', 'k', 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'};

    char enc;
    int n, i; 

    for(i = 0; i < (strlen(dataD)); i++)
    {   
        n = 0; 
        if(dataD[i] >= 65 && dataD[i] <= 90)
        {
            //Linear search for index
            while(alphaU[n] != dataD[i])
            {
                n++;
            }

            enc = ralphaU[n]; 
        }
        else
        {
            if(dataD[i] >= 97 && dataD[i] <= 122)
            {
                //Linear search for index
                while(alphaL[n] != dataD[i])
                {
                    n++;
                }

                enc = ralphaL[n]; 
            }
            else
            {
                enc = dataD[i];
            }
    
        }

        dataE[i] = enc; 
    }

    
    if(call == 'Y')
    {
        printf("DECRYPTED DATA: %s \n", dataD); 
        printf("ENCRYPTED DATA: %s \n", dataE); 
    }

    //Writes to outpath
    fprintf(snkFile, "%s \n", dataE);

    fclose(srcFile);
    fclose(snkFile);

}

void DecF(char *inpath, char *outpath, char call)
{
    FILE *srcFile = fopen(inpath, "r");
    FILE *snkFile = fopen(outpath, "w");
    
    char dataD[128] = {'\0'}; 
    char dataE[128] = {'\0'}; 

    fgets(dataE, 128, srcFile); 

    char alphaU[26] = {'A','B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U','V','W', 'X', 'Y', 'Z'};
    char alphaL[26] = {'a','b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u','v','w', 'x', 'y', 'z'};

    char ralphaU[26] = {'Z', 'Y', 'X', 'W', 'V', 'U', 'T', 'S', 'R', 'Q', 'P', 'O', 'N', 'M', 'L', 'K', 'J', 'I', 'H', 'G', 'F', 'E', 'D', 'C', 'B', 'A'};
    char ralphaL[26] = {'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q', 'p', 'o', 'n', 'm', 'l', 'k', 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'};

    int n, i; 

    for(i = 0; i < (strlen(dataE)); i++)
    {   
        n = 0; 
        if(dataE[i] >= 65 && dataE[i] <= 90)
        {
            //Linear search for index
            while(ralphaU[n] != dataE[i])
            {
                n++;
            }

            dataD[i] = alphaU[n]; 
        }
        else
        {
            if(dataE[i] >= 97 && dataE[i] <= 122)
            {
                //Linear search for index
                while(ralphaL[n] != dataE[i])
                {
                    n++;
                }

                dataD[i] = alphaL[n]; 
            }
            else
            {
                dataD[i] = dataE[i];
            }
        }
    }

    if(call == 'Y')
    {
        printf("ENCRYPTED DATA: %s \n", dataE); 
        printf("DECRYPTED DATA: %s \n", dataD); 
    }

    //Writes to outpath
    fprintf(snkFile, "%s", dataD);

    fclose(srcFile);
    fclose(snkFile);

}

//Modules without using a file 
void Enc(char *dataD, char *dataE, char call)
{

    char alphaU[26] = {'A','B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U','V','W', 'X', 'Y', 'Z'};
    char alphaL[26] = {'a','b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u','v','w', 'x', 'y', 'z'};

    char ralphaU[26] = {'Z', 'Y', 'X', 'W', 'V', 'U', 'T', 'S', 'R', 'Q', 'P', 'O', 'N', 'M', 'L', 'K', 'J', 'I', 'H', 'G', 'F', 'E', 'D', 'C', 'B', 'A'};
    char ralphaL[26] = {'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q', 'p', 'o', 'n', 'm', 'l', 'k', 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'};

    int n, i; 

    for(i = 0; i < (strlen(dataD)); i++)
    {   
        n = 0; 
        if(dataD[i] >= 65 && dataD[i] <= 90)
        {
            //Linear search for index
            while(alphaU[n] != dataD[i])
            {
                n++;
            }

            dataE[i] = ralphaU[n]; 
        }
        else
        {
            if(dataD[i] >= 97 && dataD[i] <= 122)
            {
                //Linear search for index
                while(alphaL[n] != dataD[i])
                {
                    n++;
                }

                 dataE[i] = ralphaL[n]; 
            }
            else
            {
                 dataE[i] = dataD[i];
            }
    
        }
    }

    if(call == 'Y')
    {
        printf("DECRYPTED DATA: %s \n", dataD); 
        printf("ENCRYPTED DATA: %s \n", dataE);
    }
}

void Dec(char *dataE, char *dataD, char call)
{
    char alphaU[26] = {'A','B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U','V','W', 'X', 'Y', 'Z'};
    char alphaL[26] = {'a','b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u','v','w', 'x', 'y', 'z'};

    char ralphaU[26] = {'Z', 'Y', 'X', 'W', 'V', 'U', 'T', 'S', 'R', 'Q', 'P', 'O', 'N', 'M', 'L', 'K', 'J', 'I', 'H', 'G', 'F', 'E', 'D', 'C', 'B', 'A'};
    char ralphaL[26] = {'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q', 'p', 'o', 'n', 'm', 'l', 'k', 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'};

    int n, i; 

    for(i = 0; i < (strlen(dataE)); i++)
    {   
        n = 0; 
        if(dataE[i] >= 65 && dataE[i] <= 90)
        {
            //Linear search for index
            while(ralphaU[n] != dataE[i])
            {
                n++;
            }

            dataD[i] = alphaU[n]; 
        }
        else
        {
            if(dataE[i] >= 97 && dataE[i] <= 122)
            {
                //Linear search for index
                while(ralphaL[n] != dataE[i])
                {
                    n++;
                }

                dataD[i] = alphaL[n]; 
            }
            else
            {
                dataD[i] = dataE[i];
            }
        }
    }

    if(call == 'Y')
    {
        printf("ENCRYPTED DATA: %s \n", dataE); 
        printf("DECRYPTED DATA: %s \n", dataD); 
    }
  
}

int main() 
{
    char ch, r;
    char call = 'N'; 
    char in[128] = {'\0'};
    char out[128] = {'\0'};

    //Needs to be rewritten (THE WHOLE FUNCTON)
    printf("Welcome to the Atbash Program. You can encrypt and decrypt files that use the Atbash cipher! \n"); 
    
    jump: 
    printf("Would you like to read and write to files? (Y for Yes or N for No): ");
    scanf("%c%*c", &r);
    r = toupper(r);

    if(r == 'Y')
    {
        printf("Would you like to encrypt or decrypt your file? (Type e for encrypt or d for decrypt): "); 
        scanf("%c%*c", &ch);    

        printf("What is the name of the file in which you want to either encrypt or decrypt? (You must name the path if not executed inside the same folder as the program): ");
        fgets(in, 128, stdin);
        in[(strlen(in)- 1)] = '\0';

        printf("What is the name of the file in which you want the encrypted or decrypted data to go? (You must name the path if not executed inside the same folder as the program): ");
        fgets(out, 128, stdin);
        out[(strlen(out)- 1)] = '\0';  

        printf("Would you like to see the message in the console after the program has done it's magic? (Y for Yes or N for No): ");
        scanf("%c%*c", &call);
        call = toupper(call);

        if(ch == 'd')
        {
            DecF(in, out, call);
        }
        else
        {
            if(ch == 'e')
            {
                EncF(in, out, call);
            }
        }    
    }
    else
    {
        if(r == 'N')
        {
            printf("Please enter your message: ");
            fgets(in, 128, stdin);
            in[(strlen(in)-1)] = '\0';

            printf("Would you like to encrypt or decrypt this message. (Press e to encrypt or d to decrypt): ");
            scanf("%c%*c", &ch); 
            call = 'Y'; 

            if(ch == 'd')
            {
                Dec(in, out, call);
            }
            else
            {
                if(ch == 'e')
                {
                    Enc(in, out, call);
                }
            }
        }
        else
        {
            printf("You haven't entered in the correct type: TRY AGAIN!"); 
            goto jump;
        }

    }

  

    return 0; 
}