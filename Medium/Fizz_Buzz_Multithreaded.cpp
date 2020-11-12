#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>

using namespace std;

class FizzBuzz {
private:
    int n, turn = 1;
    mutex lock;
    condition_variable cond_var;

public:
    FizzBuzz(int n) {
        this->n = n;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        int num = n/3 - n/15;
        for(int i=0; i<num; i++){
            unique_lock<mutex> ul(lock);
            cond_var.wait(ul, [this]{
                return turn % 3 == 0 && turn % 5 != 0;                
            });
            printFizz();
            turn++;
            cond_var.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        int num = n/5 - n/15;
        for(int i=0; i<num; i++){
            unique_lock<mutex> ul(lock);
            cond_var.wait(ul, [this]{
                return turn % 3 != 0 && turn % 5 == 0;                
            });
            printBuzz();
            turn++;
            cond_var.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        int num = n/15;
        for(int i=0; i<num; i++){
            unique_lock<mutex> ul(lock);
            cond_var.wait(ul, [this]{
                return turn % 15 == 0;                
            });
            printFizzBuzz();
            turn++;
            cond_var.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        int num = n - n/3 - n/5 + n/15;
        for(int i=0; i<num; i++){
            unique_lock<mutex> ul(lock);
            cond_var.wait(ul, [this]{
                return turn % 3 != 0 && turn % 5 != 0;               
            });
            printNumber(turn);
            turn++;
            cond_var.notify_all();
        }
    }
};