#include "ClientSocket.h"
#include "SocketException.h"
#include <iostream>
#include <string>

using namespace std;

int main ( int argc, int argv[] )
{
    try
	{
		ClientSocket client_socket ( "localhost", 30000 );

    	std::string reply;
                
        while(1)
        {
    		try
    		{
    			string sendMeg;
    			cin >> sendMeg;
    			
    	   		client_socket << sendMeg;
				client_socket >> reply;        	
    		}
    		catch ( SocketException& )
    		{
        		cout << "SocketException" << endl;
    		}

        	std::cout << "We received this response from the server:\n\"" << reply << "\"\n";;
        }

    }
    catch ( SocketException& e )
    {
       	std::cout << "Exception was caught:" << e.description() << "\n";
    }
	
	return 0;
}
