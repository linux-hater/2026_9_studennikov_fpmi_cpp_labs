//динамический
//Преобразовать массив вещественных чисел таким образом, чтобы все элементы, целая часть которых лежит в интервале [0, 10], располагались только на чётных индексах. Порядок следования элементов не изменять.

#include <iostream>
#include <random>
#include <string>


double*  vvod(int&ke) {
    std::cout<<"vvedite kolichestvo elementov do 100"<<std::endl;
    std::cin>>ke;
    if (ke <= 0) {
        std::cout << "OSHIBKA: kolichestvo elementov dolzhno byt > 0" << std::endl;
        return nullptr;
    }
    double* arr=new double[ke];
    std::cout<<"vvesti elementi? ili random y/n "<<std::endl;
    std::string a;
    std::cin>>a;
    if(a=="y") {
        std::cout<<"vvedite elementi"<<std::endl;
        for (int i = 0; i < ke; ++i) {
            std::cin>>arr[i];
        }
    } else if(a=="n") {
        double lg=0;
        double rg=0;
        std::cout<<"vvedite razbros elemetov"<<std::endl;
        std::cout<<"ot"<<std::endl;
        std::cin>>lg;
        std::cout<<"do"<<std::endl;
        std::cin>>rg;
        std::mt19937 genmas(452);
        std::uniform_real_distribution<double> distmas(lg, rg);
        for (int i = 0; i < ke; ++i) {
            arr[i] = distmas(genmas);
        }
        }
    else {
        std::cout<<"OSHIBKA"<<std::endl;
        return nullptr;
    }
    std::cout << "Massiv:" << std::endl;
    for (int i = 0; i < ke; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return arr;
}
void grob(double* arr, int ke) {
    int nuzhn = 0;
    double* pereh = new double[ke];

    for (int i = 0; i < ke; ++i) {
        int cel = static_cast<int>(arr[i]);
        if (cel >= 0 && cel <= 10) {
            pereh[nuzhn++] = arr[i];
        }
    }
    if (nuzhn == 0) {
        std::cout << "Net takich" << std::endl;
        delete[]pereh;
        return;
    }
    int ostatki = 0;
    for (int i=0;i < ke;++i) {
        int cel = static_cast<int>(arr[i]);
        if (!(cel >= 0 && cel <= 10)) {
            pereh[nuzhn+ ostatki] = arr[i];
            ostatki++;
        }
    }
    double* p_first_nuzhn = pereh;
    double* p_last_nuzhn = pereh + nuzhn;

    double* p_first_ostatki = pereh + nuzhn;
    double* p_last_ostatki = pereh + nuzhn+ostatki;

    int k = 0;
    int s = 1;

    while (p_first_nuzhn < p_last_nuzhn && k < ke && p_first_ostatki < p_last_ostatki && s < ke) {
        arr[k] = *p_first_nuzhn++;
        k += 2;
        arr[s] = *p_first_ostatki++;
        s += 2;
    }
    while (p_first_nuzhn < p_last_nuzhn && s < ke) {
        arr[s] = *p_first_nuzhn++;
        s += 2;
    }
    while (p_first_ostatki < p_last_ostatki && k < ke) {
        arr[k] = *p_first_ostatki++;
        k += 2;
    }
    std::cout << "Preobrazovannyi massiv:" << std::endl;
    for (int i = 0; i < ke; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    delete[]pereh;
}
int main() {
    int ke=0;
    double* arr=vvod(ke);
    if (arr == nullptr) {
        return -1;
    }
    grob(arr, ke);
    delete[]arr;
}