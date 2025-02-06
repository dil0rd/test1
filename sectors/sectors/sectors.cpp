#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct SH_SEC {
    float bn, bk; 
};


void obiedSectors(vector<SH_SEC>& sector, vector<SH_SEC>& sector_norm) {// функция объединения секторов
    int N = sector.size();
    if (N == 0) {
        return;
    }

    sort(sector.begin(), sector.end(), [](const SH_SEC& a, const SH_SEC& b) {//сначала сортируем сектора 
        return a.bn < b.bn;
        });

    SH_SEC tec = sector[0];  //создаём текущий сектор

    for (int i = 1; i < N; i++) {// Проверяем пересечение секторов
        if (sector[i].bn <= tec.bk) {
            tec.bk = max(tec.bk, sector[i].bk);//и объединяем их
        }
        else {
            sector_norm.push_back(tec);// сохраняем текущий сектор и начинаем новый
            tec = sector[i];
        }
    }

    
    sector_norm.push_back(tec); // Добавляем последний сектор, который объединили
}

int main() {
    setlocale(LC_ALL, "Russian");

    int N;
    cout << "Введите количество секторов: ";
    cin >> N;

    vector<SH_SEC> sector(N);
    vector<SH_SEC> sector_norm;


    for (int i = 0; i < N; i++) {
        cout << "Введите начало и конец сектора " << i + 1 << ": ";
        cin >> sector[i].bn >> sector[i].bk;
    }

    
    obiedSectors(sector, sector_norm);// вызов функции объединения секторов

    cout << "\nОбъединенные сектора:\n";
    for (size_t i = 0; i < sector_norm.size(); i++) {
        cout << "Сектор " << i + 1 << ": (" << sector_norm[i].bn << ", " << sector_norm[i].bk << ")\n";
    }

    return 0;
}
