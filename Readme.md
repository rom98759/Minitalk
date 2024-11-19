# Minitalk

Minitalk is a simple messaging application that allows communication between a client and a server using UNIX signals. This project was completed as part of the 42 cursus.

## Table of Contents

- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [License](#license)
- [Author](#author)

## Features

- Send and receive messages between client and server.
- Handle basic error checking and signal handling.
- Implemented in C.

### How it works

1. The server starts and displays its process ID (PID).
2. The client sends a message to the server by sending signals with the message encoded in binary.
3. The server receives the signals, decodes the message, and stores it in a list.
4. When the server receives the end-of-transmission signal, it displays the message on the standard output.


## Requirements

- UNIX-based operating system.
- GCC compiler.

## Installation

1. Clone the repository:
	```sh
	git clone https://github.com/yourusername/minitalk.git
	```
2. Navigate to the project directory:
	```sh
	cd minitalk
	```
3. Compile the server and client:
	```sh
	make
	```

## Usage

1. Start the server:
	```sh
	./server
	```
2. In a new terminal, send a message from the client:
	```sh
	./client <server_pid> "Your message here"
	```

## License

This project is licensed under the MIT License.

## Author

- Romain -  Github : [rom98759](https://github.com/rom98759)
