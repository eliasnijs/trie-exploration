import numpy as np
import matplotlib.pyplot as plt
import subprocess
import os

def saveplot(path:str, title:str, xname:str, yname:str, ax) -> None:
    ax.set_axisbelow(True)
    ax.yaxis.grid(color='silver')
    plt.subplots_adjust(bottom=0.15)
    plt.xlabel(xname) 
    plt.ylabel(yname)
    plt.title(title)
    plt.legend()
    plt.savefig(f"{path}.eps", format='eps')
    plt.savefig(f"{path}.png", format='png')


# arguments
benchmark_binary = "../build/benchmarks"

tries = ["array"]

filespath="../resources/"
files = [(filespath + filepath, os.stat(filespath + filepath).st_size) for filepath in os.listdir(filespath)]
files.sort(key=lambda x:(x[1], x[0]))

operations = [1]

# Run benchmarks
print(files)
for trie in tries:
    for oper in operations:
        for (filename, filelen) in files:
            args = f"{benchmark_binary} {trie} {filename} {oper}"
            print(args)
            popen = subprocess.Popen(args, stdout=subprocess.PIPE)
            popen.wait()
            result = float(popen.stdout.read())
            print(f"{filename:22} {trie:8} {result:12}")

