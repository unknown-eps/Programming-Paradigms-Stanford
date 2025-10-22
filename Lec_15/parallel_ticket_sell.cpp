#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

void sell_tickets(int agent_id,int num_tickets_to_sell)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout<<"Agent "<<agent_id <<"has sold all his tickets"<<"\n";
}
void sell_tickets_busy(int agent_id,int num_tickets_to_sell)
{
    auto start_time = std::chrono::high_resolution_clock::now();
    while (std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now() - start_time).count() < 1) {
    // Busy-wait
    }
    std::cout<<"Agent "<<agent_id <<"has sold all his tickets"<<"\n";
}
int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    int num_agents = 10000;
    int num_tickets = 150;
    std::vector<std::thread> agents;
    for(int i=1;i<=num_agents;i++)
    {
        agents.push_back(std::thread(sell_tickets,i,num_tickets/num_agents));
    }

    for(auto &agent: agents)
    {
        agent.join();
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Time taken: " << diff.count() << " s\n";
}