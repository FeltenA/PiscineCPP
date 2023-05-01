
#include <string>
#include <iostream>
#include <fstream>

void    fill_outfile(std::ifstream& infile, std::ofstream& outfile, std::string instr, std::string outstr) {
    std::string line;

    while (std::getline(infile, line)) {
        std::size_t pos = 0;
        std::size_t spos = 0;
        std::string newline;
        while ((pos = line.find(instr, pos)) != std::string::npos) {
            newline.append(line, spos, pos - spos);
            newline.append(outstr);
            pos += instr.size();
            spos = pos;
        }
        newline.append(line, spos, std::string::npos);
        outfile << newline;
        if (!infile.eof())
            outfile << std::endl;
    }
}

int main(int argc, char *argv[]) {
    
    if (argc != 4) {
        std::cerr << "Incorrect number of arguments" << std::endl;
        return (1);
    }
    std::string str(argv[1]);
    std::ifstream infile(str.c_str());
    if (!infile.is_open()) {
        std::cerr << "Cannot open infile" << std::endl;
        return (1);
    }
    std::ofstream outfile((str + ".replace").c_str());
    if (!outfile.is_open()) {
        std::cerr << "Cannot open outfile" << std::endl;
        infile.close();
        return (1);
    }
    fill_outfile(infile, outfile, argv[2], argv[3]);
    infile.close();
    outfile.close();
    return (0);
}