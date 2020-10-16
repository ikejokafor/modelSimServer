#pragma once


#include <thread>
#include <iostream>
#include "network.hpp"
#include "myNetProto.hpp"


class ModelSimServer
{
    public:
        /**
        * function
        *
        * \param[in] 
        * \param[in, out] 
        * \param[in] 
        *
        * \return 
        */
        ModelSimServer();
        
        
        /**
        * function
        *
        * \param[in] 
        * \param[in, out] 
        * \param[in] 
        *
        * \return 
        */
        int listenOnSocket();


        /**
        * function
        *
        * \param[in] 
        * \param[in, out] 
        * \param[in] 
        *
        * \return 
        */ 
        static void hardware_thread();
        
        
        /**
        * function
        *
        * \param[in] 
        * \param[in, out] 
        * \param[in] 
        *
        * \return 
        */        
        static void software_thread();
        

        int m_socket;
        static int m_hard_soc;
        static int m_soft_soc;
        std::thread* m_hard_thrd_hndl;
        std::thread* m_soft_thrd_hndl;
};
