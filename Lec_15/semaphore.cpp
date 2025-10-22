#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>

void sell_tickets(int agent_id, int* ptr, std::mutex& ticket_mutex)
{
    while (true) 
    {
        ticket_mutex.lock();
        if (*ptr > 0) {
            *ptr = *ptr - 1;
            ticket_mutex.unlock(); // Commenting this line will put the process in a deadlock.
        } else {
            ticket_mutex.unlock();
            break;
        }
    }
}
int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    int num_agents = 10000;
    int num_tickets = 150000;
    int* ptr = &num_tickets;
    std::mutex ticket_mutex;
    std::vector<std::thread> agents;
    for(int i=1;i<=num_agents;i++)
    {
        agents.push_back(std::thread(sell_tickets, i, ptr, std::ref(ticket_mutex)));
    }

    for(auto &agent: agents)
    {
        agent.join();
    }
    std::cout<<"Final rem tickets "<<*ptr<<std::endl;
    // auto end = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double> diff = end - start;
    // std::cout << "Time taken: " << diff.count() << " s\n";
}