#include <iostream>
#include <fstream>

// исправить ошибку с делимитром
// брать у строк после =
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
//                char s1;
                int count = 0;
                filenameForOpen.seekg(0, std::ios::end);
//                filenameForOpen.seekg(-1, std::ios::cur);
//                filenameForOpen.seekg(n, std::ios::end);
                while(getline(filenameForOpen, s) && count < 10){
                    count++;
                    filenameForOpen.seekg(-1, std::ios::cur);
                    std::cout << s;
                }
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


//int charToInt(char* a){
//    int count = 0;
//    while (a[count] != '\0'){
//
//        count++;
//    }
//}


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


                std::wcout << L"Оки";
            } else if (argv[i][0] == '-' && argv[i][1] == 't' && argv[i][2] == '\0') {
                argumentsStd.from_tail = true;
            } else if (argv[i][0] == '-' && argv[i][1] == '-' && argv[i][2] == 't' && argv[i][3] == 'a' &&
                        argv[i][4] == 'i' && argv[i][5] == 'l' && argv[i][6] == '\0') {

                std::wcout << L"Оки";

                // исправить
            } else if (argv[i][0] == '-' && argv[i][1] == 'd' && argv[i][2] == '\0') {
//                argumentsStd.delimiter = argv[i + 1];
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

