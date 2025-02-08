# Use the Ubuntu 22 as the base image
FROM ubuntu:22.04

# Set environment variables
ENV DEBIAN_FRONTEND=noninteractive \
    EIGEN_VERSION=3.4.0 \
    LD_LIBRARY_PATH=/usr/local/lib/

# Update system packages, install dependencies
RUN apt-get update -y && \
    apt-get upgrade -y && \
    apt-get install -y \
    sudo git g++ make wget cmake gdb && \
    rm -rf /var/lib/apt/lists/* && \
    apt-get clean

# Install fmt from source
WORKDIR /app
RUN git clone https://github.com/fmtlib/fmt.git && \
    cd fmt && \
    mkdir build && \
    cd build && \
    cmake .. && \
    make && \
    make install && \
    make test && \
    cd ../.. && \
    rm -rf fmt

# Install libeigen from source
WORKDIR /app
RUN wget --no-verbose https://gitlab.com/libeigen/eigen/-/archive/${EIGEN_VERSION}/eigen-${EIGEN_VERSION}.tar.gz && \
    tar xzf eigen-${EIGEN_VERSION}.tar.gz && \
    cd eigen-${EIGEN_VERSION} && \
    mkdir build && \
    cd build && \
    cmake .. && \
    make && \
    make install && \
    cd ../.. && \
    rm -rf eigen-${EIGEN_VERSION}.tar.gz eigen-${EIGEN_VERSION}

# Install Catch2
WORKDIR /app
RUN git clone https://github.com/catchorg/Catch2.git && \
    cd Catch2 && \
    cmake -B build -S . -DBUILD_TESTING=OFF && \
    cmake --build build/ --target install && \
    cd .. && \
    rm -rf Catch2

# Install clang-format and clang-tidy
RUN apt-get update && \
    apt-get install -y gnupg lsb-release software-properties-common && \
    wget https://apt.llvm.org/llvm.sh && \
    chmod +x llvm.sh && \
    ./llvm.sh 19 && \
    apt-get install -y clang-format-19 clang-tidy-19 && \
    apt-get clean
