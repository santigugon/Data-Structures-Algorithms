#ifndef MYQUEUE_H_INCLUDED
#define MYQUEUE_H_INCLUDED

class MyQueue{
    private:
        MyLinkedList lista;
    public:
        ~MyQueue();
        void enqueue(int data);
        void dequeue();
        int peek();
        bool isEmpty();
        int length();
        void flush();

};


#endif // MYQUEUE_H_INCLUDED
