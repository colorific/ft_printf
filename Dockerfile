FROM ubuntu

RUN apt-get update
RUN apt-get upgrade -y

RUN apt-get -y install build-essential
RUN apt-get -y install gcc

# http://packages.ubuntu.com/de/trusty/valgrind
RUN apt-get -y install valgrind

# create volume
RUN mkdir -p /root/build
VOLUME /root/build
