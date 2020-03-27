#include "ModelSimServer.hpp"
using namespace std;


int ModelSimServer::m_hard_soc = -1;
int ModelSimServer::m_soft_soc = -1;


ModelSimServer::ModelSimServer(char* ip_address, int port)
{
    m_socket = -1;
    if((m_socket = server_connect(ip_address, port)) == -1)
    {
        cout << "[MODELSIMSERVER]: server could not connect" << endl;
    }
}


int ModelSimServer::listenOnSocket() 
{   
    struct sockaddr client;
    int client_socket;
    int c;
    
    if(m_socket == -1)
    {
        return -1;
    }
	else
	{
		cout << "[MODELSIMSERVER] is listening for connections...."	<< endl;
	}
    msgHeader_t hdr;
    hdr.msgType = NULL_MSG;
    hdr.length = 0;
    hdr.pyld = false;
    while((client_socket = accept(m_socket, (struct sockaddr*)&client, (socklen_t*)&c))) 
    {     
        if(client_socket < 0) 
        {
	        cout << "[MODELSIMSERVER]: Client accept failed" << endl;
        } 
        else 
        {
            recv_message(client_socket, &hdr,  nullptr);
            if(hdr.msgType == CONNECT_HARDWARE)
            {
	            cout << "[MODELSIMSERVER]: hardware connected" << endl;
                m_hard_soc = client_socket;
            }
            else if(hdr.msgType == CONNECT_SOFTWARE)
            {
	            cout << "[MODELSIMSERVER]: software connected" << endl;
                m_soft_soc = client_socket;
            }
        }
	    if(m_soft_soc != -1 && m_hard_soc != -1)
	    {
		    cout << "Spawning Software and Hardware threads" << endl;
		    m_hard_thrd_hndl = new thread(hardware_thread);
		    m_soft_thrd_hndl = new thread(software_thread); 
	    }
        hdr.msgType = NULL_MSG;
        hdr.length = 0;
        hdr.pyld = false;
    }
    return 0;
}


void ModelSimServer::hardware_thread()
{
	msgHeader_t hdr;
	uint8_t* blk = new uint8_t[MAX_BLK_SZ];
	while (true)
	{
		recv_message(m_hard_soc, &hdr, blk);
        send_message(m_soft_soc, &hdr, blk);
	}
}


void ModelSimServer::software_thread()
{
    msgHeader_t hdr;
    uint8_t* blk = new uint8_t[MAX_BLK_SZ];
    while(true)
    {
        recv_message(m_soft_soc, &hdr, blk);
        send_message(m_hard_soc, &hdr, blk);
    }
}


int main(int argc, char *argv[])
{
    ModelSimServer *server = new ModelSimServer();
    server->listenOnSocket();
    return 0;   
}
