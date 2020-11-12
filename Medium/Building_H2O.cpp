#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>

using namespace std;

class H2O {
private:
    mutex lk;
    condition_variable cv;
    int o = 1, h = 2;
    
public:    
    H2O() {
        
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> ul(lk);
        cv.wait(ul, [this]{
            return h > 0;
        }); 
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        h--;
        if(o == 0 && h == 0){
            o = 1;
            h = 2;
        }
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> ul(lk);
        cv.wait(ul, [this]{
            return o > 0;
        });
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        o--;
        if(o == 0 && h == 0){
            o = 1;
            h = 2;
        }
        cv.notify_all();
    }
};