#pragma once
/*
void for_main:
	- define a queue of string 'messages'
	- define a mutex 'message_mutex'
	- define a condition_variable 'message_condition_variable'

	- spawn a jthread:
		- lambda
			- capture by reference (minimal)
			- params: stop_topen
			- body:
				- while the stop_token's stop isn't requested
					- declare a local string message
					- new scope
						- unique lock the messages_mutex
						- if messages_cv .wait
							- pass in the lock, stop_token, lambda return the messages queue not empty
							- then return // stop requested

						- assign the front of the message queue to the local message
						- pop out the message queue

					- print std::cout << "msg: " << msg << std::endl;


	- iterate of {"Tic", "Tac", "Toe"}
		- scoped_lock on the messages mutex
		- push the current string to the message queue
		- notify one of the messages_condition_variable

	- sleep the thread for 1 second
	- new scope
		- scoped_lock on the messages_mutex
		- push "done" to the queue
		- notify all

	- sleep the thread for one second
*/
#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <mutex>
#include <queue>
#include <condition_variable>
#include <print>

using namespace std::literals;

void for_main()
{
	std::queue<std::string> messages;
	std::mutex messages_mutex;
	std::condition_variable_any messages_condition_variable;

	std::jthread jthread{ [&messages, &messages_mutex, &messages_condition_variable](std::stop_token stop_token)
		{
			while (not stop_token.stop_requested())
			{
				std::string local_message;
				{
					std::unique_lock unique_lock{ messages_mutex };
					if (not messages_condition_variable.wait(
						unique_lock, stop_token, [&messages]{return not messages.empty();}))
					{
						return;
					}
				}
				local_message = messages.front();
				messages.pop();
				std::println("local_message: {}", local_message);
			}
		}
	};

	for (std::string string : { "Tic", "Tac", "Toe" })
	{
		std::scoped_lock scoped_lock{ messages_mutex };
		messages.push(string);
		messages_condition_variable.notify_one();
	}

	std::this_thread::sleep_for(1s);

	{
		std::scoped_lock scoped_lock{ messages_mutex };
		messages.push("done");
		messages_condition_variable.notify_all();
	}

	std::this_thread::sleep_for(1s);
}