# program2_487
DES implementation with cbc


How to use:
code for encryption:

```
-e -i <hex> -k <hex> -p <name of plaintextfile> -o <name of prefered output file>
```
code for decryption:
```
-d -i <hex> -k <hex> -c <name of ciphertextfile> -o <name of prefered output file>
```
For Randomization:
If you would like to create a random hex number or output filename please type R after the flags.

For best results(a.K.a. to get it to work) all flags must have spaces behind them before input info.

command-line parameters definitions:

-e encryption needs no input after
-d decryption needs no input after 
-i iv for cbc encryption 
(must be 16 characters long and hexadecimal values, F.Y.I values less than E must have and 0 infront example 8 =  08)
-k key for for encryption
(must be 16 characters long and hexadecimal values, F.Y.I values less than E must have and 0 infront example 8 =  08)
-p plaintext name for file (include extension .txt)
-c ciphertext name for file (include extension .txt)
-o out put type in output file name you would like (include extension .txt)

Examples for encryption/decryption not random:
 -e -i 2bc3b915a236768c -k 6b23b715a736778c -p plaintext.txt -o output.txt
 -d -i 2bc3b915a236768c -k 6b23b715a736778c -p ciphertext.txt -o output.txt

Examples for encryption random:
-e -i R -k R -p plaintext.txt -o R


The final output:
This program will output if there is an error with input:
If Random is choosen it will output the random variable (this will be based on the random variable)
        example: 
        -k 6b23b715a736778c
        -i 6b23b715a736778c
        -o output.txt
The final output will be if encryption is called it will output the openssl code.
        example:
        openssl enc -des-cbc -in text.txt -out cipher.txt.enc -nosalt -iv 2bc3b915a236768c -K 96b74d565d3ed9c5
