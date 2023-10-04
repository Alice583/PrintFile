#include <iostream>
#include <fstream>

// исправить ошибку с делимитром
// tail


struct ArgumentsSTD {
    long long lines = -1;
    bool from_tail = false;
    char delimiter = '\n';
    std::string filename;
};


// функция для печати содержимого из файла
void printFile(std::string filename, long long n, bool t, char d){
    std::ifstream filenameForOpen(filename);
    std::string s;
    if (!filenameForOpen){
        std::wcout << L"Файл не открыт или введен неверно" << "\n";
    }
    else{
        if (n == -1){
            while(getline(filenameForOpen, s, d)){
                std::cout << s << std::endl;
            }
        }
        else{
            if (t){
                int count = 1;
                filenameForOpen.seekg(-1,std::ios::end);
                bool keepLooping = true;
                while(keepLooping) {
                    char ch;
                    filenameForOpen.get(ch);
                    if((int)filenameForOpen.tellg() <= 1) {
                        filenameForOpen.seekg(0);
                        keepLooping = false;
                    }
                    else if(ch == d) {
                        count++;
//                        filenameForOpen.seekg(-3,std::ios::cur);
                    }
                    else if (count == n){
                        keepLooping = false;
                    }
                    else {
                        filenameForOpen.seekg(-2,std::ios::cur);
                    }
                    std::cout << count;
                }
//                while(getline(filenameForOpen, s)){
//                    std::cout << s;
//                }
                getline(filenameForOpen, s);
                std::cout << s;
            }
            else{
                int count = 1;
                while(getline(filenameForOpen, s, d) && count <= n){
                    std::cout << s << std::endl;
                    count++;
                }
            }
        }
    }
    filenameForOpen.close();
}


std::string charToInt(char* a, int count){
    std::string num;
    while (a[count] != '\0'){
        num += a[count];
        count++;
    }
    return num;
}


// функция для проверки введенных значений пользователем и вызовом нужных функций
void checkCorrectness(int argc, char** argv) {
    setlocale(LC_ALL, "rus");
    ArgumentsSTD argumentsStd;
    if (argc == 1) {
        std::wcout << L"Извините, нужно ввести аргументы и имя файла" << "\n";
    }
    else {
        for (int i = 1; i < argc; i++) {
            if (argv[i][0] == '-' && argv[i][1] == 'l' && argv[i][2] == '\0') {
                argumentsStd.lines = (std::atoi(argv[i + 1]));
                i++;
            } else if (argv[i][0] == '-' && argv[i][1] == '-' && argv[i][2] == 'l' && argv[i][3] == 'i' &&
                        argv[i][4] == 'n' && argv[i][5] == 'e' && argv[i][6] == 's' && argv[i][7] == '=') {
                argumentsStd.lines = (std::stoi(charToInt(argv[i], 8)));

            } else if (argv[i][0] == '-' && argv[i][1] == 't' && argv[i][2] == '\0') {
                argumentsStd.from_tail = true;
            } else if (argv[i][0] == '-' && argv[i][1] == '-' && argv[i][2] == 't' && argv[i][3] == 'a' &&
                        argv[i][4] == 'i' && argv[i][5] == 'l' && argv[i][6] == '\0') {
                argumentsStd.from_tail = true;

                // исправить
            } else if (argv[i][0] == '-' && argv[i][1] == 'd' && argv[i][2] == '\0') {
//                argumentsStd.delimiter = (char)argv[i + 1];
                i++;

            } else if (argv[i][0] == '-' && argv[i][1] == '-' && argv[i][2] == 'd' && argv[i][3] == 'e' &&
                        argv[i][4] == 'l' && argv[i][5] == 'i' && argv[i][6] == 'm' && argv[i][7] == 'i' &&
                        argv[i][8] == 't' && argv[i][9] == 'e' && argv[i][10] == 'r' && argv[i][11] == '=') {

                std::wcout << L"Оки";

            } else {
                argumentsStd.filename = argv[i];
            }

        }
    }
    printFile(argumentsStd.filename, argumentsStd.lines, argumentsStd.from_tail, argumentsStd.delimiter);
}


int main(int argc, char** argv) {
    checkCorrectness(argc, argv);
    return 0;
}

