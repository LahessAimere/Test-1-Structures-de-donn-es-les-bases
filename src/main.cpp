#include <iostream>

int SmallestGapWithSortedArray(int* tab, int size) {

    int smallestGap = tab[1] - tab[0];

    for (int i = 0; i < size - 1; i++) {

        int dif = tab[i + 1] - tab[i];

        if (dif < smallestGap) {
            smallestGap = dif;
        }
    }
    return smallestGap;
}

int SmallGapWithUnsortedArray(int* tab, int size){

    int smallestGap = tab[1] - tab[0];

    for (int i = 0; i < size - 1; i++){
        for (int j = i + 1; j < size; j++){

            int difBetweenTab = abs(tab[i] - tab[j]);

            if (difBetweenTab < smallestGap)
            {
                smallestGap = difBetweenTab;
            }    
        }
    }
    return smallestGap;
}

bool SubsetSumExistsOrNot(int sum, int* tab, int size)
{
    for (int i = 0; i < size - 1; i++){
        for (int j = i + 1; j < size; j++){
            if ( tab[i] + tab[j] == sum)
            {
                std::cout << "True ";
                return true;
            }
        }
    }
    std::cout << "False ";
    return false;
}

int main() {
//Question 1
    int tabSorted[] = {1, 5, 7, 9, 11, 18};
    int tabUnSorted[] = {5, 18, 7, 9, 11, 1};
    
    std::cout << "Le plus petit écart avec SmallestGapSorted dans un tableau déjà trié est : " << SmallestGapWithSortedArray(tabSorted, std::size(tabSorted)) << std::endl;
    std::cout << "Le plus petit écart avec SmallestGapSorted est dans un tableau non trié est : " << SmallGapWithUnsortedArray(tabUnSorted, std::size(tabUnSorted)) << std::endl;

//Question 2
    int tabSumExist[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;

    std::cout << "Existe-t-il un sous-ensemble du tableau dont la somme est égale à la somme cible : " << SubsetSumExistsOrNot(sum,tabSumExist, std::size(tabSumExist)) << std::endl;

    return 0;
}