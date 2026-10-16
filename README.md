# FCFS CPU Scheduling Algorithm

A menu-driven **Operating Systems Mini Project** implemented in C that simulates the First Come, First Served (FCFS) CPU scheduling algorithm.

## 📌 Project Overview

First Come, First Served (FCFS) is a non-preemptive CPU scheduling algorithm in which processes are executed in the order of their arrival time. The process that arrives first gets the CPU first.

This project helps demonstrate CPU scheduling concepts, process management, and performance evaluation.

## ✨ Features

- Add and manage process details
- Execute FCFS CPU scheduling
- Calculate Completion Time (CT)
- Calculate Turnaround Time (TAT)
- Calculate Waiting Time (WT)
- Display a Gantt chart
- Calculate average waiting and turnaround times
- Search for process details
- Reset process data
- Menu-driven interface

## 🛠️ Technologies Used

- **Programming Language:** C
- **Compiler:** GCC
- **Editor:** Visual Studio Code
- **Concepts:** CPU Scheduling, Structures, Arrays, Functions, Loops, and Conditional Statements

## ⚙️ How to Run

### 1. Clone the Repository

```bash
git clone https://github.com/shreyash905-dev/fcfs.git
```

### 2. Open the Project Folder

```bash
cd fcfs
```

### 3. Compile the Program

```bash
gcc fcfs.c -o fcfs.exe
```

### 4. Execute the Program

**Windows PowerShell:**

```powershell
.\fcfs.exe
```

## 📊 Scheduling Formulas

| Metric | Formula |
|---|---|
| Completion Time (CT) | Time at which the process finishes |
| Turnaround Time (TAT) | CT − Arrival Time |
| Waiting Time (WT) | TAT − Burst Time |
| Average Waiting Time | Total WT / Number of Processes |
| Average Turnaround Time | Total TAT / Number of Processes |

## 🧠 Algorithm

1. Accept the number of processes and their arrival and burst times.
2. Arrange the processes in FCFS order based on arrival time.
3. Calculate the start and completion times.
4. Calculate turnaround time and waiting time for each process.
5. Display the process table and Gantt chart.
6. Calculate and display average waiting and turnaround times.

## 🎯 Learning Outcomes

- Understand non-preemptive CPU scheduling.
- Implement FCFS using the C programming language.
- Calculate CPU scheduling performance metrics.
- Represent process execution using a Gantt chart.
- Strengthen programming and problem-solving skills.

## 👨‍💻 Author

**Shreyash Kadam**

GitHub: [@shreyash905-dev](https://github.com/shreyash905-dev)

## 📄 License

This project is created for educational purposes as part of an Operating Systems mini project.
