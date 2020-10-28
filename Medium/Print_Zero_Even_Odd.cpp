#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>

using namespace std;

class ZeroEvenOdd {
private:
    int n, turn = 1;
    mutex lock;
    condition_variable cond_var;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero() {
        for(int i=1; i<=n; i++){
            unique_lock<mutex> ul(lock);
            cond_var.wait(ul, [this]{
                return (turn % 4 == 1 || turn % 4 == 3);
            });
            cout << "0";
            turn++;
            //lock.unlock();
            cond_var.notify_all();
            /**
             * 兩者的差別，在於 notify_all() 會去通知所有正在等待這個 condition_variable 的執行序，而  notify_one() 則只會通知其中一個。
            */
        }
    }

    void even() {
        int num = n/2;
        for(int i=1; i<=num; i++){
            unique_lock<mutex> ul(lock);
            cond_var.wait(ul, [this]{
                return turn % 4 == 0;
            });
            cout << (turn/2);
            turn++;
            //lock.unlock();
            cond_var.notify_all();
        }
    }

    void odd() {
        int num = 0;
        if(n%2 == 0)    num = n/2;
        else
            num = n/2+1;
        for(int i=1; i<=num; i++){
            unique_lock<mutex> ul(lock);
            cond_var.wait(ul, [this]{
                return turn % 4 == 2;
            });
            cout << (turn/2);
            turn++;
            //lock.unlock();
            cond_var.notify_all();
        }
    }
};

int main(void){
    int n = 51;
    ZeroEvenOdd zeo(n);
    thread z(&ZeroEvenOdd::zero, &zeo);
    thread e(&ZeroEvenOdd::even, &zeo);
    thread o(&ZeroEvenOdd::odd, &zeo);
    z.join();
    e.join();
    o.join();
    return 0;
}