#include <iostream>
#include <fstream>


// функция для печати содержимого из файла
void printFile(std::string filename){
    std::ifstream filenameForOpen(filename);
    if (!filenameForOpen){
        std::wcout << L"Файл не открыт или введен неверно" << "\n";
    }
    else{
        std::wcout << L"Результат:" << "\n";
        std::string s;
        while(getline(filenameForOpen, s)){
            std::cout << s << std::endl;
        }
    }
    filenameForOpen.close();
}


void lines(){}

void tail(){}

void delimiter(){}


// функция для проверки введенных значений пользователем и вызовом нужных функций
void checkCorrectness(int argc, char** argv){
    setlocale(LC_ALL, "rus");
    if (argc == 1){
        std::wcout << L"Извините, нужно ввести аргументы и имя файла" << "\n";
    }
    else if (argc == 2){
        printFile(argv[argc - 1]);
    }
    else{
        for (int i = 1; i < argc - 1; ++i) {
//            std::cout << argv[i];
//            std::string s = "-l";
            if (argv[i][0] == '-' && argv[i][1] == 'l'){
                lines();
                std::wcout << L"Оки";
            }
            else if (argv[i][0] == '-' && argv[i][1] == '-' && argv[i][2] == 'l' && argv[i][3] == 'i' &&
            argv[i][4] == 'n' && argv[i][5] == 'e' && argv[i][6] == 's'){
                lines();
                std::wcout << L"Оки";
            }
            else if (argv[i][0] == '-' && argv[i][1] == 't'){
                tail();
                std::wcout << L"Оки";
            }
            else if (argv[i][0] == '-' && argv[i][1] == '-' && argv[i][2] == 't' && argv[i][3] == 'a' &&
                     argv[i][4] == 'i' && argv[i][5] == 'l'){
                tail();
                std::wcout << L"Оки";

            }
            else if (argv[i][0] == '-' && argv[i][1] == 'd'){
                delimiter();
                std::wcout << L"Оки";
            }
            else if (argv[i][0] == '-' && argv[i][1] == '-' && argv[i][2] == 'd' && argv[i][3] == 'e' &&
                     argv[i][4] == 'l' && argv[i][5] == 'i' && argv[i][6] == 'm' && argv[i][7] == 'i' &&
                     argv[i][8] == 't' && argv[i][9] == 'e' && argv[i][10] == 'r'){
                delimiter();
                std::wcout << L"Оки";

            }
            else{
                std::wcout << L"Извините, такой команды нет.";
            }
//            std::cout << argv[i] << " ";
        }
    }
}


int main(int argc, char** argv) {
    checkCorrectness(argc, argv);
    return 0;
}