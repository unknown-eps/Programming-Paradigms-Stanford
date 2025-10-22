#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

void sell_tickets(int agent_id,int* ptr)
{
    while (*ptr>0) 
    {
        *ptr = *ptr-1;
    }
}
int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    int num_agents = 10000;
    int num_tickets = 150000;
    int* ptr =&num_tickets;
    std::vector<std::thread> agents;
    for(int i=1;i<=num_agents;i++)
    {
        agents.push_back(std::thread(sell_tickets,i,ptr));
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