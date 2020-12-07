#include <iostream>
#include <thread>
#include <vector>
#include <future>
#include <numeric>

void dotProd(const std::vector<double> &a, const std::vector<double> &b, std::promise<double> &p) {
       
    try {
        if (a.size() != b.size()) {
            throw std::runtime_error("vector_size_err");
        }

        p.set_value( std::inner_product(a.begin(), a.end(), b.begin(), 0.0) );              
    }
    catch (const std::exception &e) {
        p.set_exception(std::current_exception());
    }     

    // return p;   
}

int main() {
 
    std::vector<double> a = {1, 2, 3};
    std::vector<double> b = {1, 2, 3, 4};
    
    std::array<std::thread, 10> threads;
    double sum = 0;

    for (auto &t : threads) {
        
        t = std::thread ([&]{
            std::promise<double> prom;
            std::future<double> fut = prom.get_future(); // = dotProd(a, b, prom).get_future();

            dotProd(a, b, prom);
            try {
                //double g = fut.get();
                //std::cout << "result: " << g << "\n";
                sum += fut.get();
            }
            catch(const std::exception &e) {
                std::cout << "exception caught: " << e.what() << '\n';
            }    
        });
        
        t.join();
    }

    
/*
    std::cout << "waiting...\n";

    for (auto &t : threads) {
        t.join();
    }
*/
    std::cout << "sum = " << sum << "\n";

    return 0;
}