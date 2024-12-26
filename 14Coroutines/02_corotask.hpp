#pragma once
#include <coroutine>
#include <exception>

// coroutine interface to deal with a simple task
// - providing resume() to resume the coroutine
class [[nodiscard]] CoroTask {
public:
    // initialize members for state and customization:
    struct promise_type;    // definition later in corotaskpromise.hpp
    using CoroHdl = std::coroutine_handle<promise_type>;
private:
    CoroHdl hdl;            // native coroutine handle

public:
    // constructor and destructor:
    CoroTask(auto h)
        : hdl{ h } {             // store coroutine handle in interface
    }
    ~CoroTask() {
        if (hdl) {
            hdl.destroy();      // destroy coroutine handle
        }
    }
    // don't copy or move:
    CoroTask(const CoroTask&) = delete;
    CoroTask& operator=(const CoroTask&) = delete;

    // API to resume the coroutine
    // - returns whether there is still something to process
    bool resume() const {
        if (!hdl || hdl.done()) {
            return false;       // nothing (more) to process
        }
        hdl.resume();         // RESUME (blocks until suspended again or the end)
        return !hdl.done();
    }
};

struct CoroTask::promise_type {
    auto get_return_object() {       // init and return the coroutine interface
        return CoroTask{ CoroHdl::from_promise(*this) };
    }
    auto initial_suspend() {         // initial suspend point
        return std::suspend_always{};  // - suspend immediately
    }
    void unhandled_exception() {     // deal with exceptions
        std::terminate();              // - terminate the program
    }
    void return_void() {             // deal with the end or co_return;
    }
    auto final_suspend() noexcept {  // final suspend point
        return std::suspend_always{};  // - suspend immediately
    }
};

