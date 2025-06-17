std::mutex m;
std::condition_variable cv;
class FizzBuzz {
private:
    int n;
    int curr=1;
public:

    FizzBuzz(int n) {
        this->n = n;
        
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while(true){
            std::unique_lock<std::mutex> lock(m);
            if(curr>n) break;
            if(curr%3==0 && curr%5!=0){
                printFizz();
                curr++;
                cv.notify_all();
            }
            else{
                cv.wait(lock);
            }
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while(true){
            std::unique_lock<std::mutex> lock(m);
            if(curr>n) break;
            if(curr%3!=0 && curr%5==0){
                printBuzz();
                curr++;
                cv.notify_all();
            }
            else{
                cv.wait(lock);
            }
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while(true){
            std::unique_lock<std::mutex> lock(m);
            if(curr>n) break;
            if(curr%3==0 && curr%5==0){
                printFizzBuzz();
                curr++;
                cv.notify_all();
            }
            else{
                cv.wait(lock);
            }
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while(true){
            std::unique_lock<std::mutex> lock(m);
            if(curr>n) break;
            if(curr%3!=0 && curr%5!=0){
                printNumber(curr);
                curr++;
                cv.notify_all();
            }
            else{
                cv.wait(lock);
            }
        }
    }
};