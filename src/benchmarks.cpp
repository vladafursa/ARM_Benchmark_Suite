#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <thread>
#include <numeric>
#include <fstream>
#include <random>
#include <cmath>

using namespace std;
using namespace std::chrono;

long long run_sort_test(size_t size) {
    vector<int> data(size);
    iota(data.begin(), data.end(), 0);
    shuffle(data.begin(), data.end(), default_random_engine());

    auto start = high_resolution_clock::now();
    sort(data.begin(), data.end());
    auto end = high_resolution_clock::now();

    return duration_cast<milliseconds>(end - start).count();
}

long long run_memory_stride_test(size_t size, size_t stride) {
    vector<int> arr(size, 1);
    long long sum = 0;

    auto start = high_resolution_clock::now();
    for (size_t i = 0; i < size; i += stride)
        sum += arr[i];
    auto end = high_resolution_clock::now();

    return duration_cast<milliseconds>(end - start).count();
}

long long run_multithread_test(int threads) {
    auto start = high_resolution_clock::now();

    vector<thread> workers;
    for(int i = 0; i < threads; i++) {
        workers.emplace_back([](){
            double x = 0;
            for(int j = 0; j < 1e7; j++) x += sin(j);
        });
    }

    for(auto& t : workers) t.join();
    auto end = high_resolution_clock::now();

    return duration_cast<milliseconds>(end - start).count();
}

int main() {
    // Create CSV file
       ofstream fout("results/benchmark_output.csv");
       fout << "test,type,value,time_ms\n";

       // Sorting benchmark
       for(size_t size : {100000, 500000, 1000000}) {
           long long ms = run_sort_test(size);
           fout << "sort,array_size," << size << "," << ms << "\n";
       }

       // Memory benchmark
       for(size_t stride : {1, 16, 64, 256}) {
           long long ms = run_memory_stride_test(1e7, stride);
           fout << "memory_stride,stride," << stride << "," << ms << "\n";
       }

       // Multithreading benchmark
       for(int threads : {1, 2, 4, 8}) {
           long long ms = run_multithread_test(threads);
           fout << "threads,count," << threads << "," << ms << "\n";
       }

       fout.close();
       cout << "Benchmark results saved to results/benchmark_output.csv\n";
       return 0;
}
