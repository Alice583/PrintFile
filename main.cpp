#include <iostream>
#include <fstream>


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
            while(getline(filenameForOpen, s)){
                std::cout << s << std::endl;
            }
        }
        else{
            if (t){
                filenameForOpen.seekg(0, std::ios::end);
                filenameForOpen.seekg(n, std::ios::end);
                while(getline(filenameForOpen, s)){
                    filenameForOpen.seekg(-1, std::ios::cur);
                    std::cout << s << std::endl;
                }
            }
            else{
                int count = 1;
                while(getline(filenameForOpen, s) && count <= n){
                    std::cout << s << std::endl;
                    count++;
                }
            }
        }
    }
    filenameForOpen.close();
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
                std::wcout << L"Оки";

            } else if (argv[i][0] == '-' && argv[i][1] == '-' && argv[i][2] == 'l' && argv[i][3] == 'i' &&
                        argv[i][4] == 'n' && argv[i][5] == 'e' && argv[i][6] == 's' && argv[i][7] == '=') {
//                int a = int();


                std::wcout << L"Оки";
            } else if (argv[i][0] == '-' && argv[i][1] == 't' && argv[i][2] == '\0') {
                argumentsStd.from_tail = true;
                std::wcout << L"Оки";
            } else if (argv[i][0] == '-' && argv[i][1] == '-' && argv[i][2] == 't' && argv[i][3] == 'a' &&
                        argv[i][4] == 'i' && argv[i][5] == 'l' && argv[i][6] == '\0') {

                std::wcout << L"Оки";

                // исправить
            } else if (argv[i][0] == '-' && argv[i][1] == 'd' && argv[i][2] == '\0') {
//                argumentsStd.delimiter = argv[i + 1];
                i++;
                std::wcout << L"Оки";

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

