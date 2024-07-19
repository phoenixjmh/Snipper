#pragma once
#include <map>
#include <string>
#include <regex>
#include <algorithm>

std::map<std::string, std::string> extensionToDirectoryTitle =
{
{".txt","Text"},
{".c", "C & C++"},
{".h", "C & C++"},
{".cpp", "C & C++"},
{".hpp", "C & C++"},
{".cs", "C#"},
{".java", "Java"},
{".js", "Javascript"},
{".ts", "Typescript"},
{".py", "Python"},
{".rb", "Ruby"},
{".php", "Php"},
{".go", "Go"},
{".swift", "Swift"},
{".kt", "Kotlin"},
{".rs", "Rust"},
{".scala", "Scala"},
{".vb", "Visual Basic"},
{".fs", "F#"},
{".html", "Html"},
{".css", "Css"},
{".scss", "Scss"},
{".sql", "Sql"},
{".xml", "Xml"},
{".json", "Json"},
{".yaml", "Yaml"},
{".md", "Markdown"},
{".sh", "Bash"},
{".ps1", "Powershell"},
{".asm", "Assembly"},
{".pl", "Perl"},
{".lua", "Lua"},
{".r", "R"},
{".dart", "Dart"},
{".groovy", "Groovy"},
{".pas", "Pascal"},
{".m", "Objective-C"},
{".coffee", "CoffeeScript"}
};

std::string GetLanguageFromExtension(std::string fileExtension)
{

    std::string language = extensionToDirectoryTitle[fileExtension];
    if (!language.empty())
        return language;

    std::cout << "\nSorting not supported for file type: " << fileExtension;
    exit(EXIT_FAILURE);
}
