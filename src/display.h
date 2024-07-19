#pragma once
#include <string>
#include <iostream>
void PrintBadArgs()
{
    std::cerr << "Error::Insufficient arguments provided.\n\n use snipper --help for usage details\n";
}
void PrintHelp()
{
    std::cout << R"(
    Default directory to store snippets must be set prior to use
        snipper -directory <path/to/store/snippets>

    Usage:
        snipper [<input> <output>]
            - <input>  :  must have file extension
            - <output> :  file extension not necessary

    Examples:
        To Initialize:
            snipper -directory ../
        Store a snippet:
            snipper main.cpp quickSort  - outfile does not have extension in name
)";
}
void PrintConfigChanged(std::string dir)
{
    std::cerr << "Set Snippet save directory to: " << dir << "\n";
}
void PrintNotInitialized()
{
    std::cerr << "Error: no default directory set.\n\n use snipper --help for usage details\n";
}

void PrintInputHelpMessage(std::string arg)
{
    std::cerr << "Error::Input '" << arg << "' could not be found.\n\n use snipper --help for usage details\n";
}
void PrintInvalidInputFormat(std::string arg)
{
    std::cerr << "Error::Invalid Input: '" << arg << ".\n\n use snipper --help for usage details\n";
}
