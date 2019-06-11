#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

string decToBin (int num)
{
    string out;
    if (num >= 128)
    {
        num = num - 128;
        out = "1";
    }
    else
        out = "0";
    if (num >= 64)
    {
        num -= 64;
        out += "1";
    }
    else
        out += "0";
    if (num >= 32)
    {
        num -= 32;
        out += "1";
    }
    else
        out += "0";
    if (num >= 16)
    {
        num -= 16;
        out += "1";
    }
    else
        out += "0";
    if (num >= 8)
    {
        num -= 8;
        out += "1";
    }
    else
        out += "0";
    if (num >= 4)
    {
        num -= 4;
        out += "1";
    }
    else
        out += "0";
    if (num >= 2)
    {
        num -= 2;
        out += "1";
    }
    else
        out += "0";
    if (num >= 1)
    {
        num -= 1;
        out += "1";
    }
    else
        out += "0";
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
                        break;
                }
            }

        }
        asIpBin = decToBin(atoi(asIp1.data())) + decToBin(atoi(asIp2.data())) +
        decToBin(atoi(asIp3.data())) + decToBin(atoi(asIp4.data())) ;
    }
    cout << "Match: " << out << endl;
    return out;
}

int main(int argc, char* argv[])
{
    ifstream inFile;
    ifstream dbFile;
    ofstream outFile;
    string first;
    string second;
    string third;
    string fourth;
    inFile.open(argv[2]);
    dbFile.open(argv[1]);
    outFile.open("output.txt");
    string test = "abc";
    string dataLine;
    while (getline(inFile, first, '.' ) && getline(inFile, second, '.' )
           && getline(inFile, third, '.' ) && getline(inFile, fourth, '\n' ))
    {
        cout << "Searching for " << first << "." << second  << "." << third << "." << fourth << endl;
        dataLine = mapAS(first, second, third, fourth, dbFile);
        outFile << dataLine;
        dbFile.clear();
        dbFile.seekg(0, ios::beg);
    }
    outFile.close();
    cout << "Saved to output.txt" << endl;
    return 0;
}
