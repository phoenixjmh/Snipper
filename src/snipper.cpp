
#include "snipper.h"

namespace fs = std::filesystem;
using std::string;
const string SNIPPET_DIR = "Snippets";
const string CONFIG_FILE = "config.txt";

int main(int argc, char* argv[])
{
    int process = HandleArgs(argc, argv);
    switch (process)
    {
    case 0:
        PrintHelp();
        break;
    case 1:
        SetDefaultDirectory(argv[2]);
        break;
    case 2:
        Snip(ValidateInputFormat(argv[1]), ValidateOutputFormat(argv[2]));
        break;
    case -1:
        PrintBadArgs();
        break;
    }
}

int HandleArgs(int argc, char* argv[])
{
    if (argc < 2)
    {
        return -1;
    }
    if (string(argv[1]) == "--help")
    {
        return 0;
    }
    if (string(argv[1]) == "-directory")
    {
        return 1;
    }
    if (argc == 3)
    {
        return 2;
    }
    return -1;
}
void Snip(const string& inputArg, const string& outputArg)
{
    if (inputArg.empty() || outputArg.empty())
        return;

    fs::path inputPath = inputArg;
    if (!exists(inputPath))
    {
        PrintInputHelpMessage(inputArg);
        return;
    }
    string fileExtension = inputPath.extension().string();

    fs::path outputPath = CreateOutputDirectory(outputArg, fileExtension);

    WriteOutputFile(inputPath, outputPath);
}

void SetDefaultDirectory(const string& dirArg)
{
    fs::path baseDir = dirArg;

    fs::path defaultSaveDirectory = baseDir / SNIPPET_DIR;
    fs::path absPath = fs::absolute(defaultSaveDirectory);
    string absPathString = absPath.string();

    if (!fs::exists(defaultSaveDirectory))
    {
        std::cout << "Specified directory not found: Create? [Y] Yes [N] No ";
        string resp;
        std::cin >> resp;
        if (tolower(resp[0]) == 'y')
        {
            try
            {
                fs::create_directories(defaultSaveDirectory);
                std::cout << "Created directory:" << dirArg << "\n";
                StoreDirectory(absPathString);
                return;
            }
            catch (const std::exception& e)
            {
                std::cerr << "Error setting default directory: " << e.what();
                return;
            }
        }
        return;
    }
    StoreDirectory(absPathString);
}

void StoreDirectory(string save_path_string)
{
    fs::path config = GetConfigFilePath() / CONFIG_FILE;
    std::ofstream file(config);

    if (!file.good())
    {
        std::cerr << "Failed to access config file";
        return;
    }
    file << save_path_string;
    if (file.fail())
    {
        std::cerr << "Failed to write to config file";
        return;
    }
    PrintConfigChanged(save_path_string);
}

string GetStoredDirectory()
{
    fs::path config = GetConfigFilePath() / CONFIG_FILE;
    std::ifstream file(config);
    if (!file.good())
    {
        PrintNotInitialized();
        exit(EXIT_FAILURE);
    }
    string line;
    getline(file, line);
    // error check
    file.close();
    return line;
}

fs::path CreateOutputDirectory(const string& output_filename,
    const string& fileExtension)
{
    try
    {
        fs::path save_directory = GetStoredDirectory();
        string languageDirectory = GetLanguageFromExtension(fileExtension);

        fs::path outputDir = save_directory / languageDirectory; // Snippets/C++ etc..
        if (!exists(outputDir))
        {
            fs::create_directories(outputDir);
        }

        fs::path outputPath = save_directory / languageDirectory / (output_filename + fileExtension);
        return outputPath;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error creating output directory:" << e.what() << "\n";
        return fs::path();
    }
}
void WriteOutputFile(const fs::path& input_filepath, const fs::path& output_filepath)
{
    std::ofstream outFile(output_filepath, std::ios::binary);
    std::ifstream inFile(input_filepath, std::ios::binary);

    if (!outFile)
    {
        std::cerr << "Error: unable to create output file: " << output_filepath;
        return;
    }
    if (!inFile.good())
    {
        std::cerr << "Error: unable to read input file: " << input_filepath;
        return;
    }

    inFile.seekg(0, std::ios::end);
    if (inFile.tellg() == 0)
    {
        std::cerr << "Error: Input file is empty: " << input_filepath << "\n";
        return;
    }
    inFile.seekg(0, std::ios::beg);  

    outFile << inFile.rdbuf();

    if (outFile.fail())
    {
        std::cerr << "Failed to write to output file";
        return;
    }

    std::cout << "\n Snippet saved to : " << output_filepath << "\n";
}

string ValidateInputFormat(const string& arg)
{
    // input must have file extension
    string validated = arg;
    if (validated.find('.') != string::npos)
    {
        return validated;
    }
    PrintInvalidInputFormat(validated);
    return "";
}
string ValidateOutputFormat(const string& arg)
{
    // strip file extension
    string validated;
    for (char c : arg)
    {
        if (c != '.')
        {
            validated += c;
        }
        else
        {
            return validated;
        }
    }
    return validated;
}
fs::path GetConfigFilePath(){
    fs::path homeDir;
#ifdef _WIN32
    homeDir = fs::path(std::getenv("USERPROFILE"));
#else
    homeDir = fs::path(std::getenv("HOME"));
#endif
        fs::path config_path= homeDir / ".snipper_config";
    if(!exists(config_path)){
        try{
            fs::create_directories(config_path);
            return config_path;

        }
        catch(const std::exception& e){
            std::cerr << "Error accessing config file" << e.what();
            return fs::path();
        }
    }
    return config_path;
}

