# Apple Silicon ARM Benchmark Suite

This project provides a benchmarking tool to evaluate how different workloads behave on Apple Silicon ARM processors.  
It focuses on runtime characteristics related to **memory locality**, **cache behaviour**, and **thread scalability**.

---

## Overview
The benchmark suite measures performance across:
- **Sorting** with increasing dataset sizes  
- **Memory access** using variable stride patterns  
- **Parallel compute workloads** using multiple threads  

Execution results are exported to **CSV** and can be visualised using the provided **Python script**.

---

##  Repository Structure
```
arm-benchmark-suite/
│
├── src/
│   └── benchmarks.cpp
|   └── analyse.py
│
├── results/
│   └── benchmark_output.csv
│   └── memory_stride.png
│   └── sort_benchmark.png
│   └── thread_scaling.png
│
|── .gitignore
└── README.md

```

## Build and Run
Tested on **macOS with Apple Silicon (ARM64)**.

**Compile:**
```bash
cd src
g++  benchmarks.cpp -o benchmarks 
```
**Analyse**
```
python3 analyse.py
```

