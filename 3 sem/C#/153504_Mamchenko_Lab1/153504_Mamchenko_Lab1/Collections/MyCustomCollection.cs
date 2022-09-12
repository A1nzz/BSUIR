using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using _153504_Mamchenko_Lab1.Interfaces;

namespace _153504_Mamchenko_Lab1.Collections
{

    public class Node<T>
    {

        public Node(T data)
        {
            Data = data;
        }
        public T? Data { get; set; }
        public Node<T>? Next { get; set; }
        public Node<T>? Prev { get; set; }

    }
    public class MyCustomCollection<T> : ICustomCollection<T>
    {
        private int _count = 0;

        private Node<T>? _head;

        private Node<T>? _tail;

        private Node<T>? _current;

        public MyCustomCollection()
        {
        }

        public T this[int index] { 
            get
            {
                if (index < 0 || index >= _count)
                {
                    throw new IndexOutOfRangeException();
                }
                var current = _head;
                for (int i = 0; i < index; i++)
                {
                    current = current.Next;
                }
                return current.Data;
            }
            set
            {
                if (index < 0 || index >= _count)
                {
                    throw new IndexOutOfRangeException();
                }
                var current = _head;
                for (int i = 0; i < index; i++)
                {
                    current = current.Next;
                }
                current.Data = value;
            }
        }

        public int Count
        {
            get { return _count; }
        }

        public void Add(T item)
        {
            var node = new Node<T>(item);
            if (_head == null)
            {
                _head = node;
                _current = node;
            }

            else
            {
                _tail.Next = node;
                node.Prev = _tail;
            }
            _tail = node;
            _count++;
        }

        public T Current()
        {
            if (_current == null)
            {
                throw new InvalidOperationException();
            }
            return _current.Data;
        }

        public void Next()
        {
            if (_current == null)
            {
                throw new InvalidOperationException();
            }
            if (_current.Next == null)
            {
                throw new InvalidOperationException();
            }
            _current = _current.Next;
        }

        public void Remove(T item)
        {
            var current = _head;
            while (current != null)
            {
                if (current.Data.Equals(item))
                {
                    if (_current.Equals(current))
                    {
                        RemoveCurrent();
                    } else
                    {
                        if (current.Prev != null)
                        {
                            current.Prev.Next = current.Next;
                        }
                        else
                        {
                            _head = current.Next;
                        }
                        if (current.Next != null)
                        {
                            current.Next.Prev = current.Prev;
                        }
                        else
                        {
                            _tail = current.Prev;
                        }
                        _count--;
                        return;
                    }
                    
                }
                current = current.Next;
            }
        }

        public T RemoveCurrent()
        {
            if (_current == null)
            {
                throw new InvalidOperationException();
            }
            var current = _current;
            if (current.Prev != null)
            {
                current.Prev.Next = current.Next;
                _current = current.Prev;
            }
            else
            {
                _head = current.Next;
            }
            if (current.Next != null)
            {
                current.Next.Prev = current.Prev;
                _current = current.Next; 
            }
            else
            {
                _tail = current.Prev;
            }
            if (_current.Next != null)
            {
                _current = _current.Next;
            }
            else if (_current.Prev != null)
            {
                _current = _current.Prev;
            }
            else
            {

                _current.Data = default(T);
            }
            _count--;
            return current.Data;
        }

        public void Reset()
        {
            _current = _head;
        }
    }
}
