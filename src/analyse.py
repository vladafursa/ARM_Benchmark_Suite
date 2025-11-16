import pandas as pd
import matplotlib.pyplot as plt

# Load CSV
df = pd.read_csv("../results/benchmark_output.csv")

# Sorting benchmark
sort_df = df[df['test'] == 'sort']
plt.figure()
plt.plot(sort_df['value'], sort_df['time_ms'], marker='o')
plt.title("Sorting Benchmark")
plt.xlabel("Array size")
plt.ylabel("Time (ms)")
plt.grid(True)
plt.savefig("../results/sort_benchmark.png")

# Memory stride benchmark
mem_df = df[df['test'] == 'memory_stride']
plt.figure()
plt.plot(mem_df['value'], mem_df['time_ms'], marker='o')
plt.title("Memory Stride Benchmark")
plt.xlabel("Stride")
plt.ylabel("Time (ms)")
plt.grid(True)
plt.savefig("../results/memory_stride.png")

# Multithreading benchmark
thread_df = df[df['test'] == 'threads']
plt.figure()
plt.plot(thread_df['value'], thread_df['time_ms'], marker='o')
plt.title("Thread Scaling Benchmark")
plt.xlabel("Thread count")
plt.ylabel("Time (ms)")
plt.grid(True)
plt.savefig("../results/thread_scaling.png")

print("Plots saved in results/ folder")
