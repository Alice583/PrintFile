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
            std::string s = "-l";
            if (argv[i] == s){ std::wcout << L"Оки";}
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