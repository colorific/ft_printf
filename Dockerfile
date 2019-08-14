FROM ubuntu

RUN apt-get update
RUN apt-get upgrade -y

RUN apt-get -y install build-essential
RUN apt-get -y install gcc

# http://packages.ubuntu.com/de/trusty/valgrind
RUN apt-get -y install valgrind

# install sshd
RUN apt-get install -y vim openssh-server

# enable login with root over ssh
RUN mkdir /var/run/sshd
RUN echo 'root:root' | chpasswd
RUN sed -i 's/PermitRootLogin without-password/PermitRootLogin yes/' /etc/ssh/sshd_config
RUN sed 's@session\s*required\s*pam_loginuid.so@session optional pam_loginuid.so@g' -i /etc/pam.d/sshd

# create volume
RUN mkdir -p /root/build
VOLUME /root/build

# launch
CMD /usr/sbin/sshd -D
EXPOSE 22
