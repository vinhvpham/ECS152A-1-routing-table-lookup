ip2as.cpp
project1, ecs152a
Vinh Pham

-Program was written in C++, tested to be working on Windows 10 operating system, compiled with GNU GCC Compiler. Also tested to successfully compile and run on linux but the output file has different spacing.

-Finds the longest prefix match of the IP given a database text file and input file, and outputs to "output.txt".

-Program assumes that it will be ran with the correct arguments in the form of ip2as <DB file> <IP file> . for brevity, No validation for the correct number or arguments were written into the program. 

-Progam also assumes that the IP file will be in the correct format.

-Lines in the DB file with the incorrect number of fields will be skipped.

sources:
http://www.cplusplus.com/ was referenced to search for useful libraries, in particular, <sstream> and <algorithm> were used for working with substrings.

Extended instructions:

#
# IP2AS: This tool maps an IP address to an AS. It uses static table
#        Address prefix to AS number collected from whois DB and BGP
#        tables. This table is stored in a file and should be given to
#        the tool as a parameter. It will perform longest prefix
#        matching and will map the IP to an AS number.
#
#	 The tool should print out the longest prefix that the IP
#	 address is matched to, and the corresponding AS number.

Usage: 

   ip2as <DB file> <IP file>  
 
Steps:

1. Put the set of IP addresses you want to map to ASes into the <IP
   file>. You can list one IP address per line. 
   
   For example, look at IPlist.txt file, which contains the following:
   
   169.237.33.90
   208.30.172.70

2. The <DB file> has data about which address block belongs to
   a particular AS (look at DB_091803.txt file, for example).
   The <DB file> is constructed based on IRR database and
   BGP routing table.
  
3. Run ip2as and specify the <DB file> and <IP file>

   For example, if you run 
   >> ip2as DB_091803.txt IPlist.txt

   the output should look like the following:
   
   169.237.0.0/16  1852 169.237.33.90
   208.0.0.0/11  1239 208.30.172.70

   


