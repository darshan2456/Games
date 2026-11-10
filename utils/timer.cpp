#include <thread>
#include <chrono>
void sleep_seconds(double val){
    std::this_thread::sleep_for( std::chrono::duration<double>(val) );
}
