### 网络(socket)编程

#### 网络编程的复杂性

1. 与原来的多文件 单个程序的文件不同，网络编程需要至少两个：一个服务器（server）和一个以上的客户端（client）
2. 第一个程序为server.c（依赖于一些.h头文件和.c文件的一个文件）在主机上 第二个为client.c
3. 多个程序的关系：一种可能的架构——每个client段都跟server建立信道（connection)，从而达到信息的收发
4. **建立信道（connection）是最麻烦的、最为关键的**一步，建立之后实现**send**和**recieve**两个函数即可

#### 如何建立信道（connection）

eg.http://1.15.154.28:5000

- 第一个部分“1.15.154.28”为ip地址，定位到唯一的主机
- 第二个“:5000”为端口号(port)，要尽量设大，如http服务端口号为80
- 第三个为用户协议(protocol) 如"http:"，目的是要使server和client都能够理解互相发送的信息数据，即规定收发的数据格式
    - 需要server端实现：listen(ip,port)功能，用于被动(passive)监听是否有client端需要建立链接
    - 需要client端实现：connect(ip,port)功能，用于主动(active)发送请求
        - 套接字(socket)函数，client和server端各有一个socket，拼接成一个connection
        - server端：socket创建之后需要实现①绑定ip地址bind(server,ip,port)函数②listen(s)监听有没有请求的发送
          并且需要所有的ip地址全部监听到`③while(1){accept(s)}//当有请求发送时 接受并创建一个对应的socket(client*)`
        - client端：socket创建知乎实现connect(client,ip,port)的链接后与socket(client*)链接即可
        - **注意相互连接的socket为socket(client)和socket(client*)，socket(server)只起到了门卫的作用**
