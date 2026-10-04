# MFMS
Municipal Financial Management Sysytem-PAP521S Programming in practice project A 


## Functions, Integration and Validation Module

Done by: Joesphine Teodol (225044226)

What it does:

- Reads and checks all user input for the other modules
- Rejects empty input, letters where numbers are expected, and negative amounts
- Handles invalid menu choices in one place
- Main menu that connects the modules together

Files:

- validation.h - the function prototypes
- validation.c - the input-checking functions
- main.c - the main menu and the switch that calls each module

Functions:

- readInt - reads a whole number, repeats until valid
- readFloat - reads a decimal number, rejects negatives
- readString - reads text, rejects empty or too-long input
- getValidInt - group name for readInt
- getValidDouble - group name for readFloat, returns a double
- getValidString - group name for readString
- getMenuChoice - reads a number within a given range
- displayMainMenu - prints the main menu
- main - owns the supplier and asset arrays and calls each module's menu