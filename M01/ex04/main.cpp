#include <iostream>
#include <fstream>
#include <string>


void replace(const std::string &filename, const std::string &s1, const std::string &s2) {
    if (s1.empty()) 
    {
        std::cerr << "Error: s1 cannot be empty." << std::endl;
        return;
    }

    std::ifstream inputFile;
    inputFile.open(filename.c_str());
    if (!inputFile) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    std::string outputFilename = filename + ".replace";
    std::ofstream outputFile;
    outputFile.open(outputFilename.c_str());
    if (!outputFile) {
        std::cerr << "Error: Unable to create output file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inputFile, line))
    {
        size_t pos = 0;
        pos = line.find(s1, pos);
        while (pos != std::string::npos)
        {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s2.length();
            pos = line.find(s1, pos);
        }
        outputFile << line << '\n';
    }
    inputFile.close();
    outputFile.close();
    std::cout << "File successfully created: " << outputFilename << std::endl;
}

int main(int argc, char *argv[])
{
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    replace(argv[1], argv[2], argv[3]);
    return 0;
}
