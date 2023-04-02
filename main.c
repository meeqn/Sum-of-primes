#include <iostream>

using namespace std;

bool is_prime_number(unsigned int nb) {
        if (nb == 1)
                return 0;
        else if (nb == 2)
                return 1;
        else if (nb % 2 == 0)
                return 0;
        else {
                for (int j = 3; j <= ((nb + 1) / 2); j += 2) {
                        if (nb % j == 0)
                                return 0;
                
}
        
}
        return 1;
}

void write_chain(int* primeParts, int size) {
        for (int i = 0; i < size; i++) {
                cout << primeParts[i];
                if (i<size-1)
                        cout << "+";
        
}cout << endl;
}

void set_prime_arr(int firstComponent, int* firstNumbersArr) {
        int j = 0;
        for (int i = 0; i < (firstComponent + 1) / 2; i++) {
                firstNumbersArr[i] = 0;
        
}
        for (int i = 2; i <=firstComponent; i++) {
                if (is_prime_number(i)) {
                        firstNumbersArr[j] = i;
                        j++;
                
}
        
}
}

void partition(unsigned int baseNum, unsigned int sum, int parts[], int primes[], int partsAmount, int primesAmount, int partsIndex, int primesIndex) {
        if (sum == baseNum) {
                write_chain(parts, partsIndex);
                return;
        
}

        if (partsIndex >= partsAmount || sum > baseNum)
                return;

        for (int i = 0; i <primesAmount; i++) {
                if (partsIndex <= 1 || parts[partsIndex - 1] >= primes[i]) {
                        parts[partsIndex] = primes[i];
                        partition(baseNum, sum + primes[i], parts, primes, partsAmount, primesAmount, partsIndex + 1, i);
                
}
                else
                        return;
        
        
}

}

int main() {
        int lines;
        cin >> lines;
        for (int i = 0; i < lines; i++) {
                unsigned int baseNumber;
                int firstComponent;

                cin >> baseNumber >> firstComponent;

                if (is_prime_number(firstComponent)) {
                        int partsAmount = (baseNumber + 1) / 2;
                        int primesAmount = (firstComponent + 1) / 2;

                        int* primeParts = new int[partsAmount];
                        for (int j = 0; j < partsAmount; j++) {
                                primeParts[j] = 0;
                        
}
                        primeParts[0] = firstComponent;

                        int* primeNumbersArr = new int[primesAmount];
                        set_prime_arr(firstComponent, primeNumbersArr);
                        partition(baseNumber, firstComponent, primeParts, primeNumbersArr, partsAmount, primesAmount, 1, 0);

                        delete[] primeParts;
                        delete[] primeNumbersArr;
                
}
        
}
        return 0;
}
