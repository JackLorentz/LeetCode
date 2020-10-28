#include <stdio.h>
//#include <pthread.h>
#include <unistd.h>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>

using namespace std;

/*static int turn = 0;

// 子執行緒函數
void* child(void *data) {
    int n = *((int*)data); // 取得輸入資料
    for(int i=0; i<n; i++) {
        while(turn != 1){} 
        printf("bar"); // 每秒輸出文字
        turn = 0;
        //sleep(1);
    }
    pthread_exit(NULL); // 離開子執行緒
}*/

class FooBar {
private:
    int n;
    int turn = 0;
    mutex lock;//確保CS只有一個線程存取的鎖
    condition_variable cond_var;//負責執行wait和signal

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo() {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> ul(lock);//管理mutex工具, 避免函數被中斷而未被解鎖的情況
            cond_var.wait(ul, [this]{
                return turn % 2 == 0;//若turn為偶數才會解除busy waiting進入CS並上鎖
            });
        	// printFoo() outputs "foo". Do not change or remove this line.
        	cout << "foo";
            turn++;
            cond_var.notify_one();//相當於signal(解鎖, 讓其他線程存取CS)
        }
    }

    void bar() {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> ul(lock);
            cond_var.wait(ul, [this]{
                return turn % 2 == 1;
            });
            // printBar() outputs "bar". Do not change or remove this line.
            cout << "bar";
            turn++;
            cond_var.notify_one();
        }
    }
};

// 主程式
int main() {
    int n = 4;
    /*pthread_t t; // 宣告 pthread 變數
    pthread_create(&t, NULL, child, &n); // 建立子執行緒*/
    FooBar fb(n);
    thread f(&FooBar::foo, &fb);
    thread b(&FooBar::bar, &fb);
    f.join();
    b.join();

    // 主執行緒工作
    /*for(int i=0; i<n; i++) {
        while(turn != 0){}
        printf("foo"); // 每秒輸出文字
        turn = 1;
        //sleep(1);
    }

    pthread_join(t, NULL); // 等待子執行緒執行完成*/
    return 0;
}