#include <iostream>
#include <fstream>
#include <cstring>
#include <limits>

// tail

struct ArgumentsSTD {
    unsigned long long lines = std::numeric_limits<unsigned long long>::max();
    bool from_tail = false;
    char delimiter = '\n';
    std::string filename;
};


void toBegin(ArgumentsSTD* argumentsStd) {
    std::ifstream filenameForOpen(argumentsStd->filename);
    char symb;
    if (!filenameForOpen) {
        std::wcout << L"Файл не открыт или введен неверно" << "\n";
    } else {
        if (argumentsStd->lines == -1) {
            while (filenameForOpen.get(symb) && filenameForOpen.good()) {
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
            while (filenameForOpen.get(symb) && filenameForOpen.good() && count <= argumentsStd->lines){
                if (argumentsStd->delimiter != '\n' && symb == '\n'){
                    continue;
                }
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
    filenameForOpen.close();
}


void toEnd(ArgumentsSTD* argumentsStd){
    unsigned long long count = 0;
    char ch;
    std::ifstream filenameForOpen(argumentsStd->filename, std::ios::ate);
    if (!filenameForOpen) {
        std::wcout << L"Файл не открыт или введен неверно" << "\n";
    }
    while(count < argumentsStd->lines && filenameForOpen.good()) {
        filenameForOpen.seekg(-1, std::ios::cur);
        filenameForOpen.get(ch);
        if (ch == argumentsStd->delimiter) {
            std::cout << "this /n" << ch;
            count++;
        }
        filenameForOpen.seekg(-1, std::ios::cur);
        std::cout << ch;
    }
    char symb;
    while (filenameForOpen.get(symb) && filenameForOpen.good()){
//        if (argumentsStd->delimiter != '\n' && symb == '\n'){
//            continue;
//        }
        std::cout << symb;
//        if (symb == argumentsStd->delimiter) {
//            if (argumentsStd->delimiter != '\n') {
//                std::cout << '\n';
//            }
//        }

    }
    filenameForOpen.close();
}


//unsigned long long charToInt(char* a, int count){
//    char* num = nullptr;
//    while (a[count] != '\0'){
//        num += a[count];
//        count++;
//    }
//    return std::stoull(num);
//}


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


// функция для проверки введенных значений пользователем и вызовом нужных функций
void checkCorrectness(int argc, char* argv[]) {
    setlocale(LC_ALL, "rus");
    ArgumentsSTD argumentsStd;
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
                // исправить
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
    if (argumentsStd.from_tail){
        toEnd(&argumentsStd);
    } else{
        toBegin(&argumentsStd);
    }
}


int main(int argc, char* argv[]) {
    checkCorrectness(argc, argv);
    return 0;
}

