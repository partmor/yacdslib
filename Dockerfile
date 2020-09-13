FROM ubuntu:18.04

RUN apt-get update && apt-get upgrade -y
RUN apt-get install -y \
    automake \
    autoconf \
    libtool \
    pkg-config \
    texinfo \
    build-essential \
    wget \
    libssl-dev 

RUN apt remove --purge cmake && hash -r

RUN wget https://github.com/Kitware/CMake/releases/download/v3.18.2/cmake-3.18.2.tar.gz
RUN tar -zxvf cmake-3.18.2.tar.gz
WORKDIR /cmake-3.18.2
RUN ./bootstrap
RUN make && make install
WORKDIR /
RUN rm -rf cmake-3.18.2

RUN wget https://github.com/libcheck/check/releases/download/0.15.2/check-0.15.2.tar.gz
RUN tar -zxvf check-0.15.2.tar.gz
WORKDIR /check-0.15.2
RUN autoreconf --install && ./configure
RUN make && make install
WORKDIR /
RUN rm -rf check-0.15.2

COPY CMakeLists.txt Doxyfile README.md /pkg/
COPY cmake/ /pkg/cmake/
COPY src/ /pkg/src/
COPY tests/ /pkg/tests/
WORKDIR /pkg

RUN mkdir build 
WORKDIR /pkg/build
RUN cmake ..
RUN make
RUN make test
