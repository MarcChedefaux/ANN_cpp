
# Artificial Neural Network in C++

This project aims to completely implement an Artificial Neural Network in C++. To implement this, I don't want to use any external library except the standard library.
The goal is to create the network object and to make it train on data. For this, I'll need to implement the feed forward algorithm to make the network infer. Eventually, I'll need to implement the back propagation algorithm to make it learn.


## Features

- Neural Network inference
- Neural Network training
- Different activation functions
- Save & Load system
- No use of external library


## Documentation

The documentation is available in the doc folder. It is generated thanks to Doxygen. To compile the documentation, run the following command
```bash
  make doc
```


## Running Tests

Test are executed with the Google-Test framework. To run tests, run the following command

```bash
  make prepare
  make test
```


## Run Locally

Clone the project

```bash
  git clone https://github.com/MarcChedefaux
```

Go to the project directory

```bash
  cd ANN_cpp
```

Prepare the different import

```bash
  make prepare
```

Run the main program

```bash
  make run
```


## Authors

- [@MarcChedefaux](https://www.github.com/MarcChedefaux)

