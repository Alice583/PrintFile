#include <iostream>
#include <fstream>


// функция для проверки введенных значений пользователем и вызовом нужных функций
void checkCorrectness(int argc, char** argv){
    setlocale(LC_ALL, "rus");
    if (argc == 1){
        std::wcout << L"Извините, нужно ввести аргументы и имя файла" << "\n";
    }
    else if (argc == 2){
        std::ifstream filename(argv[argc - 1]);
            if (!filename){
            std::wcout << L"Файл не открыт или введен неверно" << "\n";
            }
            else{
                std::wcout << L"Результат:" << "\n";
                std::string s;
                while(getline(filename, s)){
                    std::cout << s << std::endl;
                }
            }
        filename.close();
    }
    else{
        for (int i = 1; i < argc - 1; ++i) {
            std::cout << argv[i] << " ";
        }
    }
}

int main(int argc, char** argv) {
    checkCorrectness(argc, argv);
    return 0;
}