class Foo {
private:
    mutex mtx;
    condition_variable cv;
    int stage = 1;
public:
    Foo() {}
    void first(function<void()> printFirst) {
        unique_lock<mutex> lock(mtx);
        printFirst();
        stage = 2;
        cv.notify_all();
    }
    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [&]() { return stage == 2; });
        printSecond();
        stage = 3;
        cv.notify_all();
    }
    void third(function<void()> printThird) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [&]() { return stage == 3; });
        printThird();
    }
}; 