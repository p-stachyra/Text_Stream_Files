# Text Stream Files
This repository is a test repository for C project. Basic text stream operations are performed by the application.

## Functionality
The main driver expects 2 or 1 command line arguments. In case of 1 command line argument (the main's filename), the characters are read from the STDIN. If 2 command line arguments are provided, the second command line argument is the file name containing text which is read, frequencies of characters and words are examined, the upper-case letters are converted to lower-case and vice versa and that modified input is saved to a new file.

## Example
1) Compile: gcc main.c calculateFrequencies.c convertTextCase.c -o textStreamProgram
2) Run: textStreamProgram.exe example_text_file.txt
3) Outputs: frequencies of words and alphanumerical characters are outputted to STDIN, modified copy of the file is saved as modified_file.txt


