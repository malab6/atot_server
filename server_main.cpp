#include "ServerSocket.h"
#include "SocketException.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
//str#include <string>

using namespace std;

void upload();

int main ( int argc, int argv[] )
{
	cout << "running....\n";

	try
    {
      // Create the socket
		ServerSocket server ( 30000 );

    	while ( true )
		{

			ServerSocket new_sock;
			server.accept ( new_sock );

			try
	    	{
	    		while ( true )
				{
					string data;
					new_sock >> data;
					
					cout << "receiving data : " << data << endl;
					
					
					
					if(strcmp(data.c_str(),"1") == 0)
					{							
						upload();
					}
					
					new_sock << data;
				}
	    	}
	  		catch ( SocketException& ) {}

		}
    }
  	catch ( SocketException& e )
    {
    	cout << "Exception was caught:" << e.description() << "\nExiting.\n";
    }

	return 0;
}

void upload()
{
	cout << "uploading..." << endl;

	int fd = open("video.avi", O_RDONLY);
	
	if(fd == -1)
	{
		cout << "File open error" << endl;
		return;
	}
	cout << "File open" << endl;
}
