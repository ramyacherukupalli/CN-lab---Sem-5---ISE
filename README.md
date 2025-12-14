# Computer Networks Lab Programs

This repository contains implementations of various **Computer Networks (CN) laboratory experiments** written in **C and C++**.  
The programs cover key networking concepts such as **error detection, routing algorithms, traffic shaping, scheduling, and client–server communication**.

---

## 📁 List of Experiments

### 1. CRC Error Detection
- **File:** `CRC_16bit.cpp`
- **Description:** Implements Cyclic Redundancy Check (CRC) to detect transmission errors using a generator polynomial.

### 2. Client–Server Communication
- **Files:** `server.cpp`, `client.cpp`
- **Description:** Demonstrates basic client–server communication using socket programming.
- **Sample File:** `sample.txt`

### 3. Distance Vector Routing Algorithm
- **File:** `Distance_vector.cpp`
- **Description:** Simulates the Distance Vector routing algorithm used in computer networks.

### 4. Link State Routing Algorithm
- **File:** `Link_State_routing.c`
- **Description:** Implements the Link State routing algorithm using graph-based shortest path computation.

### 5. Leaky Bucket Algorithm
- **File:** `Leaky_bucket.c`
- **Description:** Simulates the Leaky Bucket algorithm for traffic shaping and congestion control.

### 6. Priority Queue Scheduling
- **File:** `Priority_queue.c`
- **Description:** Demonstrates packet scheduling using a priority queue mechanism.

---

## ⚙️ Execution Steps

### Compile and Run C++ Programs
```bash
g++ filename.cpp -o output.exe
output.exe
```
### Compile and Run C Programs
```bash
gcc filename.c -o output.exe
output.exe
```

## 📂 Project Structure
```
CN_LAB/
│
├── CRC_16bit.cpp
├── client.cpp
├── server.cpp
├── Distance_vector.cpp
├── Link_State_routing.c
├── Leaky_bucket.c
├── Priority_queue.c
├── sample.txt
├── .gitignore
└── README.md
```
