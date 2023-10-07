#include <iostream>
#include <fstream>
#include <cstring>
#include <limits>


struct ArgumentsSTD {
    unsigned long long lines = std::numeric_limits<unsigned long long>::max();
    bool from_tail = false;
    char delimiter = '\n';
    std::string filename;
};


void FromStartToEnd(ArgumentsSTD* argumentsStd) {
    std::ifstream filename_for_open(argumentsStd->filename, std::ios::binary);
    char symb;
    if (!filename_for_open) {
        std::wcout << L"Файл не открыт или введен неверно" << "\n";
    } else {
        if (argumentsStd->lines == -1) {
            while (filename_for_open.get(symb) && filename_for_open.good()) {
                if (argumentsStd->delimiter != '\n' && symb == '\n') {
                    continue;
                }
                std::cout << symb;
                if (symb == argumentsStd->delimiter) {
                    if (argumentsStd->delimiter != '\n') {
                        std::cout << '\n';
                    }
                }

            }
        }
        else{
            int count = 1;
            while (filename_for_open.get(symb) && filename_for_open.good() && count <= argumentsStd->lines){
                std::cout << symb;
                if (symb == argumentsStd->delimiter){
                    if (argumentsStd->delimiter != '\n'){
                        std::cout << '\n';
                    }
                    count++;
                }
            }
        }
    }
    filename_for_open.close();
}


void FromEndToStart(ArgumentsSTD* argumentsStd) {
    unsigned long long count = 0;
    char ch;
    std::ifstream filename_for_open(argumentsStd->filename, std::ios::ate | std::ios::binary);
    if (!filename_for_open) {
        std::wcout << L"Файл не открыт или введен неверно" << "\n";
    }
    while(count < argumentsStd->lines && filename_for_open.good()) {
        if (filename_for_open.tellg() == 0) {
            break;
        }
        filename_for_open.seekg(-1, std::ios::cur);
        filename_for_open.get(ch);
        filename_for_open.seekg(-1, std::ios::cur);
        if (ch == argumentsStd->delimiter) {
            count++;
        }
    }
    char symb;
    filename_for_open.get(symb);
    while (filename_for_open.get(symb) && filename_for_open.good()) {
        std::cout << symb;
        if (symb == argumentsStd->delimiter) {

        }

    }
    filename_for_open.close();
}



char getDelimiter(char* args){
    if (strlen(args) == 1){
        return args[0];
    }
    else if (args[0] == '\\'){
        if (args[1] == 'n'){
            return '\n';
        }
        else if (args[1] == 't'){
            return '\t';
        }
        else if (args[1] == 'v'){
            return '\v';
        }
        else if (args[1] == '0'){
            return '\0';
        }
    }
    if (strlen(args) >= 2){
        std::wcout << L"Ошибка, неверный делиметр" << '\n';
    }
    return 0;
}


ArgumentsSTD CheckCorrectness(int argc, char* argv[], ArgumentsSTD argumentsStd) {
    setlocale(LC_ALL, "rus");

    if (argc < 2) {
        std::wcout << L"Извините, нужно ввести аргументы и имя файла" << "\n";
    }
    else {
        for (int i = 1; i < argc; i++) {
            if (std::strcmp(argv[i], "-l") == 0){
                argumentsStd.lines = std::atoll(argv[i + 1]);
                i++;
            }
            else if (std::strncmp(argv[i], "--lines=", 8) == 0){
                argumentsStd.lines = std::atoll(argv[i] + 8);
            }
            else if (std::strcmp(argv[i], "-t") == 0) {
                argumentsStd.from_tail = true;
            }
            else if (std::strncmp(argv[i], "--tail", 6) == 0){
                argumentsStd.from_tail = true;
            }
            else if  (std::strcmp(argv[i], "-d") == 0) {
                argumentsStd.delimiter = getDelimiter(argv[i + 1]);
                i++;
            }
            else if (std::strncmp(argv[i], "--delimiter=", 12) == 0) {
                argumentsStd.delimiter = getDelimiter(argv[i] + 12);
            }
            else {
                argumentsStd.filename = argv[i];
            }

        }
    }
    return argumentsStd;

}

void CheckDirection(ArgumentsSTD argumentsStd) {
    if (argumentsStd.from_tail && argumentsStd.lines != -1){
        FromEndToStart(&argumentsStd);
    } else{

        FromStartToEnd(&argumentsStd);
    }
}

int main(int argc, char* argv[]) {
    ArgumentsSTD argumentsStd;
    argumentsStd = CheckCorrectness(argc, argv, argumentsStd);
    CheckDirection(argumentsStd);
    return 0;
}

