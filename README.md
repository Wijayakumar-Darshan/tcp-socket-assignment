# TCP Client-Server Socket Programming

## Assignment II

This project demonstrates a simple TCP client-server application using TCP socket communication in a Linux environment.

The application allows a client to connect to a server, send a message, receive a response from the server, and successfully terminate the connection.

---

## Features

- TCP server implementation
- TCP client implementation
- Client-server communication using TCP sockets
- Client sends a message to the server
- Server receives and processes the message
- Server sends a response back to the client
- Successful connection termination

---

## Technologies Used

- C Programming Language
- Linux Environment (Ubuntu WSL)
- POSIX TCP Socket API
- GCC Compiler
- Make Build Tool

---

## Project Structure

```
tcp-socket-assignment/
│
├── server.c        # TCP server program
├── client.c        # TCP client program
├── Makefile        # Compilation automation
├── README.md       # Project documentation
└── .gitignore      # Ignored files
```

---

## How to Compile

### Using Makefile

Run:

```bash
make
```

This will create:

```
server
client
```

executables.

---

## How to Run

### Step 1: Start the Server

Open the first terminal:

```bash
./server
```

Expected output:

```
Server started...
Waiting for client connection...
```

---

### Step 2: Start the Client

Open another terminal:

```bash
./client
```

Expected output:

```
Connected to server
Message sent: Hello Server
Server response: Message received successfully from server
Connection closed
```

---

## Server Output Example

```
Server started...
Waiting for client connection...
Client connected successfully
Client message: Hello Server
Response sent to client
Connection closed
```

---

## Client Output Example

```
Connected to server
Message sent: Hello Server
Server response: Message received successfully from server
Connection closed
```

---

## Cleaning Compiled Files

To remove generated executable files:

```bash
make clean
```

---

## Google Drive Link

link : [https://drive.google.com/file/d/1VhLi2pV6LaIno04DKMwwpFhK4Alz6X7g/view?usp=sharing]

## Author

Darshan Wijayakumar
