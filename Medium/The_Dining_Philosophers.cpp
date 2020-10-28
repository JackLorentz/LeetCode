#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>

using namespace std;

/**
 * 資源分級法: 每個叉子給個編號0-4, 每個人一定要先拿低編號叉子再拿高編號的叉子, 
 * 這樣第一輪最高編號的人沒法用餐而最低編號可以拿最高編號的叉子開始用餐
*/

class DiningPhilosophers {
public:
    int l_id = 0, r_id = 0;//每位哲學家左右叉子編號
    bool forks[5] = {false};//每個叉子使用狀況
    condition_variable cond_var;
    mutex l_lock, r_lock;
    
    DiningPhilosophers() {
        
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
		unique_lock<mutex> l_cv(l_lock);
        unique_lock<mutex> r_cv(r_lock);
        
        if(philosopher-1 < 0)   l_id = 4;
        else
            l_id = philosopher-1;
        
        //先拿低編號叉子
        cond_var.wait(l_cv, [this]{
            return !forks[l_id];
        });
        pickLeftFork();
        forks[l_id] = true;
        
        //再拿高編號的叉子
        r_id = (philosopher+1)%5;
        cond_var.wait(r_cv, [this]{
            return !forks[r_id];
        });
        pickRightFork();
        forks[r_id] = true;
        
        eat();
        
        putLeftFork();
        forks[l_id] = false;
        l_lock.unlock();
        cond_var.notify_all();
        
        putRightFork();
        forks[r_id] = false;
        r_lock.unlock();
        cond_var.notify_all();
    }
};