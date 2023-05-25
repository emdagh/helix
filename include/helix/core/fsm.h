#pragma once

namespace helix
{

template <typename T> struct state
{
    virtual void enter(const T&) = 0;
    virtual void update(const T&) = 0;
    virtual void leave(const T&) = 0;
};

template <typename T> class fsm
{
    using ptr_t = state<T>*; // std::unique_ptr<state<T>>;
    std::stack<ptr_t> _stack;

public:
    void push(const T& t, state<T>* s)
    {
        pop();
        _stack.push(s);
        _stack.top()->enter(t);
    }

    void pop(const T& t)
    {
        if (_stack.size())
        {
            _stack.top()->leave(t);
        }
    }
};
} // namespace helix