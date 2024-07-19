
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include <filesystem>
#include <map>
#include "display.h"
#include "language_sort.h"


void StoreDirectory(std::string dir);
std::string ValidateInputFormat(const std::string& arg);
std::string ValidateOutputFormat(const std::string& arg);
std::filesystem::path CreateOutputDirectory(const std::string& output_filename, const std::string& fileExtension);
void SetDefaultDirectory(const std::string& dirArg);
int HandleArgs(int argc, char* argv[]);
void Snip(const std::string& inputArg, const std::string& outputArg);
void WriteOutputFile(const std::filesystem::path& input_filepath, const std::filesystem::path& output_filepath);
std::filesystem::path GetConfigFilePath();
