#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;


//convert an integer to a binary string using repeated subtraction algorithm
string decToBin (int num)
{
    string out = "";
    for (int i=7; i>=0; i--)
    {
        if (num >= (1<<i))
        {
            num = num - (1<<i);
            out += "1";
        }
        else
        {
            out += "0";
        }
    }
    return out;
}

string mapAS (string ip1, string ip2, string ip3, string ip4, ifstream& ASlist)
{
    int ipdec;
    string ipBin, asIpBin, teststr;
    string out;
    string asIp1, asIp2, asIp3, asIp4, asPrefix, asId;
    ipdec = atoi(ip1.data());
    string asLine;
    ipBin = decToBin(atoi(ip1.data())) + decToBin(atoi(ip2.data())) +
        decToBin(atoi(ip3.data())) + decToBin(atoi(ip4.data())) ;
    stringstream ss;
    int currentMatch = 0;
    while (getline(ASlist, asLine, '\n'))
    {
        if (count(asLine.begin(),asLine.end(), '.') == 3)
        {
            ss.clear();
            ss << asLine;
            getline(ss, asIp1, '.');
            getline(ss, asIp2, '.');
            getline(ss, asIp3, '.');
            getline(ss, asIp4, ' ');
            getline(ss, asPrefix, '.');
            getline(ss, asId, '\n');
            asIpBin = decToBin(atoi(asIp1.data())) + decToBin(atoi(asIp2.data())) +
            decToBin(atoi(asIp3.data())) + decToBin(atoi(asIp4.data())) ;
            if (atoi(asPrefix.data()) > currentMatch)
            {
                for (int i=0; i<atoi(asPrefix.data()); i++)
                {
                    if (ipBin.at(i) == asIpBin.at(i))
                    {
                        if (i == atoi(asPrefix.data()) - 1)
                        {
                            out = asIp1 + "." + asIp2 + "." + asIp3 + "." + asIp4 + "/" + asPrefix + " " +
                                    asId + ip1 + "." + ip2 + "." + ip3 + "." + ip4 + "\n" ;
                            currentMatch = atoi(asPrefix.data());
                        }
                    }
                    else
                    {
                        break;
                    }
                }
            }

        }
        asIpBin = decToBin(atoi(asIp1.data())) + decToBin(atoi(asIp2.data())) +
        decToBin(atoi(asIp3.data())) + decToBin(atoi(asIp4.data())) ;
    }
    return out;
}
