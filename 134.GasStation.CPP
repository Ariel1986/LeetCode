/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1).
You begin the journey with an empty tank at one of the gas stations.
Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
Note:
The solution is guaranteed to be unique.
Tag: Greedy
*/

//Code:
//Code 1:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int maxGas = -1;
       
        auto canComplete = [&gas, &cost](int& leftGas, int begin, int end) -> int
        {
            for(int i = begin; i < end; ++i)
            {
                leftGas += gas[i];
                leftGas -= cost[i];
                if(leftGas < 0) return i;
            }
        
            return end;
        };
        
        for(int i = 0, iEnd = gas.size(); i < iEnd; )
        {
            int curGas = gas[i] - cost[i];
            int index = -1;
            if(curGas > maxGas) 
            {
                maxGas = curGas;
                int leftGas = 0;
                index = canComplete(leftGas, i, iEnd);
                if(index == iEnd)
                {
                    if(i == 0) return 0;
                    else if(leftGas > 0)
                    {
                        index = canComplete(leftGas, 0, i);
                        if(index == i) return i;
                    }
                }
                else
                    maxGas = -1;
            }
            i = std::max(index, i) + 1;
        }
        
        return -1;
    }
    
//Code 2:
int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost)
{
    if (gas.size() != cost.size()) return -1;
    
    const int stationNum = (int)gas.size();
    int startingStation = -1;
    for (int i = 0; i < stationNum; )
    {
        if (gas[i] - cost[i] < 0)
        {
            ++i;
            continue;
        }
        
        startingStation = i;
        int k = startingStation;
        int netGas = 0;
        for (;;)
        {
            netGas += gas[k%stationNum] - cost[k%stationNum];
            
            if (netGas < 0)
            {
                i = k+1;
                break;
            }
            
            ++k;
            if (k%stationNum == startingStation)
            {
                return startingStation;
            }
        }
    }
    
    return -1;
}
    
