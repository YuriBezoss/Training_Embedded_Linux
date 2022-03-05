FROM ubuntu:latest
# COPY . /usr/src/app

# Install dependencies
RUN apt-get update && apt-get upgrade -y &&\
	apt-get install -y software-properties-common 

# Install network packets
RUN apt-get install -y net-tools iputils-ping tcpdump\
    wget unzip

# Install Python
RUN apt-get install -y python3 python3-pip &&\
    pip3 install gitlint

# Install Buildtools
RUN apt-get install -y build-essential \
    clang-format clang-format-10 clang-tools-10 \
    cmake gcovr git libcunit1-dev ninja-build \
	 clang lldb llvm gdb autoconf

# Install Linux tools
RUN apt-get install -y vim && \
    apt-get clean;

# Set working directory
WORKDIR /dev/

# Compile wakaama server
#RUN cmake ./examples/server &&\
#    cmake ./examples/client &&\
#    make

