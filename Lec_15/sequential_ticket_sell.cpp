#include <iostream>
#include <thread>
#include <chrono>

void sell_tickets(int agent_id,int num_tickets_to_sell)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout<<"Agent "<<agent_id <<"has sold all his tickets"<<"\n";
}

int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    int num_agents = 5;
    int num_tickets = 150;
    for(int i=1;i<=num_agents;i++)
    {
        sell_tickets(i,num_tickets/num_agents);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Time taken: " << diff.count() << " s\n";
}