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

int main() {

    int tab[] = {1, 5, 7, 9, 11, 18};
    int tab2[] = {5, 18, 7, 9, 11, 1};

    std::cout << "Le plus petit écart avec SmallestGapSorted est : " << SmallestGapWithSortedArray(tab, std::size(tab)) << std::endl;

    std::cout << "Le plus petit écart avec SmallestGapSorted est : " << SmallGapWithUnsortedArray(tab2, std::size(tab)) << std::endl;

    return 0;
}