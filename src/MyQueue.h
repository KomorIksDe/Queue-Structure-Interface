#ifndef MYQUEUE_H_INCLUDED
#define MYQUEUE_H_INCLUDED

template<typename T>
class MyQueue {
    private:
        struct Element {
            Element* prev = nullptr;
            T data;

            Element(T& data)
            :   data(data)
            { }
        };

        int count      = 0;
        Element* first = nullptr;
        Element* last  = nullptr;

    public:
        ~MyQueue() {
            clear();
        }

        void clear() {
            while(count != 0)
                pop();
        }

        T& front() const {
            if(count != 0)
                return this->first->data;
        }

        T& back() const {
            if(count != 0)
                return this->last->data;
        }

        bool empty() const {
            return this->count == 0;
        }

        int size() const {
            return this->count;
        }

        void push(T& data) {
            Element* elem = new Element(data);

            if(count == 0) {
                first = elem;
                last  = elem;
                count++;

                return;
            }

            first->prev = elem;
            first = elem;
            count++;
        }

        void pop() {
            if(count == 0) {
                first = nullptr;
                last  = nullptr;
                count--;

                return;
            }

            Element* temp = last;

            last = last->prev;
            delete temp;
            count--;
        }
};

#endif // MYQUEUE_H_INCLUDED
