#include <iostream>
#include <vector>

using namespace std;

std::vector<int> primes;

int isPrime (int num) {
    bool isPrime = true;
    
    for (int i = 2; i <= num/2; i++) {
        if (num%i == 0) {
            isPrime = false;
        }
    }
    
    return isPrime;
}

void getPrime (int num) {
    int count = primes.size();
    for (int i = primes.empty() ? 2 : primes.back() + 1; count < num; i++) { 
        if (isPrime(i)) {
            count++;
            primes.push_back(i);
        }
    }
    
}

int josephus (int num) {
    int res = 0;
    int hop = 1;
    
    for (int i = 1; i <= num; i++) {
        if (i == 1) {
            continue;
        } else {
            if (primes.size() < num-i+1) {
                getPrime(num-i+1);
            }
            hop = primes[num-i];
            res = ((hop - 1)%i + 1 + res)%i;
        }
    }
    
    return res + 1;
}


int main()
{
    
    int n;
    
    std::cin >> n;
    
    while (n != 0) {
        std::cout << josephus(n) << endl;
        
        std::cin >> n;
    }
    
    

    return 0;
}
