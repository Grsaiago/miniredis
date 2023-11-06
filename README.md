# Miniredis
🚨This is a WIP, some sections may describe what I'll do instead of what's already implemented🚨 <br/>

✨ A miniature version of Redis in C++ ✨<br/>
"Why?" you may ask! <br/>
Why not? This project aims to improve my understanding of sockets, communication protocols, and OOP concepts.

## Socket
Well, let's start from the beginning, shall we? <br/>
The sockets used in this project are all TCP/IPV4 SO_NONBLOCK Sockets with SO_REUSEADDR. The main server socket is the Type ATcpIpSocket. <br/>
This ensures that: <br/>
* A) Using TCP, we have reliability on the protocol's handshake/ack features.
* B) By using SO_NONBLOCK, we ensure we can handle multiple connections with poll/epoll.
* C) By using SO_REUSEADDR we ensure that the same port can be reassigned to another process after the redis turns off, or it can be restarted on the same port if for some reason it closes.
* D) I'm able to practice OOP concepts in creating the classes for the connections xD

## Protocol
Miniredis doesn't implement every type in the Redis Serialization Protocol [(RESP)](https://redis.io/docs/reference/protocol-spec/), but it supports the following: <br/>
* ```+```: Simple strings.
* ```-```: Error values.
* ```:```: Base 10 ints.
* ```*```: Arrays.
* ```$```: Bulk Strings.

### ```+```: Simple strings
WIP

### ```-```: Error values
WIP

### ```:```: Base 10 ints
WIP

### ```*```: Arrays
WIP

### ```$```: Bulk Strings
WIP
